#include <gb/gb.h>
#include <stdio.h>
#include "tile_data.h"

void update_switches() {
   HIDE_WIN;
   SHOW_SPRITES;
   SHOW_BKG;
}

void init() {
   DISPLAY_ON;
   set_bkg_data(0, 17, tile_data);
   set_bkg_data(17, 40, font_data);
   set_sprite_data(0, 15, tile_data+16);
}

UINT8 input;
void handle_input() {
   input = joypad();
   
}

UINT8 rand_counter;
void main() {
   printf(" \n UTCTF ROM\n BY GG\n\n");
   printf("PRESS START TO BEGIN\n");
   
   while(!(joypad() & J_START)){
      rand_counter++;
   }

   init();

   while(1) {
      rand_counter++;
      handle_input();
      wait_vbl_done();
   }
}
