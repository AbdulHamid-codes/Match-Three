/*
 * Base.cpp
 *
 *  Created on: May 16, 2020
 *      Author: abdulhamid
 */

#include "GamePlay.h"
GamePlay::GamePlay(): GameBoard(),Player(),Menu()
{
	gameState=1;
}
int GamePlay::getGameState(){
	return gameState;
}
void GamePlay::setGameState(int s){
	gameState=s;
}

//GamePlay::~GamePlay() {
	// TODO Auto-generated destructor stub
//}

