/*
 * Copyright (c) 2023 The ZMK Contributors
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <lvgl.h>
#include <zephyr/kernel.h>

struct zmk_widget_typing_pet {
    sys_snode_t node;
    lv_obj_t *obj;
};

int zmk_widget_typing_pet_init(struct zmk_widget_typing_pet *widget, lv_obj_t *parent);
