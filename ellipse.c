#include <math.h>//sin/cos,M_PI
#include <stdlib.h>//rand
#include "spheres.h"

void drawmanycircles(int ***map,int n,int radius){
for(int i=0;i<n;i++){
	int cp =rand()%3;
	switch(cp){
	case 0: cp =1; break; //red
	case 1: cp =10; break; //cyan
	case 2: cp =20; break; //white
	default: break;}
	drawrandom3dcircle(map,cp,radius);
}
return;}

vect3 drawrandom3dcircle(int ***map,int cp,int radius){
vect3 center =(vect3){rand()%(WIDTH-22)+11,rand()%(HEIGHT-22)+11,
	rand()%(DEPTH-22)+11};
vect3 a =(vect3){rand()%101,rand()%101,rand()%101};
vect3 b =(vect3){rand()%101,rand()%101,rand()%101};
drawdot3dcircle(map,cp,center,radius,a,b);
return center;}

void drawdot3dcircle(int ***map,int cp, vect3 center,int radius,
		vect3 a, vect3 b){
float na =sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
vect3f ua =(vect3f){a.x/na,a.y/na,a.z/na};
float nb =sqrt(b.x*b.x+b.y*b.y+b.z*b.z);
vect3f ub =(vect3f){b.x/nb,b.y/nb,b.z/nb};
int n =100;
float t =2*M_PI;
int xx,yy,zz;
for(int i=0;i<n;i++){
	t -=2*M_PI/n;
	xx =cosf(t)*radius*ua.x +sinf(t)*radius*ub.x +center.x;
	yy =cosf(t)*radius*ua.y +sinf(t)*radius*ub.y +center.y;
	zz =cosf(t)*radius*ua.z +sinf(t)*radius*ub.z +center.z;
	if(xx>=0&&xx<WIDTH && yy>=0&&yy<HEIGHT && zz>=0&&zz<DEPTH-1)
		map[zz][yy][xx] =cp;}
return;}

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
