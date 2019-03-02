/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include "hhkb.h"

#define BASE 0
#define HHKB 1
#define SAM  2

#define TMUX_PREFIX SS_LCTRL("B")

enum custom_keycodes {
    EXAMPLE_MACRO = SAFE_RANGE,
    SILLY_MACRO,
    //GRAVE_ESCAPE,
    TMUX_PREV,
    TMUX_NEXT,
    TMUX_RENAME_TAB,
    TMUX_RENUM_TAB,
    TMUX_NEW_TAB,
    TMUX_SPLIT_PANE,
    TMUX_KILL_PANE,
    TMUX_W1,
    TMUX_W2,
    TMUX_W3,
    TMUX_W4,
    TMUX_W5,
    TMUX_W6,
    TMUX_W7,
    TMUX_W8,
    TMUX_W9,
    TMUX_W0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE Level: Default Layer
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Esc   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     | ` |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Fn1   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Cont  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Shift | Z | X | C | V | B | N | M | , | . | / | Shift | Fn0 |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

            |------+------+-----------------------+------+------|
            | LAlt | LGUI | ******* Space ******* | RGUI | RAlt |
            |------+------+-----------------------+------+------|
    */

    /* CUSTOMIZATIONS:
        - Fn1 added on TAB (hold to engage, tap to send regular TAB)
    */

  [BASE] = LAYOUT(  //  default layer
  KC_ESC,                   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,    KC_6,  KC_7,  KC_8,     KC_9,    KC_0,     KC_MINS,  KC_EQL,    KC_BSLS,  KC_GRV, \
  LT(SAM, KC_TAB),          KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,    KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_LBRC,  KC_RBRC,   KC_BSPC,          \
  MT(MOD_LCTL, KC_ESC),     KC_A,  KC_S,  KC_D,  KC_F,  KC_G,    KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_QUOT,  KC_ENT,                      \
  KC_LSFT,                  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,    KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,  MO(HHKB),                    \
                                        KC_LALT,  KC_LGUI,  /*        */ KC_SPC,      KC_RGUI,  KC_RALT),



    /* Layer HHKB: HHKB mode (HHKB Fn)
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Pwr  | F1  | F2  | F3  | F4 | F5 | F6 | F7 | F8  | F9  | F10 | F11 | F12   | Ins   | Del |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Caps |     |     |     |    |    |    |    | Psc | Slk | Pus | Up  |       | Backs |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | VoD | VoU | Mut |    |    | *  | /  | Hom | PgU | Lef | Rig | Enter |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    | +  | -  | End | PgD | Dow |     | (N/A) |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+

     */

  [HHKB] = LAYOUT(
  KC_PWR,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL, \
  KC_CAPS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PSCR,  KC_SLCK,  KC_PAUS,  KC_UP,    KC_TRNS,  KC_BSPC,          \
  KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_TRNS,  KC_TRNS,  KC_PAST,  KC_PSLS,  KC_HOME,  KC_PGUP,  KC_LEFT,  KC_RGHT,  KC_PENT,                    \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PPLS,  KC_PMNS,  KC_END,   KC_PGDN,  KC_DOWN,  KC_TRNS,  KC_TRNS,                    \
                        KC_TRNS, KC_TRNS,           KC_TRNS,                KC_TRNS, KC_TRNS),



    /* Layer SAM: SAM custom mode (HHKB Tab)
      |------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-------+-------+-----|
      |      |tmux1|tmux2|tmux3|tmux4|tmux5|tmux6|tmux7|tmux8|tmux9|tmux0|     |       |       |NUMLK|
      |------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-------+-------+-----|
      |(N/A) |     |tmuxW|     |tmuxR|tmuxT|     |     |NUM_7|NUM_8|NUM_9|tmuxP|tmuxN  |       |     |
      |------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |tmuxD|     |     |     |     |NUM_4|NUM_5|NUM_6|     |       |       |     |
      |------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |     |     |     |     |NUM_1|NUM_2|NUM_3|     |       |       |     |
      |------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** |NUM_0 |NUM_. |
                 |------+------+----------------------+------+------+

     */

    /* CUSTOMIZATIONS:
        - Numpad added to right-hand side
    */

  [SAM] = LAYOUT(
  KC_TRNS,  TMUX_W1,  TMUX_W2,         TMUX_W3,           TMUX_W4,           TMUX_W5,          TMUX_W6,         TMUX_W7,  TMUX_W8,  TMUX_W9,  TMUX_W0,  KC_TRNS,         KC_TRNS,          KC_TRNS,  KC_NUMLOCK, \
  KC_TRNS,  KC_TRNS,  TMUX_KILL_PANE,  KC_TRNS,           TMUX_RENAME_TAB,   TMUX_NEW_TAB,     KC_TRNS,         KC_TRNS,  KC_P7,    KC_P8,    KC_P9,    TMUX_PREV,       TMUX_NEXT,        KC_TRNS,              \
  KC_TRNS,  KC_TRNS,  KC_TRNS,         TMUX_SPLIT_PANE,   SILLY_MACRO,           KC_TRNS,          KC_TRNS,         KC_TRNS,  KC_P4,    KC_P5,    KC_P6,    KC_TRNS,         KC_TRNS,                                \
  KC_TRNS,  KC_TRNS,  KC_TRNS,         KC_TRNS,           KC_TRNS,           KC_TRNS,          TMUX_RENUM_TAB,  KC_TRNS,  KC_P1,    KC_P2,    KC_P3,    KC_TRNS,         KC_TRNS,                                \
                                    KC_TRNS, KC_TRNS,            KC_TRNS,                KC_P0, KC_PDOT)};

const uint16_t PROGMEM fn_actions[] = {

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case EXAMPLE_MACRO:
                SEND_STRING("Example string");
                return false;
            case SILLY_MACRO:
                SEND_STRING("Hello NAME,");
                SEND_STRING(SS_TAP(X_ENTER));
                SEND_STRING("I just wanted to reach out to you PERSONALLY to let you know I'm giving your problem with PRODUCT my full attention. No one is as important as you, [NAME].");
                SEND_STRING(SS_TAP(X_ENTER));
                SEND_STRING("Thank you,");
                SEND_STRING(SS_TAP(X_ENTER));
                SEND_STRING("Sam");
                return false;
            //case GRAVE_ESCAPE: // Send ` if super or alt are held down, end ESC if otherwise (or if shift is held down)
            //    if ((keyboard_report->mods & (MOD_BIT(KC_LGUI))) || (keyboard_report->mods & (MOD_BIT(KC_LALT)))) {
            //        SEND_STRING("`");
            //    } else {
            //        SEND_STRING(SS_TAP(X_ESCAPE));
            //    }
            //    return false;
            case TMUX_PREV:        // C-b p
                SEND_STRING(TMUX_PREFIX SS_TAP(X_P));
                return false;
            case TMUX_NEXT:        // C-b n
                SEND_STRING(TMUX_PREFIX SS_TAP(X_N));
                return false;
            case TMUX_RENAME_TAB:  // C-b R
                SEND_STRING(TMUX_PREFIX SS_DOWN(X_LSHIFT) SS_TAP(X_R) SS_UP(X_LSHIFT));
                return false;
            case TMUX_RENUM_TAB:  // C-b R
                SEND_STRING(TMUX_PREFIX SS_DOWN(X_LSHIFT) SS_TAP(X_N) SS_UP(X_LSHIFT));
                return false;
            case TMUX_NEW_TAB:     // C-b T
                SEND_STRING(TMUX_PREFIX SS_DOWN(X_LSHIFT) SS_TAP(X_T) SS_UP(X_LSHIFT));
                return false;
            case TMUX_KILL_PANE:   // C-b w
                if (keyboard_report->mods & MOD_BIT(KC_LSHIFT)) { // Check if shift is pressed
                    SEND_STRING(TMUX_PREFIX SS_DOWN(X_LSHIFT) SS_TAP(X_W) SS_UP(X_LSHIFT)); // Prompt to kill window
                } else {
                    SEND_STRING(TMUX_PREFIX SS_TAP(X_W) SS_TAP(X_Y)); // Kill pane with auto 'y'
                }
                return false;
            case TMUX_SPLIT_PANE:  // C-b W
                if (keyboard_report->mods & MOD_BIT(KC_LSHIFT)) { // Check if shift is pressed
                    SEND_STRING(TMUX_PREFIX SS_DOWN(X_LSHIFT) SS_TAP(X_D) SS_UP(X_LSHIFT)); // Split pane horizontally
                } else {
                    SEND_STRING(TMUX_PREFIX SS_TAP(X_D)); // Split pane vertically
                }
                return false;
            case TMUX_W1:          // C-b 1
                SEND_STRING(TMUX_PREFIX SS_TAP(X_1));
                return false;
            case TMUX_W2:          // C-b 2
                SEND_STRING(TMUX_PREFIX SS_TAP(X_2));
                return false;
            case TMUX_W3:          // C-b 3
                SEND_STRING(TMUX_PREFIX SS_TAP(X_3));
                return false;
            case TMUX_W4:          // C-b 4
                SEND_STRING(TMUX_PREFIX SS_TAP(X_4));
                return false;
            case TMUX_W5:          // C-b 5
                SEND_STRING(TMUX_PREFIX SS_TAP(X_5));
                return false;
            case TMUX_W6:          // C-b 6
                SEND_STRING(TMUX_PREFIX SS_TAP(X_6));
                return false;
            case TMUX_W7:          // C-b 7
                SEND_STRING(TMUX_PREFIX SS_TAP(X_7));
                return false;
            case TMUX_W8:          // C-b 8
                SEND_STRING(TMUX_PREFIX SS_TAP(X_8));
                return false;
            case TMUX_W9:          // C-b 9
                SEND_STRING(TMUX_PREFIX SS_TAP(X_9));
                return false;
            case TMUX_W0:          // C-b 0
                SEND_STRING(TMUX_PREFIX SS_TAP(X_0));
                return false;
        }
    }
    return true;
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
