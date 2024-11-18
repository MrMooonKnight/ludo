#ifndef  GRID_H
#define GRID_H


// calculate the new coordinates of teh tokens after moving a token in threadplayer.
// new coordinates are calculated using the location attribute of the token
void calculateCoordinates(int distance,token *t)
{
	int attr;

    //checking players tokens
	if (t->sym=='T')
	{
		attr=1;
	}
	else if (t->sym=='G')
	{
		attr=2;
	} 
	else if (t->sym=='S')
	{
		attr=3;
	} 
	else if (t->sym=='U')
	{
		attr=4;
	} 
	
	for (int i = 0; i < distance; i++)
	{
		sem_init(&sem_master,0,1);
        //ceating master thread
		pthread_create(&tid3,NULL,&MasterThread,&attr);
		pthread_join(tid3,NULL);
		t->location++;
        // checking if the token is not at home
        // assigning respective values if not at home
		if(!t->atHome)
		{			
			if(t->yCord>9&&t->xCord==6){
				t->yCord--;
			}
			else if(t->yCord==9&&t->xCord==6){
				t->yCord=8;
				t->xCord=5;
			}
			else if(t->yCord==8&&t->xCord>0&&t->xCord<=5){	
				t->xCord--;
			}
			else if (t->xCord==0&&t->yCord>6)
			{
				t->yCord--;
			}
			else if(t->yCord==6&&t->xCord<5){
				t->xCord++;
			}
			else if(t->xCord==5&&t->yCord==6){
				t->yCord=5;
				t->xCord=6;
			}
			else if(t->yCord>0&&t->xCord==6){
				t->yCord--;
			}
			else if(t->yCord==0&&t->xCord<8){
				t->xCord++;
			}
			else if(t->yCord<5&&t->xCord==8){
				t->yCord++;
			}
			else if(t->xCord==8&&t->yCord==5){
				t->yCord=6;
				t->xCord=9;
			}
			else if(t->xCord<14&&t->yCord==6){
				t->xCord++;
			}
			else if(t->xCord==14&&t->yCord<8){
				t->yCord++;
			}
			else if(t->xCord>9&&t->yCord==8){
				t->xCord--;
			}
			else if(t->xCord==9 && t->yCord==8)
			{
				t->yCord=9;
				t->xCord=8;
			}
			else if(t->xCord==8&&t->yCord<14 ){
				t->yCord++;
			}
			else if(t->xCord>6&&t->yCord==14 ){
				t->xCord--;
			}
			if(t->location>51){
				t->location=(t->location%52);
			}
		}
		else
		{
			if (t->sym=='T')
			{
				t->xCord++;
			}
			else if (t->sym=='S')
			{
				t->yCord++;
			}
			else if (t->sym=='G')
			{
				t->yCord--;
			}
			else if (t->sym=='U')
			{
				t->xCord--;
			}
				
		}
	}
}



// draw the board
void drawBoard(){

    system("clear");
    header();
    // cout << endl << endl;

    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
                
            // grid for four tokens     
			if(tokens==4)
			{
			if(i==4&&j==1&&!player1.gotis[0].notAtYard)
				whiteBox("T");
            else if(i==4&&j==4&&!player1.gotis[1].notAtYard)
				whiteBox("T");
            else if(i==1&&j==4&&!player1.gotis[2].notAtYard)
				whiteBox("T");
            else if(i==1&&j==1&&!player1.gotis[3].notAtYard)
				whiteBox("T");
			else if(i==10&&j==1&&!player2.gotis[0].notAtYard)
				whiteBox("G");
            else if(i==10&&j==4&&!player2.gotis[1].notAtYard)
				whiteBox("G");
            else if(i==13&&j==1&&!player2.gotis[2].notAtYard)
				whiteBox("G");
            else if(i==13&&j==4&&!player2.gotis[3].notAtYard)
				whiteBox("G");
			else if(i==1&&j==10&&!player3.gotis[0].notAtYard)
				whiteBox("S");
            else if(i==1&&j==13&&!player3.gotis[1].notAtYard)
				whiteBox("S");
            else if(i==4&&j==10&&!player3.gotis[2].notAtYard)
				whiteBox("S");
            else if(i==4&&j==13&&!player3.gotis[3].notAtYard)
				whiteBox("S");
			else if(i==10&&j==10&&!player4.gotis[0].notAtYard)
				whiteBox("U");
            else if(i==10&&j==13&&!player4.gotis[1].notAtYard)
				whiteBox("U");
            else if(i==13&&j==10&&!player4.gotis[2].notAtYard)
				whiteBox("U");
            else if(i==13&&j==13&&!player4.gotis[3].notAtYard)
				whiteBox("U");	
            else if(i == player1.gotis[0].yCord && j == player1.gotis[0].xCord&&player1.gotis[0].notAtYard)
                whiteBoxL("T");
            else if(i==player1.gotis[1].yCord&&j==player1.gotis[1].xCord&&player1.gotis[1].notAtYard)
                whiteBoxL("T");
            else if(i==player1.gotis[2].yCord&&j==player1.gotis[2].xCord&&player1.gotis[2].notAtYard)
                whiteBoxL("T");
            else if(i==player1.gotis[3].yCord&&j==player1.gotis[3].xCord&&player1.gotis[3].notAtYard)
                whiteBoxL("T");
			else if(i==player2.gotis[0].yCord&&j==player2.gotis[0].xCord&&player2.gotis[0].notAtYard)
                whiteBoxL("G");
            else if(i==player2.gotis[1].yCord&&j==player2.gotis[1].xCord&&player2.gotis[1].notAtYard)
                whiteBoxL("G");
            else if(i==player2.gotis[2].yCord&&j==player2.gotis[2].xCord&&player2.gotis[2].notAtYard)
                whiteBoxL("G");
            else if(i==player2.gotis[3].yCord&&j==player2.gotis[3].xCord&&player2.gotis[3].notAtYard)
                whiteBoxL("G");
            else if(i==player3.gotis[0].yCord&&j==player3.gotis[0].xCord&&player3.gotis[0].notAtYard)
                whiteBoxL("S");
            else if(i==player3.gotis[1].yCord&&j==player3.gotis[1].xCord&&player3.gotis[1].notAtYard)
                whiteBoxL("S");
            else if(i==player3.gotis[2].yCord&&j==player3.gotis[2].xCord&&player3.gotis[2].notAtYard)
                whiteBoxL("S");
            else if(i==player3.gotis[3].yCord&&j==player3.gotis[3].xCord&&player3.gotis[3].notAtYard)
                whiteBoxL("S");
			else if(i==player4.gotis[0].yCord&&j==player4.gotis[0].xCord&&player4.gotis[0].notAtYard)
                whiteBoxL("U");
            else if(i==player4.gotis[1].yCord&&j==player4.gotis[1].xCord&&player4.gotis[1].notAtYard)
                whiteBoxL("U");
            else if(i==player4.gotis[2].yCord&&j==player4.gotis[2].xCord&&player4.gotis[2].notAtYard)
                whiteBoxL("U");
            else if(i==player4.gotis[3].yCord&&j==player4.gotis[3].xCord&&player4.gotis[3].notAtYard)
                whiteBoxL("U");



			else if(j<5&&i<5)
                whiteBox();
			else if(j<6&&i==5)
				redBox();
			else if(j==5&&i<6)
				redBox();
            else if(j<5&&i>9)
                whiteBox();
			else if(j<6&&i==9)
                blueBox();
			else if(j==5&&i>8)
                blueBox();
            else if(j>9&&i<5)
                whiteBox();
			else if(j>8&&i==5)
                greenBox();
			else if(j==9&&i<6)
                greenBox();
            else if(j>9&&i>9)
                whiteBox();
            else if(j>8&&i==9)
                yellowBox();
            else if(j==9&&i>8)
                yellowBox();
            else if(j==1&&i==6)
                redBoxL();
            else if(j==2&&i==8)
                redBoxL();
            else if(i==7&&j>0&&j<6)
                redBoxL();
            else if(j==6&&i==2)
                greenBoxL();
            else if(j==8&&i==1)
                greenBoxL();
            else if(j==7&&i>0&&i<6)
                greenBoxL();
            else if(j==6&&i==13)
                blueBoxL();
            else if(j==8&&i==12)
                blueBoxL();
            else if(j==7&&i>8&&i<14)
                blueBoxL();
            else if(j==13&&i==8)
                yellowBoxL();
            else if(j==12&&i==6)
                yellowBoxL();
            else if(i==7&&j>8&&j<14)
                yellowBoxL();
            else if(i == 6 && (j == 6 || j == 7 || j ==8))
            	greenBoxL();
            else if(i == 7 && j == 6)
            	redBoxL();
            else if(i == 7&& j == 7)
            	whiteBoxL();
            else if(i == 7 && j == 8)
            	yellowBoxL();

            else if(i == 8 && (j == 6 || j == 7 || j ==8))
            	blueBoxL();
            else
                whiteBoxL();  	

			}
			
            //grid for 3 tokens
			else if(tokens==3)
			{
				if(i==4&&j==1&&!player1.gotis[0].notAtYard)
				whiteBox("T");
            else if(i==4&&j==4&&!player1.gotis[1].notAtYard)
				whiteBox("T");
            else if(i==1&&j==4&&!player1.gotis[2].notAtYard)
				whiteBox("T");
			else if(i==10&&j==1&&!player2.gotis[0].notAtYard)
				whiteBox("G");
            else if(i==10&&j==4&&!player2.gotis[1].notAtYard)
				whiteBox("G");
            else if(i==13&&j==1&&!player2.gotis[2].notAtYard)
				whiteBox("G");
        
			else if(i==1&&j==10&&!player3.gotis[0].notAtYard)
				whiteBox("S");
            else if(i==1&&j==13&&!player3.gotis[1].notAtYard)
				whiteBox("S");
            else if(i==4&&j==10&&!player3.gotis[2].notAtYard)
				whiteBox("S");
           
			else if(i==10&&j==10&&!player4.gotis[0].notAtYard)
				whiteBox("U");
            else if(i==10&&j==13&&!player4.gotis[1].notAtYard)
				whiteBox("U");
            else if(i==13&&j==10&&!player4.gotis[2].notAtYard)
				whiteBox("U");
        
            else if(i==player1.gotis[0].yCord&&j==player1.gotis[0].xCord&&player1.gotis[0].notAtYard)
                whiteBoxL("T");
            else if(i==player1.gotis[1].yCord&&j==player1.gotis[1].xCord&&player1.gotis[1].notAtYard)
                whiteBoxL("T");
            else if(i==player1.gotis[2].yCord&&j==player1.gotis[2].xCord&&player1.gotis[2].notAtYard)
                whiteBoxL("T");
            
			else if(i==player2.gotis[0].yCord&&j==player2.gotis[0].xCord&&player2.gotis[0].notAtYard)
                whiteBoxL("G");
            else if(i==player2.gotis[1].yCord&&j==player2.gotis[1].xCord&&player2.gotis[1].notAtYard)
                whiteBoxL("G");
            else if(i==player2.gotis[2].yCord&&j==player2.gotis[2].xCord&&player2.gotis[2].notAtYard)
                whiteBoxL("G");
            
            else if(i==player3.gotis[0].yCord&&j==player3.gotis[0].xCord&&player3.gotis[0].notAtYard)
                whiteBoxL("S");
            else if(i==player3.gotis[1].yCord&&j==player3.gotis[1].xCord&&player3.gotis[1].notAtYard)
                whiteBoxL("S");
            else if(i==player3.gotis[2].yCord&&j==player3.gotis[2].xCord&&player3.gotis[2].notAtYard)
                whiteBoxL("S");
            
			else if(i==player4.gotis[0].yCord&&j==player4.gotis[0].xCord&&player4.gotis[0].notAtYard)
                whiteBoxL("U");
            else if(i==player4.gotis[1].yCord&&j==player4.gotis[1].xCord&&player4.gotis[1].notAtYard)
                whiteBoxL("U");
            else if(i==player4.gotis[2].yCord&&j==player4.gotis[2].xCord&&player4.gotis[2].notAtYard)
                whiteBoxL("U");


				else if(j<5&&i<5)
                whiteBox();
			else if(j<6&&i==5)
				redBox();
			else if(j==5&&i<6)
				redBox();
            else if(j<5&&i>9)
                whiteBox();
			else if(j<6&&i==9)
                blueBox();
			else if(j==5&&i>8)
                blueBox();
            else if(j>9&&i<5)
                whiteBox();
			else if(j>8&&i==5)
                greenBox();
			else if(j==9&&i<6)
                greenBox();
            else if(j>9&&i>9)
                whiteBox();
            else if(j>8&&i==9)
                yellowBox();
            else if(j==9&&i>8)
                yellowBox();
            else if(j==1&&i==6)
                redBoxL();
            else if(j==2&&i==8)
                redBoxL();
            else if(i==7&&j>0&&j<6)
                redBoxL();
            else if(j==6&&i==2)
                greenBoxL();
            else if(j==8&&i==1)
                greenBoxL();
            else if(j==7&&i>0&&i<6)
                greenBoxL();
            else if(j==6&&i==13)
                blueBoxL();
            else if(j==8&&i==12)
                blueBoxL();
            else if(j==7&&i>8&&i<14)
                blueBoxL();
            else if(j==13&&i==8)
                yellowBoxL();
            else if(j==12&&i==6)
                yellowBoxL();
            else if(i==7&&j>8&&j<14)
                yellowBoxL();
             else if(i == 6 && (j == 6 || j == 7 || j ==8))
            	greenBoxL();
            else if(i == 7 && j == 6)
            	redBoxL();
            else if(i == 7&& j == 7)
            	whiteBoxL();
            else if(i == 7 && j == 8)
            	yellowBoxL();

            else if(i == 8 && (j == 6 || j == 7 || j ==8))
            	blueBoxL();
            else
                whiteBoxL();  	
			}
            //grid for 2 tokens
			else if(tokens==2)
			{
				if(i==4&&j==1&&!player1.gotis[0].notAtYard)
				whiteBox("T");
            else if(i==4&&j==4&&!player1.gotis[1].notAtYard)
				whiteBox("T");
            
			else if(i==10&&j==1&&!player2.gotis[0].notAtYard)
				whiteBox("G");
            else if(i==10&&j==4&&!player2.gotis[1].notAtYard)
				whiteBox("G");
            
			else if(i==1&&j==10&&!player3.gotis[0].notAtYard)
				whiteBox("S");
            else if(i==1&&j==13&&!player3.gotis[1].notAtYard)
				whiteBox("S");
            
			else if(i==10&&j==10&&!player4.gotis[0].notAtYard)
				whiteBox("U");
            else if(i==10&&j==13&&!player4.gotis[1].notAtYard)
				whiteBox("U");
           
            else if(i==player1.gotis[0].yCord&&j==player1.gotis[0].xCord&&player1.gotis[0].notAtYard)
                whiteBox("T");
            else if(i==player1.gotis[1].yCord&&j==player1.gotis[1].xCord&&player1.gotis[1].notAtYard)
                whiteBox("T");
            
			else if(i==player2.gotis[0].yCord&&j==player2.gotis[0].xCord&&player2.gotis[0].notAtYard)
                whiteBoxL("G");
            else if(i==player2.gotis[1].yCord&&j==player2.gotis[1].xCord&&player2.gotis[1].notAtYard)
                whiteBoxL("G");
            
            else if(i==player3.gotis[0].yCord&&j==player3.gotis[0].xCord&&player3.gotis[0].notAtYard)
                whiteBoxL("S");
            else if(i==player3.gotis[1].yCord&&j==player3.gotis[1].xCord&&player3.gotis[1].notAtYard)
                whiteBoxL("S");
			else if(i==player4.gotis[0].yCord&&j==player4.gotis[0].xCord&&player4.gotis[0].notAtYard)
                whiteBoxL("U");
            else if(i==player4.gotis[1].yCord&&j==player4.gotis[1].xCord&&player4.gotis[1].notAtYard)
                whiteBoxL("U");
				else if(j<5&&i<5)
                whiteBox();
			else if(j<6&&i==5)
				redBox();
			else if(j==5&&i<6)
				redBox();
            else if(j<5&&i>9)
                whiteBox();
			else if(j<6&&i==9)
                blueBox();
			else if(j==5&&i>8)
                blueBox();
            else if(j>9&&i<5)
                whiteBox();
			else if(j>8&&i==5)
                greenBox();
			else if(j==9&&i<6)
                greenBox();
            else if(j>9&&i>9)
                whiteBox();
            else if(j>8&&i==9)
                yellowBox();
            else if(j==9&&i>8)
                yellowBox();
            else if(j==1&&i==6)
                redBoxL();
            else if(j==2&&i==8)
                redBoxL();
            else if(i==7&&j>0&&j<6)
                redBoxL();
            else if(j==6&&i==2)
                greenBoxL();
            else if(j==8&&i==1)
                greenBoxL();
            else if(j==7&&i>0&&i<6)
                greenBoxL();
            else if(j==6&&i==13)
                blueBoxL();
            else if(j==8&&i==12)
                blueBoxL();
            else if(j==7&&i>8&&i<14)
                blueBoxL();
            else if(j==13&&i==8)
                yellowBoxL();
            else if(j==12&&i==6)
                yellowBoxL();
            else if(i==7&&j>8&&j<14)
                yellowBoxL();
             else if(i == 6 && (j == 6 || j == 7 || j ==8))
            	greenBoxL();
            else if(i == 7 && j == 6)
            	redBoxL();
            else if(i == 7&& j == 7)
            	whiteBoxL();
            else if(i == 7 && j == 8)
            	yellowBoxL();
            else if(i == 8 && (j == 6 || j == 7 || j ==8))
            	blueBoxL();
            else
                whiteBoxL();  	
			}






            // grid for 1 token
			else if(tokens==1)
			{
			if(i==4&&j==1&&!player1.gotis[0].notAtYard)
				whiteBox("T");
			else if(i==10&&j==1&&!player2.gotis[0].notAtYard)
				whiteBox("G");
            
			else if(i==1&&j==10&&!player3.gotis[0].notAtYard)
				whiteBox("S");
            
			else if(i==10&&j==10&&!player4.gotis[0].notAtYard)
				whiteBox("U");
            
            else if(i==player1.gotis[0].yCord&&j==player1.gotis[0].xCord&&player1.gotis[0].notAtYard)
                whiteBoxL("T");
           
			else if(i==player2.gotis[0].yCord&&j==player2.gotis[0].xCord&&player2.gotis[0].notAtYard)
                whiteBoxL("G");
           
            else if(i==player3.gotis[0].yCord&&j==player3.gotis[0].xCord&&player3.gotis[0].notAtYard)
                whiteBoxL("S");
            
			else if(i==player4.gotis[0].yCord&&j==player4.gotis[0].xCord&&player4.gotis[0].notAtYard)
                whiteBoxL("U");

				else if(j<5&&i<5)
                whiteBox();
			else if(j<6&&i==5)
				redBox();
			else if(j==5&&i<6)
				redBox();
            else if(j<5&&i>9)
                whiteBox();
			else if(j<6&&i==9)
                blueBox();
			else if(j==5&&i>8)
                blueBox();
            else if(j>9&&i<5)
                whiteBox();
			else if(j>8&&i==5)
                greenBox();
			else if(j==9&&i<6)
                greenBox();
            else if(j>9&&i>9)
                whiteBox();
            else if(j>8&&i==9)
                yellowBox();
            else if(j==9&&i>8)
                yellowBox();
            else if(j==1&&i==6)
                redBoxL();
            else if(j==2&&i==8)
                redBoxL();
            else if(i==7&&j>0&&j<6)
                redBoxL();
            else if(j==6&&i==2)
                greenBoxL();
            else if(j==8&&i==1)
                greenBoxL();
            else if(j==7&&i>0&&i<6)
                greenBoxL();
            else if(j==6&&i==13)
                blueBoxL();
            else if(j==8&&i==12)
                blueBoxL();
            else if(j==7&&i>8&&i<14)
                blueBoxL();
            else if(j==13&&i==8)
                yellowBoxL();
            else if(j==12&&i==6)
                yellowBoxL();
            else if(i==7&&j>8&&j<14)
                yellowBoxL();
             else if(i == 6 && (j == 6 || j == 7 || j ==8))
            	greenBoxL();
            else if(i == 7 && j == 6)
            	redBoxL();
            else if(i == 7&& j == 7)
            	whiteBoxL();
            else if(i == 7 && j == 8)
            	yellowBoxL();
            else if(i == 8 && (j == 6 || j == 7 || j ==8))
            	blueBoxL();
            else
                whiteBoxL();  	
			}
			
				
            
			
        }
        cout << endl;
    }
    disclaimer();
    sleep(2);
}


#endif