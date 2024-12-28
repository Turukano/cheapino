enum layer_names {
    DEF,
    NAV,
    SYM,
    BLANK
};

#include QMK_KEYBOARD_H
#include "definitions.h"
#include "macros.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Layer 0: Base Layer
    [DEF] = LAYOUT_split_3x5_3(
     KC_NO,   KC_D,    KC_U,    KC_A,    KC_X,                                        KC_P,    KC_H,    KC_L,                 KC_M,  KC_W,  
     KC_C,    KC_T,    KC_I,    KC_E,    KC_O,                                        KC_B,    KC_N,    KC_R,                 KC_S,    KC_G,   
     KC_F,    KC_V,    DE_UDIA, DE_ADIA, DE_ODIA,                                     DE_Y,    DE_Z,    LSFT_T(DE_QUOT), LT(0,KC_COMM),  KC_K,      
                                OSL(SYM), KC_LSFT, KC_J,                     KC_BSPC, KC_SPC, MO(NAV)          
),

    // Navi sollte links sein, damit ich mit der rechten Hand die Maus bewegen kann. Vielleicht sollte ich NAV nochmal komplett neu machen. Allerdings: Wie aktiviert man Nav? Eventuell als Base Layer???
    [NAV] = LAYOUT_split_3x5_3(
     KC_NO,      KC_7,    KC_8,    KC_9,    KC_NO,                                        LT(0,C(KC_A)),  C(KC_LEFT), KC_UP,     C(KC_RIGHT),  KC_NO,     
LT(0,G(S(KC_S))),KC_4, KC_5,    KC_6,    KC_NO,                                        LT(0,TD_C_X),  KC_LEFT,    KC_DOWN,   KC_RIGHT,        LT(0,KC_TAB),   
     KC_NO,   KC_1,    KC_2,    KC_3,    KC_NO,                                        KC_NO,       LT(0,C(DE_Z)),  KC_NO,    LT(0,KC_COMM),   KC_NO,   //Punkt noch als Tapdance oder woandershin
                                          OSL(SYM), KC_LSFT, KC_0,       KC_BSPC, KC_LALT, KC_NO        
),

    // Layer 2: Symbols and Navigation
    [SYM] = LAYOUT_split_3x5_3(
        KC_TILD, KC_EXLM, KC_AMPR, KC_HASH, KC_MINS,     KC_LBRC, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN,
        KC_GRV,  KC_DLR, KC_COMM, KC_DOT, KC_COLN,       KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PERC,
        KC_PLUS, KC_PIPE, KC_SLSH, KC_CIRC, KC_UNDS,     KC_RBRC, KC_EQL, KC_BSLS, KC_AT, KC_ASTR,
                                KC_LSFT, KC_ENTER,       KC_SCLN, KC_TRNS, KC_ENT, KC_NO
    ),

    // Layer 3: Function Keys and Numpad
    [BLANK] = LAYOUT_split_3x5_3(
        KC_PAST, KC_1, KC_2, KC_3, KC_0,                 KC_WH_U, KC_F1, KC_F2, KC_F3, KC_F11,
        KC_PSLS, KC_4, KC_5, KC_6, KC_PPLS,              KC_F10, KC_F4, KC_F5, KC_F6, KC_END,
        KC_MINS, KC_7, KC_8, KC_9, KC_EQL,               KC_WH_D, KC_F7, KC_F8, KC_F9, KC_F12,
                                KC_LGUI, KC_SPC,         KC_F13, KC_TRNS, KC_ENT, KC_TRNS
    ),
};

// Encoder Map
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif