#include <ncurses.h>
#include "spheres.h"

void drawdebug(vect3 pos){
WINDOW *win =newwin(3,20,1,COLS-20-2);
box(win,0,0);
mvwprintw(win,1,2,"x=%i;y=%i;z=%i",pos.x,pos.y,pos.z);
wrefresh(win);
delwin(win);	return;}
