/*
Copyright jungwoo
*/

#include "satan.h"


// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL1 1
#define _FL2 2
#define _FL3 3
#define _FL4 4

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define GSpace GUI_T(KC_SPC)
#define GTab GUI_T(KC_TAB)

#define LTap LT(_FL4,KC_TAB)

#define CtrW LCTL(KC_W)
#define CtrZ LCTL(KC_Z)
#define CtrX LCTL(KC_X)
#define CtrC LCTL(KC_C)
#define CtrV LCTL(KC_V)
#define CtrF LCTL(KC_F)
#define CtrT LCTL(KC_T)

#define FN_F24 LM(_FL1, KC_F24)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |Fn1    |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Alt |Gui |      Space/gui        |Alt |FN |GUI  |Ctrl |
   * `-----------------------------------------------------------'
   */
[_BL] = LAYOUT_60_ansi(
  F(0),     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC, \
  LTap,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS, \
  MO(_FL1), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,  \
  KC_LSFT,          KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,         KC_RSFT, \
  KC_LCTL, KC_LALT,KC_LGUI,                GSpace,                                 KC_HAEN,MO(_FL1), TG(_FL2),KC_RCTL ),

  /* Keymap _FL1: Function Layer
   * ,-----------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|  DEL  |
   * |-----------------------------------------------------------|
   * | CAPS|   | UP|CrW|Ref|CrT|   |Hom| UP|End|   |Vdn|Vup|     |
   * |-----------------------------------------------------------|
   * |      |Lef|Dow|Rig|CrF|   |PgU|Lef|Dow|Rig|   |   |        |
   * |-----------------------------------------------------------|
   * |Shift   |CrZ|CrX|CrC|CrV|   |PgD|   | BL|BLS|BLB|          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
[_FL1] = LAYOUT_60_ansi(
  KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_DEL,  \
  KC_CAPS,  _______,	 KC_UP,   CtrW, KC_WREF,    CtrT, _______, KC_HOME,   KC_UP,  KC_END, _______, KC_VOLD, KC_VOLU,  _______, \
  _______,  KC_LEFT, KC_DOWN, KC_RIGHT,    CtrF, _______, KC_PGUP, KC_LEFT, KC_DOWN, KC_RIGHT, _______,_______,_______, \
  KC_LSFT,      CtrZ,    CtrX,    CtrC,    CtrV,  _______, KC_PGDN, _______, BL_TOGG,  BL_STEP,  BL_BRTG,KC_RSFT, \
  _______,_______,_______,                _______,                        _______,_______,_______,_______),
  
  /* Keymap _FL2: Function Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Alt |Gui |      Space/gui        |Alt |FN |GUI  |Ctrl |
   * `-----------------------------------------------------------'
   */
[_FL2] = LAYOUT_60_ansi(
  F(0),     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC, \
  KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS, \
  KC_CAPS, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,  \
  KC_LSFT,          KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,         KC_RSFT, \
  KC_LCTL, KC_LALT,KC_LGUI,                KC_SPACE,                               KC_HAEN,MO(_FL3), TG(_FL2),KC_RCTL ), 
  
  /* Keymap _FL3: Function Layer
   * ,-----------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|  DEL  |
   * |-----------------------------------------------------------|
   * | CAPS|   | UP|CrW|Ref|CrT|   |Hom| UP|End|   |Vdn|Vup|     |
   * |-----------------------------------------------------------|
   * |      |Lef|Dow|Rig|CrF|   |PgU|Lef|Dow|Rig|   |   |        |
   * |-----------------------------------------------------------|
   * |Shift   |CrZ|CrX|CrC|CrV|   |PgD|   | BL|BLS|BLB|   RESET  |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
[_FL3] = LAYOUT_60_ansi(
  KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_DEL,  \
  KC_CAPS,  _______,	 KC_UP,   CtrW, KC_WREF,    CtrT, _______, KC_HOME,   KC_UP,  KC_END, _______, KC_VOLD, KC_VOLU,  _______, \
  _______,  KC_LEFT, KC_DOWN, KC_RIGHT,    CtrF, _______, KC_PGUP, KC_LEFT, KC_DOWN, KC_RIGHT, _______,_______,_______, \
  KC_LSFT,      CtrZ,    CtrX,    CtrC,    CtrV,  _______, KC_PGDN, _______, BL_TOGG,  BL_STEP,  BL_BRTG,  RESET, \
  _______,_______,_______,                _______,                        _______,_______,_______,_______),

  /* Keymap _FL4: Function Layer
   * ,-----------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|  DEL  |
   * |-----------------------------------------------------------|
   * |     |   | UP|CrW|Ref|CrT|   |  7|  8|  9|   |Vdn|Vup|     |
   * |-----------------------------------------------------------|
   * |      |Lef|Dow|Rig|CrF|   |   |  4|  5|  6|   |   |        |
   * |-----------------------------------------------------------|
   * |Shift   |CrZ|CrX|CrC|CrV|   |  0|  1|  2|  3|   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
[_FL4] = LAYOUT_60_ansi(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
  _______, _______, KC_VOLD, KC_VOLU, _______, _______, _______,   KC_7,   KC_8,   KC_9, _______, KC_VOLD, KC_VOLU,  _______, \
  _______,  KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______,   KC_4,   KC_5,   KC_6, _______,_______,_______, \
  _______,   _______, _______, _______, _______, _______,   KC_0,   KC_1,   KC_2,   KC_3, _______,   _______, \
  _______,_______,_______,                _______,                        _______,_______,_______,_______),
  
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}


uint32_t layer_state_set_user(uint32_t state) {
  //uint32_t old_state = 0;
  switch (biton32(state)) {
    case _BL:
	case _FL1:
	  breathing_period_set(5);
      break;
	case _FL2:
      //backlight_toggle();
	  breathing_period_set(3);
	  breathing_enable();
	  backlight_set(3);
	  backlight_level(5);
	  //backlight_step();
	  //backlight_set(3);
	  //PORTB &= ~(1<<2);
      break;
  }
  //old_state = state;
  return state;
}

/* gh60 led control

void matrix_scan_user(void) {

//Layer LED indicators
    uint32_t layer = layer_state;

    if (layer & (1<<1)) {
        gh60_wasd_leds_on();
        gh60_fn_led_on();
    } else {
        gh60_wasd_leds_off();
        gh60_fn_led_off();
    }

    if (layer & (1<<2)) {
        gh60_poker_leds_on();
        gh60_esc_led_on();
    } else {
        gh60_poker_leds_off();
        gh60_esc_led_off();
    }

};

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _L1:
      backlight_set(0);
      break;
    case _FL1:
      backlight_set(3);
      break;
  }
  return state;
}

*/

/* fn custom

enum custom_keycodes {
	Fn_Custom = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch(keycode) {
			case Fn_Custom:
				SEND_STRING("QMK is the best thing ever!");
				return false;
		}
	}
	return true;
};

*/