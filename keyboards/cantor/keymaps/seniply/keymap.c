// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

enum layers {
  _COLEMAK_DH,
  _EXT,
  _FNC,
  _SYM,
  _NUM
};

#define _BAK LALT(KC_LEFT)
#define _FND LCTL(KC_F)
#define _FWD LALT(KC_RGHT)

#define _LALT OSM(MOD_LALT)
#define _LGUI OSM(MOD_LGUI)
#define _LSFT OSM(MOD_LSFT)
#define _LCTL OSM(MOD_LCTL)
#define _RALT OSM(MOD_RALT)

#define _UNDO LCTL(KC_Z)
#define _CUT LCTL(KC_X)
#define _COPY LCTL(KC_C)
#define _WIN KC_LGUI
#define _PSTE LCTL(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤Bsp│   │Ent├───┘
      *                       └───┘   └───┘
      */
    [_COLEMAK_DH] = LAYOUT_split_3x6_3(
        KC_ESC,   KC_Q,  KC_W,  KC_F,  KC_P,  KC_B,      KC_J,  KC_J,  KC_U,    KC_Y,   KC_QUOT, KC_BSPC,
        KC_LALT,  KC_A,  KC_R,  KC_S,  KC_T,  KC_G,      KC_M,  KC_N,  KC_E,    KC_I,   KC_O,    KC_ENT,
        KC_LCTL,  KC_Z,  KC_X,  KC_C,  KC_D,  KC_V,      KC_K,  KC_H,  KC_COMM, KC_DOT, KC_SLSH, KC_DEL,
                        MO(_EXT), KC_LSFT, MO(_SYM),    MO(_NUM), KC_SPC, MO(_FNC)
    ),
    [_EXT] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_NO, _BAK,  _FND,  _FWD,  KC_INS,   KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_CAPS, KC_TRNS,
        KC_TRNS, _LALT, _LGUI, _LSFT, _LCTL, _RALT,    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_TRNS,
        KC_TRNS, _UNDO, _CUT,  _COPY, _WIN,  _PSTE,    KC_NO,   KC_NO,   KC_TAB,  KC_APP,  KC_PSCR, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_NO,     KC_NO, KC_TRNS, KC_NO
    ),
    [_FNC] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_MSTP, KC_MPRV, KC_MPLY,   KC_MNXT, KC_BRIU,      KC_F12, KC_F7, KC_F8, KC_F9, KC_SCRL, KC_TRNS,
        KC_TRNS, _LALT,   _LGUI,   _LSFT,     _LCTL,   KC_BRID,      KC_F11, KC_F4, KC_F5, KC_F6, KC_NO,   KC_TRNS,
        KC_TRNS, KC_MUTE, KC_VOLD, RCS(KC_C), KC_VOLU, RCS(KC_V),    KC_F10, KC_F1, KC_F2, KC_F3, KC_NO,   KC_TRNS,
                                            KC_NO, KC_TRNS, KC_NO,  KC_NO, KC_TRNS, KC_TRNS
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC,      KC_EQL,  KC_GRV,  KC_COLN, KC_SCLN, KC_PLUS, KC_TRNS,
        KC_TRNS, _LALT,   _LGUI, _LSFT,   _LCTL,   KC_CIRC,      KC_ASTR, KC_LPRN, KC_LCBR, KC_LBRC, KC_MINS, KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO, KC_BSLS, KC_PIPE, KC_AMPR,      KC_TILD, KC_RPRN, KC_RCBR, KC_RBRC, KC_UNDS, KC_TRNS,
                                    KC_NO, KC_TRNS, KC_TRNS,    KC_NO, KC_TRNS, KC_NO
    ),
    [_NUM] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NUM,      KC_EQL,  KC_7, KC_8, KC_9, KC_PLUS, KC_TRNS,
        KC_TRNS, _LALT, _LGUI, _LSFT, _LCTL,  _RALT,      KC_ASTR, KC_4, KC_5, KC_6, KC_MINS, KC_TRNS,
        KC_TRNS, KC_NO, KC_NO, KC_TAB, KC_NO, KC_NO,      KC_0,    KC_1, KC_2, KC_3, KC_SLSH, KC_TRNS,
                               KC_NO, KC_TRNS, KC_NO,    KC_TRNS, KC_TRNS, KC_NO
    )
};

