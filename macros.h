enum {
    TD_C_X,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_C_X] = ACTION_TAP_DANCE_DOUBLE(C(KC_C), C(KC_X)),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    case KC_ENTER:
        if (get_mods() == MOD_BIT(KC_LSFT)) {
            if (record->event.pressed) {
                tap_code16(C(KC_ENTER));
            } else {
               // clear_keyboard_but_mods();
            }
            return false;
        }
        return true;

    case KC_BSPC:
        if (get_mods() == MOD_BIT(KC_LSFT)) {
            if (record->event.pressed) {
                tap_code16(C(KC_BSPC));
            } else {
               // clear_keyboard_but_mods();
            }
            return false;
        }
        return true;

    case KC_UP:
        if (get_mods() == MOD_BIT(KC_LALT)) {
            if (record->event.pressed) {
                tap_code(KC_PGUP);
            } else {
               // clear_keyboard_but_mods();
            }
            return false;
        }
        return true;

    case KC_DOWN:
        if (get_mods() == MOD_BIT(KC_LALT)) {
            if (record->event.pressed) {
                tap_code16(KC_PGDN);
            } else {
               // clear_keyboard_but_mods();
            }
            return false;
        }
        return true;

    case LT(0,TD_C_X): //COPYPASTE
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_V)); 
                return false;
            }
            return true;

    case LT(0,G(S(KC_S))): //TEXTSHOT
            if (!record->tap.count && record->event.pressed) {
                tap_code16(S(KC_T)); 
                return false;
            }
            return true;

    case LT(0,C(KC_A)): //PRINTALL
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_P)); 
                return false;
            }
            return true;

    case LT(0,C(DE_Z)): //UNDOREDO
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(DE_Y)); 
                return false;
            }
            return true;

    case LT(0,KC_TAB): //TABMENU
            if (!record->tap.count && record->event.pressed) {
                tap_code(KC_APP); 
                return false;
            }
            return true;

    case LT(0,KC_COMM): //COMMDOT
            if (!record->tap.count && record->event.pressed) {
                tap_code(KC_DOT); 
                return false;
            }
            return true;

    }
    return true;
};