/*
 * TimeBar.h
 *
 *  Created on: Jun 9, 2020
 *      Author: abdulhamid
 */

#ifndef TIMEBAR_H_
#define TIMEBAR_H_
#include "util.h"
#include "TPbar.h"

class TimeBar : public TPbar {
protected:
	int len;
	int filledLen;
public:
	TimeBar();
	void displayBar();
	void increaseFilledLenBy(int);
	void decreaseFilledLenBy(int);
	int getFilledLen();
	int getLen();
	void resetBar();
	virtual ~TimeBar();
};

#endif /* TIMEBAR_H_ */
