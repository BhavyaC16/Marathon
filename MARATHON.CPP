/*
		COMPUTER SCIENCE-GAME-MARATHON
DEVELOPED BY      : BHAVYA CHOPRA
ROLL NUMBER       : 13
CLASS AND SECTION : XI-J
*/
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>

void line();
void colour(int TC, int TB);
void gameboard();
void score(char name1[],char name2[],int p1, int p2);
void dice(int &score);

void main()
{
	colour(RED,GREEN);
	int positionplayer1=1, positionplayer2=1, position;
	char nameplayer1[100], nameplayer2[100];
	clrscr();
	randomize();
	line();
	cout<<"\n\t\t\t\tMARATHON\n";
	line();
	cout<<"\t\t\t\tWELCOME TO MARATHON!"<<endl<<"This is a two player game and the first player to reach the 30th position wins!"<<endl<<"But, beware of the traps on the track!"<<endl<<"Press any key to throw the dice!"<<endl;
	cout<<"\n\tEnter Name of Player 1:";
	gets(nameplayer1);
	cout<<"\n\tEnter Name of Player 2:";
	gets(nameplayer2);
	while(positionplayer1<30 && positionplayer2<30)
	{
		gameboard();
		score(nameplayer1, nameplayer2, positionplayer1, positionplayer2);
		cout<<"\n"<<nameplayer1<<"'s turn... Throw the dice!";
		getch();
		position=positionplayer1;
		dice(positionplayer1);
		if (positionplayer1==position+6)
		{
			cout<<"\nSIX! You get another turn!"<<endl<<"Throw the dice!";
			getch();
			dice(positionplayer1);
		}
		else if(positionplayer1<position && positionplayer1!=0)
		{
			cout<<"\nOOPS! You have to move back 2 spaces! You are now at position "<<positionplayer1<<endl;
			getch();
		}
		else if(positionplayer1>position+6)
		{
			cout<<"\nWOW! You move ahead 10 sapces! You are now at position "<<positionplayer1<<endl;
			getch();
		}
		else if(positionplayer1==0)
		{
			cout<<"\nSORRY! You will have to begin again!"<<endl;
		}
		getch();
		cout<<"\n"<<nameplayer2<<"'s turn... Throw the dice!";
		getch();
		position=positionplayer2;
		dice(positionplayer2);
		if (positionplayer2==position+6)
		{
			cout<<"\nSIX! You get another turn!"<<endl<<"Throw the dice!";
			getch();
			dice(positionplayer2);
		}
		else if(positionplayer2<position && positionplayer2!=0)
		{
			cout<<"\nOOPS! You have to move back 2 spaces! You are now at position "<<positionplayer2<<endl;
			getch();
		}
		else if(positionplayer2>position+6)
		{	cout<<"\nWOW! You move ahead 10 spaces! You are now at position "<<positionplayer2<<endl;
			getch();
		}
		else if(positionplayer2==0)
		{
			cout<<"\nSORRY! You will have to begin again!"<<endl;
		}
		getch();
	}
	clrscr();
	cout<<"\n";
	line();
	textcolor(BLUE);
	cprintf("\nFINAL RESULT:\n");
	if(positionplayer1>=positionplayer2)
	{
		cout<<nameplayer1;
		textcolor(BLACK);
		cprintf(" won the Marathon!!");
		cout<<endl;
	}
	else
	{
		cout<<nameplayer2;
		textcolor(BLACK);
		cprintf(" won the Marathon!!\n");
		cout<<endl;
	}
	for(int i=0; i<80; i++)
	{
		textcolor(WHITE);
		cprintf("_");
	}
	cout<<endl;
	textcolor(WHITE);
	cout<<"\t\t\tHOPE YOU ENJOYED THE GAME!!";
	getch();
}

void line()
{
	for(int i=0;i<80;i++)
	{
		cprintf("_");
	}
}

void gameboard()
{
	clrscr();
	cout<<"\n";
	line();
	cout<<"\n\t\t\t\tSPECIAL SPACES!\n";
	cout<<"\n\t\tMOVE AHEAD 10 SPACES at 10 and 16\n";
	cout<<"\n\t\tMOVE BACK 2 SPACES at 5, 18 and 27\n";
	cout<<"\n\t\tSTART ALL OVER AGAIN at 15 and 29\n";
	cout<<endl;
}

void score(char name1[], char name2[], int p1, int p2)
{
	cout<<"\n";
	line();
	cout<<"\n\t\t\t\tCURRENT SCORES\n";
	line();
	cout<<"\n\t\t"<<name1<<" is at position "<<p1<<endl;
	cout<<"\n\t\t"<<name2<<" is at position "<<p2<<endl;
	line();
	cout<<endl;
}

void dice(int &score)
{
	int dice;
	dice=random(6)+1;
	cout<<"\nYou got "<<dice<<" points!";
	score+=dice;
	cout<<" You are at position "<<score;
	switch(score)
	{
		case 5:score=3;break;
		case 18:score=16;break;
		case 27:score=25;break;
		case 15:score=0;break;
		case 29:score=0;break;
		case 10:score=20;break;
		case 16:score=26;
	}
}

void colour(int TC, int TB)
{
	textcolor(TC);
	textbackground(TB);
}