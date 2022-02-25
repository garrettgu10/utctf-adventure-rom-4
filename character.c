#include "character.h"
#include <gb/gb.h>

static INT16 y_v = 0;
static INT16 x_v = 0;
#define MAX_Y_VEL 1000
#define MAX_X_VEL 500
#define MIN_X_VEL 200
#define X_DECEL 10
#define GRAVITY 10
#define FLOOR_Y 136
static UINT16 x = 75 * 256;
static UINT16 y = 75 * 256;

void init_character() {
    SPRITES_8x8;
    set_sprite_tile(0, 0);
    move_sprite(0, x, y);

    SHOW_SPRITES;
}

UINT8 ready_for_jump;
void tick_character() {
    if(y_v < MAX_Y_VEL) {
        y_v += GRAVITY;
    }

    if(x_v > 0) {
        x_v -= X_DECEL;
    }else if(x_v < 0) {
        x_v += X_DECEL;
    }

    y += y_v;
    x += x_v;

    if(x > (160 << 8)) {
        x = 8 << 8;
    }

    if(x < (8 << 8)) {
        x = 160 << 8;
    }

    if(y > FLOOR_Y << 8) {
        y = FLOOR_Y << 8;
        ready_for_jump = 1;
    }

    move_sprite(0, x >> 8, y >> 8);
}

UINT8 input;
void handle_input() {
    input = joypad();
    
    if(input & J_A) {
        //jump
        if(ready_for_jump){
            y_v = -500;
            ready_for_jump = 0;
        }
    }

    if(input & J_LEFT) {
        if(x_v > -MIN_X_VEL) {
            x_v = -MIN_X_VEL;
        }
        x_v -= 20;
        if(x_v < -MAX_X_VEL){
            x_v = -MAX_X_VEL;
        }
    }
    
    if(input & J_RIGHT) {
        if(x_v < MIN_X_VEL) {
            x_v = MIN_X_VEL;
        }
        x_v += 20;
        if(x_v > MAX_X_VEL) {
            x_v = MAX_X_VEL;
        }
    }
}