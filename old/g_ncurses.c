#include <ncurses.h>
#include "g_hdr.h"
#include <math.h>
#include <stdlib.h>//malloc

void	*g_init(){
initscr(); noecho(); cbreak();
//nodelay(stdscr, true);
curs_set(0); start_color();
refresh();

init_pair(10, 9, 15);
return NULL;}

void	g_end(void *env){
endwin();
return;}

char	g_getch(void *env){
return getch();}

void	g_hello(void *env){
printw("hello");
return;}

void	g_circle(void *env){
int	n = 100;
vect	*pts = (vect*)malloc(sizeof(vect)*n);
int	half_minor_axis, half_major_axis;
float	t = 0;

half_minor_axis = 7;
half_major_axis = 14;

for (int i=0;i<n;i++){
	t+=2*M_PI/n;
	pts[i].y = half_minor_axis*sin(t) +10;
	pts[i].x = half_major_axis*cos(t) +20;
}
for (int i=0;i<n;i++){
	mvaddch(pts[i].y, pts[i].x, '.');
}
refresh();
free(pts);
return;}

void	g_point(void *env){
attron(COLOR_PAIR(10));
mvaddch(2, 2, '+');
attroff(COLOR_PAIR(10));
return;}

void	g_ellipse(void *env){
int	n = 100;
vect	*pts = (vect*)malloc(sizeof(vect)*n);
int	half_minor_axis, half_major_axis;
float	t = 0;

half_minor_axis = 7;
half_major_axis = 40;

for (int i=0;i<n;i++){
	t+=2*M_PI/n;
	pts[i].y = half_minor_axis*sin(t) +7;
	pts[i].x = half_major_axis*cos(t) +40;
}
for (int i=0;i<n;i++){
	mvaddch(pts[i].y, pts[i].x, '.');
}
refresh();
free(pts);
return;}

void	g_square_ellipse(void *env){
return;}





void	*g_window(int y, int x, int height, int width, char *title){
WINDOW	*win = newwin(height, width, y, x);
box(win, 0, 0);
mvwprintw(win, 1, 1, title);
wmove(win, 3, 2);
for (int i=1; i<width-2; i++){
wprintw(win, "─");}
wrefresh(win);
return win;}
