LTO_ENABLE = yes
DEBOUNCE_TYPE = sym_eager_pk #https://www.reddit.com/r/glorious/comments/qj373e/some_quick_tips_for_qmk_newcomers/
#asym_eager_defer_pk might also be acceptable, https://www.reddit.com/r/MouseReview/comments/rx35bq/mouse_debounce_detailed_explanation/ https://docs.google.com/document/d/1BVQPBEpF3gRLZFOt3E5n6J2cbsEbwO4ZJ6fv2TC6qT0/edit
BOOTMAGIC_ENABLE = no
RING_BUFFERED_6KRO_REPORT_ENABLE = yes
NKRO_ENABLE = yes
RGBLIGHT_ENABLE = no
KEY_LOCK_ENABLE = no
VIA_ENABLE = no
OLED_DRIVER_ENABLE = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MUSIC_ENABLE = no
MAGIC_ENABLE = yes

CONSOLE_ENABLE = no #yes for debugging

CUSTOM_MATRIX = lite
SRC += matrix.c