#include "board.h"
#include "player.h"
#include "threadMaster.h"
#include "grid.h"
#include "threadVictim.h"
#include "threadPlayer.h"
#include "conio.h"


int main(void)
{ 
	system("clear");
	header();
	// inputting the number of tokens for the game
	// cout << "\nEnter The Number Of Tokens : ";
	tokens = inputInt("Enter The Number Of Tokens : ");
	while (tokens > 4 || tokens < 1)
	{
		disclaimer("Invalid Number Of Tokens.");
		tokens = inputInt("Enter The Number Of Tokens : ");
		// cout << "\nInvalid Number Of Tokens.\nEnter The Number Of Tokens : ";
		// cin >> tokens;
	}
	cin.ignore();

	// creating players
	player p1('T',tokens);
	player p2('G',tokens);
	player p3('S',tokens);
	player p4('U',tokens);
	
	// initializing the players in threadMaster.h
	player1 = p1;
	player2 = p2;
	player3 = p3;
	player4 = p4;

	/// an array for random turn order of the players
	int turnsOrder[4] = {1,2,3,4};	

	while(1){
		
		sem_init(&sem_player,0,1);	
		// shuffling for random turns order;
		random_shuffle(turnsOrder,turnsOrder+4);

		pthread_t tid[4];
		
       

		//creating the threads each for one player
		for(int i=0;i<4;i++)
		{
			pthread_create(&tid[i], NULL, &playerthread, &turnsOrder[i]);
			
		}

		//joing all the threads
		for(int i=0;i<4;i++)
		{
			pthread_join(tid[i], NULL);

		}
		// cout << "Round End. Press Any Key To Continue." << endl;

		char cont;
		disclaimer("Round Ended. Press Any Key To Continue.");
		cin.ignore();	
		cont = getch();
	}    
    return 0;
}




