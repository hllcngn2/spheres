#ifndef SPHERES_H
#define SPHERES_H

typedef struct{
	int c;
	int color;
}pixel;

typedef pixel** screen;
typedef pixel* row;

screen newscreen(void);
void dispscreen(screen);
void freescreen(screen);

#endif
