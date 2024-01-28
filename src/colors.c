#include <ncurses.h>

void make_colors(void){
//red
init_color(20,800,0,0);
init_color(21,600,0,0);
init_color(22,400,0,0);
init_color(23,200,0,0);
init_pair(10,0,20);
init_pair(11,0,21);
init_pair(12,0,22);
init_pair(13,0,23);

//cyan
init_color(30,0,800,800);
init_color(31,0,600,600);
init_color(32,0,400,400);
init_color(33,0,200,200);
init_pair(20,0,30);
init_pair(21,0,31);
init_pair(22,0,32);
init_pair(23,0,33);

//
init_color(40,800,800,800);
init_color(41,600,600,600);
init_color(42,400,400,400);
init_color(43,200,200,200);
init_pair(30,0,40);
init_pair(31,0,41);
init_pair(32,0,42);
init_pair(33,0,43);
return;}

void test_colors(int** scr){
//red
scr[5][4] =10;
scr[6][5] =11;
scr[7][5] =12;
scr[8][6] =13;

//cyan
scr[5][14] =20;
scr[6][15] =21;
scr[7][15] =22;
scr[8][16] =23;

//
scr[5][24] =30;
scr[6][25] =31;
scr[7][25] =32;
scr[8][26] =33;
return;}
