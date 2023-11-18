#include <math.h>//sin/cos,M_PI
#include "spheres.h"

void drawdotellipse(int*** map,int cp,int radius,int x,int y,int z){
int n =100;
float t=M_PI; int xx,yy,zz;
float p=2*M_PI/3;
for(int i=0;i<n;i++){
	//p +=2*M_PI/n;
	t -=M_PI/n;
	xx =radius*sinf(t)*cosf(p) +x;
	yy =radius*sinf(t)*sinf(p) +y;
	zz =radius*cosf(t) +z;
	if(xx>=0&&xx<WIDTH && yy>=0&&yy<HEIGHT && zz>=0&&zz<DEPTH-1)
		map[zz][yy][xx] =cp;}
return;}
