/*
 * GameBoard.cpp
 *
 *  Created on: May 12, 2020
 *      Author: abdulhamid
 */

#include "GameBoard.h"
#include "util.h"
#include <math.h>

GameBoard::GameBoard(){
	gems = new Gem*[10];
	for(int i=0;i<10;++i){
		gems[i]=new Gem[10];
	}

	int m=150, n=150;
	for(int i=0;i<10;++i){
		m=150;
		for(int j=0;j<10;++j){
			gems[i][j].setCoOrdinates(m,n);
			gems[i][j].setColor(GetRandInRange(0,7));
			m+=55;
		}
		n+=55;
	}
}
void GameBoard::drawGems(){
    for(int i=0;i<10;++i){
   	 for(int j=0;j<10;j++){
   		gems[i][j].drawGem();
   	 }
    }
}
bool GameBoard::findMatch(){
	for(int i=0;i<10;++i){      // To check For Horizontal matchces
		for(int j=1;j<10;++j){
			int count=0;
			int a=0;
			if(gems[i][j].getColor()==gems[i][j-1].getColor()){
			    a=j;
				count++;
				while(gems[i][a].getColor()==gems[i][j].getColor() && a<10){
					count++;
					a++;
				}
			}
	     if(count>=3){
	    	 for(int x=j-1, loop=0;loop<count;++loop,++x){
	    		 gems[i][x].setColor(7);
	    	 }
	    		glutPostRedisplay();
	    		glutPostRedisplay();
	    	 for(int x=j-1, loop=0;loop<count;++x,++loop){
	    		 gems[i][x].setColor(GetRandInRange(0,7));
	    	 }
	    	 return true;
	     }
		}
	}
		for(int i=0;i<10;++i){      // To check For Vertical matchces
			for(int j=1;j<10;++j){
				int count=0;
				int a=0;
				if(gems[j][i].getColor()==gems[j-1][i].getColor()){
				    a=j;
					count++;
					while( a<10  && gems[a][i].getColor()==gems[j][i].getColor()){
						count++;
						a++;
					}
				}
		     if(count>=3){
		    	 for(int x=j-1, loop=0;loop<count;++loop,++x){
		    		 gems[x][i].setColor(7);
		    	 }
		    		glutPostRedisplay();
		    	 for(int x=j-1, loop=0;loop<count;++x,++loop){
		    		 gems[x][i].setColor(GetRandInRange(0,7));
		    	 };
		    	 return true;
		     }
			}
		}
return false;
}
void  GameBoard::swapGems(int x1, int y1, int x2, int y2){
	int i1=0, i2=0, j1=0, j2=0, c1=0, c2=0;
	i1=(x1-155)/52;
	j1=(y1-155)/52;
	c1=gems[j1][i1].getColor();
	i2=(x2-155)/52;
	j2=(y2-155)/52;
	c2=gems[j2][i2].getColor();
	if((i1==i2 || j1==j2) && (abs(i1-i2)<=1 && abs(j1-j2)<=1)){
		gems[j1][i1].setColor(c2);
		gems[j2][i2].setColor(c1);
	}
}
void GameBoard::displayPauseIcon(){
	DrawCircle(30,600,20,colors[GREEN]);
	DrawTriangle( 20, 615 ,20, 585,45 , 600 , colors[WHITE] );
}

GameBoard::~GameBoard() {
	// TODO Auto-generated destructor stub
}

