#ifndef PLAYER_H
#define	PLAYER_H



// #include "threadMaster.h" 
#include <iostream>
#include<time.h>
#include<pthread.h>	
#include<stdio.h>
#include<stdlib.h>	
#include<algorithm>
#include<sys/wait.h>
#include<semaphore.h>
#include <unistd.h>



using namespace std;


// dice variable
int dice[4][3];
int rolling_dice()
{
	srand (time(NULL));
	return rand()%6+1;
}

//structure for token
struct token
{
	
	int location;
	int xCord; // x cord of grid
	int yCord; // y cord of the grid
	
	bool notAtYard; //shows the state of token
	bool atHome;
	bool stop;
	bool win;
    
    char sym;
    
    token(){

    	// default values
        location = -1;  // -1 means that the token is at the Yard.
        xCord = 0;
        yCord = 0;
		
		stop = false;
		win  = false;
		atHome = false;
		notAtYard = false;
	
		sym='?'; // default symbol
    }   
    // parameterized constructor
	token(int v,int x1,int y1,bool o,bool s,bool w,char symb){

		// inititalizing
		location=v;
        xCord = x1;
        yCord = y1;
		stop = s;
		win = w;
		notAtYard = o;
		sym = symb;
	}
	
};




// pleayer structure
struct player{
    
	// variables / attrs
    token *gotis;

	int hitRate;
	int noSixes;
	
	bool hasWon; 
	bool inGame;
	
	char playerSymbol;
	//constructor
	player(){
		
		hitRate = 0;
		hasWon = 0;
		inGame = 1;
		noSixes = 0;
	}
	
	//parameterised constructor
	player(char symbol,int tokenAmount)
	{
		
        gotis = new token [tokenAmount];

        // initializing the tokens
        for (int i=0;i<tokenAmount;i++)
        {
            gotis[i].sym=symbol;
        }

        // assigning default values at thte start of the game
        playerSymbol = symbol;
		hitRate = 0;
		hasWon = 0;
		inGame = 1;
		noSixes = 0;
	}
};


#endif