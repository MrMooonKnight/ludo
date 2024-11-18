#ifndef THREADVICTIM_H
#define THREADVICTIM_H




// checks if there is a victim
// victim means that if a player is killed
// if a player lands on another player than the player below gets killed 
void* hitVictimThread(void * attr)
{
	
	int temp=(*(int*)attr);
	
	player * currPlayer;
	
	 if(temp==1){
		currPlayer=&player1;
	}
	else if(temp==2){
		currPlayer=&player2;
	}
	else if(temp==3){
		currPlayer=&player3;
	}
	else if(temp==4){
		currPlayer=&player4;
	} 

    if(currPlayer->inGame && !currPlayer->hasWon)
	{
		sem_wait(&sem_board);
		for(int i=0;i<tokens;i++)
		{
			if(currPlayer->gotis[i].sym=='T')
			{
				for(int j=0;j<tokens;j++)
				{
					if(currPlayer->gotis[i].xCord == player3.gotis[j].xCord&&currPlayer->gotis[i].yCord == player3.gotis[j].yCord && player3.gotis[j].notAtYard == 1 && player3.gotis[j].stop != 1)
					{
						cout<<"Player 1 Killed Player 3 "<<endl;
						player3.gotis[j].location=-1;
						player3.gotis[j].notAtYard=0;
						player3.gotis[j].atHome=0;
						player3.gotis[j].xCord=8;
						player3.gotis[j].yCord=1;
						currPlayer->hitRate++;
					}
					if(currPlayer->gotis[i].xCord==player4.gotis[j].xCord &&currPlayer->gotis[i].yCord==player4.gotis[j].yCord && player4.gotis[j].notAtYard==1 &&player4.gotis[j].stop!=1)
					{
						cout<<"Player 1 Killed Player 4 "<<endl;
						player4.gotis[j].location=-1;
						player4.gotis[j].notAtYard=0;
						player4.gotis[j].atHome=0;
						player4.gotis[j].xCord=13;
						currPlayer->hitRate++;
						player4.gotis[j].yCord=8;
					}
					if(currPlayer->gotis[i].xCord==player2.gotis[j].xCord && currPlayer->gotis[i].yCord==player2.gotis[j].yCord && player2.gotis[j].notAtYard==1 &&player2.gotis[j].stop!=1)
					{
						cout<<"Player 1 Killed Player 2 "<<endl;
						player2.gotis[j].atHome=0;

						player2.gotis[j].location=-1;
						player2.gotis[j].notAtYard=0;
						player2.gotis[j].xCord=6;
						currPlayer->hitRate++;
						player2.gotis[j].yCord=13;
					}
				}
			}
			else if(currPlayer->gotis[i].sym=='G')
			{
				for(int j=0;j<tokens;j++)
				{
					if(currPlayer->gotis[i].xCord==player1.gotis[j].xCord && currPlayer->gotis[i].yCord==player1.gotis[j].yCord&& player1.gotis[j].notAtYard==1 && player1.gotis[j].stop!=1)
					{
						cout<<"Player 2 Killed Player 1 "<<endl;
						player1.gotis[j].location=-1;
						currPlayer->hitRate++;
						player1.gotis[j].atHome=0;
						player1.gotis[j].notAtYard=0;
						player1.gotis[j].xCord=1;
						player1.gotis[j].yCord=6;
					}
					if(currPlayer->gotis[i].xCord==player3.gotis[j].xCord && currPlayer->gotis[i].yCord==player3.gotis[j].yCord && player3.gotis[j].notAtYard==1  &&player3.gotis[j].stop!=1)
					{
						cout<<"Player 2 Killed Player 3 "<<endl;
						player3.gotis[j].location=-1;
						player3.gotis[j].atHome=0;
						player3.gotis[j].notAtYard=0;
						currPlayer->hitRate++;
						player3.gotis[j].xCord=8;
						player3.gotis[j].yCord=1;
					}
					if(currPlayer->gotis[i].xCord==player4.gotis[j].xCord && currPlayer->gotis[i].yCord==player4.gotis[j].yCord && player4.gotis[j].notAtYard==1  &&player4.gotis[j].stop!=1)
					{
						cout<<"Player 2 Killed Player 4 "<<endl;
						player4.gotis[j].location=-1;
						player4.gotis[j].notAtYard=0;
						currPlayer->hitRate++;
						player4.gotis[j].atHome=0;
						player4.gotis[j].xCord=13;
						player4.gotis[j].yCord=8;
					}
				}
			}
			else if(currPlayer->gotis[i].sym=='S')
			{
				for(int j=0;j<tokens;j++)
				{
					if(currPlayer->gotis[i].xCord==player4.gotis[j].xCord && currPlayer->gotis[i].yCord==player4.gotis[j].yCord && player4.gotis[j].notAtYard==1  &&player4.gotis[j].stop!=1)
					{
						cout<<"Player 3 Killed Player 4 "<<endl;
						player4.gotis[j].location=-1;
						player4.gotis[j].notAtYard=0;
						player4.gotis[j].atHome=0;
						player4.gotis[j].xCord=13;
						currPlayer->hitRate++;
						player4.gotis[j].yCord=8;
					}
					if(currPlayer->gotis[i].xCord==player2.gotis[j].xCord && currPlayer->gotis[i].yCord==player2.gotis[j].yCord && player2.gotis[j].notAtYard==1  &&player2.gotis[j].stop!=1)
					{
						cout<<"Player 3 Killed Player 2 "<<endl;
						player2.gotis[j].location=-1;
						player2.gotis[j].notAtYard=0;
						currPlayer->hitRate++;
						player2.gotis[j].atHome=0;
						player2.gotis[j].xCord=6;
						player2.gotis[j].yCord=13;
					}
					if(currPlayer->gotis[i].xCord==player1.gotis[j].xCord && currPlayer->gotis[i].yCord==player1.gotis[j].yCord && player1.gotis[j].notAtYard==1  &&player1.gotis[j].stop!=1)
					{
						cout<<"Player 3 Killed Player 1 "<<endl;
						player1.gotis[j].location=-1;
						currPlayer->hitRate++;
						player1.gotis[j].atHome=0;
						player1.gotis[j].notAtYard=0;
						player1.gotis[j].xCord=1;
						player1.gotis[j].yCord=6;
					}
				}
			}
			else if(currPlayer->gotis[i].sym=='U')
			{
				for(int j=0;j<tokens;j++)
				{
					if(currPlayer->gotis[i].xCord==player2.gotis[j].xCord &&currPlayer->gotis[i].yCord==player2.gotis[j].yCord && player2.gotis[j].notAtYard==1 && player2.gotis[j].stop!=1)
					{
						cout<<"Player 4 Killed Player 2 "<<endl;
						player2.gotis[j].location=-1;
						player2.gotis[j].notAtYard=0;
						player2.gotis[j].xCord=6;
						currPlayer->hitRate++;
						player2.gotis[j].atHome=0;
						player2.gotis[j].yCord=13;
					}
					if(currPlayer->gotis[i].xCord==player1.gotis[j].xCord && currPlayer->gotis[i].yCord==player1.gotis[j].yCord  && player1.gotis[j].notAtYard==1 &&player1.gotis[j].stop!=1)
					{
						cout<<"Player 4 Killed Player 1 "<<endl;
						player1.gotis[j].location=-1;
						currPlayer->hitRate++;
						player1.gotis[j].atHome=0;
						player1.gotis[j].notAtYard=0;
						player1.gotis[j].xCord=1;
						player1.gotis[j].yCord=6;
					}
					if(currPlayer->gotis[i].xCord==player3.gotis[j].xCord && currPlayer->gotis[i].yCord==player3.gotis[j].yCord && player3.gotis[j].notAtYard==1 && player3.gotis[j].stop!=1)
					{
						cout<<"Player 4 Killed Player 3 "<<endl;
						player3.gotis[j].location=-1;
						currPlayer->hitRate++;
						player3.gotis[j].notAtYard=0;
						player3.gotis[j].atHome=0;
						player3.gotis[j].xCord=8;
						player3.gotis[j].yCord=1;
					}
				}
			}
		}
		sem_post(&sem_board);
	}
pthread_exit(NULL);
}





#endif