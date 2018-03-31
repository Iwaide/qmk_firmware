#include "ergo42.h"
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
                  KC_ESC, KC_W,       KC_E,       KC_R,    KC_T,            KC_Y,    KC_U,       KC_I,    KC_O,    KC_BSPC,
        KC_TAB,   KC_Q,   KC_S,       KC_D,       KC_F,    KC_G,            KC_H,    KC_J,       KC_K,    KC_L,    KC_P,    KC_BSLASH,
        KC_LCTRL, KC_A,   KC_X,       KC_C,       KC_V,    KC_B,            KC_N,    KC_M,       KC_COMM, KC_DOT,  KC_SCLN, KC_QUOT,
        KC_LSFT,  KC_Z,   MO(_LOWER), MO(_LOWER), KC_LALT, KC_SPC, KC_LBRC, KC_RBRC, MO(_RAISE), KC_LGUI, KC_HOME, KC_END,  KC_SLSH, KC_ENT\
),

    /* META
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |   6  |  [   |   |  ]   |   7  |   8  |   9  |   0  |   -  |  ^   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | Alt  |  F1  |      |Muhen | Henk |      |  (   |   |  )   | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |  F2  |  F3  |  F4  |  F5  |  F6  |  {   |   |  }   |  F7  |  F8  |  F9  | F10  | F11  |\/Sft |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  App |PrtSc |ESC/  |Space/|Tab/  |   |Back  |Enter/| Del  |Reset |=>GAME|=>SYMB|  \   |
 * |      |      |      |      |~SYMB |RCtrl |Shift |   |Space |~META |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

    [RAISE] = KEYMAP(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, _______, _______, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,
        _______, KC_F1, XXXXXXX, KC_MHEN, KC_HENK, XXXXXXX, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
        _______, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, _______, _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, SFT_T(KC_RO),
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, _______, _______, _______\
),

    /* SYMB
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |   !  |   "  |   #  |   $  |   %  |   &  |  [   |   |  ]   |   '  |   (  |   )  |   ~  |   =  |  ~   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | Alt  |      |      |      |      |      |  (   |   |  )   |      |      |      |      |   +  |  *   |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |      |      |      |      |      |  {   |   |  }   |      |      |   <  |   >  |   ?  |  \   |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  App |PrtSc |ESC/  |Space/|Tab/  |   |Back  |Enter/| Del  |PrtSc |=>GAME|=>SYMB|  \   |
 * |      |      |      |      |~SYMB |RCtrl |Shift |   |Space |~META |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

    [LOWER] = KEYMAP(
        S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), _______, _______, S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_MINS), S(KC_EQL),
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_SCLN), S(KC_QUOT),
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, S(KC_COMM), S(KC_DOT), S(KC_SLSH), S(KC_RO),
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
)};
