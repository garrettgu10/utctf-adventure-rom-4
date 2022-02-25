#include <gb/gb.h>
#include <stdio.h>
#include <rand.h>
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

UINT16 rand_counter;
void main() {
   printf(" \n UTCTF ROM 4\n BY GG\n\n");
   printf(" NOW WITH MUSIC\n\n");
   printf("PRESS START TO BEGIN\n");
   
   while(!(joypad() & J_START)){
      rand_counter++;
   }

   initrand(rand_counter);

   init();

   while(1) {
      rand_counter++;
      handle_input();
      tick_sound();
      wait_vbl_done();
   }
}
