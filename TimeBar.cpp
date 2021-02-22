/*
 * TimeBar.cpp
 *
 *  Created on: Jun 9, 2020
 *      Author: abdulhamid
 */

#include "TimeBar.h"

TimeBar::TimeBar() {
	len = 200;
	filledLen=100;

}
void TimeBar::displayBar(){
	DrawLine( 300 , 100 ,  300+len , 100 , 20 , colors[MISTY_ROSE] );
	DrawLine( 300 , 100 ,  300+filledLen ,100 , 20 , colors[GREEN] );
}
void TimeBar::increaseFilledLenBy(int i){
	filledLen+=i;
}
void TimeBar::decreaseFilledLenBy(int d){
	filledLen-=d;
}
int TimeBar::getFilledLen(){
	return filledLen;
}
int TimeBar::getLen(){
	return len;
}
void TimeBar::resetBar(){
	filledLen=100;
}
TimeBar::~TimeBar() {
	// TODO Auto-generated destructor stub
}

