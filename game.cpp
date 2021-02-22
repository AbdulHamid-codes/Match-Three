//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include "GamePlay.h"
#include "Player.h"
#include "Gem.h"
#include "GameBoard.h"
#include "TPbar.h"
#include "ProgressBar.h"
#include "TimeBar.h"
#include "Menu.h"
#include <iostream>
#include<string>
#include<curses.h>    // For getchar()
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

/*
 * Main Canvas drawing function.
 * */

GamePlay *gp;
void GameDisplay()/**/{
   static GamePlay gamePlay;
   gp=&gamePlay;

   static int first=1;
   if(first){
		glClearColor(0, 0,0.0, 0 );
		glClear (GL_COLOR_BUFFER_BIT); //Update the color

		if(gp->displayMenu()==1){
			int mod;
			gp->getPlayerName();
			glClearColor(0, 0,0.0, 0 );
			glClear (GL_COLOR_BUFFER_BIT);
			DrawSquare( 0 , 0 ,800,colors[GREEN]);

			DrawString( 280,650, "Enter your option on terminal ", colors[MISTY_ROSE]);
			DrawString( 300,600, "1. Normal Mode ", colors[MISTY_ROSE]);
		   DrawString( 300,550, "2. TimeTrial Mode", colors[MISTY_ROSE]);
		   glutSwapBuffers(); // do not modify this line.
		   cin>>mod;
		   gp->setLevelMode(mod-1);

		}

		 first=0;

		glutSwapBuffers(); // do not modify this line..
   }
   else {
	glClearColor(0, 0,0, 0 );
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	DrawSquare( 0 , 0 ,800,colors[SNOW]);

	for(int i=150;i<700;i+=55){     // To draw the boxes for gems
		for(int j=150;j<700;j+=55){
			DrawLine( i , j ,  i+50 , j , 2 , colors[MISTY_ROSE] );
			DrawLine( i , j ,  i , j+50 , 2 , colors[MISTY_ROSE] );
			DrawLine( i , j+50 ,  i+50 , j+50 , 2 , colors[MISTY_ROSE] );
			DrawLine( i+50 , j ,  i+50 , j+50 , 2 , colors[MISTY_ROSE] );
		}
	}
	gp->drawGems();
	gp->displayMenuIcon();
	gp->displayPauseIcon();
	gp->displayScoreAndLevel();

	if(gp->getLevelMode()==0){
		gp->pb.displayBar();
	}
	static int runs=0;   // Used for constantly depleting time bar
	runs++;
	if(gp->getLevelMode()==1){
		DrawString( 25,500, "Lives "+to_string(gp->getLives()), colors[MISTY_ROSE]);
		if(gp->getGameState())    // If game is active/not paused
		if(runs%100==0)           // To deplete timeBar with each second
		gp->tb.decreaseFilledLenBy(5);
		gp->tb.displayBar();

	}

    do{                                  // Checking for mathces
    	if(gp->findMatch()){
    		gp->incrementScoreBy(5+10/gp->getLevel());
    		if(gp->getLevelMode()==0){
    			gp->pb.increaseFilledLenBy(5+10/gp->getLevel());
    	    	if(gp->pb.getFilledLen()>=gp->pb.getLen()){
    	    		gp->pb.resetBar();
    	    		gp->updateLevel();
    	    	}
    		}
    		if(gp->getLevelMode()==1){
    			gp->tb.increaseFilledLenBy(5+10/gp->getLevel());
    	    	if(gp->tb.getFilledLen()>=gp->tb.getLen()){
    	    		gp->tb.resetBar();
    	    		gp->updateLevel();
    	    	}
            	/*if(gp->tb.getFilledLen() <= 0){
	    	        gp->decreaseLives();
		          	gp->tb.increaseFilledLenBy(100);
        		   if(gp->getLives()<=0){
    	    		    glClearColor(0, 0,0, 0 );
    	    		    glClear (GL_COLOR_BUFFER_BIT); //Update the colors        	    	
					    DrawSquare( 0 , 0 ,800,colors[SNOW]);
        	    	    DrawString( 300, 650, "Game Over", colors[MISTY_ROSE]);
        			    getchar();
    		      	}
        	   }*/				
    		}
    	}

    	glutPostRedisplay();
    }
    while(gp->findMatch());

   }
     
		if(gp->tb.getFilledLen() <= 0){
	    	gp->decreaseLives();
			gp->tb.increaseFilledLenBy(100);
        		if(gp->getLives()<=0){
    	    		glClearColor(0, 0,0, 0 );
    	    		glClear (GL_COLOR_BUFFER_BIT); //Update the colors        	    	
					DrawSquare( 0 , 0 ,800,colors[SNOW]);
        	    	DrawString( 300, 650, "Game Over", colors[MISTY_ROSE]);
        			getchar();
    			}
        	}

	glutPostRedisplay();
	glutSwapBuffers(); // do not modify this line..
}

void NonPrintableKeys(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
	}
	else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
	}

	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
	}
	glutPostRedisplay();

}

void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	if (key == 'p' || key=='P') {
		if(gp->getGameState()==0)
			gp->setGameState(1);
		else
			gp->setGameState(0);
	}
	if (key == 'm' || key == 'M'){ //Key for placing the bomb

		if(gp->displayMenu()==1){
			int mod;
			gp->getPlayerName();
			glClearColor(0, 0,0.0, 0 );
			glClear (GL_COLOR_BUFFER_BIT);
			DrawSquare( 0 , 0 ,800,colors[GREEN]);

			DrawString( 280,650, "Enter your option on terminal ", colors[MISTY_ROSE]);
			DrawString( 300,600, "1. Normal Mode ", colors[MISTY_ROSE]);
		   DrawString( 300,550, "2. TimeTrial Mode", colors[MISTY_ROSE]);
		   glutSwapBuffers(); // do not modify this line.
		   cin>>mod;
		   gp->setLevelMode(mod-1);
		}
	}

	glutPostRedisplay();
}

void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutPostRedisplay();
	glutTimerFunc(1000.0, Timer, 0);
}

void MousePressedAndMoved(int x, int y) {
	//cout << x << " " << 703-y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

void MouseClicked(int button, int state, int x, int y) {
	static int x1, y1, x2, y2;

	if (button == GLUT_LEFT_BUTTON){ // dealing only with left button
		//cout << GLUT_DOWN << " " << GLUT_UP << endl;
		if(state==GLUT_DOWN){
			x1=x;
			y1=800-y-55;
		}
		if(state==GLUT_UP){
			x2=x;
			y2=800-y-55;
			if(x1 > 150 && x1<700 && x2 <700 && x2>150 && y1 > 150 && y1<700 && y2 <700 && y2>150 ){
				gp->swapGems(x1, y1, x2, y2);
			}
		}
   }
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
	int width = 800, height = 800; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
