#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int rowCount;
int colCount;
char board[50][50];
void menu();
void playGame();
void showBoard();
void plyrTurn(char player);
void check4win(char player);
int choice;
char ply1 = 'X';
char ply2 = 'O';
int win;



int main(int argc, char const *argv[])
{
//Display the menu.	
	menu();

}

void menu() //The main menu function.
{

	printf("\n\nXOXO WELCOME TO CONNECT 4! XOXO\n\n");
	printf("1. Start a new game\n");
	printf("2. Instructions\n");
	printf("3. Exit\n\n");
	printf("Enter a number to chose\n");
	
	scanf("%d",&choice);
	  switch(choice)
	  {
//start a game.		  
		case 1: 
		{
		  playGame();
		  break;
		}
//Display the instructions.		
		case 2:
		{
		  printf("\n\nAdapted from https://gamezrules.com/connect-4-rules/\n\n");
		  printf("OBJECTIVES OF THE GAME\n");
		  printf("To be the first player to Make 4 identical tokens in a row diagonally, horizontally or vertically.\n\n");
		  printf("RULES OF THE GAME\n\n");
		  printf("The connect 4 game rules are pretty straightforward. The game name says it, you have to 'connect four' to \nwin the game, you have to make a row of four tokens of the same type(O or X) The rows can be done vertically,\nhorizontally or diagonally.\n");

		  printf("Each turn, the player will get the chance to drop and make the row of their token,\n but sometimes instead of making your row, the player has to stop another opponent from making his row by\ndropping your token in that place.\n\n");

		  printf("WINNING\n\n");
		  printf("The game ends when any players make four tokens of their type in a row, or when all available slots are occupied,\nin that case, the game ends in a tie.\n");
		  scanf("");
		  menu();
		  break;
		}
//Exit the program.		
		case 3:
		{
			break;
		};
	  }
}


void playGame() //Playing a round of the game.
{
//The users can decide the board size.	

	printf("\nHow big should the board be?\n\n");
	printf("How many columns?\n");
	scanf("%d",&colCount);
	printf("How many rows?\n");
	scanf("%d",&rowCount);

//The game starts and continues untill win conditions are met. 
 
	win=1;
	while(win==1)
	{
		plyrTurn(ply1);
		check4win(ply1);
		getchar();
	
		if(win==0) //Loop is broken when someone has won.
		{
			break;
		}
			
		plyrTurn(ply2);
		check4win(ply2);
		getchar();
	}
	printf("\nGAME OVER\n");
	menu();
  }
  

void showBoard() //Printing the board to the console.
{
	puts("\n  XOXO CONNECT FOUR XOXO\n");
    int row,col,a,c,b;
    if(b==0){                              
        for(a=0;a<rowCount;a++){
                for(c=0;c<colCount;c++)
                board[a][c]=' ';
        }
    }
    b++;

    for(row=0; row<rowCount; row++){        
        for(col=0; col<colCount; col++){

            printf("| %c ",board[row][col]);
        }
        printf("|\n");
        for(a=0; a<colCount; a++) printf("____");
        printf("\n");
    }
    for(a=0; a<colCount; a++)printf("%*d",4,a+1);
    printf("\n");

}

void plyrTurn(char player)
{
  showBoard();
  int choiceBad=1;
  int colPick;
  
  if(player == 'X')
  {
	printf("PLAYER ONE\n\n");
  }
  else
  {
	  printf("PLAYER TWO\n\n");
  }
  printf("Pick a column...\n");

//Making sure the player doesn't enter a choice higher than the number of columns(colCount).

  while (choiceBad==1)
  {
    scanf("%d",&colPick);
	
    if(colPick>colCount)
    {
      printf("Your choice is too high. Try again\n");
    }
	
//Placing the player token on the board.
	
    else
    {
		choiceBad=0;
		int x,y;

		for(x=0;x<colCount;x++)
		{
			if(x==colPick-1)
			{
				for(y=0;y<rowCount;y++)
				{	
					if(board[y][x]=='X' || board[y][x]=='O')
					{  		
						board[y-1][x] = player;	
						break;							
					}	
					else if(y==rowCount-1)
					{
						y=rowCount-1;
						board[y][x] = player;
						break;
					}		
				}
			}
		}
    }
  }
}


void check4win(char player) //To check if there is four tokens in a line.
{
	int x,y;

//Horizontal check.	

	for(x=0;x<colCount;x++)
	{
		{
			for(y=0;y<rowCount;y++)
			{
				if (board[y][x] == player && board[y][x+1] == player && board[y][x+2] == player && board[y][x+3] == player)
				{
					if(player=='X')
					{
						printf("player one(X) wins!\n");
						win = 0;
					}
					else
					{
						printf("player two(O) wins!\n");
						win = 0;
					}					
				}
			}
		}
		
	}
	
//Vertical check.	
	
	for(x=0;x<colCount;x++)
	{
		{
			for(y=0;y<rowCount;y++)
			{
				if (board[y][x] == player && board[y+1][x] == player && board[y+2][x] == player && board[y+3][x] == player)
				{
					if(player=='X')
					{
						printf("player one(X) wins!\n");
						win = 0;
					}
					else
					{
						printf("player two(O) wins!\n");
						win = 0;
					}
				}
			}
		}
	}
	
//Diagonal check.	
	
	for(x=0;x<colCount;x++)
	{
		{
			for(y=0;y<rowCount;y++)
			{
				if (board[y][x] == player && board[y-1][x-1] == player && board[y-2][x-2] == player && board[y-3][x-3] == player)
				{
					if(player=='X')
					{
						printf("player one(X) wins!\n");
						win = 0;
					}
					else
					{
						printf("player two(O) wins!\n");
						win = 0;
					}			 
				}
			}
		}
	}
	
//Diagonal check.	
	
	for(x=0;x<colCount;x++)
	{
		{
			for(y=0;y<rowCount;y++)
			{
				if (board[y][x] == player && board[y-1][x+1] == player && board[y-2][x+2] == player && board[y-3][x+3] == player)
				{
					if(player=='X')
					{
						printf("player one(X) wins!\n");
						win = 0;
					}
					else
					{
						printf("player two(O) wins!\n");
						win = 0;
					}
				}
			}
		}
	}
	
}


