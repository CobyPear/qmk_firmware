enum layer_names {
    _QWERTY,
    _NUM,
    _SYMB,
    _KEYB,
};

#ifdef OLED_ENABLE

void render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("qwerty\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("num\n"), false);
            break;
        case _SYMB:
            oled_write_P(PSTR("symbol\n"), false);
            break;
        case _KEYB:
            oled_write_P(PSTR("RGB/media\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     if (!is_keyboard_master()) {
//         return OLED_ROTATION_180; // flips the display 180 degrees if offhand
//     }

//     return rotation;
// }

bool oled_task_user(void) {
    if (!is_keyboard_master()) {
        render_status();
    } else {
        render_status();
    }

    return false;
}
#endif
