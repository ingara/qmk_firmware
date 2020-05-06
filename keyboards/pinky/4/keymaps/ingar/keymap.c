/* Copyright 2018 'Masayuki Sunahara'
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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes { QWERTY = SAFE_RANGE, LOWER, RAISE, ADJUST };

#define ________ KC_TRNS
#define XXXXXXXX KC_NO
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_ADJ ADJUST
#define KC_CTLTB CTL_T(KC_TAB)

#define KC_ALTSFT(kc) LALT(LSFT(kc))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        //,---------------------------------------------------------------------.  ,---------------------------------------------------------------------.
        KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, LALT(KC_LSHIFT), /* |--| */ LALT(KC_LSHIFT), KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL,
        //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, LALT_T(KC_TAB), /* |--| */ KC_BSPC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
        //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        CTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, CTL_T(KC_ESC), /* |--| */ KC_ENT, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        KC_LOWER, CTL_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_ADJ, /* |--| */ KC_ADJ, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
        //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        /* -- */ /* -- */ KC_HYPR, LT(_LOWER, KC_BSPC), KC_LGUI, KC_LSHIFT, /* |--| */ KC_RSHIFT, KC_SPC, LM(_ADJUST, MOD_LALT), KC_HYPR /* -- */ /* -- */                         //`---------------------------------------'  `---------------------------------------'
    ),

    [_LOWER] = LAYOUT(                                                                                                                                     //,---------------------------------------------------------------------.  ,---------------------------------------------------------------------.
        KC_GRV, ________, ________, ________, ________, ________, ________, /* |--| */ ________, ________, ________, ________, KC_MINS, KC_EQL, ________,             //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        ________, ________, ________, ________, ________, ________, ________, /* |--| */ ________, ________, KC_LPRN, KC_RPRN, ________, ________, KC_EQL,          //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        ________, ________, ________, ________, ________, ________, ________, /* |--| */ ________, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, ________, ________,            //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        ________, ________, ________, ________, ________, ________, ________, /* |--| */ ________, ________, ________, LSFT(KC_COMM), LSFT(KC_DOT), KC_PIPE, KC_NONUS_BSLASH,  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        ________, ________, ________, ________, /* |--| */ ________, ________, ________, ________                                                                     //`---------------------------------------'  `---------------------------------------'
        ),

    [_RAISE] = LAYOUT(                                                                                                                                                           //,---------------------------------------------------------------------.  ,---------------------------------------------------------------------.
        KC_GRV, ________, ________, ________, ________, ________, ________, /* |--| */ ________, ________, ________, ________, KC_MINS, KC_EQL, ________,                                   //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        ________, ________, ________, ________, ________, ________, ________, /* |--| */ ________, ________, ________, ________, ________, ________, ________,                              //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        ________, ________, ________, ________, ________, ________, ________, /* |--| */ ________, KC_ALTSFT(KC_H), KC_ALTSFT(KC_J), KC_ALTSFT(KC_K), KC_ALTSFT(KC_L), ________, ________,  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        ________, ________, ________, ________, ________, ________, ________, /* |--| */ ________, ________, ________, ________, ________, ________, ________,                              //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        ________, ________, ________, ________, /* |--| */ ________, KC_ALTSFT(KC_SPC), ________, ________                                                                                  //`---------------------------------------'  `---------------------------------------'
        ),

    [_ADJUST] = LAYOUT(                                                                                                                                            //,---------------------------------------------------------------------.  ,---------------------------------------------------------------------.
        ________, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_MPLY, /* |--| */ LGUI(LSFT(KC_SPC)), KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_DELETE,                                    //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        ________, ________, KC_MS_UP, KC_MS_WH_DOWN, ________, ________, ________, /* |--| */ KC_DELETE, ________, ________, ________, KC_F11, KC_F12, ________,               //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        ________, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_BTN1, ________, ________, /* |--| */ LGUI(LCTL(KC_SPC)), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, ________, ________,  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        ________, ________, ________, KC_MS_WH_UP, ________, ________, KC_LOWER, /* |--| */ KC_LOWER, ________, ________, ________, ________, ________, KC_BSLASH,                //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
        ________, ________, ________, ________, /* |--| */ ________, ________, ________, ________                                                                             //`---------------------------------------'  `---------------------------------------'
        )};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // set_timelog();
    }

    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
    }
    return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}
