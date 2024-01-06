#include <math.h>//sin/cos,M_PI
#include "spheres.h"

void drawdot3dellipse(int ***map,int cp, vect3 center,vect3 maj,vect3 min){
int n =100;
float t =2*M_PI;
int xx,yy,zz;
for(int i=0;i<n;i++){
	t -=2*M_PI/n;
	xx =cosf(t)*maj.x +sinf(t)*min.x +center.x;
	yy =cosf(t)*maj.y +sinf(t)*min.y +center.y;
	zz =cosf(t)*maj.z +sinf(t)*min.z +center.z;
	if(xx>=0&&xx<WIDTH && yy>=0&&yy<HEIGHT && zz>=0&&zz<DEPTH-1)
		map[zz][yy][xx] =cp;}
return;}

void drawdotverticalcircle(int*** map,int cp,vect3 center,int radius){
int n =100;
float t =2*M_PI;
int xx,yy,zz;
for(int i=0;i<n;i++){
	t -=2*M_PI/n;
	xx =radius*cosf(t) +center.x;
	yy =radius*sinf(t) +center.y;
	zz =center.z;
	if(xx>=0&&xx<WIDTH && yy>=0&&yy<HEIGHT && zz>=0&&zz<DEPTH-1)
		map[zz][yy][xx] =cp;}
return;}
