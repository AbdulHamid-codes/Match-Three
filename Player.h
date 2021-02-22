/*
 * Player.h
 *
 *  Created on: May 6, 2020
 *      Author: abdulhamid
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include<string>
#include<iostream>
using namespace std;

class Player {
protected:
	string name;
	long int score;
	int level;
	int levelMode;
	int lives;
public:
	Player();
	void getPlayerName();
	long int getScore();
	int getLevel();
	int getLevelMode();
	void setLevelMode(int );
	void displayScoreAndLevel();
	void incrementScoreBy(int);
	void updateLevel();
	void decreaseLives();
	int getLives();

	//virtual ~Player();
};

#endif /* PLAYER_H_ */
