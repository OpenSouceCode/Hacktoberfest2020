#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
void rule()
	{
		cout<<"\t\t WELCOME TO THE GAME OF ROCK-PAPER-SCISSORS\n";
		cout<<"Welcome to the rules of the game\n";
		cout<<"1. If the user takes a number <=3 then it is rock\n";
		cout<<"2. If the user takes a number >3 and <=6 then it is scissors\n";
		cout<<"3. If the user takes a number >6 and <=9 then it is paper\n";
		cout<<"Points are scored on following bases:\n";
		cout<<"ROCK BEATES SCISSORS\n";
		cout<<"SCISSORS BEATS PAPER\n";
		cout<<"PAPER BEATS ROCK\n";
		cout<<"After you make your move then the computer makes the move\n";
		cout<<"\t\t\tAre you ready for the game!!!\n";
	}
void game(int oppscore=0,int score=0,int opp)
	{
		int select;
		while (oppscore<6&&score<6)
			{
				cout<<"\nMake your move\n";
				srand((unsigned)time(0));
				opp=rand()%10;
				cin>>select;
				if (select<=3)
					{
						cout<<"You chose: ROCK\n";
						if (opp<=3)
							{
								cout<<"Comp chose: ROCK\n";
								cout<<"Your Score: "<<score;
								cout<<"\nComp Score: "<<oppscore;
							}
						if (opp>3&&opp<=6)
							{
								cout<<"Comp chose: SCISSORS\n";
								score++;
								cout<<"Your Score: "<<score;
								cout<<"\nComp Score: "<<oppscore;
							}
						if (opp>6&&opp<=9)
							{
								cout<<"Comp chose: PAPER\n";
								oppscore++;
								cout<<"Your Score: "<<score;
								cout<<"\nComp Score: "<<oppscore;
							}
					}
				if (select>3&&select<=6)
					{
						cout<<"You chose: SCISSORS\n";
						if (opp<=3)
							{
								cout<<"Comp chose: ROCK\n";
								oppscore++;
								cout<<"Your Score: "<<score;
								cout<<"\nComp Score: "<<oppscore;
							}
						if (opp>3&&opp<=6)
							{
								cout<<"Comp chose: SCISSORS\n";
								cout<<"Your Score: "<<score;
								cout<<"Comp Score: "<<oppscore;
							}
						if (opp>6&&opp<=9)
							{
								cout<<"Comp chose: PAPER\n";
								score++;
								cout<<"Your Score: "<<score;
								cout<<"\nComp Score: "<<oppscore;
							}
					}
				if (select>6&&select<=9)
					{
						cout<<"You chose: PAPER\n";
						if (opp<=3)
							{
								cout<<"Comp chose: ROCK\n";
								score++;
								cout<<"Your Score: "<<score;
								cout<<"\nComp Score: "<<oppscore;
							}
						if (opp>3&&opp<=6)
							{
								cout<<"Comp chose: SCISSORS\n";
								oppscore++;
								cout<<"Your Score: "<<score;
								cout<<"\nComp Score: "<<oppscore;
							}
						if (opp>6&&opp<=9)
							{
								cout<<"Comp chose: PAPER\n";
								cout<<"Your Score: "<<score;
								cout<<"\nComp Score: "<<oppscore;
							}
					}
			}
	}
void main ()
{
  clrscr();
  int a,o,s=0,op=0;
  rule();
  game(op,s,o);
  getch();
}
