#include <windows.h>

#include <time.h>
#include "graphics.h"
#include "setup.h"


int main() // Obviously the main program loop
{
    int Keypress;



//Usual .. Just set up the screen
	SetConsoleSize(79,50);
//	AltEnter();
	TITLE_SCREEN();
	BOOT_UP();
//Start Game
	INIT_BOARD(difficulty, galaxyX, galaxyY);
	ClearScreen();
	HUD();
	UPDATE_ENERGY_LEVELS();
	DRAW_BORD();

		    //  \/--- Bug work around to display command cursor
	    SetConsoleCursor(5,45);
    	printf("									");
    	SetColor(14);
    	SetConsoleCursor(5,45);
    	SetConsoleCursor(5,45);
    	printf("Command :>");

mainlogic:
    	do
    	{
    	   GameTime(1);
	    }

      while(!kbhit());
      {


        Keypress = getch();

      	if ((acceptinput(Keypress) == 1))

                            return 0;

  	 	SetConsoleCursor(5,45);
    	printf("									");
    	SetColor(14);
    	SetConsoleCursor(5,45);
    	printf("Command :>");
    	printf("\a");
      	UPDATE_ENERGY_LEVELS();
      	goto mainlogic;
      	};


}

int acceptinput(int input) //Accepts input from the user and acts upon it
{



	int result,answer, inputstring;
//	int input;
	int x,y;



//	SetConsoleCursor(5,45);
//	 printf("									");
//	SetColor(14);
//	SetConsoleCursor(5,45);
//    printf("Command :>");
//	printf("\a");
//    input = getch();

	switch((input))
	{

	case 117:
	    UpgradeEnterprise();
	    return 0;
	case 27:

	  return 1;

	case 101: // End Turn
	  END_TURN();
	  return 0;

	case 96: // Switch Fullscreen mode
	  AltEnter();
	  return 0;

	case 99: // Captians Log
	CaptiansLog();
		return 0;

	case 109: // Move Enterprise

			SetConsoleCursor(5,45);
			printf("                              ");
			SetConsoleCursor(5,45);
			printf("SULU: Which X Coaridnate?:>");
			x = getch();
			x = (x - 48);
			SetConsoleCursor(5,45);
			printf("SULU: Which Y Coaridnate?:>");
			y = getch();
			y = (y - 48);
			SetConsoleCursor(5,45);
			printf("                                 ");

			move_enterprise(x,y);

			UPDATE_ENERGY_LEVELS();

        return 0;

	  case 102:
		  fireat();
		  return 0;

	  case 83:
		  ClearNRedraw();
		  return 0;

	  case 98:
		 BuyItems();
		 return 0;

	case 119:
		DrawGalaxyMap(1);
		return 0;

		case 115:

		SetConsoleCursor(5,45);
			printf("                              ");
			SetConsoleCursor(5,45);
			printf("SPOCK: Scan X Coaridnate?:>");
			x= getch();
			x = (x - 48);
			SetConsoleCursor(5,45);
			printf("SPOCK: Scan Y Coaridnate?:>");
			y = getch();
			y = (y - 48);
			SetConsoleCursor(5,45);
			printf("                                 ");

			if(gameboard[x][y].contains == 0)
			{

				ScrollLog("SPOCK: Empty Space");

			}
			if(gameboard[x][y].contains == 1)
			{

				ScrollLog("SPOCK: The Enterprise(NCC171-D) @ ");
				printf("X:%i Y:%i",x,y);

			}
			if(gameboard[x][y].contains == 2) //klingon
			{
				int tag;
				tag = gameboard[x][y].enemytag;

				ScrollLog("SPOCK:	");
				printf("Klingon(%i) X:%i Y:%i  SHLDS:%i HULL:%i PHSR:%i",gameboard[x][y].enemytag,klingon[tag].x,klingon[tag].y,klingon[tag].shields,klingon[tag].hull,klingon[tag].phaser);


			}
			if(gameboard[x][y].contains == 3) //planet
			{
			ScrollLog("SPOCK: A Planet");

			}
			if(gameboard[x][y].contains == 4) //starbase
			{
				ScrollLog("SPOCK: A StarBase");


			}
			return 0;


		case 105:
			SetConsoleCursor(5,45);
			printf("                              ");
			SetConsoleCursor(5,45);



					if ((enterprise[0].energy < 9))
					{
						printf("SCOTTY: Divert (0 - %i) power to Impulse?:>",enterprise[0].energy);

					}
					else
					{
						printf("SCOTTY: Divert (0 - 9) power to Impulse?:>");
					}

			answer=getch();
			answer = answer - 48;
			if ((enterprise[0].energy < answer))
			{
				ScrollLog("SCOTTY: Not enough energy...");
				return 0;
			}
			else
			{
			enterprise[0].energy = enterprise[0].energy - answer;
			enterprise[0].impulse = enterprise[0].impulse + answer;
			}
			SetConsoleCursor(5,45);
			return 0;

		case 112:
			SetConsoleCursor(5,45);
			printf("                              ");
			SetConsoleCursor(5,45);



					if ((enterprise[0].energy < 9))
					{
						printf("SCOTTY: Divert (0 - %i) power to Phaser?:>",enterprise[0].energy);

					}
					else
					{
						printf("SCOTTY: Divert (0 - 9) power to Phaser?:>");
					}

			answer=getch();
			answer = answer - 48;
			if ((enterprise[0].energy < answer))
			{
				ScrollLog("SCOTTY: Not enough energy...");
				return 0;
			}
			else
			{
			enterprise[0].energy = enterprise[0].energy - answer;
			enterprise[0].phaser = enterprise[0].phaser + answer;

			}
			SetConsoleCursor(5,45);
			return 0;

		case 104:
			SetConsoleCursor(5,45);
			printf("                              ");
			SetConsoleCursor(5,45);

					if ((enterprise[0].energy < 9))
					{
						printf("SCOTTY: Divert (0 - %i) power to Shields?:>",enterprise[0].energy);

					}
					else
					{
						printf("SCOTTY: Divert (0 - 9) power to Shields?:>");
					}

			answer=getch();
			answer = answer - 48;
			if ((enterprise[0].energy < answer))
			{
				ScrollLog("SCOTTY: Not enough energy...");
				return 0;
			}
			else
			{
			enterprise[0].energy = enterprise[0].energy - answer;
			enterprise[0].shields = enterprise[0].shields + answer;
			}
			SetConsoleCursor(5,45);
			return 0;

	 default:
	  return 0;


	}



	return 0;
}

void TITLE_SCREEN() // Kinda Speeks for itself
{
	int x,a,b;
	int locationx, locationy; //Random Location of stars on title

	srand ( time(NULL) );

	for (a=0;a<370;a++)
	{
	   locationx = rand() %90;
       locationy = rand() %50;

              if ((b <2))
              {
              SetColor(10);
              b++;
              SetConsoleCursor(locationx,locationy);
              printf(".");
              }
              else
              {
                  SetColor(14);
                 b =0;
                  SetConsoleCursor(locationx,locationy);
                  printf("ú");
              }



	}

    SetColor(8);
	DrawBox(10,9,60,10,0);
	SetConsoleCursor(20,15);
	SetColor(2);
	printf("--- ========    STAR TREK    =========== ---");
	SetConsoleCursor(30,25);
	printf("By Markian Rutkowskyj");
	    time_t timer;

	    timer=time(NULL);
	    SetConsoleCursor(17,30);
	    SetColor(6);
	    printf("Current StarDate: %s\n",asctime(localtime(&timer)));

	//while(!kbhit());
	printf("                              ");
	SetConsoleCursor(5,45);
	SetColor(2);
	printf("Game Difficulty ( 1 - 9 ) ?:>");
	x = getch();
	difficulty = (x - 48);

}

void DOCK()
{

}

void END_TURN()
{

	int a = 0, foundenterprise = 0, damage;



	/*----------Look for enterprise--------------------------------*/
	for(a=0; a<galaxy[galaxyX][galaxyY].klingons;a++)
	{
		if ((klingon[a].hull > 0))
		{

			if ((gameboard[klingon[a].x-1][klingon[a].y].contains == 1))
			{
				foundenterprise =1;
				DrawFireAnim(enterprise[0].x,enterprise[0].y,klingon[a].x,klingon[a].y,0);
			}

			if ((gameboard[klingon[a].x-1][klingon[a].y-1].contains == 1))
			{
				foundenterprise =1;
				DrawFireAnim(enterprise[0].x,enterprise[0].y,klingon[a].x,klingon[a].y,0);
			}
			if ((gameboard[klingon[a].x][klingon[a].y-1].contains == 1))
			{
				foundenterprise =1;
				DrawFireAnim(enterprise[0].x,enterprise[0].y,klingon[a].x,klingon[a].y,0);
			}
			if ((gameboard[klingon[a].x+1][klingon[a].y-1].contains == 1))
			{
				foundenterprise =1;
				DrawFireAnim(enterprise[0].x,enterprise[0].y,klingon[a].x,klingon[a].y,0);
			}
			if ((gameboard[klingon[a].x+1][klingon[a].y].contains == 1))
			{
				foundenterprise =1;
				DrawFireAnim(enterprise[0].x,enterprise[0].y,klingon[a].x,klingon[a].y,0);
			}
			if ((gameboard[klingon[a].x+1][klingon[a].y+1].contains == 1))
			{
				foundenterprise =1;
				DrawFireAnim(enterprise[0].x,enterprise[0].y,klingon[a].x,klingon[a].y,0);
			}
			if ((gameboard[klingon[a].x][klingon[a].y+1].contains == 1))
			{
				foundenterprise =1;
				DrawFireAnim(enterprise[0].x,enterprise[0].y,klingon[a].x,klingon[a].y,0);
			}
			if ((gameboard[klingon[a].x-1][klingon[a].y+1].contains == 1))
			{
				foundenterprise =1;
				DrawFireAnim(enterprise[0].x,enterprise[0].y,klingon[a].x,klingon[a].y,0);
			}


			if((foundenterprise ==1))
			{

					if ((klingon[a].phaser > difficulty)) // encapsulating if
					{
						damage = rand () % klingon[a].phaser; //Random damage done to enterprise, so to simulate combat
						damage = damage * enterprise[0].shipclass;
						klingon[a].phaser = klingon[a].phaser - damage;
						enterprise[0].shields = enterprise[0].shields - damage;
						ScrollLog("They hit us captain (");
						printf("%i)",damage);
						enterprise[0].damagetaken = enterprise[0].damagetaken + damage;
						if ((damage > enterprise[0].shields))
							enterprise[0].hull = enterprise[0].hull - damage;
							UPDATE_ENERGY_LEVELS();
					foundenterprise = 0;

					}
					else
					{
						if((klingon[a].phaser < (15 - difficulty)))
						{
							klingon[a].phaser = klingon[a].phaser + difficulty;
						}
					}

			}
			else
			{ //Move klingon

				if (((enterprise[0].x < klingon[a].x) && (enterprise[0].y < klingon[a].y) && (gameboard[klingon[a].x-1][klingon[a].y-1].contains <1)))
				{

					gameboard[klingon[a].x][klingon[a].y].contains = 0;
					gameboard[klingon[a].x][klingon[a].y].enemytag = 99; // i forget what the 99 is for.. i get the feeling that its depriceiated
					klingon[a].x = klingon[a].x -1;
					klingon[a].y = klingon[a].y - 1;
					gameboard[klingon[a].x][klingon[a].y].contains = 2;
					gameboard[klingon[a].x][klingon[a].y].enemytag = a;
				}else if (((enterprise[0].x == klingon[a].x) && (enterprise[0].y < klingon[a].y) && (gameboard[klingon[a].x][klingon[a].y-1].contains <1)))
				{

					gameboard[klingon[a].x][klingon[a].y].contains = 0;
					gameboard[klingon[a].x][klingon[a].y].enemytag = 99;
					klingon[a].x = klingon[a].x;
					klingon[a].y = klingon[a].y - 1;
					gameboard[klingon[a].x][klingon[a].y].contains = 2;
					gameboard[klingon[a].x][klingon[a].y].enemytag = a;
				}else if (((enterprise[0].x > klingon[a].x) && (enterprise[0].y < klingon[a].y) && (gameboard[klingon[a].x+1][klingon[a].y-1].contains <1)))
				{

					gameboard[klingon[a].x][klingon[a].y].contains = 0;
					gameboard[klingon[a].x][klingon[a].y].enemytag = 99;
					klingon[a].x = klingon[a].x + 1;
					klingon[a].y = klingon[a].y - 1;
					gameboard[klingon[a].x][klingon[a].y].contains = 2;
					gameboard[klingon[a].x][klingon[a].y].enemytag = a;
				}else if (((enterprise[0].x > klingon[a].x) && (enterprise[0].y == klingon[a].y) && (gameboard[klingon[a].x+1][klingon[a].y].contains <1)))
				{

					gameboard[klingon[a].x][klingon[a].y].contains = 0;
					gameboard[klingon[a].x][klingon[a].y].enemytag = 99;
					klingon[a].x = klingon[a].x + 1;
					klingon[a].y = klingon[a].y;
					gameboard[klingon[a].x][klingon[a].y].contains = 2;
					gameboard[klingon[a].x][klingon[a].y].enemytag = a;
				}else if (((enterprise[0].x > klingon[a].x) && (enterprise[0].y > klingon[a].y) && (gameboard[klingon[a].x+1][klingon[a].y+1].contains < 1)))
				{

					gameboard[klingon[a].x][klingon[a].y].contains = 0;
					gameboard[klingon[a].x][klingon[a].y].enemytag = 99;
					klingon[a].x = klingon[a].x + 1;
					klingon[a].y = klingon[a].y + 1;
					gameboard[klingon[a].x][klingon[a].y].contains = 2;
					gameboard[klingon[a].x][klingon[a].y].enemytag = a;
				}else if (((enterprise[0].x == klingon[a].x) && (enterprise[0].y > klingon[a].y) && (gameboard[klingon[a].x][klingon[a].y+1].contains < 1)))
				{

					gameboard[klingon[a].x][klingon[a].y].contains = 0;
					gameboard[klingon[a].x][klingon[a].y].enemytag = 99;
					klingon[a].x = klingon[a].x;
					klingon[a].y = klingon[a].y + 1;
					gameboard[klingon[a].x][klingon[a].y].contains = 2;
					gameboard[klingon[a].x][klingon[a].y].enemytag = a;
				}else if (((enterprise[0].x < klingon[a].x) && (enterprise[0].y > klingon[a].y) && (gameboard[klingon[a].x-1][klingon[a].y+1].contains < 1)))
				{

					gameboard[klingon[a].x][klingon[a].y].contains = 0;
					gameboard[klingon[a].x][klingon[a].y].enemytag = 99;
					klingon[a].x = klingon[a].x - 1;
					klingon[a].y = klingon[a].y + 1;
					gameboard[klingon[a].x][klingon[a].y].contains = 2;
					gameboard[klingon[a].x][klingon[a].y].enemytag = a;
				}else if (((enterprise[0].x < klingon[a].x) && (enterprise[0].y == klingon[a].y) && (gameboard[klingon[a].x-1][klingon[a].y].contains < 1)))
				{

					gameboard[klingon[a].x][klingon[a].y].contains = 0;
					gameboard[klingon[a].x][klingon[a].y].enemytag = 99;
					klingon[a].x = klingon[a].x - 1;
					klingon[a].y = klingon[a].y;
					gameboard[klingon[a].x][klingon[a].y].contains = 2;
					gameboard[klingon[a].x][klingon[a].y].enemytag = a;
				}

				DRAW_BORD();
			}



		}

	}

	///////------------Enterprise Update------------------------------------------------------------------/


		enterprise[0].experience = (enterprise[0].kills * 40) + (enterprise[0].tfired * 5) + ((enterprise[0].damagetaken / 0.5) + (enterprise[0].damagecaused * 0.5) * 2) + (enterprise[0].sbvisited * 20) + (enterprise[0].glTraveled * 25);

	//-----------------------------------------------------------------------//
		if((enterprise[0].shields < (16 - enterprise[0].warpcoil)))
		enterprise[0].shields = enterprise[0].shields + enterprise[0].warpcoil;

		if((enterprise[0].phaser < (16 - enterprise[0].warpcoil)))
		enterprise[0].phaser = enterprise[0].phaser + enterprise[0].warpcoil;

		if((enterprise[0].impulse < (16 - enterprise[0].warpcoil)))
		enterprise[0].impulse = enterprise[0].impulse + enterprise[0].warpcoil;


		//----------------------------------------------------------------------------//

/*
		if ((enterprise[0].energy > 15 * enterprise[0].shipclass))
					enterprise[0].energy =15 * enterprise[0].shipclass;

		if ((enterprise[0].shields > 15 * enterprise[0].shipclass))
			enterprise[0].shields =15 * enterprise[0].shipclass;

		if ((enterprise[0].impulse > 15 * enterprise[0].shipclass))
			enterprise[0].impulse =15 * enterprise[0].shipclass;

		if ((enterprise[0].phaser > 15 * enterprise[0].shipclass))
			enterprise[0].phaser =15 * enterprise[0].shipclass;


		if((enterprise[0].energy < ((15 * enterprise[0].shipclass) - enterprise[0].warpcoil)))
		enterprise[0].energy = enterprise[0].energy + enterprise[0].warpcoil;

*/
		//-------------------------------------------------------------------------------------------------

		if ((docked ==1))
		{
					if((enterprise[0].energy < ((15 * enterprise[0].shipclass) - enterprise[0].warpcoil)))
					{
					enterprise[0].energy = enterprise[0].energy + starbase[0].coil;
					SetColor(4);
					SetConsoleCursor(72,7);
					printf("%i ", (enterprise[0].warpcoil + starbase[0].coil));
					}
		}

		if ((enterprise[0].hull < 0))
		{
		   DrawDeathAnim(enterprise[0].x, enterprise[0].y);
		   ClearScreen();
		   printf("You are dead");

        }

}

void fireat()
{
	int x,y,weapon, tag, damage, strength;

	if ((enterprise[0].phaser == 0 && enterprise[0].photons == 0 ))
	{
			SetConsoleCursor(5,45);
			printf("SULU: Unable to fire .. Divert power or END turn!");
			getch();
			return;
	}


			DrawRangeFinder(enterprise[0].x,enterprise[0].y);
			SetConsoleCursor(5,45);
			printf("                              ");
			SetConsoleCursor(5,45);
			printf("SULU: Which X Coaridnate?:>");
			x = getch();
			x = (x - 48);

			SetConsoleCursor(5,45);
			printf("SULU: Which Y Coaridnate?:>");
			y = getch();
			y = (y - 48);


			SetConsoleCursor(5,45);
			if ((enterprise[0].photons > 0 ))
			{
				printf("SULU: Phasers( 0 )  or Photon Torpedos( 1 ) ?:>");
				weapon = getch();
				weapon = (weapon - 48);
				SetConsoleCursor(5,45);
				printf("                                                 ");
			}
			else
			{
				weapon = 0;
			}

			if ((weapon == 0))
			{
					SetConsoleCursor(5,45);
					if ((enterprise[0].phaser < 9))
					{
						printf("SULU: Phaser strength? ( 1  - %i ) :>",enterprise[0].phaser);

					}
					else
					{
					printf("SULU: Phaser strength? ( 1  - 9 ) :>");
					}

					strength = getch();
					strength = (strength - 48);

			}
			else
			{
				enterprise[0].photons --;
				enterprise[0].tfired ++;
				strength = 0;
			}

			SetConsoleCursor(5,45);
			printf("                                                 ");

		/*--------------- Location logic--------------------------------------*/


		if (x > (enterprise[0].x - 2))
		{
			if (x < (enterprise[0].x +2))
			{
				if (y > (enterprise[0].y - 2))
				{
					if (y < (enterprise[0].y + 2))
					{
						//finaly.. i think we got there!

					/*---------------------------------------------------------------------*/

						if(gameboard[x][y].contains == 2) //klingon
						{
						if ((strength > (enterprise[0].phaser)))
						{


							strength = enterprise[0].phaser;



						}
						else
						{
						enterprise[0].phaser = enterprise[0].phaser - strength;
							if ((enterprise[0].phaser < 0))
								enterprise[0].phaser =0;
						}
						fired = 1;
						UPDATE_ENERGY_LEVELS();
						DrawFireAnim(x,y,enterprise[0].x,enterprise[0].y,weapon);
						damage = CALCULATE_DAMAGE(weapon,strength);
						SetColor(3);
						ScrollLog("CHECKOV: We got them! They took");

						printf(" (%i) damage",damage);
						enterprise[0].damagecaused = enterprise[0].damagecaused + damage;
                        ScrollLog("                                        ");
						tag = gameboard[x][y].enemytag;
					/*--------------------------------------------------------------------------*/

						 if(( (klingon[tag].shields > 0) && damage < klingon[tag].shields))
						 {
							klingon[tag].shields = klingon[tag].shields - damage;
							return;
						 }

						 if(( (klingon[tag].shields > 0) && damage >= klingon[tag].shields))
						 {
							klingon[tag].shields = 0;
							ScrollLog("CHECKOV: Their SHIELDS are down!\n");

							return;

						}



						 if (((klingon[tag].shields == 0) && (damage < klingon[tag].hull)))
						 {
							 klingon[tag].hull = klingon[tag].hull - damage;
							 return;
						 }

						 if (((klingon[tag].shields == 0) && (damage >= klingon[tag].hull)))
						 {
							gameboard[x][y].contains = 0;
							klingon[tag].hull = 0;
							enterprise[0].kills++;
							DrawDeathAnim(klingon[tag].x,klingon[tag].y);
							ScrollLog("CHECKOV: We killed them ");
							printf("(%i)!", enterprise[0].kills);
							enterprise[0].score = enterprise[0].score + (difficulty *20);
							DRAW_BORD();
							galaxy[galaxyX][galaxyY].klingons --;
							if ((galaxy[galaxyX][galaxyY].klingons == 0))
							{
								DrawGalaxyMap(1);
								enterprise[0].score = enterprise[0].score + 250;
							}
							return;
						 }

			/*			 if (((klingon[tag].shields == 0) && (damage > klingon[tag].hull)))
						 {
							gameboard[x][y].contains = 0;
							klingon[tag].hull = 0;
							enterprise[0].kills++;
							ScrollLog("CHECKOV: We killed them ");
							printf("(%i)!", enterprise[0].kills);
							enterprise[0].score = enterprise[0].score + (difficulty *20);
							DRAW_BORD();

							if ((enterprise[0].kills == galaxy[galaxyX][galaxyY].klingons))
								ScrollLog("You WIN!!!!!");

							return;
						 }
				*/
						}
					/*-----------------------------------------------------------------------*/

					}


				}

			}
		}


	}

void DrawRangeFinder(int myX, int myY)
{
	int plotx, ploty, counter;
	plotx = (myX *2 + 10);
	ploty = (myY *2 + 7);
	SetColor(2);

	if ((myX >1))
	{
	SetConsoleCursor(plotx-2,ploty);
	printf("%s",piecetype[gameboard[myX-1][myY].contains]);//left
	}

	if((myX > 0 && myY < 9))
	{
	SetConsoleCursor(plotx-2,ploty+2);
	printf("%s",piecetype[gameboard[myX-1][myY+1].contains]);//bottom left
	}

	if((myX > 0 && myY > 0))
	{
	SetConsoleCursor(plotx-2,ploty-2);
	printf("%s",piecetype[gameboard[myX-1][myY-1].contains]); //top left
	}

	if ((myY > 0))
	{
	SetConsoleCursor(plotx,ploty-2);
	printf("%s",piecetype[gameboard[myX][myY-1].contains]);//center top
	}

	if ((myX < 9 && myY > 0))
	{
	SetConsoleCursor(plotx+2,ploty-2);
	printf("%s",piecetype[gameboard[myX+1][myY-1].contains]);//top right
	}

	if((myX < 9))
	{
	SetConsoleCursor(plotx+2,ploty);
	printf("%s",piecetype[gameboard[myX+1][myY].contains]);//rigth
	}

	if((myX < 9 && myY < 9))
	{
	SetConsoleCursor(plotx+2,ploty+2);
	printf("%s",piecetype[gameboard[myX+1][myY+1].contains]);//bottom right
	}
	if((myY < 9))
	{
	SetConsoleCursor(plotx,ploty+2);
	printf("%s",piecetype[gameboard[myX][myY+1].contains]);//center bottom
	}





}

void DrawFireAnim(int x,int y,int myX,int myY, int weapon)
{
						// x 10 y 7

						int plotx, ploty, counter; // x and y co ord of where we should draw animation

						plotx = (myX *2 + 10);
						ploty = (myY *2 + 7); // <--- Relative to absolute conversion


						SetColor(2);
						DrawBox(2,2,75,45,0);
						/*------------------ P H O T O N ------- T O R P E D O E S--------*/
						if ((weapon == 1))
						{



							if ((x < myX) && (y < myY))
							{
								for(counter = 0 ; counter < 15 ; counter++)
								{
									SetColor(counter);
									Sleep(100);


									if((counter < 7))
									DrawAt(plotx - 1,ploty - 1,4);// upwards \ //
									if((counter > 6))
									DrawAt(plotx - 2 ,ploty - 2,4);
									SetConsoleCursor(0,0);
								}
								DRAW_BORD();
							}


							if ((x > myX) && (y < myY))
							{
								for(counter = 0 ; counter < 15 ; counter++)
								{
									SetColor(counter);
									Sleep(100);
									if((counter < 7))
									DrawAt((plotx + 1),(ploty - 1),4); // upwards / //
									if((counter > 6))
									DrawAt((plotx + 2),(ploty - 2),4);
									SetConsoleCursor(0,0);
								}
								DRAW_BORD();

							}
							if ((x < myX) && (y == myY))
							{
								for(counter = 0 ; counter < 15 ; counter++)
								{
									SetColor(counter);
									Sleep(100);
									if((counter < 7))
									DrawAt(plotx -1,ploty,4); // left --
									if((counter > 6))
									DrawAt(plotx -2,ploty,4);
									SetConsoleCursor(0,0);
								}
								DRAW_BORD();
							}

							if ((x > myX) && (y == myY))
							{
								for(counter = 0 ; counter < 15 ; counter++)
								{
									SetColor(counter);
									Sleep(100);
									if((counter < 7))
									DrawAt(plotx +1,ploty,4); // right --
									if((counter > 6))
									DrawAt(plotx +2,ploty,4);
									SetConsoleCursor(0,0);
								}
								DRAW_BORD();
							}


						if ((x == myX) && (y < myY))
						{
							for(counter = 0 ; counter < 15 ; counter++)
							{
								SetColor(counter);
								Sleep(100);
								if((counter < 7))
								DrawAt(plotx,ploty -1,4); // upward |
								if((counter > 6))
								DrawAt(plotx,ploty -2,4);
								SetConsoleCursor(0,0);
							}
							DRAW_BORD();
						}

						if ((x == myX) && (y > myY))
						{
							for(counter = 0 ; counter < 15 ; counter++)
							{
								SetColor(counter);
								Sleep(100);
								if((counter < 7))
								DrawAt(plotx,ploty+1,4); // downwards |
								if((counter > 6))
								DrawAt(plotx,ploty+2,4);
								SetConsoleCursor(0,0);
							}
							DRAW_BORD();
						}
						if ((x > myX) && (y > myY))
						{
							for(counter = 0 ; counter < 15 ; counter++)
							{
								SetColor(counter);
                                Sleep(100);
								if((counter < 7))
								DrawAt(plotx +1,ploty+1,4); // downwars \ //
								if((counter > 7))
								DrawAt(plotx +2,ploty+2,4);
								SetConsoleCursor(0,0);
							}
							DRAW_BORD();
						}

						if ((x < myX) && (y > myY))
						{
							for(counter = 0 ; counter < 15 ; counter++)
							{
								SetColor(counter);
								Sleep(100);
								if((counter < 7))
								DrawAt(plotx -1,ploty+1,4); // downwards / //
								if((counter > 7))
								DrawAt(plotx -2,ploty+2,4);
								SetConsoleCursor(0,0);

							}
							DRAW_BORD();
						}

							SetColor(5);
							DrawBox(2,2,75,45,0);
							SetColor(15);

							return;

						}


						/*---------------------P H A S E R-----------------------------------------------*/

						if ((x < myX) && (y < myY))
						{
							for(counter = 0 ; counter < 15 ; counter++)
							{
								SetColor(counter);
								Sleep(60);
								DrawAt(plotx - 1,ploty - 1,92);// upwards \ //
								DrawAt(plotx - 2 ,ploty - 2,92);
								SetConsoleCursor(0,0);
							}
							DRAW_BORD();
						}


						if ((x > myX) && (y < myY))
						{
							for(counter = 0 ; counter < 15 ; counter++)
							{
								SetColor(counter);
								Sleep(60);
								DrawAt((plotx + 1),(ploty - 1),47); // upwards / //
								DrawAt((plotx + 2),(ploty - 2),47);
								SetConsoleCursor(0,0);
							}
							DRAW_BORD();

						}
						if ((x < myX) && (y == myY))
						{
							for(counter = 0 ; counter < 15 ; counter++)
							{
								SetColor(counter);
								Sleep(60);
								DrawAt(plotx -1,ploty,196); // left --
								DrawAt(plotx -2,ploty,196);
								SetConsoleCursor(0,0);
							}
							DRAW_BORD();
						}

						if ((x > myX) && (y == myY))
						{
							for(counter = 0 ; counter < 15 ; counter++)
							{
								SetColor(counter);
								Sleep(60);
								DrawAt(plotx +1,ploty,196); // right --
								DrawAt(plotx +2,ploty,196);
								SetConsoleCursor(0,0);
							}
							DRAW_BORD();
						}


						if ((x == myX) && (y < myY))
						{
							for(counter = 0 ; counter < 15 ; counter++)
							{
								SetColor(counter);
								Sleep(60);
								DrawAt(plotx,ploty -1,124); // upward |
								DrawAt(plotx,ploty -2,124);
								SetConsoleCursor(0,0);
							}
							DRAW_BORD();
						}

						if ((x == myX) && (y > myY))
						{
							for(counter = 0 ; counter < 15 ; counter++)
							{
								SetColor(counter);
								Sleep(60);
								DrawAt(plotx,ploty+1,124); // downwards |
								DrawAt(plotx,ploty+2,124);
								SetConsoleCursor(0,0);
							}
							DRAW_BORD();
						}
						if ((x > myX) && (y > myY))
						{
							for(counter = 0 ; counter < 15 ; counter++)
							{
								SetColor(counter);
								Sleep(60);
								DrawAt(plotx +1,ploty+1,92); // downwars \ //
								DrawAt(plotx +2,ploty+2,92);
								SetConsoleCursor(0,0);
							}
							DRAW_BORD();
						}

						if ((x < myX) && (y > myY))
						{
							for(counter = 0 ; counter < 15 ; counter++)
							{
								SetColor(counter);
								Sleep(60);
								DrawAt(plotx -1,ploty+1,47); // downwards / //
								DrawAt(plotx -2,ploty+2,47);
								SetConsoleCursor(0,0);
							}
							DRAW_BORD();
						}

						SetColor(5);
						DrawBox(2,2,75,45,0);
					SetColor(15);
}

void DrawDeathAnim(int myX, int myY)
{
		myX = (myX *2 + 10);
		myY = (myY *2 + 7);

		int counter = 0;


			SetColor(3);
			Sleep(100);
			DrawAt(myX,myY,88);
			Sleep(100);
			SetColor(2);
			DrawAt(myX,myY,43);
			Sleep(100);
			DrawAt(myX,myY,42);
			Sleep(100);
			SetColor(1);
			DrawAt(myX,myY,176);
			Sleep(100);


}

void DrawWarpAnim()
{
	int a,b, locationx, locationy;

		srand ( time(NULL) );

	for (a=0;a<370;a++)
	{
	   locationx = rand() %90;
       locationy = rand() %50;

              if ((b <2))
              {
              SetColor(10);
              b++;
              SetConsoleCursor(locationx,locationy);
              printf(".");
              }
              else
              {
                  SetColor(14);
                 b =0;
                  SetConsoleCursor(locationx,locationy);
                  printf("ú");
              }



	}


	SetConsoleCursor(18,25);
	printf("          Warping................    ");

	for (a = 1; a < 24; a++)
	{
		SetColor(0);
		DrawBox((25 - a),(25 -a),(a*2)+30,(a*2),1);
//		sleep(15);

	}

		srand ( time(NULL) );

	for (a=0;a<370;a++)
	{
	   locationx = rand() %90;
       locationy = rand() %50;

              if ((b <2))
              {
              SetColor(10);
              b++;
              SetConsoleCursor(locationx,locationy);
              printf(".");
              }
              else
              {
                  SetColor(14);
                 b =0;
                  SetConsoleCursor(locationx,locationy);
                  printf("ú");
              }



	}

	SetConsoleCursor(18,25);
	printf("          Warping................    ");

	for (a = 1; a < 24; a++)
	{
		SetColor(8);
		DrawBox((25 - a),(25 -a),(a*2)+30,(a*2),1);
//		sleep(15);

	}

			srand ( time(NULL) );

	for (a=0;a<370;a++)
	{
	   locationx = rand() %90;
       locationy = rand() %50;

              if ((b <2))
              {
              SetColor(10);
              b++;
              SetConsoleCursor(locationx,locationy);
              printf(".");
              }
              else
              {
                  SetColor(14);
                 b =0;
                  SetConsoleCursor(locationx,locationy);
                  printf("ú");
              }



	}

	for (a = 1; a < 24; a++)
	{
		SetColor(2);
		DrawBox((25 - a),(25 -a),(a*2)+30,(a*2),0);
//		sleep(15);

	}

	SetConsoleCursor(18,25);
	printf("          Warping................    ");

  	srand ( time(NULL) );

	for (a=0;a<370;a++)
	{
	   locationx = rand() %90;
       locationy = rand() %50;

              if ((b <2))
              {
              SetColor(10);
              b++;
              SetConsoleCursor(locationx,locationy);
              printf(".");
              }
              else
              {
                  SetColor(14);
                 b =0;
                  SetConsoleCursor(locationx,locationy);
                  printf("ú");
              }



	}

	SetConsoleCursor(18,25);
	printf("          Warping................    ");
	for (a = 1; a < 24; a++)
	{
		SetColor(8);
		DrawBox((25 - a),(25 -a),(a*2)+30,(a*2),1);
//		sleep(15);
	}
			srand ( time(NULL) );

	for (a=0;a<370;a++)
	{
	   locationx = rand() %90;
       locationy = rand() %50;

              if ((b <2))
              {
              SetColor(10);
              b++;
              SetConsoleCursor(locationx,locationy);
              printf(".");
              }
              else
              {
                  SetColor(14);
                 b =0;
                  SetConsoleCursor(locationx,locationy);
                  printf("ú");
              }



	}
}

int CALCULATE_DAMAGE(int weapon, int strength)
{
	int damage, result, HIGH, LOW;
	LOW = 1;
	result = 1;
	srand ( time(NULL) );

	if (weapon == 0)
	{//Phaser

		return (strength * enterprise[0].shipclass);
	}

	if (weapon == 1)
	{//Photons
		LOW = 3;
		strength = 7;
		damage = strength * 4;
		HIGH = damage;
		result = rand() % (HIGH - LOW ) + LOW;
		return result;
	}
	return 0;
}

int move_enterprise(int x, int y)
{
		if ((x > 9))
			x = 9;
		if ((x < 0))
			x = 0 ;
		if ((y > 9))
			y = 9;
		if ((y < 0 ))
			y = 0;

		int difference, difference1;
		difference = (enterprise[0].x - x);
		difference1 = (difference + (enterprise[0].y - y));

		if ((difference > enterprise[0].impulse))
		{

						ScrollLog("SCOTTY: Insufficiant impulse power ..");

			return 0;

		}
	/*-----------------------------------------------------------------------*/
			if ((gameboard[x][y].contains == 0))
			{
			if ((fired == 1))
			{
					END_TURN();
					fired = 0;
			}
			if((docked == 0))
			{
				gameboard[enterprise[0].x][enterprise[0].y].contains = 0;

			}
			else
			{
				gameboard[enterprise[0].x][enterprise[0].y].contains = 4;
				SetConsoleCursor(46,4);
				printf("                       ");
				SetConsoleCursor(55,21);
				printf("                   ");
				SetConsoleCursor(55,22);
				printf("                   ");
				SetConsoleCursor(57,23);
				printf("                   ");
				SetConsoleCursor(58,24);
				printf("                   ");
				docked = 0;
			}
			gameboard[x][y].contains = 1;
			enterprise[0].x = x;
			enterprise[0].y = y;

				if ((difference1 > 0))
				{
					enterprise[0].impulse = (enterprise[0].impulse - difference1);
				}
				else
				{
				enterprise[0].impulse = (enterprise[0].impulse + difference1);
				};


			ScrollLog("SULU: Enterprise is moving to ");
			printf("(%i,%i)",x,y);

			enterprise[0].x = x;
			enterprise[0].y = y;
			DRAW_BORD();
			END_TURN();
			return 1;
			}
	/*-------------------------------------------------------------------------------*/
			if(gameboard[x][y].contains == 2)
			{

				ScrollLog("SULU: Klingon occupies ");
				printf("(%i,%i)", x,y);
				DRAW_BORD();
				return 0;
			}

			if(gameboard[x][y].contains == 3)
			{

				ScrollLog("SULU: A Planet occupies ");
				printf("(%i,%i)", x,y);
				DRAW_BORD();
				return 0;
			}

			if(gameboard[x][y].contains == 4)
			{

				ScrollLog("SULU: Docking with Starbase ");
				printf("(%i,%i)", x,y);

				gameboard[enterprise[0].x][enterprise[0].y].contains = 0;
				gameboard[x][y].contains = 1;
				enterprise[0].x = x;
				enterprise[0].y = y;
				SetColor(0);
				SetConsoleCursor(55,21);
				printf("Photons:%i",(difficulty * 15));
				SetConsoleCursor(55,22);

				SetConsoleCursor(57,23);
				printf("Hull Rep:%i", difficulty * 55);
				SetConsoleCursor(58,24);
				printf("Probes:%i",difficulty * 20);


				SetConsoleCursor(46,4);

				printf(" --== D O C K E D ==-- ");
				if ((galaxy[galaxyX][galaxyY].sbvisited == 0))
				{
					galaxy[galaxyX][galaxyY].sbvisited = 1;
					enterprise[0].sbvisited ++;
				}
				docked = 1;
				DRAW_BORD();
				return 0;
			}








		DRAW_BORD();
		UPDATE_ENERGY_LEVELS();
		return 0;
}

void INIT_BOARD(int difficulty, int x, int y)
{
	int random,a,b;
	int locationx,locationy;
	srand ( time(NULL) );

		for (a=0;a<10;a++) //Clear the board
		{
				for(b=0;b<10;b++)
						{
						gameboard[a][b].contains = 0;

						}
       }

				if ((galaxy[galaxyX][galaxyY].visited == 0))
				{

					enterprise[0].glTraveled ++;
					galaxy[galaxyX][galaxyY].visited = 1;
				}

	for(a=0;a<galaxy[galaxyX][galaxyY].klingons;a++)
	{
		klingon[a].energy = 10;
		klingon[a].hull = 10;
		klingon[a].shields=15;
		klingon[a].phaser=15;
		klingon[a].impulse=15;


	}

		locationx = rand() % 10;
		locationy = rand () % 10;
		gameboard[5][5].contains = 1;//enterprise
		enterprise[0].x = 5;
		enterprise[0].y = 5;
		gameboard[locationx][locationy].contains = 4;//starbase
		starbase[0].x = locationx;
		starbase[0].y = locationy;
		starbase[0].coil = difficulty;

		random = rand () % 20;
		starbase[0].torpedo = random;






	for(a=0;a<difficulty;a++)
	{
		locationx = rand() % 10;
		locationy = rand () % 10;
		if(gameboard[locationx][locationy].contains < 1)
		{
		gameboard[locationx][locationy].contains = 3;
		}
		else
		{
			a--;
		}
	}


	for(a=0;a<galaxy[galaxyX][galaxyY].klingons;a++)
	{

		locationx = rand() % 10;
		locationy = rand () % 10;

		//--- IFFI BUG FIX!! -------------------------------// <-- upon further revision is a good bug fix however this fix needs to be implemented all over the place

		if ((locationx == 0 ))
			locationx = 1;

		if ((locationy == 0))
			locationy = 1;


		if ((locationx > 8))
			locationx = 8;

		if ((locationy > 8))
			locationy = 8;

		//----------------------------------------------------//
		if((gameboard[locationx][locationy].contains < 1))
		{

		gameboard[locationx][locationy].contains = 2;//klingon

		klingon[a].x = locationx;
		klingon[a].y = locationy;
	//	printf("\nKlingon (%i) : LocationX: %i	LocationY: %i",a,locationx, locationy);
	//	sleep(900);
		gameboard[locationx][locationy].enemytag = a;
		}
		else
		{
			a--;
		}
	}

}

void DRAW_BORD()
{
	int a =0, b =0;


		SetColor(15);


		for(a=0;a<19;a++)
		{
			for(b=0;b<19;b++)
			{
			SetConsoleCursor(a+10,b+7);
			printf("ú");
			}
		}

		for(a=0; a<10;a++)
	{
		for(b=0;b<10;b++)
		{
		SetConsoleCursor(10+(a*2),7 + (b*2));
		if ((gameboard[a][b].contains == 3))
			SetColor(7);
		if ((gameboard[a][b].contains == 1))
			SetColor(6);//enterprise
		if ((gameboard[a][b].contains == 4))
			SetColor(3);
		if ((gameboard[a][b].contains == 2))
			SetColor(1);
		if ((gameboard[a][b].contains == 0))
			SetColor(15);

		printf("%s",piecetype[gameboard[a][b].contains]);
		SetColor(15);
		}


	}

}

void BOOT_UP()
{
	int a, b;
	srand ( time(NULL) );




	for (a=0;a<10;a++)
	{
		for(b=0;b<10;b++)
		{
			galaxy[a][b].probed = 0;
			galaxy[a][b].sbvisited = 0;
			galaxy[a][b].visited = 0;
			galaxy[a][b].klingons = rand () % difficulty *2;
			if ((galaxy[a][b].klingons == 0))
				galaxy[a][b].klingons =1;

				TotalKlingons = TotalKlingons + galaxy[a][b].klingons;
		}
	}

	enterprise[0].energy = 30;
	enterprise[0].hull = 30;
	enterprise[0].shields = 30;
	enterprise[0].phaser = 30;
	enterprise[0].impulse = 30;
    enterprise[0].energymax = 30;
	enterprise[0].hullmax = 30;
	enterprise[0].shieldsmax = 30;
	enterprise[0].phasermax = 30;
	enterprise[0].impulsemax = 30;

	enterprise[0].x = 5;
	enterprise[0].y = 5;
	enterprise[0].kills = 0;
	enterprise[0].photons = (7 - difficulty);
	enterprise[0].score=0;
	gameboard[5][5].contains = 1;
	enterprise[0].warpcoil=1;
	enterprise[0].probes = (7 - difficulty);
	enterprise[0].shipclass = 1;


	SetConsoleTitle("STAR TREK - BY MANIC MOSCOW");
}

void HUD()
{
	int a;

	SetColor(5);
	DrawBox(2,2,75,45,0);
	SetColor(8);
	DrawBox(5,40,35,16,1);
	SetColor(10);
	DrawBox(6,9,20,20,1);

	for(a=0; a<10;a++)
	{
		SetConsoleCursor(8,7+(a*2));
		printf("%i",a);
	}

	for(a=0; a<10;a++)
	{
		SetConsoleCursor(30,7+(a*2));
		printf("%i",a);
	}

	for(a=0; a<10;a++)
	{
		SetConsoleCursor(10+(a*2),5);
		printf("%i",a);
	}

	for(a=0; a<10;a++)
	{
		SetConsoleCursor(10+(a*2),27);
		printf("%i",a);
	}
	SetColor(14);
	SetConsoleCursor(43,7);
	printf("AUX POWER:");
	SetConsoleCursor(48,9);
	printf("HULL:");
	SetConsoleCursor(45,11);
	printf("SHIELDS:");
	SetConsoleCursor(42,13);
	printf("PHASER NRG:");
	SetConsoleCursor(41,15);
	printf("IMPULSE NRG:");
	SetConsoleCursor(41,17);
	printf("  PHOTON TORPEDOES:");
	SetConsoleCursor(53,19);
	printf("PROBES:");
	SetConsoleCursor(43,4);
	printf("SCORE:");

}

void ClearNRedraw()
{
	system("cls");
	ClearScreen();
	HUD();
	DRAW_BORD();
	UPDATE_ENERGY_LEVELS();
}

void UPDATE_ENERGY_LEVELS()
{
	int a;

	SetColor(2);
	ProgressBar(53,7,15,enterprise[0].energy, enterprise[0].energymax);
	ProgressBar(53,9,15,enterprise[0].hull, enterprise[0].hullmax);
	ProgressBar(53,11,15,enterprise[0].shields, enterprise[0].shieldsmax);
	ProgressBar(53,13,15,enterprise[0].phaser, enterprise[0].phasermax);
	ProgressBar(53,15,15,enterprise[0].impulse, enterprise[0].impulsemax);

	SetColor(13);



	SetConsoleCursor(69,7);
	printf("%i ", enterprise[0].energy);
	SetConsoleCursor(69,9);
	printf("%i ", enterprise[0].hull);
	SetConsoleCursor(69,11);
	printf("%i ", enterprise[0].shields);
	SetConsoleCursor(69,13);
	printf("%i ", enterprise[0].phaser);
	SetConsoleCursor(69,15);
	printf("%i ", enterprise[0].impulse);
	SetConsoleCursor(60,17);
	printf("           ");
	SetConsoleCursor(60,17);
	for (a =0; a < enterprise[0].photons;a++)
	{
	printf("*");
	}

	SetConsoleCursor(60,19);
	for (a =0; a < enterprise[0].probes;a++)
	{
	printf("*");
	}


	SetConsoleCursor(49,4);
	printf("%i ", enterprise[0].score);

	SetColor(4);
	SetConsoleCursor(72,7);
	printf("%i ", enterprise[0].warpcoil);
	if ((docked ==1))
					if((enterprise[0].energy < (16 - enterprise[0].warpcoil)))
					{
					enterprise[0].energy = enterprise[0].energy + starbase[0].coil;
					SetColor(4);
					SetConsoleCursor(72,7);
					printf("%i ", (enterprise[0].warpcoil + starbase[0].coil));
					}


}

void DrawGalaxyMap(int ask)
{
	int a,b, x,y;

	ClearScreen();
	SetColor(3);

	DrawBox(2,2,75,45,0);
	SetColor(5);
	DrawBox(11,30,20,20,0);
	//---------------------------------------------//
	SetColor(0);
	for(a=0;a<19;a++)
		{
		for(b=0;b<19;b++)
			{

			SetConsoleCursor(a+31,b+12);
			printf("ú");
			}
		}


		for(a=0;a<10;a++)
		{
				for(b=0;b<10;b++)
				{
					if((galaxy[a][b].probed > 0))
					{
						if((galaxy[a][b].klingons < 1))
						{
						SetColor(3);
						}
						else
						{
							SetColor(2);
						}
						SetConsoleCursor(31+(a*2),12 + (b*2));
						printf("%i",galaxy[a][b].klingons);
					}
					else
					{
						SetColor(0);
						SetConsoleCursor(31+(a*2),12 + (b*2));
						printf("");
					}
					if(( a == galaxyX && b == galaxyY))
					{
						SetColor(5);
						SetConsoleCursor(31+(a*2),12 + (b*2));
						printf("E");
					}
				}
		}
	/*-------------Draw side numbers-**/////
	SetColor(2);
	for(a=0; a<10;a++)
	{
		SetConsoleCursor(29,12+(a*2));
		printf("%i",a);
	}

	for(a=0; a<10;a++)
	{
		SetConsoleCursor(51,12+(a*2));
		printf("%i",a);
	}

	for(a=0; a<10;a++)
	{
		SetConsoleCursor(31+(a*2),10);
		printf("%i",a);
	}

	for(a=0; a<10;a++)
	{
		SetConsoleCursor(31+(a*2),32);
		printf("%i",a);
	}
	SetConsoleCursor(11,5);
	printf("-----==========    G A L A X Y   M A P    ==========-----");
	SetConsoleCursor(5,10);
	printf("PROBES: %i",enterprise[0].probes);
	SetColor(9);
	SetConsoleCursor(5,40);
	printf("Starfleet HQ Reports %i Klingons in known existance", TotalKlingons);

		//--------------------------------------------------------------------//


			if ((ask ==1))
			{
			SetConsoleCursor(5,45);
			printf("                                               ");
			SetConsoleCursor(5,45);
			printf("(F)ire probe, (W)arp, or any other to cancel?:>");
			a = getch();

			if ((a == 102 || a == 119))
			{
			SetConsoleCursor(5,45);
			printf("                                               ");
			SetConsoleCursor(5,45);
			printf("SULU: Which X Coaridnate?:>");
			x = getch();
			x = (x - 48);
			SetConsoleCursor(5,45);
			printf("SULU: Which Y Coaridnate?:>");
			y = getch();
			y = (y - 48);
			SetConsoleCursor(5,45);
			printf("                                 ");

			switch((a))
			{
			case 102://fire probe
				galaxy[x][y].probed = 1;
				DrawGalaxyMap(1);
			case 119://Warp routine
				galaxy[galaxyX][galaxyY].probed = 1;
				galaxyX = x;
				galaxyY = y;

				DrawWarpAnim();
				INIT_BOARD(difficulty,galaxyX,galaxyY);
				ClearNRedraw();
				default:
				return ;
			}

			}
			else
			{
				ClearNRedraw();
				return;
			}
			}

}

void BuyItems()
{
	int x;
	if ((docked == 1))
	{
	 SetConsoleCursor(5,45);
			printf("                              ");
			SetConsoleCursor(5,45);
			printf("SCOTTY: (P)hotons, (H)ull repair, p(R)obe or (U)pgrade?:>");
			x= getch();
			switch((x))
			{

			case 117:
				SetConsoleCursor(5,45);
				printf("                                                           ");
				SetConsoleCursor(5,45);
				printf("SCOTTY: Warp (C)oil (%i)  or (S)hip Class (%i) ?:>",(difficulty * 125),(difficulty * 256));
				x = getch();
				if((x == 115))
				{
					UpgradeEnterprise();
				}
				if((x == 99))
				{
					enterprise[0].warpcoil++;
				}
				return;

				case 104:
				if ((enterprise[0].score > (difficulty * 100)))
				{
					enterprise[0].score = enterprise[0].score - (difficulty *100);
					enterprise[0].hull = 15;
				}
				else
				{
					ScrollLog("SCOTTY: Not enough points to do that...");
				}
				return ;

			case 114:
				if ((enterprise[0].score > (difficulty *25)))
				{
					if ((enterprise[0].probes > 14))
					{
						ScrollLog("SCOTTY: Fully Stocked...");
						return;
					}
					enterprise[0].probes = enterprise[0].probes +1;
					enterprise[0].score = enterprise[0].score - (difficulty *25);
				}
				else
				{
					ScrollLog("SCOTTY: Not enough points to do that...");
				}
				return ;

			case 112:
				if ((enterprise[0].score > (difficulty *15)))
				{
					if ((enterprise[0].photons > 14))
					{
						ScrollLog("SCOTTY: Fully Stocked...");
						return;
					}
					enterprise[0].photons = enterprise[0].photons + 1;
					enterprise[0].score = enterprise[0].score - (difficulty * 15);
				}
				else
				{
					ScrollLog("SCOTTY: Not enough points to do that...");
				}
				return ;
			default:
					return;
			}
	}
}

void CaptiansLog()
{
	int experience;
	ClearScreen();
	DrawBox(2,2,75,45,0);
	SetColor(3);

	SetConsoleCursor(10,8);
	printf("----=======| C A P T A I N ' S  --  L O G |=======----");



	//Ship level, Captains name, Klingons Kiled, Torpedos fired, Galaxys Traveled
	SetColor(0);


	SetConsoleCursor(10,30);
	printf("Current Sector: X-%i , Y-%i",galaxyX,galaxyY);
	SetConsoleCursor(7,32);
	printf("Starbases Visited: %i",enterprise[0].sbvisited);
	SetConsoleCursor(7,34);
	printf("Galaxys Traversed: %i",enterprise[0].glTraveled);
	SetConsoleCursor(14,40);
	printf("Ship Class: %i",enterprise[0].shipclass);


	SetConsoleCursor(50,30);
	printf("Klingons Kiled: %i",enterprise[0].kills);
	SetConsoleCursor(50,32);
	printf(" Photons Fired: %i",enterprise[0].tfired);
	SetConsoleCursor(52,34);
	printf("Damage Taken: %i",enterprise[0].damagetaken);
	SetConsoleCursor(51,36);
	printf("Damage Caused: %i",enterprise[0].damagecaused);
	SetConsoleCursor(52,38);
	printf("Total Damage: %i",(enterprise[0].damagetaken + enterprise[0].damagecaused));
	SetConsoleCursor(18,38);
	printf("Score: %i",enterprise[0].score);





	experience = (enterprise[0].kills * 40) + (enterprise[0].tfired * 5) + ((enterprise[0].damagetaken / 0.5) + (enterprise[0].damagecaused * 0.5) * 2) + (enterprise[0].sbvisited * 20) + (enterprise[0].glTraveled * 25);
	SetConsoleCursor(14,36);
	printf("Experience: %i", experience);

	SetColor(5);
	if ((experience < 300))
	{
	SetConsoleCursor(10,20);
	printf("----=======É------------------------------»=======----");
	SetConsoleCursor(10,21);
	printf("-----------|           C A D E T          |-----------");
	SetConsoleCursor(10,22);
	printf("----=======È------------------------------¼=======----");
	}
	if (((experience > 300) && (experience < 500)))
	{
	SetConsoleCursor(10,20);
	printf("----=======É------------------------------»=======----");
	SetConsoleCursor(10,21);
	printf("-----------|       SNR  C A D E T         |-----------");
	SetConsoleCursor(10,22);
	printf("----=======È------------------------------¼=======----");

	}

	if ((experience > 500 && experience < 800))
	{
	SetConsoleCursor(10,20);
	printf("----=======É------------------------------»=======----");
	SetConsoleCursor(10,21);
	printf("-----------|        E N S I G N           |-----------");
	SetConsoleCursor(10,22);
	printf("----=======È------------------------------¼=======----");

	}

	if ((experience > 800 && experience < 1000))
	{
	SetConsoleCursor(10,20);
	printf("----=======É------------------------------»=======----");
	SetConsoleCursor(10,21);
	printf("-----------|    SNR E N S I G N           |-----------");
	SetConsoleCursor(10,22);
	printf("----=======È------------------------------¼=======----");

	}

	if ((experience > 1000 && experience < 2000))
	{
	SetConsoleCursor(10,20);
	printf("----=======É------------------------------»=======----");
	SetConsoleCursor(10,21);
	printf("-----------|    ELITE    |-----------");
	SetConsoleCursor(10,22);
	printf("----=======È------------------------------¼=======----");

	}

	getch();
	ClearNRedraw();
}

void UpgradeEnterprise()
{
	enterprise[0].shipclass++;
	enterprise[0].energy = (15 * enterprise[0].shipclass);
	enterprise[0].hull = (15 * enterprise[0].shipclass);
	enterprise[0].shields = (15 * enterprise[0].shipclass);
	enterprise[0].phaser = (15 * enterprise[0].shipclass);
	enterprise[0].impulse = (15 * enterprise[0].shipclass);

}

void GameTime(int input)
{

    	/*This next part of code is only used to get a game timer going and
	for something to press the end_turn button once the timer runs out
	very uneffience code witch could probably do with a lot of tweeking in the
	future but will do for now
	*/


    char usefultime[60] ="";
    char convertime[]="";

    time_t timer;
         //Calculate time offset so time allways starts full
        timer=time(NULL);
  	    strncpy(usefultime,asctime(gmtime(&timer)),30);
	    convertime[0] = usefultime[18];

	    gametime = atoi(convertime);

	  	if ((difficulty < 5))
	    gametime = (10 - gametime);

	    if ((difficulty > 5))
	         gametime = (20 - gametime);
	         if ((difficulty == 5))
	         gametime = (20 - gametime);




  	    SetConsoleCursor(17,30);
	    SetColor(6);

	    if ((gametime == 0))
	    {
	         END_TURN();

	     }





}


