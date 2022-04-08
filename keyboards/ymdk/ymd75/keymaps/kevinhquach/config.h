#pragma once

#undef DYNAMIC_KEYMAP_LAYER_COUNT

#undef BACKLIGHT_LEVELS
#define BACKLIGHT_LEVELS 2

#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 11
#define MATRIX_IO_DELAY 10 //to use with custom matrix implementation, might need to increase (max 30)

//23 slightly too low
//30 works

//matrix + debounce
//27 + 25 good
//27 + 15 good
//27 + 13 bad!!
//27 + 14 good? maybe rare enough to not happen
//15 + 14 good
    //not really too annoyed with 14 debounce, I wasn't able to hit 14ms holds on old keyboard anyway...
//wtf 10 + 14 works
    //~1650 when typing, ~1500 idle (good enough for me)

#define FORCE_NKRO

#ifdef DEBOUNCE
    #undef DEBOUNCE
    #define DEBOUNCE 14 //with eager, this doesn't matter unless I can double tap a key in DEBOUNCE ms or if I need to hold for less than DEBOUNCE ms
#else
    #define DEBOUNCE 14
#endif
//7 too low?
//9 too low

#ifdef LED_PIN_ON_STATE
    #undef LED_PIN_ON_STATE
    #define LED_PIN_ON_STATE 1 //want led on when caps is off
#else
    #define LED_PIN_ON_STATE 1 //want led on when caps is off
#endif

#define NO_ACTION_MACRO //double check these here https://github.com/qmk/qmk_firmware/blob/master/quantum/quantum.c
#define NO_ACTION_FUNCTION //double check more here https://github.com/qmk/qmk_firmware/blob/master/quantum/action.h
//#define NO_ACTION_TAPPING //double check more here https://github.com/qmk/qmk_firmware/blob/master/quantum/quantum.h
    //DOING ABOVE MESSES WITH LAYERS
#define NO_ACTION_ONESHOT //double check more here https://github.com/qmk/qmk_firmware/blob/master/docs/config_options.md
#define NO_MUSIC_MODE

//for no debug
#ifndef NO_DEBUG
#define NO_DEBUG
#undef CONSOLE_ENABLE
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

//for debugging
/*#define DEBUG_MATRIX_SCAN_RATE //USE FOR CHECKING OUT THE SCAN RATE, REMOVE FOR ACTUAL USE, use qmk toolbox to check
#ifdef NO_DEBUG
    #undef NO_DEBUG
#endif
#ifdef NO_PRINT
    #undef NO_PRINT
#endif
#ifndef CONSOLE_ENABLE
    #define CONSOLE_ENABLE
#endif*/

#ifdef RGB_DI_PIN //not totally sure about this one
    #undef RGB_DI_PIN
#endif
#ifdef RGBLIGHT_ANIMATIONS
    #undef RGBLIGHT_ANIMATIONS
#endif
#ifdef RGBLED_NUM
    #undef RGBLED_NUM
#endif
#ifdef RGBLIGHT_HUE_STEP
    #undef RGBLIGHT_HUE_STEP
#endif
#ifdef RGBLIGHT_SAT_STEP
    #undef RGBLIGHT_SAT_STEP
#endif
#ifdef RGBLIGHT_VAL_STEP
    #undef RGBLIGHT_VAL_STEP
#endif
#ifdef RGBLIGHT_SLEEP
    #undef RGBLIGHT_SLEEP
#endif

#ifdef LOCKING_SUPPORT_ENABLE
    #undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
    #undef LOCKING_RESYNC_ENABLE
#endif

#ifdef MAX_LAYER
    #undef MAX_LAYER
    #define MAX_LAYER 2
#else
    #define MAX_LAYER 2
#endif
#define LAYER_STATE_8BIT

#undef RGBLIGHT_ANIMATIONS
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_TWINKLE
#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_BREATHING
#undef ENABLE_RGB_MATRIX_BAND_SAT
#undef ENABLE_RGB_MATRIX_BAND_VAL
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#undef ENABLE_RGB_MATRIX_CYCLE_ALL
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#undef ENABLE_RGB_MATRIX_RAINDROPS
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#undef ENABLE_RGB_MATRIX_HUE_BREATHING
#undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#undef ENABLE_RGB_MATRIX_HUE_WAVE
#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN
#undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_MULTISPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH