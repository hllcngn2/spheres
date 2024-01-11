#include <ncurses.h>

void make_colors(void){
//red
init_color(20,800,0,0);
init_color(21,600,0,0);
init_color(22,400,0,0);
init_color(23,200,0,0);
init_pair(1,0,20);
init_pair(2,0,21);
init_pair(3,0,22);
init_pair(4,0,23);

//cyan
init_color(30,0,800,800);
init_color(31,0,600,600);
init_color(32,0,400,400);
init_color(33,0,200,200);
init_pair(10,0,30);
init_pair(12,0,31);
init_pair(13,0,32);
init_pair(14,0,33);

//
init_color(40,800,800,800);
init_color(41,600,600,600);
init_color(42,400,400,400);
init_color(43,200,200,200);
init_pair(20,0,40);
init_pair(22,0,41);
init_pair(23,0,42);
init_pair(24,0,43);
return;}

void test_colors(int** scr){
//red
scr[5][4] =1;
scr[6][5] =2;
scr[7][5] =3;
scr[8][6] =4;

//cyan
scr[5][14] =10;
scr[6][15] =12;
scr[7][15] =13;
scr[8][16] =14;

//
scr[5][24] =20;
scr[6][25] =22;
scr[7][25] =23;
scr[8][26] =24;
return;}
