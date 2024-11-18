#ifndef THREADPLAYER_H
#define THREADPLAYER_H

#include "conio.h"

void* playerthread(void* turn)
{

	char roll;
	bool threeSixes=true;
	

	// id sent to thread by main
	// turn has the player who has the current turn.
	int playerID = ( * ( int* ) turn );

	player * currPlayer;

	//setting the id of the dice
	int diceId = playerID - 1;
	// resetting the dice to 0
	for (int  i = 0; i < 3; i++)
	{
		dice[diceId][i]=0;
	}

	// pointing to the player who has the turn
	switch(playerID)
	{

			case 1 :
					{
						currPlayer = &player1;
						break;
					}
			case 2 :
					{
						currPlayer = &player2;
						break;
					}
			case 3 :
					{
						currPlayer = &player3;
						break;
					}
			case 4 :
					{
						currPlayer = &player4;
						break;
					}};


	sem_wait(&sem_player);

	
	// start dice rolling loop
	for(int i=0;i<3;i++){
		string t = "Player ";
		t += currPlayer->playerSymbol;
		blueLine(t);
		blueLine("Press 'r' To Roll The Dice.");
		// cout << "\nPress 'r' To Roll The Dice." << endl;
		roll = getch();
		while(roll != 'r')
		{
			disclaimer("Invalid Choice");
			blueLine("Press 'r' To Roll The Dice.");
		}

		// rolling the dice
		dice[diceId][i]=rolling_dice(); 
		
		string txt = "";
		txt += "Player ";
		txt += currPlayer->playerSymbol;
		txt += " Got : ";
		string temp = to_string(dice[diceId][i]);
		txt += temp;
		blueLine(txt);
		sleep(1);

		// roll again if a six occurs
        if (dice[diceId][i]!=6)
	    {
			currPlayer->noSixes++;
	    }
	    else
	    {
			currPlayer->noSixes=0;
	    }
	    // break if no six
		if(dice[diceId][i]!=6){
			threeSixes=false;
			break;
		}

	} // end rolling for loop

	// checking 3 consecutive sixes
	if(threeSixes)
	{
		for (int  i = 0; i < 3; i++)
		{
			// resetting dice -> turn loss due to 6 consec sixes
			dice[diceId][i]=0;
		}
	}
	


	// loop to move the tokens and validate turns
	for( int j=0;  j < 3 &&  dice[diceId][j] > 0 ; j++){
		
		int gotiId = 1;
		bool movable = false;
		
		for(int i=0; i < tokens; i++)
		{
			if(currPlayer->gotis[i].notAtYard == 1)
			{
				movable = true;
			}
		}

		// turn will be valid if either there is a movable token (token not at yard)
		// or there is a six to move the token out of the yard
		if(movable || dice[diceId][j]==6)
		{
			disclaimer();
			
			string txt = "Player : ";
			txt += currPlayer->playerSymbol;
			blueLine(txt);
			
			txt = "Dice Value : ";
			txt += to_string(dice[diceId][j]);

			gotiId = inputInt("Enter The ID Of The Token That You Want To Move : ");
			cin.ignore();

			while(gotiId > tokens || gotiId < 1)
			{
				string temp = "Enter A Valid Id (1 - ";
				temp += to_string(tokens+1);
				temp += " ) : ";
				gotiId = inputInt(temp);
				cin.ignore();
			}
			// checking if the token can be moved or not
			while(((!currPlayer->gotis[gotiId-1].notAtYard) && dice[diceId][j]!=6) || (currPlayer->gotis[gotiId-1].win))
			{
				string txt1 = "This Token Cannot Be Moved. Because ";
				if (!currPlayer->gotis[gotiId].notAtYard)
				{
					txt1 += "This Token Is At The Yard And The Dice Value Is Not Six.";
					disclaimer(txt1);

				}
				else 
				{
					txt1+= "This Token Has Won And Is At Home.";
					disclaimer(txt1);
				}

				// taking input again
				gotiId = inputInt("Enter The ID Of The Token That You Want To Move : ");
				cin.ignore();

			}

			bool winflag=0;
			bool notmoveflag=0;
			
			while (currPlayer->gotis[gotiId-1].location+dice[diceId][j]  >  56)
			{
				disclaimer("This Token Cannot Take This Move. :( .");
				// cout << "\nThis Token Cannot Take This Move. :( ." << endl;

				for (int k = 0; k < tokens; k++)
				{
					if(k!=gotiId-1)
					{
						if (!currPlayer->gotis[k].win && currPlayer->gotis[k].notAtYard)
						{
							winflag=1;
						}
						if(dice[diceId][j]==6 && !currPlayer->gotis[k].notAtYard)
						{
							winflag=1;
						}
					}
				}
				if(winflag){
					gotiId = inputInt("Enter The ID Of The Token That You Want To Move : ");
					cin.ignore();
					
				}
				else
				{
					notmoveflag=1;
					break;
				}
			}


			// move the token that is to be moved
			// distance that is to be moved.
			// token who's distance is to be changed
			if(currPlayer->gotis[gotiId-1].notAtYard && !notmoveflag){
				calculateCoordinates(dice[diceId][j],&currPlayer->gotis[gotiId-1]);
			}
			// if unlockable
			else if(dice[diceId][j]==6)
			{
				
				currPlayer->gotis[gotiId-1].location=0;
				currPlayer->gotis[gotiId-1].notAtYard=1;
				if(currPlayer->gotis[gotiId-1].sym=='T')
				{
					currPlayer->gotis[gotiId-1].xCord=1;
					currPlayer->gotis[gotiId-1].yCord=6;
				}
				else if(currPlayer->gotis[gotiId-1].sym=='G')
				{
					currPlayer->gotis[gotiId-1].xCord=6;
					currPlayer->gotis[gotiId-1].yCord=13;
				}
				else if(currPlayer->gotis[gotiId-1].sym=='S')
				{
					currPlayer->gotis[gotiId-1].xCord=8;
					currPlayer->gotis[gotiId-1].yCord=1;
				}
				else if(currPlayer->gotis[gotiId-1].sym=='U')
				{
					currPlayer->gotis[gotiId-1].xCord=13;
					currPlayer->gotis[gotiId-1].yCord=8;
				}
				
			}

			// checking if the token is at a safe spot
			// safe spots = 0,8,13,21,26,34,39,47
			int spot = currPlayer->gotis[gotiId-1].location;
			//safe points conditions
			if(spot==0 || spot==8 || spot==13 || spot==21 || spot==26 || spot==34 || spot==39 || spot==47)
			{
				currPlayer->gotis[gotiId-1].stop=1;
			}
			else
			{
				currPlayer->gotis[gotiId-1].stop=0;
			}
		}

		// for(int i=0;i<tokens;i++)
		// // cout<<endl;
		

		// taking control of the board
		
		sem_init(&sem_board,0,1);
		pthread_create(&gtid2,NULL,&hitVictimThread,&playerID);
		pthread_join(gtid2,NULL);

		drawBoard();
	}
	sem_post(&sem_player);
	pthread_exit(NULL);
}




#endif