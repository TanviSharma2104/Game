#include<stdio.h>
#include<conio.h>

char matrix[10]={'0','1','2','3','4','5','6','7','8','9'};

int gameStatus();
void printMatrix();

int main(){
	int player=1;
	int  i, choice;
	char symbol;
	do{
		printMatrix();
		player=(player%2!=0)?1:2;
		printf("Player %d , Enter a number to mark your turn: ",player);
		scanf("%d",&choice);

		symbol=(player==1)?'X':'O';

		if(choice==1 && matrix[1]=='1'){
			matrix[1]=symbol;

		}
		else if(choice==2 && matrix[2]=='2')matrix[2]=symbol;
		else if(choice==3 && matrix[3]=='3')matrix[3]=symbol;
		else if(choice==4 && matrix[4]=='4')matrix[4]=symbol;
		else if(choice==5 && matrix[5]=='5')matrix[5]=symbol;
		else if(choice==6 && matrix[6]=='6')matrix[6]=symbol;
		else if(choice==7 && matrix[7]=='7')matrix[7]=symbol;
		else if(choice==8 && matrix[8]=='8')matrix[8]=symbol;
		else if(choice==9 && matrix[9]=='9')matrix[9]=symbol;
		else {
			printf("Invalid move");
			player--;

		}
		i=gameStatus();
		player++;

	}while(i==-1);

	printMatrix();

	if(i==1)printf("==> Player %d win ",--player);
	else printf("==> Game Draw");

	return 0;
}

// 1 --> Game over and return winner
// 0 --> Game in progress, continue playing
// -1 -->Game over, Game draw

int gameStatus(){
	if(matrix[1]== matrix[2] && matrix[2]==matrix[3])return 1;
	if(matrix[4]== matrix[5] && matrix[5]==matrix[6])return 1;
	if(matrix[7]== matrix[8] && matrix[8]==matrix[9])return 1;
	if(matrix[1]== matrix[4] && matrix[4]==matrix[7])return 1;
	if(matrix[2]== matrix[5] && matrix[5]==matrix[8])return 1;
	if(matrix[3]== matrix[6] && matrix[6]==matrix[9])return 1;
	if(matrix[1]== matrix[5] && matrix[5]==matrix[9])return 1;
	if(matrix[3]== matrix[5] && matrix[5]==matrix[7])return 1;
	else if(
		matrix[1]!='1' && matrix[2]!='2' && matrix[3]!='3' &&
		matrix[4]!='4' && matrix[5]!='5' && matrix[6]!='6' &&
		matrix[7]!='7' && matrix[8]!='8' && matrix[9]!='9'
		)return 0;
	else return -1;

}
void printMatrix(){
	printf("\n\n\t Tic Tac Toe \n\n");
	printf("Player 1 --> X  Player 2 --> O \n\n");

	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",matrix[1],matrix[2],matrix[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");

	printf("  %c  |  %c  |  %c  \n",matrix[4],matrix[5],matrix[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");

	printf("  %c  |  %c  |  %c  \n",matrix[7],matrix[8],matrix[9]);
	printf("     |     |     \n");
}


