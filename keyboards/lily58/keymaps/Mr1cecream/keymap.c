#include QMK_KEYBOARD_H
#include "features/achordion.h"

enum layer_number {
    _COLDH = 0, // Colemak DH (with home row mods)
    _GAME,      // Colemak DH without home row mods
    _QWERTY,    // QWERTY (without home row mods)
    _FUNC,      // Function layer
    _SYM,       // Symbol layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* NORMAL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =+  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  -_  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '"  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |   _  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt | FUNC | /Space  /       \Enter \  | SYM  |  BS  |LAYOUT|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

// Colemak DH home row mods
#define HOME_A GUI_T(KC_A)
#define HOME_R ALT_T(KC_R)
#define HOME_S CTL_T(KC_S)
#define HOME_T SFT_T(KC_T)
#define HOME_N RSFT_T(KC_N)
#define HOME_E CTL_T(KC_E)
#define HOME_I ALT_T(KC_I)
#define HOME_O GUI_T(KC_O)
// QWERTY home row mods
#define QHOME_S ALT_T(KC_S)
#define QHOME_D CTL_T(KC_D)
#define QHOME_F SFT_T(KC_F)
#define QHOME_J SFT_T(KC_J)
#define QHOME_K CTL_T(KC_K)
#define QHOME_L ALT_T(KC_L)
#define QHOME_SC GUI_T(KC_SCLN)
// switch layout
#define S_COLDH DF(_COLDH)
#define S_QWERTY DF(_QWERTY)
#define S_GAME DF(_GAME)

    // clang-format off
 [_COLDH] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_EQL,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_MINS,
  KC_LCTL,  HOME_A, HOME_R,  HOME_S,  HOME_T,  KC_G,                     KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,   KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, KC_LBRC,   KC_RBRC, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,  KC_UNDS,
                       KC_LGUI , KC_LALT, MO(_FUNC), KC_SPC,    KC_ENT,  MO(_SYM), KC_BSPC, S_QWERTY
),

 [_GAME] = LAYOUT(
  _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______,  _______,
  _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______,  _______,
  _______,  KC_A,    KC_R,    KC_S,    KC_T,    _______,                     _______, KC_N,    KC_E,    KC_I,    KC_O,     _______,
  _______,  _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,  _______,
                          _______ , _______, _______, _______,         _______, _______, _______, S_COLDH
),

 [_QWERTY] = LAYOUT(
  _______,  _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______,  _______,
  _______,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     _______,
  _______,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  _______,
  _______,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______,   _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  _______,
                          _______ , _______, _______, _______,   _______, _______, _______, S_COLDH
),
  // _______,  HOME_A,  QHOME_S, QHOME_D, QHOME_F, KC_G,                     KC_H,    QHOME_J, QHOME_K, QHOME_L, QHOME_SC, _______,

/* SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  '   |  <   |  >   |  "   |  .   |                    |  &   |  _   |  [   |  ]   |  %   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  !   |  -   |  +   |  =   |  #   |-------.    ,-------|  |   |  :   |  (   |  )   |  ?   |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |  ^   |  /   |  *   |  \   |  `   |-------|    |-------|  ~   |  $   |  {   |  }   |  @   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |      | /Space  /       \Enter \  |      |  BS  |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_SYM] = LAYOUT(
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,
  _______,  KC_QUOT, KC_LABK, KC_RABK, KC_DQUO, KC_DOT,                   KC_AMPR, KC_UNDS, KC_LBRC, KC_RBRC, KC_PERC,  _______,
  _______,  KC_EXLM, KC_MINS, KC_PLUS, KC_EQL,  KC_HASH,                  KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES,  _______,
  _______,  KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_GRV, _______, _______, KC_TILD, KC_DLR,  KC_LCBR, KC_RCBR, KC_AT,    _______,
                            _______ , _______, _______, _______, _______, _______, _______, _______
),

/* FUNCTION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |COLDH |VOL D |VOL_M |VOL_U |      |                    |      | HOME | PGDN | PGUP | END  |NK TGL|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL | CAPS |M PRV | M PP |M NXT |      |-------.    ,-------|      | LEFT | DOWN |  UP  |RIGHT |  \|  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|QWERTY|B BACK|      |B FWD |      |-------|    |-------|      |      |      |      |      | GAME |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |      | /Space  /       \Enter \  |      |  DEL |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_FUNC] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  XXXXXXX, S_COLDH, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX,                   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  NK_TOGG,
  _______, CW_TOGG, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS,
  _______, S_QWERTY,KC_WBAK, XXXXXXX, KC_WFWD, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S_GAME,
                             _______, _______, _______, _______, _______, _______ , KC_DEL, _______
)};
// clang-format on

/* layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _FUNC, _RAISE, _ADJUST);
} */

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        oled_write_ln(read_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
        // oled_write_ln(read_timelog(), false);
    } else {
        oled_write(read_logo(), false);
    }
    return false;
}
#endif // OLED_ENABLE

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // only shift alphas
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        // continue caps word
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
            return true;

        default:
            return false;
    }
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    switch (tap_hold_keycode) {
        case HOME_S:
            if (other_keycode == KC_C || other_keycode == KC_Z) {
                return true;
            }
        case HOME_T:
            if (other_keycode == KC_V) {
                return true;
            }
            break;
    }

    if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4) {
        return true;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

/* static bool oneshot_mod_tap(uint16_t keycode, keyrecord_t *record) {
    if (record->tap.count == 0) {
        if (record->event.pressed) {
            const uint8_t mods = (keycode >> 8) & 0x1f;
            add_oneshot_mods(((mods & 0x10) == 0) ? mods : (mods << 4));
        }
        return false;
    }
    return true;
} */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }

    /* switch (keycode) {
        case HOME_T:
        case HOME_N:
            return oneshot_mod_tap(keycode, record);
    } */

    if (record->event.pressed) {
#ifdef OLED_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }

    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}

bool achordion_eager_mod(uint8_t mod) {
    switch (mod) {
        case MOD_LSFT:
        case MOD_RSFT:
        case MOD_LCTL:
        case MOD_RCTL:
        case MOD_LALT:
        case MOD_RALT:
            return true;
        default:
            return false;
    }
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    return 800;
}
