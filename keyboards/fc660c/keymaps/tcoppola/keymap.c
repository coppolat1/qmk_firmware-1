/*
Copyright 2017 Balz Guenat

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

/* Tap Dance declrations */
enum
{
  TD_VOL_UP_PLAY_PAUSE = 0,
  TD_FN_CAPS = 1
};

qk_tap_dance_action_t tap_dance_actions[] =
{
  // Tap once for volume up, twice for play/pause.
  [TD_VOL_UP_PLAY_PAUSE] = ACTION_TAP_DANCE_DOUBLE(KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE),
  [TD_FN_CAPS] = ACTION_TAP_DANCE_DOUBLE(_______, KC_CAPS)
};

/* Keyboard Layouts */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,     TG(2),
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,     KC_DEL,
        MO(1),  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,     KC_ENT,
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,     KC_UP,
        KC_LCTL,KC_LGUI,KC_LALT,          KC_SPC,                       KC_RALT,KC_RCTL,MO(2),      KC_LEFT,KC_DOWN,KC_RGHT
    ),
  [1] = LAYOUT(
        KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,     _______,
        _______,_______,_______,_______,_______,_______,_______,KC_HOME,KC_UP,  KC_END,_______,_______,_______,_______,     _______,
        _______,_______,_______,_______,_______,KC_PPLS,KC_PGUP,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,     _______,
        _______,_______,_______,_______,KC_PMNS,_______,KC_PGDN,KC_DEL,_______, _______,_______,_______,     KC_WH_U,
        _______,_______,_______,                _______,                _______,_______,MO(2),       _______,KC_WH_D,_______
    ),
  [2] = LAYOUT(
        KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,     _______,
        _______,_______,_______,_______,_______,_______,_______,_______,KC_PSCR,KC_SLCK,KC_PAUS,_______,_______,_______,     _______,
        TD(TD_FN_CAPS),_______,_______,_______,_______,_______,_______,_______,KC_HOME,KC_PGUP,_______,_______,     _______,
        _______,_______,_______,KC_C,   _______,_______,_______,_______,KC_END, KC_PGDN,_______,_______,     KC_AUDIO_VOL_UP,
        _______,_______,_______,                _______,                _______,_______,MO(2),       TD(TD_VOL_UP_PLAY_PAUSE),KC_AUDIO_VOL_DOWN,KC_MEDIA_NEXT_TRACK
    ),

};
//KC_SYSREQ KC_PSCR

// KC_MEDIA_PLAY_PAUSE


uint32_t layer_state_set_user(uint32_t state)
{
  switch(biton32(state))
  {
    case 1:   //Caps Lock layer active
      PORTB &= ~(1<<6);
      break;
    case 2:   //Fn layer active
      PORTB &= ~(1<<5);
      break;
    default:
      PORTB |= (1<<5 | 1<<6);
      break;
  }
  return state;
}


