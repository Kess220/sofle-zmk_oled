/*
 * Copyright (c) 2023 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <lvgl.h>
#include <zephyr/kernel.h>

struct zmk_widget_animation_status {
    sys_snode_t node;
    lv_obj_t *obj;
};

int zmk_widget_animation_status_init(struct zmk_widget_animation_status *widget,
                                   lv_obj_t *parent);
