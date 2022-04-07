/*
Copyright 2019 Alex Ong
Modified 2022 Kevin Quach <kquach1337@gmail.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
//taken from https://github.com/qmk/qmk_firmware/blob/master/keyboards/handwired/xealousbrown/matrix.c
#include <stdint.h>
#include <stdbool.h>
#include "wait.h"
#include "util.h"
#include "matrix.h"
#include "debounce.h"
#include "quantum.h"

/* matrix state(1:on, 0:off) */
extern matrix_row_t raw_matrix[MATRIX_ROWS];  // raw values
extern matrix_row_t matrix[MATRIX_ROWS];      // debounced values

// matrix code
// super fast read_cols code.
static inline matrix_row_t read_cols(void) {
    return (PINB & (1 << 7) ? 0 : (1UL << 0)) |
           (PINB & (1 << 3) ? 0 : (1UL << 1)) |
           (PINB & (1 << 2) ? 0 : (1UL << 2)) |
           (PINB & (1 << 1) ? 0 : (1UL << 3)) |
           (PINB & (1 << 0) ? 0 : (1UL << 4)) |
           (PINE & (1 << 6) ? 0 : (1UL << 5)) |
           (PINF & (1 << 0) ? 0 : (1UL << 6)) |
           (PINF & (1 << 1) ? 0 : (1UL << 7)) |
           (PINF & (1 << 4) ? 0 : (1UL << 8)) |
           (PINF & (1 << 5) ? 0 : (1UL << 9)) |
           (PINF & (1 << 6) ? 0 : (1UL << 10)) |
           (PINF & (1 << 7) ? 0 : (1UL << 11));

}

static void unselect_rows(void) {
    DDRD &= ~0b11111111;
    PORTD &= ~0b11111111;
    DDRB &= ~0b00010000;
    PORTB &= ~0b00010000;
}

static void select_row(uint8_t row) {
    switch (row) {
        case 0:
            DDRD |= (1 << 0);
            PORTD &= ~(1 << 0);
            break;
        case 1:
            DDRD |= (1 << 1);
            PORTD &= ~(1 << 1);
            break;
        case 2:
            DDRD |= (1 << 2);
            PORTD &= ~(1 << 2);
            break;
        case 3:
            DDRD |= (1 << 3);
            PORTD &= ~(1 << 3);
            break;
        case 4:
            DDRD |= (1 << 5);
            PORTD &= ~(1 << 5);
            break;
        case 5:
            DDRD |= (1 << 4);
            PORTD &= ~(1 << 4);
            break;
        case 6:
            DDRD |= (1 << 6);
            PORTD &= ~(1 << 6);
            break;
        case 7:
            DDRD |= (1 << 7);
            PORTD &= ~(1 << 7);
            break;
        case 8:
            DDRB |= (1 << 4);
            PORTB &= ~(1 << 4);
            break;
    }
}

static void init_pins(void) {
    DDRB &= ~(1 << 7 | 1 << 4 | 1 << 3 | 1 << 2 | 1 << 1 | 1 << 0);
    PORTB |= (1 << 7 | 1 << 4 | 1 << 3 | 1 << 2 | 1 << 1 | 1 << 0);
    DDRD &= ~(1 << 7 | 1 << 6 | 1 << 5 | 1 << 4 | 1 << 3 | 1 << 2 | 1 << 1 | 1 << 0);
    PORTD |= (1 << 7 | 1 << 6 | 1 << 5 | 1 << 4 | 1 << 3 | 1 << 2 | 1 << 1 | 1 << 0);
    DDRE &= ~(1 << 6);
    PORTE |= (1 << 6);
    DDRF &= ~(1 << 7 | 1 << 6 | 1 << 5 | 1 << 4 | 1 << 1 | 1 << 0);
    PORTF |= (1 << 7 | 1 << 6 | 1 << 5 | 1 << 4 | 1 << 1 | 1 << 0);
}

// Only need to init the pins. Debounce / raw matrix are initialized already for us.
void matrix_init_custom(void) {
    // initialize key pins
    init_pins();
}

// Only need to scan the result into current_matrix, and return changed.
uint8_t matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;

    // Set row, read cols
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        select_row(current_row);
        matrix_output_unselect_delay(current_row, changed);
        matrix_row_t cols = read_cols();
        changed |= (current_matrix[current_row] != cols);
        current_matrix[current_row] = cols;

        unselect_rows();
        //this internally calls matrix_io_delay()
        matrix_output_unselect_delay(current_row, changed);
    }

    return changed;
}