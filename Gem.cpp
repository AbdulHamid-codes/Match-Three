/*
 * Gem.cpp
 *
 *  Created on: May 11, 2020
 *      Author: abdulhamid
 */

#include "Gem.h"

Gem::Gem() {
	x=0;
	y=0;
	color=5;
}
int Gem::getX(){
	return x;
}
int Gem::getY(){
	return y;
}
int Gem::getColor(){
	return color;
}
void Gem::setCoOrdinates(int a, int b){
	x=a;
	y=b;
}
void Gem::setColor(int c){
	color=c;
}
void Gem::drawGem(){
	if(color== 0){
		DrawSquare( x+5 , y+5 ,40, colors[DARK_RED]);
	}
	else if(color== 1){
		DrawSquare( x+5 , y+5 ,40, colors[GREEN]);
	}
	else if(color== 2){
		DrawSquare( x+5 , y+5 ,40, colors[YELLOW]);
	}
	else if(color== 3){
		DrawSquare(  x+5 , y+5 ,40, colors[	SKY_BLUE]);
	}
	 else if(color== 4){
		DrawSquare(  x+5 , y+5 ,40, colors[DARK_SLATE_GRAY]);
	}
	 else if(color==5){
		 DrawSquare(  x+5 , y+5 ,40, colors[GOLD]);
	 }
	 else if(color==6){
		 DrawSquare(  x+5 , y+5 ,40, colors[LIGHT_PINK]);
	 }
	 else
		 DrawSquare(  x+5 , y+5 ,40, colors[BLACK]);
}
void Gem::drawGemAt(int a, int b){
	DrawSquare(  a+5 , b+5 ,40, colors[RED]);
}
Gem::~Gem() {
	// TODO Auto-generated destructor stub
}

