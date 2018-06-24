#include "natohara.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define BASE 0
#define RAISE 1
#define LOWER 2

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 *        ,----------------------------------.                 ,----------------------------------.
 *        | Esc  |   W  |   E  |   R  |   T  |                 |   Y  |   U  |   I  |   O  | BKSP |
 * .------+------+------+------+------+------.                 -------+------+------+------+------+------.
 * | Tab  |   Q  |   S  |   D  |   F  |   G  |                 |   H  |   J  |   K  |   L  |   P  |  \   |
 * |------+------+------+------+------+------.                 |------+------+------+------+------+------|
 * | Ctrl |   A  |   X  |   C  |   V  |   B  |                 |   N  |   M  |   ,  |   .  |   ;  |  '   |
 * |------+------+------+------+------+------+------.   .------+------+------+------+------+------+------|
 * | Sft  |   Z  | LOWER| LOWER| Alt  |Space |  [   |   |   ]  | RAISE| GUI  | HOME | END  |   /  | Enter|
 * `------------------------------------------------'   `------------------------------------------------'
 */

    [BASE] = KEYMAP(
        XXXXXXX,  KC_ESC, KC_W,       KC_E,       KC_R,    KC_T,                     KC_Y,      KC_U,    KC_I,    KC_O,    KC_BSPC, XXXXXXX, \
        KC_TAB,   KC_Q,   KC_S,       KC_D,       KC_F,    KC_G,                     KC_H,      KC_J,    KC_K,    KC_L,    KC_P,    KC_BSLASH, \
        KC_LCTRL, KC_A,   KC_X,       KC_C,       KC_V,    KC_B,                     KC_N,      KC_M,    KC_COMM, KC_DOT,  KC_SCLN, KC_QUOT, \
        KC_LSFT,  KC_Z,   MO(LOWER),  MO(LOWER),  KC_LALT, KC_SPC, KC_LBRC, KC_RBRC, MO(RAISE), KC_LGUI, KC_HOME, KC_END,  KC_SLSH, KC_ENT \
),

/* RAISE
 *        ,----------------------------------.                 ,-----------------------------------.
 *        |   `  |   2  |   3  |   4  |   5  |                 |   6  |   7  |   8  |   9  |  DEL  |
 * .------+------+------+------+------+------.                 -------+------+------+------+------+------.
 * | Tab  |   1  |   ←  |   ↑  |   ↓  |   →  |                 |   ←  |   ↓  |   ↑  |   →  |   0  |      |
 * |------+------+------+------+------+------.                 |------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |                 |      |      |      |      |   -  |  =   |
 * |------+------+------+------+------+------+------.   .------+------+------+------+------+------+------|
 * | Sft  |      | LOWER| LOWER| Alt  |Space |RClick|   |   ]  | RAISE| GUI  | HOME | END  |   /  | Click|
 * `------------------------------------------------'   `------------------------------------------------'
 */

    [RAISE] = KEYMAP(
        XXXXXXX, KC_GRV,     KC_2,       KC_3,       KC_4,        KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,     KC_DEL,   XXXXXXX, \
        _______, KC_1,       KC_MS_LEFT, KC_MS_UP,   KC_MS_RIGHT, _______,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_0,     _______, \
        _______, _______,    LCTL(KC_X), KC_MS_DOWN, _______,     _______,                          _______, _______, _______, _______,  KC_MINUS, KC_EQUAL, \
        _______, LCTL(KC_Z), _______,    _______,    _______,     _______,     KC_MS_BTN2, _______, _______, _______, _______, _______,  _______,  KC_MS_BTN1 \
),

/* LOWER
 *        ,----------------------------------.                 ,-----------------------------------.
 *        |   `  |  F2  |  F3  |  F4  |  F5  |                 |  F6  |  F7  |  F8  |  F9  |  DEL  |
 * .------+------+------+------+------+------.                 -------+------+------+------+------+------.
 * | Tab  |  F1  | F11  | F12  |      |      |                 |      |      |      |      |      |      |
 * |------+------+------+------+------+------.                 |------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |                 |      |      |      |      |   -  |  =   |
 * |------+------+------+------+------+------+------.   .------+------+------+------+------+------+------|
 * | Sft  |      | LOWER| LOWER| Alt  |Space |   [  |   |   ]  | RAISE| GUI  | HOME | END  |   /  | Click|
 * `------------------------------------------------'   `------------------------------------------------'
 */

    [LOWER] = KEYMAP(
        XXXXXXX, KC_GRV,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_DEL,  XXXXXXX, \
        _______, KC_F1,   KC_F11,  KC_F12,  _______, _______,                   _______, _______, _______, _______, KC_F10,  _______, \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)};
