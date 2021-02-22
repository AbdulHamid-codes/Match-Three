/*
 * TPbar.h
 *
 *  Created on: Jun 9, 2020
 *      Author: abdulhamid
 */

#ifndef TPBAR_H_
#define TPBAR_H_

class TPbar {
public:
	TPbar();
	virtual void displayBar()=0;
	virtual void increaseFilledLenBy(int)=0;
	virtual void decreaseFilledLenBy(int)=0;
	virtual int getFilledLen()=0;
	virtual int getLen()=0;
	virtual void resetBar()=0;
	virtual ~TPbar();
};

#endif /* TPBAR_H_ */
