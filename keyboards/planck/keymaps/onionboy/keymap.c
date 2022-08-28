/* Copyright 2015-2021 Jack Humbert
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

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _COLEMAKDH,
  _L1,
  _L2,
  _L3,
  _GAMING,
  _GAMING2,
  _MOUSE
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAKDH,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

// Space bar hyper key
#define SPACE HYPR_T(KC_SPC)

// Left-hand home row mods - QWERTY
#define HOME_A LSFT_T(KC_A)
#define HOME_S LGUI_T(KC_S)
#define HOME_D LALT_T(KC_D)
#define HOME_F RCTL_T(KC_F)

// Left-hand home row mods L1 - QWERTY
#define ESC_MOD LSFT_T(KC_ESC)
#define QUOT_MOD LGUI_T(KC_QUOT)
#define NUHS_MOD LALT_T(KC_NUHS)
#define BSLS_MOD RCTL_T(KC_BSLS)

// Left-hand home row mods L2 - QWERTY
#define TAB_MOD LSFT_T(KC_TAB)

// Right-hand home row mods - QWERTY
#define HOME_J LCTL_T(KC_J)
#define HOME_K LALT_T(KC_K)
#define HOME_L LGUI_T(KC_L)
#define HOME_SCLN RSFT_T(KC_SCLN)

// Right-hand home row mods L1 - QWERTY
#define MINS_MOD LCTL_T(KC_MINS)
#define EQL_MOD LALT_T(KC_EQL)
#define LBRC_MOD LGUI_T(KC_LBRC)
#define RBRC_MOD RSFT_T(KC_RBRC)

// Right-hand home row mods L2 - QWERTY
#define D_MOD LCTL_T(KC_DOWN)
#define U_MOD LALT_T(KC_UP)
#define R_MOD LGUI_T(KC_RIGHT)

// Left-hand home row mods - COLEMAKDH
#define CM_HOME_A LSFT_T(KC_A)
#define CM_HOME_R LGUI_T(KC_R)
#define CM_HOME_S LALT_T(KC_S)
#define CM_HOME_T RCTL_T(KC_T)

// Left-hand home row mods LC1 - COLEMAKDH
#define CM_ESC_MOD LSFT_T(KC_ESC)
#define CM_QUOT_MOD LGUI_T(KC_QUOT)
#define CM_NUHS_MOD LALT_T(KC_NUHS)
#define CM_BSLS_MOD RCTL_T(KC_BSLS)

// Left-hand home row mods LC2 - COLEMAKDH
#define CM_TAB_MOD LSFT_T(KC_TAB)

// Right-hand home row mods - COLEMAKDH
#define CM_HOME_N LCTL_T(KC_N)
#define CM_HOME_E LALT_T(KC_E)
#define CM_HOME_I LGUI_T(KC_I)
#define CM_HOME_O RSFT_T(KC_O)

// Right-hand home row mods LC1 - COLEMAKDH
#define CM_MINS_MOD LCTL_T(KC_MINS)
#define CM_EQL_MOD LALT_T(KC_EQL)
#define CM_LBRC_MOD LGUI_T(KC_LBRC)
#define CM_RBRC_MOD RSFT_T(KC_RBRC)

// Right-hand home row mods LC2 - COLEMAKDH
#define CM_D_MOD LCTL_T(KC_DOWN)
#define CM_U_MOD LALT_T(KC_UP)
#define CM_R_MOD LGUI_T(KC_RIGHT)

// Layers
#define L1 MO(_L1)
#define L2 MO(_L2)
#define L3 MO(_L3)
#define GAMING DF(_GAMING)
#define GAMING2 MO(_GAMING2)
#define QWERTY DF(_QWERTY)
#define COLEMAKDH DF(_COLEMAKDH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |      |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  L1  |  Spc | Bksp |  L2  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      XXXXXXX,
    XXXXXXX, HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,    KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, XXXXXXX,
    XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, L1,      SPACE,   LT(_MOUSE, KC_BSPC), L2,      XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX
),

/* Colemak DH
 * ,-----------------------------------------------------------------------------------.
 * |      |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  L1  |  Spc | Bksp |  L2  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAKDH] = LAYOUT_planck_grid(
    XXXXXXX, KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,    KC_J,    KC_L,       KC_U,       KC_Y,       KC_SCLN,   XXXXXXX,
    XXXXXXX, CM_HOME_A,  CM_HOME_R,  CM_HOME_S,  CM_HOME_T,  KC_G,    KC_M,    CM_HOME_N,  CM_HOME_E,  CM_HOME_I,  CM_HOME_O, XXXXXXX,
    XXXXXXX, KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,    KC_K,    KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,   XXXXXXX,
    XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    L1,         SPACE,   LT(_MOUSE, KC_BSPC), L2,XXXXXXX, XXXXXXX,    XXXXXXX,   XXXXXXX
),

/* L1 
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  Esc |   '  |   #  |   \  |   ~  |      |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |   \  |   `  |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  Spc | Bksp |  L3  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_L1] = LAYOUT_planck_grid(
    XXXXXXX, KC_EXLM, KC_AT,    KC_HASH,  KC_DLR,   KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN,  KC_RPRN,  XXXXXXX,
    XXXXXXX, ESC_MOD, QUOT_MOD, NUHS_MOD, BSLS_MOD, KC_TILD, XXXXXXX, MINS_MOD, EQL_MOD, LBRC_MOD, RBRC_MOD, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  KC_NUBS,  KC_GRV,  XXXXXXX, KC_UNDS,  KC_PLUS, KC_LCBR,  KC_RCBR,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  _______,  SPACE,   KC_BSPC, L3,       XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX
),

/* L2
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  Tab |      |      |      |      | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   ,  |   .  |ENTER |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  L3  |  Spc | Bksp |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_L2] = LAYOUT_planck_grid(
    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
    XXXXXXX, TAB_MOD, KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX, KC_LEFT, D_MOD,   U_MOD,   R_MOD,   KC_RSFT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  KC_ENT,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, L3,      SPACE,   KC_BSPC, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* L3
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      | HOME | PGDN | PGUP | END  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | BOOT |QWERTY|COLMAK|      |      |      |  DEL |      |      |GAMING|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_L3] = LAYOUT_planck_grid(
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
    XXXXXXX, KC_F11,  KC_F12,  XXXXXXX,  XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
    XXXXXXX, QK_BOOT, QWERTY, COLEMAKDH, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  XXXXXXX, XXXXXXX, GAMING,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* MOUSE
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      | MSUP |      |      |      | ACL0 | ACL1 | ACL2 |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | MSLF | MSDN | MSRT |      |      | BTN1 | BTN2 | BTN3 |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | WHLF | WHUP | WHDN | WHRT |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* GAMING
 * ,-----------------------------------------------------------------------------------.
 * |      |  TAB |  Q   |  W   |  E   |  R   |  T   |  Y   |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | LCTL |  A   |  S   |  D   |  F   |  G   |  H   |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | LSFT |  Z   |  X   |  C   |  V   |  B   |  N   |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |GMING2|  SPC |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_planck_grid(
    XXXXXXX, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GAMING2, KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* GAMING2
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  ESC |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | EXIT |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING2] = LAYOUT_planck_grid(
    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_QWERTY), XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

};
