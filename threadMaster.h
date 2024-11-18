#ifndef THREADMASTER_H
#define THREADMASTER_H



//********** GLOBAL VARIABLES ***************

// Master thread will control the players
player player1;
player player2;
player player3;
player player4;

// Semophores and threads
sem_t sem_player;
sem_t sem_board;
sem_t sem_master;

pthread_t gtid2;
pthread_t tid3;

// number of tokens
int tokens = 4; // default 4

void* MasterThread(void * val)
{
	
	int playerID = ( * ( int* ) val );
	player * currPlayer;
		
	switch(playerID){

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

	sem_wait(&sem_master);
	

	// kick out of the game if 20 turns with no sixes
	if(currPlayer->noSixes >= 20)
	{
		currPlayer -> inGame=0;
	}

	bool noWin = 0;
	for (int i = 0; i < tokens; i++)
	{
		if(!currPlayer->gotis[i].win)
		{
			noWin =1;
		}
	}


	// checking hit rate and checking if the tokens are entering home
	for (int i = 0; i < tokens; i++)
	{		
			if(currPlayer->hitRate > 0 && currPlayer->gotis[i].location >= 50) 	
			{
				// 50 is the location number for the starting of home
				currPlayer->gotis[i].atHome=1;
			}
			else{
				currPlayer->gotis[i].atHome=0;
			
			}
			
	}
	// checking if the player has won
	if (noWin == 0)
	{
		currPlayer->hasWon=1;
	}
	
	sem_post(&sem_master);
	
	pthread_exit(NULL);
}



#endif