/*
 * Gem.h
 *
 *  Created on: May 11, 2020
 *      Author: abdulhamid
 */
#include<string>
#include"util.h"
#ifndef GEM_H_
#define GEM_H_

class Gem {
private:
	int x;
	int y;
	int color;  // The index of that color in the color array
public:
	Gem();
	int getX();
	int getY();
	int getColor();
	void setCoOrdinates(int a, int b);
	void setColor(int c);
	void drawGem();
	void drawGemAt(int a, int b);
	virtual ~Gem();
};

#endif /* GEM_H_ */
