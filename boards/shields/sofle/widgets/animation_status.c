/*
 * Copyright (c) 2023 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zmk/display/widgets/output_status.h>
#include <zmk/display/widgets/layer_status.h>
#include <zmk/display/widgets/battery_status.h>
#include <zmk/events/activity_state_changed.h>
#include <zmk/event_manager.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);
static lv_obj_t *animation_label;
static lv_obj_t *pet_label;
static int animation_frame = 0;
static bool is_active = true;

// Frames da animação do "pet"
static const char *pet_frames[] = {
    " (◕‿◕) ",
    " (◕ ‿ ◕)",
    " (◕‿◕) ",
    " (◕  ‿ ◕)",
};

// Indicador rotativo
static const char *spinner_frames[] = {
    "|", "/", "-", "\\"
};

static void update_animation_cb(lv_timer_t *timer) {
    if (!animation_label) return;
    
    // Atualiza frame da animação
    animation_frame = (animation_frame + 1) % 4;
    
    if (is_active) {
        // Mostra pet animado quando ativo
        lv_label_set_text(pet_label, pet_frames[animation_frame]);
        lv_label_set_text_fmt(animation_label, "Active %s", 
                               spinner_frames[animation_frame]);
    } else {
        // Mostra pet dormindo quando inativo
        lv_label_set_text(pet_label, " (- ‿ -) ");
        lv_label_set_text(animation_label, "Sleep...");
    }
}

static void set_layer_symbol(lv_obj_t *label, uint8_t layer) {
    const char *layer_symbols[] = {
        "🏠",  // Base/Default
        "🔧",  // Lower/Tools
        "🧭",  // Raise/Navigation  
        "⚙️",  // Adjust/System
    };
    
    if (layer < ARRAY_SIZE(layer_symbols)) {
        lv_label_set_text(label, layer_symbols[layer]);
    }
}

int zmk_widget_animation_status_init(struct zmk_widget_animation_status *widget,
                                   lv_obj_t *parent) {
    widget->obj = lv_obj_create(parent);
    lv_obj_set_size(widget->obj, 128, 32);
    
    // Label para animação principal
    animation_label = lv_label_create(widget->obj);
    lv_obj_align(animation_label, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_label_set_text(animation_label, "Starting...");
    
    // Label para o "pet"
    pet_label = lv_label_create(widget->obj);
    lv_obj_align(pet_label, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(pet_label, " (◕‿◕) ");
    
    // Timer para animar (atualiza a cada 500ms)
    lv_timer_create(update_animation_cb, 500, NULL);
    
    sys_slist_append(&widgets, &widget->node);
    return 0;
}

int zmk_widget_animation_status_listener(const zmk_event_t *eh) {
    const struct zmk_activity_state_changed *ev = as_zmk_activity_state_changed(eh);
    
    if (ev) {
        is_active = (ev->state == ZMK_ACTIVITY_ACTIVE);
        return 0;
    }
    
    return 0;
}

ZMK_DISPLAY_WIDGET_LISTENER(widget_animation_status, struct zmk_activity_state_changed,
                          zmk_widget_animation_status_listener, NULL)
