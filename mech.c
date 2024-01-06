#include <ncurses.h>//LINES/COLS
#include "spheres.h"

void movement(char c,vect3* pos){
if((c==K_LEFT || c==K_UP_LEFT || c==K_DOWN_LEFT) && (*pos).x>0) (*pos).x--;
else if((c==K_RIGHT||c==K_UP_RIGHT||c==K_DOWN_RIGHT)&&(*pos).x<WIDTH-COLS/2)(*pos).x++;
if((c==K_UP || c==K_UP_LEFT || c==K_UP_RIGHT) && (*pos).y>0) (*pos).y--;
else if((c==K_DOWN||c==K_DOWN_LEFT||c==K_DOWN_RIGHT)&&(*pos).y<HEIGHT-LINES)(*pos).y++;
else if(c==K_FORWARD && (*pos).z<DEPTH-1) (*pos).z++;
else if(c==K_BACKWARD && (*pos).z>0) (*pos).z--;
return;}
