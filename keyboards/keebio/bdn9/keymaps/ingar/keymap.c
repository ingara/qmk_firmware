/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

enum custom_keycodes {
    MACRO_SHRUG = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |      | Knob 2: Change HUE |
        | Press: Mute       | Play | Press: Toggle LED  |
        | Hold: Layer 2     | Up   | RGB Mode           |
        | Media Previous | Play/Pause  | Media Next |
     */
    [0] = LAYOUT(
        KC_MUTE, KC_MPLY, RGB_TOG,
        MO(1)  , MACRO_SHRUG  , RGB_MOD,
        KC_MPRV, KC_MPLY, KC_MNXT
    ),
    /*
        | RESET          | N/A  | Media Stop |
        | Held: Layer 2  | Home | RGB Mode   |
        | Media Previous | End  | Media Next |
     */
    [1] = LAYOUT(
        RESET  , BL_STEP, KC_STOP,
        _______, KC_HOME, RGB_MOD,
        KC_MPRV, KC_END , KC_MNXT
    ),
};

void encoder_update_user(uint8_t index, bool fakeClockwise) {
    bool clockwise = !fakeClockwise;

    // Left encoder
    if (index == 0) {
        if (clockwise) {
            tap_code(KC__VOLUP);
        } else {
            tap_code(KC__VOLDOWN);
        }
    }
    // Right encoder
    else if (index == 1) {
        if (clockwise) {
            rgblight_increase_hue_noeeprom();
        } else {
            rgblight_decrease_hue_noeeprom();
        }
    }
}


void keyboard_post_init_user(void) {
    // Call the post init code.
    rgblight_enable_noeeprom(); // enables Rgb, without saving settings
    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 1); // sets mode to Slow breathing without saving
    rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
}

void matrix_init_user(void) {
   set_unicode_input_mode(UC_OSX); // REPLACE UC_XXXX with the Unicode Input Mode for your OS. See table below.
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case MACRO_SHRUG: {
            if (record->event.pressed) {
                send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
            }
            return false;
            break;
        }
    }

    return true;
}
