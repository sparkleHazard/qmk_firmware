/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "action.h"
#include QMK_KEYBOARD_H
#include "keychron_common.h"

// #define BOLDBOR
// #define PSTEFRM
// #define MRGCNTR
// #define WRAPTXT
// #define PSTEVAL

// enum custom_keycodes {
//     BOLDBOR = SAFE_RANGE,
//     PSTEFRM,
//     MRGCNTR,
//     WRAPTXT,
//     PSTEVAL,
//     EXZOOMI,
//     EXZOOMO,
// };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case BOLDBOR:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("h") "bt");
        }
        break;

    case PSTEFRM:
        if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_LALT);
            tap_code(KC_V);
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
            tap_code(KC_T);
            tap_code(KC_ENT);
        }
        break;

    case MRGCNTR:
        if (record->event.pressed) {
           SEND_STRING(SS_LALT("hmm"));
        }
        break;

    case WRAPTXT:
        if (record->event.pressed) {
           SEND_STRING(SS_LALT("hw"));
        }
        break;

    case PSTEVAL:
        if (record->event.pressed) {
           register_code(KC_LCTL);
           register_code(KC_LALT);
           tap_code(KC_V);
           unregister_code(KC_LCTL);
           unregister_code(KC_LALT);
           tap_code(KC_V);
        }
        break;

    case EXZOOMI:
        if (record->event.pressed) {
           register_code(KC_LCTL);
           register_code(KC_LALT);
           tap_code(KC_EQL);
           unregister_code(KC_LCTL);
           unregister_code(KC_LALT);
        }
        break;

    case EXZOOMO:
        if (record->event.pressed) {
           register_code(KC_LCTL);
           register_code(KC_LALT);
           tap_code(KC_MINS);
           unregister_code(KC_LCTL);
           unregister_code(KC_LALT);
        }
        break;
    }
    return true;
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_NO) {
                    rgb_matrix_set_color(index, RGB_GREEN);
                }
            }
        }
    }

    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i < led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, RGB_RED);
            }
        }
    }
    return false;
}

// clang-format off

enum layers{
  BASE,
  EXCEL,
  WIN_BASE,
  FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ansi_103(
        KC_MUTE,  KC_F13,   KC_F14,   TO(EXCEL),  KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_DEL,            RGB_MOD,
        KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,           KC_PGUP,
        KC_P7,    KC_P8,    KC_P9,    KC_PPLS,    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,           KC_PGDN,
        KC_P4,    KC_P5,    KC_P6,                KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,            KC_HOME,
        KC_P1,    KC_P2,    KC_P3,    KC_PENT,    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_P0,              KC_PDOT,              KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RWIN,  MO(FN),     KC_RCTL,  KC_LEFT,  KC_DOWN, KC_RGHT),
    [EXCEL] = LAYOUT_ansi_103(
        KC_MUTE,  KC_F13,   KC_F14,   TO(BASE),   KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,            RGB_TOG,
        KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,    KC_CALC,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_MINS,    KC_EQL,   KC_BSPC,           XXXXXXX,
        KC_P7,    KC_P8,    KC_P9,    KC_PPLS,    XXXXXXX,  XXXXXXX,  WRAPTXT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  PSTEVAL,  XXXXXXX,    XXXXXXX,  KC_BSLS,           XXXXXXX,
        KC_P4,    KC_P5,    KC_P6,                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  PSTEFRM,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              _______,           XXXXXXX,
        KC_P1,    KC_P2,    KC_P3,    KC_PENT,    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     BOLDBOR,  XXXXXXX,  MRGCNTR,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  KC_UP,
        KC_P0,              KC_PDOT,              KC_LCTL,  XXXXXXX,  XXXXXXX,                                _______,                                XXXXXXX,  MO(FN),     XXXXXXX,  KC_LEFT,  KC_DOWN, KC_RGHT),
    [WIN_BASE] = LAYOUT_ansi_103(
        KC_MUTE,  _______,  _______,  _______,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,     KC_F12,   KC_DEL,            RGB_MOD,
        KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,    KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,           KC_PGUP,
        KC_P7,    KC_P8,    KC_P9,    KC_PPLS,    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,     KC_LBRC,    KC_RBRC,                     KC_PGDN,
        KC_P4,    KC_P5,    KC_P6,                KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,              KC_ENT,            KC_HOME,
        KC_P1,    KC_P2,    KC_P3,    KC_PENT,    KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM, KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_P0,              KC_PDOT,              KC_LCTL,  KC_LWIN,  KC_LALT,                                 KC_SPC,                                KC_RALT,  MO(FN),     KC_RCTL,  KC_LEFT,  KC_DOWN, KC_RGHT),
    [FN] = LAYOUT_ansi_103(
        RGB_TOG,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   XXXXXXX,           RGB_TOG,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,           XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,                     XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,           XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  NK_TOGG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,
        XXXXXXX,            XXXXXXX,             XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX),
};

// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [EXCEL]   = {ENCODER_CCW_CW(EXZOOMO, EXZOOMI) },
    [WIN_BASE] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [FN]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif

void housekeeping_task_user(void) {
    housekeeping_task_keychron();
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if (!process_record_keychron(keycode, record)) {
//         return false;
//     }
//     return true;
// }
