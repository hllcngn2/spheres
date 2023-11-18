#include "g_libx.h"

#include <math.h>
#include <time.h>//time time_t
#include <stdlib.h>//rand

void	*g_init(){
g_env	*env = (g_env*)malloc(sizeof(g_env));
env->disp = XOpenDisplay(NULL);
env->font = XLoadQueryFont(_disp, "9x15");
env->gc = XCreateGC(_disp, RootWindow(_disp, 0), 0, NULL);
XSetFont(_disp, _gc, env->font->fid);
XSetForeground(_disp, _gc, 0x77733333);
env->winid = XCreateSimpleWindow(_disp, RootWindow(_disp, 0),
		0, 0, 1000, 1000, 30, 0xff333333, 0xff333333);
XSelectInput(_disp, _winid, KeyPressMask | ExposureMask);
XMapWindow(_disp, _winid);

time_t	t;
time(&t);
srand(t);
return (void*)env;}

void	g_end(void *env){
XCloseDisplay(_disp);
free(env);
return;}

char	g_getch(void *env){
XEvent		xe;
while(1){ XNextEvent(_disp, &xe);
	if (xe.type == KeyPress) return 0;}
return 0;}

void	g_hello(void *env){
XDrawString(_disp, _winid, _gc, 33, 33, "hello", 5);
return;}

void	g_circle(void *env){
XDrawArc(_disp, _winid, _gc, 100, 33, 200, 200, 360*64, 360*64);
return;}

void	g_point(void *env){
XDrawPoint(_disp, _winid, _gc, 400, 400);
return;}

void	g_ellipse(void *env){
int	n = 10000;
XPoint	*pts = (XPoint*)malloc(sizeof(XPoint)*n);
int	half_minor_axis, half_major_axis;
float	t = 0;

half_minor_axis = 100;
half_major_axis = 200;

for (int i=0;i<n;i++){
	t+=2*M_PI/n;
	pts[i].x = half_major_axis*cos(t) +400;
	pts[i].y = half_minor_axis*sin(t) +400;
}

XDrawPoints(_disp, _winid, _gc, pts, n, CoordModeOrigin);
free(pts);
return;}

void	g_square_ellipse(void *env){
int	n = 17;//12;//900;
XPoint	*pts = (XPoint*)malloc(sizeof(XPoint)*(n+1));
int	half_minor_axis, half_major_axis;
float	t = 0;

half_minor_axis = 100;
half_major_axis = 200;

for (int i=0;i<n;i++){
	pts[i].x = half_major_axis*cos(t) +400 +rand()%50;
	pts[i].y = half_minor_axis*sin(t) +650 +rand()%50;
	t+=2*M_PI/n;
}
pts[n].x = pts[0].x;//half_major_axis*cos(0) +400;
pts[n].y = pts[0].y;//half_minor_axis*sin(0) +650;

XDrawLines(_disp, _winid, _gc, pts, n+1, CoordModeOrigin);
free(pts);
return;}






void	*g_window(int y, int x, int width, int height, char *title){

return NULL;}
