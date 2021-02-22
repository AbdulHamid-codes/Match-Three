/*
 * GameBoard.h
 *
 *  Created on: May 12, 2020
 *      Author: abdulhamid
 */

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_
#include "util.h"
#include "Gem.h"
#include "util.h"
#include "TPbar.h"
#include"TimeBar.h"
#include"ProgressBar.h"

class GameBoard {
public:
    ProgressBar pb;
    TimeBar tb;
	Gem **gems;
	GameBoard();
	void drawGems();
	void swapGems(int x1, int y1, int x2, int y2);
	bool findMatch();
	void displayPauseIcon();
	virtual ~GameBoard();
};

#endif /* GAMEBOARD_H_ */
