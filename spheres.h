#ifndef SPHERES_H
#define SPHERES_H
#include <ncurses.h>

#define DEPTH 500
#define HEIGHT 500
#define WIDTH 500
#define RADIUS 30
#define SPHERES_MARGIN (RADIUS+40)
#define HORIZON 100

#define K_QUIT '1'
#define K_DEBUG '2'

#define K_LEFT 'a'
#define K_RIGHT 'd'
#define K_UP 'w'
#define K_DOWN 's'
#define K_UP_LEFT 'q'
#define K_UP_RIGHT 'e'
#define K_DOWN_LEFT 'z'
#define K_DOWN_RIGHT 'x'

#define K_FORWARD 'r'
#define K_BACKWARD 'c'

#define K_FACE_FRONT 'o'
#define K_FACE_BACK 'l'
#define K_FACE_LEFT 'k'
#define K_FACE_RIGHT ';'
#define K_FACE_UP 'p'
#define K_FACE_DOWN '.'

#define FRONT 1
#define BACK 2
#define LEFT 3
#define RIGHT 4
#define UP 5
#define DOWN 6

typedef struct{
	int x,y,z; }vect3;
typedef struct{
	float x,y,z; }vect3f;

typedef struct{
	int debug; }Flags;
void drawdebug(vect3 pos,int facing);

void make_colors(void);
void test_colors(int**);

int** newscreen(void);
void drawscreen(int** scr,int*** map,vect3 pos,int facing);
void dispscreen(int**);
void freescreen(int**);

int*** newmap(void);
void freemap(int***);

void drawdot3dcircle(int ***map,int cp, vect3 center,vect3f a, vect3f b);
vect3 drawrandom3dcircle(int ***map,int cp);
void drawmanycircles(int ***map,int n);

void movement(char c,vect3* pos);
void turn(char c,int *facing);

#endif
