/*
 * ProgressBar.cpp
 *
 *  Created on: May 14, 2020
 *      Author: abdulhamid
 */
#include "ProgressBar.h"

ProgressBar::ProgressBar() {
	len = 200;
	filledLen=6;
}
void ProgressBar::displayBar(){
	DrawLine( 300 , 100 ,  300+len , 100 , 20 , colors[MISTY_ROSE] );
	DrawLine( 300 , 100 ,  300+filledLen ,100 , 20 , colors[GREEN] );
}
void ProgressBar::increaseFilledLenBy(int i){
	filledLen+=i;
}
void ProgressBar::decreaseFilledLenBy(int d){
	filledLen-=d;
}
int ProgressBar::getFilledLen(){
	return filledLen;
}
int ProgressBar::getLen(){
	return len;
}
void ProgressBar::resetBar(){
	filledLen=0;
}

ProgressBar::~ProgressBar() {
	// TODO Auto-generated destructor stub
}

