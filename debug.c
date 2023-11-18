#include <ncurses.h>

void drawdebug(int x,int y,int z){
WINDOW *win =newwin(3,16,1,COLS-16-2);
box(win,0,0);
mvwprintw(win,1,2,"x=%i;y=%i;z=%i",x,y,z);
wrefresh(win);
delwin(win);	return;}
