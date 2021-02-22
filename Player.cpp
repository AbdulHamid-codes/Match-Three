/*
 * Player.cpp
 *
 *  Created on: May 6, 2020
 *      Author: abdulhamid
 */

#include "Player.h"
#include "util.h"
#include <string>

Player::Player() {
	name="";
	score=0;
	level=1;
	levelMode=0;
	lives=3;
}
void Player::getPlayerName(){
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	DrawSquare( 0 , 0 ,800,colors[GREEN]);
	 DrawString( 300, 400,"Enter your name in terminal", colors[BLACK]);

		glutSwapBuffers(); // do not modify this line..
		cin>>name;
		return;
}
long int Player::getScore(){
	return score;
}
int Player::getLevel(){
	return level;
}
void Player::incrementScoreBy(int s){
	score+=s;
}
void Player::updateLevel(){
	level+=1;
}
int Player::getLevelMode(){
	return levelMode;
}
void Player::setLevelMode(int l){
	levelMode=l;
}
void Player::decreaseLives(){
	lives-=1;
}
int Player::getLives(){
	return lives;
}

void Player::displayScoreAndLevel(){
    DrawString( 280, 740, "Score "+to_string(score), colors[MISTY_ROSE]);
    DrawString( 400, 740, "Level "+to_string(level), colors[MISTY_ROSE]);
    if(levelMode==0)
    DrawString( 520, 740, "Mode NM", colors[MISTY_ROSE]);
    if(levelMode==1)
    	DrawString( 520, 740, "Mode TT", colors[MISTY_ROSE]);
}


//Player::~Player() {
	// TODO Auto-generated destructor stub
//}

