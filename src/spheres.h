#ifndef SPHERES_H
#define SPHERES_H
#include <ncurses.h>

#define DEPTH	450
#define HEIGHT	450
#define WIDTH	450
#define RADIUS	20
#define SPHERES_MARGIN	(RADIUS+40)
#define HORIZON	80
#define SPHERES_COUNT	16

#define K_QUIT	'1'
#define K_DEBUG	'2'

#define K_LEFT	'a'
#define K_RIGHT	'd'
#define K_UP	'w'
#define K_DOWN	's'
#define K_UP_LEFT	'q'
#define K_UP_RIGHT	'e'
#define K_DOWN_LEFT	'z'
#define K_DOWN_RIGHT	'x'

#define K_FORWARD	'r'
#define K_BACKWARD	'c'

#define K_FACE_FRONT	'o'
#define K_FACE_BACK	'l'
#define K_FACE_LEFT	'k'
#define K_FACE_RIGHT	';'

#define FRONT	1
#define BACK	2
#define LEFT	3
#define RIGHT	4
#define UP	5
#define DOWN	6


typedef struct{
	int x,y,z;	}vect3;
typedef struct{
	float x,y,z;	}vect3f;

typedef struct{
	int debug;	}Flags;
void drawdebug(vect3 pos,int facing);

void make_colors(void);
void test_colors(int**);

char*** newmap(void);
void freemap(char***);

int** newscreen(void);
void freescreen(int**);
void drawscreen(int** scr,char*** map,vect3 pos,int facing);
void dispscreen(int**);

void drawdot3dcircle(char ***map,int cp, vect3 center,vect3f a, vect3f b);
vect3 drawrandomsphere(char ***map,int cp);
void drawmanyspheres(char ***map,int n);

void movement(char c,vect3* pos);
void turn(char c,int *facing);

#endif
