#include <iostream>
#include <cstdlib> 
#include <Windows.h>
#include <ctime> 
#include <conio.h>
#include <string>
#define LEFT 72
#define RIGHT 80
#define DOWN 75
#define UP 77
using namespace std;

int foodx, foody, score = 0, lenght;
int snakex = 9, snakey = 9;
bool flag = true;
string status = "";

void gameEnd()
{
	if (snakex == 1 || snakey == 1 || snakex == 100 || snakey == 20)
	{
		flag = false;
	}
	else
	{
		return;
	}
}

void direction()
{
	int c = 0;

	switch ((c = _getch())) {
	case UP:
		snakey++;
		break;
	case DOWN:
		snakey--;
		break;
	case LEFT:
		snakex--;
		break;
	case RIGHT:
		snakex++;
		break;
	default:
		break;
	}
}

void main()
{
	srand((unsigned)time(0));
	foodx = (rand() % 98) + 2;
	foody = (rand() % 18) + 2;
	lenght = score + 1;

	while (flag == true)
	{
		system("cls");
		for (int i = 1; i <= 100; i = i + 1)
		{
			cout << "-";
		}

		for (int i = 1; i <= 20; i = i + 1)
		{
			cout << "\n|";
			for (int j = 2; j <= 99; j = j + 1)
			{
				if (i == foodx && j == foody)
				{
					cout << "o";
					if (foodx == snakex && foody == snakey)
					{
						foodx = (rand() % 98) + 2;
						foody = (rand() % 18) + 2;
						score++;
					}
				}
				else if (i == snakex && j == snakey)
				{
					cout << ">";
				}
				else
				{
					cout << " ";
				}
			}
			cout << "|";
		}
		cout << endl;


		for (int i = 1; i <= 100; i = i + 1)
		{
			cout << "-";
		}


		cout << "\n=>Your Score = " << score << "\n";
		cout << status << endl;	
		direction();
		gameEnd();
	}
	cout << "\n=>Your Score = " << score << "\n";
	cout << "Game Ended" << endl;
}
