/*
 * ProgressBar.h
 *
 *  Created on: May 14, 2020
 *      Author: abdulhamid
 */

#ifndef PROGRESSBAR_H_
#define PROGRESSBAR_H_
#include "util.h"
#include "TPbar.h"

class ProgressBar : public TPbar {
private:
	int len;
	int filledLen;
public:
	ProgressBar();
	void displayBar();
	void increaseFilledLenBy(int);
	void decreaseFilledLenBy(int);
	int getFilledLen();
	int getLen();
	void resetBar();
	virtual ~ProgressBar();
};

#endif /* PROGRESSBAR_H_ */
