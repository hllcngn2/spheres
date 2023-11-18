#include <ncurses.h>//LINES/COLS
#include "spheres.h"

void movement(char c,int* x,int* y,int*z){
if((c==K_LEFT || c==K_UP_LEFT || c==K_DOWN_LEFT) && *x>0) (*x)--;
else if((c==K_RIGHT||c==K_UP_RIGHT||c==K_DOWN_RIGHT)&&*x<WIDTH-COLS/2)(*x)++;
if((c==K_UP || c==K_UP_LEFT || c==K_UP_RIGHT) && *y>0) (*y)--;
else if((c==K_DOWN||c==K_DOWN_LEFT||c==K_DOWN_RIGHT)&&*y<HEIGHT-LINES)(*y)++;
else if(c==K_FORWARD && *z<DEPTH-1) (*z)++;
else if(c==K_BACKWARD && *z>0) (*z)--;
return;}
