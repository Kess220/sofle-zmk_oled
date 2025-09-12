/*
 * Copyright (c) 2023 The ZMK Contributors
 * SPDX-License-Identifier: MIT
 * 
 * Typing Speed Pet - Animação que reage à velocidade de digitação
 */

#include <zmk/display/widgets/output_status.h>
#include <zmk/events/keycode_state_changed.h>
#include <zmk/event_manager.h>
#include <zephyr/kernel.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);
static lv_obj_t *pet_label;
static lv_obj_t *wpm_label;
static lv_obj_t *mood_label;

// Controle de velocidade
static int keys_pressed = 0;
static int64_t last_key_time = 0;
static int64_t typing_start_time = 0;
static int current_wpm = 0;
static int animation_frame = 0;

// Estados do pet baseados na velocidade
typedef enum {
    PET_SLEEPING,   // 0 WPM
    PET_AWAKE,      // 1-20 WPM
    PET_HAPPY,      // 21-40 WPM
    PET_EXCITED,    // 41-60 WPM
    PET_HYPER,      // 61+ WPM
} pet_mood_t;

static pet_mood_t current_mood = PET_SLEEPING;

// Frames de animação para cada estado
static const char *pet_frames[][4] = {
    // SLEEPING
    {" (- ‿ -) ", " (- ‿ -) ", " (- ‿ -) ", " (- ‿ -) "},
    
    // AWAKE  
    {" (◕ ‿ ◕) ", " (◕ ‿ ◕) ", " (◕ ‿ ◕) ", " (◕ ‿ ◕) "},
    
    // HAPPY
    {" (◕‿◕) ", " (◕ ‿ ◕) ", " (◕‿◕) ", " (◕ ‿ ◕) "},
    
    // EXCITED
    {" (◕▿◕) ", " (◕‿◕) ", " (◕▿◕) ", " (◕‿◕) "},
    
    // HYPER
    {" (⌐■_■) ", " (◕▿◕)! ", " (⌐■_■) ", " ＼(^o^)／ "}
};

// Mensagens de humor
static const char *mood_messages[] = {
    "Zzz...",           // SLEEPING
    "Ready!",           // AWAKE
    "Nice!",            // HAPPY
    "Great!!",          // EXCITED
    "ON FIRE!!!"        // HYPER
};

// Cores/intensidade baseadas no humor
static const char *speed_bars[] = {
    "▁",                // SLEEPING
    "▁▁",               // AWAKE
    "▁▂▃",              // HAPPY
    "▁▂▃▄▅",           // EXCITED
    "▁▂▃▄▅▆▇█"         // HYPER
};

static void calculate_wpm(void) {
    int64_t now = k_uptime_get();
    
    if (typing_start_time == 0) {
        typing_start_time = now;
        return;
    }
    
    int64_t time_diff = now - typing_start_time;
    if (time_diff > 0) {
        // Calcula WPM aproximado (assumindo 5 chars por palavra)
        current_wpm = (keys_pressed * 60000) / (time_diff * 5);
    }
    
    // Reset se parou de digitar por mais de 3 segundos
    if ((now - last_key_time) > 3000) {
        keys_pressed = 0;
        typing_start_time = 0;
        current_wpm = 0;
    }
}

static pet_mood_t get_mood_from_wpm(int wpm) {
    if (wpm == 0) return PET_SLEEPING;
    if (wpm <= 20) return PET_AWAKE;
    if (wpm <= 40) return PET_HAPPY;
    if (wpm <= 60) return PET_EXCITED;
    return PET_HYPER;
}

static void update_pet_animation(void) {
    if (!pet_label || !wpm_label || !mood_label) return;
    
    calculate_wpm();
    current_mood = get_mood_from_wpm(current_wpm);
    
    // Atualiza frame da animação
    animation_frame = (animation_frame + 1) % 4;
    
    // Atualiza pet
    lv_label_set_text(pet_label, pet_frames[current_mood][animation_frame]);
    
    // Atualiza WPM
    lv_label_set_text_fmt(wpm_label, "%d WPM %s", current_wpm, speed_bars[current_mood]);
    
    // Atualiza mensagem de humor
    lv_label_set_text(mood_label, mood_messages[current_mood]);
}

static void animation_timer_cb(lv_timer_t *timer) {
    update_pet_animation();
}

int zmk_widget_typing_pet_init(struct zmk_widget_typing_pet *widget, lv_obj_t *parent) {
    widget->obj = lv_obj_create(parent);
    lv_obj_set_size(widget->obj, 128, 32);
    
    // Pet no centro
    pet_label = lv_label_create(widget->obj);
    lv_obj_align(pet_label, LV_ALIGN_CENTER, 0, -2);
    lv_label_set_text(pet_label, " (- ‿ -) ");
    
    // WPM no topo
    wpm_label = lv_label_create(widget->obj);
    lv_obj_align(wpm_label, LV_ALIGN_TOP_MID, 0, 0);
    lv_label_set_text(wpm_label, "0 WPM");
    
    // Humor na parte inferior
    mood_label = lv_label_create(widget->obj);
    lv_obj_align(mood_label, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_label_set_text(mood_label, "Zzz...");
    
    // Timer para animação (atualiza baseado no humor)
    lv_timer_create(animation_timer_cb, 800, NULL);
    
    sys_slist_append(&widgets, &widget->node);
    return 0;
}

static int typing_pet_listener(const zmk_event_t *eh) {
    struct zmk_keycode_state_changed *ev = as_zmk_keycode_state_changed(eh);
    
    if (ev && ev->state) { // Tecla pressionada (não solta)
        keys_pressed++;
        last_key_time = k_uptime_get();
        
        // Acelera animação se digitando rápido
        if (current_mood >= PET_EXCITED) {
            // Atualiza imediatamente para responsividade
            update_pet_animation();
        }
    }
    
    return 0;
}

ZMK_LISTENER(typing_pet, typing_pet_listener);
ZMK_SUBSCRIPTION(typing_pet, zmk_keycode_state_changed);
