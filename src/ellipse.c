#include <math.h>//sin/cos,M_PI
#include <stdlib.h>//rand
#include "spheres.h"

void drawmanycircles(int ***map,int n){
for(int i=0;i<n;i++){
	int cp =rand()%3;
	switch(cp){
	case 0: cp =1; break; //red
	case 1: cp =10; break; //cyan
	case 2: cp =20; break; //white
	default: break;}
	drawrandom3dcircle(map,cp);
}
return;}

vect3 drawrandom3dcircle(int ***map,int cp){
vect3 center =(vect3){rand()%(WIDTH-SPHERES_MARGIN*2)+SPHERES_MARGIN,
			rand()%(HEIGHT-SPHERES_MARGIN*2)+SPHERES_MARGIN,
			rand()%(DEPTH-SPHERES_MARGIN*2)+SPHERES_MARGIN};
vect3f a =(vect3f){rand()%101,rand()%101,rand()%101};
vect3f b =(vect3f){rand()%101,rand()%101,rand()%101};
drawdot3dcircle(map,cp,center,a,b);
return center;}

void drawdot3dcircle(int ***map,int cp, vect3 center,vect3f a, vect3f b){
float na =sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
vect3f ua =(vect3f){a.x/na,a.y/na,a.z/na};
float nb =sqrt(b.x*b.x+b.y*b.y+b.z*b.z);
vect3f ub =(vect3f){b.x/nb,b.y/nb,b.z/nb};
int n =100;
float t =2*M_PI;
int x,y,z;
for(int i=0;i<n;i++){
	t -=2*M_PI/n;
	x =(int)(cosf(t)*(float)RADIUS*ua.x
		+sinf(t)*(float)RADIUS*ub.x +center.x);
	y =(int)(cosf(t)*(float)RADIUS*ua.y
		+sinf(t)*(float)RADIUS*ub.y +center.y);
	z =(int)(cosf(t)*(float)RADIUS*ua.z
		+sinf(t)*(float)RADIUS*ub.z +center.z);
	map[z][y][x] =cp;}
return;}
