/*
 * Base.h
 *
 *  Created on: May 16, 2020
 *      Author: abdulhamid
 */

#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_
#include "util.h"
#include "GameBoard.h"
#include "Player.h"
#include "Gem.h"
#include "ProgressBar.h"
#include "Menu.h"
#include "TPbar.h"


class GamePlay : public GameBoard ,public Menu, public Player{
	int gameState;
public:
	GamePlay();
	int getGameState();
    void setGameState(int);
};

#endif /* GAMEPLAY_H_ */
