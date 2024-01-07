#ifndef SPHERES_H
#define SPHERES_H

#define DEPTH 200
#define HEIGHT 200
#define WIDTH 200

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
void drawdebug(vect3 pos);

void make_colors(void);
void test_colors(int**);

int** newscreen(void);
void drawscreen(int** scr,int*** map,vect3 pos,int facing);
void dispscreen(int**);
void freescreen(int**);

int*** newmap(void);
void freemap(int***);

void drawdotverticalcircle(int*** map,int cp,vect3 center,int radius);
void drawdot3dellipse(int ***map,int cp, vect3 center,vect3 maj,vect3 min);
void drawdot3dcircle(int ***map,int cp, vect3 center,int radius,
		vect3 a, vect3 b);
vect3 drawrandom3dcircle(int ***map,int cp,int radius);
void drawmanycircles(int ***map,int n,int radius);

void movement(char c,vect3* pos);

#endif
