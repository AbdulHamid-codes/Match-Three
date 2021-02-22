/*
 * Menu.h
 *
 *  Created on: Jun 7, 2020
 *      Author: abdulhamid
 */

#ifndef MENU_H_
#define MENU_H_
#include "GamePlay.h"

class Menu {
private:
public:
	Menu();
    int displayMenu();
    void displayMenuIcon();
	virtual ~Menu();
};

#endif /* MENU_H_ */
