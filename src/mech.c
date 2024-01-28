#include <ncurses.h>//LINES/COLS
#include "spheres.h"

void movement(char c,vect3* pos){
if	((c==K_LEFT || c==K_UP_LEFT || c==K_DOWN_LEFT)
	&& (*pos).x>0)
	(*pos).x--;
else if	((c==K_RIGHT||c==K_UP_RIGHT||c==K_DOWN_RIGHT)
	&& (*pos).x<WIDTH)
	(*pos).x++;
if	((c==K_UP || c==K_UP_LEFT || c==K_UP_RIGHT)
	&& (*pos).y>0)
	(*pos).y--;
else if	((c==K_DOWN||c==K_DOWN_LEFT||c==K_DOWN_RIGHT)
	&& (*pos).y<HEIGHT)
	(*pos).y++;
else if(c==K_FORWARD
	&& (*pos).z<DEPTH)
	(*pos).z++;
else if(c==K_BACKWARD
	&& (*pos).z>0)
	(*pos).z--;
return;}

void turn(char c,int *facing){
switch(c){
case K_FACE_FRONT:	*facing =FRONT;		break;
case K_FACE_BACK:	*facing =BACK;		break;
case K_FACE_LEFT:	*facing =LEFT;		break;
case K_FACE_RIGHT:	*facing =RIGHT;		break;
default:	break;}
return;}
