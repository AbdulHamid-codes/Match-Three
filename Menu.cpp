/*
 * Menu.cpp
 *
 *  Created on: Jun 7, 2020
 *      Author: abdulhamid
 */

#include "Menu.h"

#include "util.h"
#include<curses.h>

Menu::Menu() {
	// TODO Auto-generated constructor stub

}
int Menu::displayMenu(){
	int option;
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	DrawSquare( 0 , 0 ,800,colors[GREEN]);
	 DrawString( 300, 600, "Welcome!!!", colors[BLACK]);
	 DrawString( 250, 550, "Please Enter your choice in terminal", colors[BLACK]);
	 DrawString( 300, 500, "1.New Game", colors[BLACK]);
	 DrawString( 300, 450, "2.Levels", colors[BLACK]);
	 DrawString( 300, 400, "3.Level modes ", colors[BLACK]);
	 DrawString( 300, 350, "4.Highest Score ", colors[BLACK]);
	 DrawString( 300, 300, "5.Setting ", colors[BLACK]);
	 DrawString( 300, 250, "6.Back to game", colors[BLACK]);

		glutSwapBuffers(); // do not modify this line..
		cin>>option;
		if(option==1)
	       return 1;
		if(option==3){
			glClearColor(0, 0,0.0, 0 );
			glClear (GL_COLOR_BUFFER_BIT);
		    DrawString( 300, 740, "1. Normal Mode ", colors[MISTY_ROSE]);
		    DrawString( 420, 740, "2. TimeTrial Mode", colors[MISTY_ROSE]);
		    DrawString( 420, 700, "press any key to continue", colors[MISTY_ROSE]);
		    getchar();
			glutSwapBuffers(); // do not modify this line..
			return 3;
		}
		return 0;
}
void Menu::displayMenuIcon(){
	DrawLine( 20 , 680 ,  50 , 680 , 5 , colors[MISTY_ROSE] );   // To draw the meny icon
	DrawLine( 20 , 670 ,  50 , 670 , 5 , colors[MISTY_ROSE] );
	DrawLine( 20 , 660 ,  50 , 660 , 5 , colors[MISTY_ROSE] );
	DrawString( 60, 660, "Menu ", colors[MISTY_ROSE]);
}


Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

