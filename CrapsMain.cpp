#include <iostream>
#include <stdlib.h>
#include "Dice.h"
#include "ReadDouble.h"


using namespace std;

void main()
{
	double		Balance;
	double		Bet;
	int			Roll;
	int			Point;
	char		Answer;

	cout << "Welcome to the craps table, your starting balance is $50" << endl;
	Balance = 50;
	do {
		cout << "Your current balance is: $" << Balance << endl;
		cout << "Enter your bet: ";
		Bet = ReadDouble();
		while (Bet > Balance || Bet <= 1)
		{
			cout << "Error! That isn't a valid bet" << endl;
			Bet = ReadDouble();
		}
		cout << "Your bet is: $" << Bet << ", May the odds favor you\n" << endl;
		InitDice();
		Roll = ThrowDice();
		cout << "Roll is " << Roll << endl;

		switch (Roll)
		{
		case 7:
		case 11:
			Balance = Balance + Bet;
			cout << "Winner!\nBalance is now: $" << Balance << endl;
			do {
				cout << "\nDo you want to continue? y/n ";
				cin >> Answer;
				if (Answer == 'N' || Answer == 'n')
				{
					cout << "You cashed out with: $" << Balance << " \nThanks For Playing!" << endl;
					exit(0);
				}
				else
					if (Answer == 'Y' || Answer == 'y')
						cout << "Good Luck\n" << endl;
					else
						cout << "Error! Please choose a valid answer." << endl;
			} while (Answer != 'y' && Answer != 'Y' && Answer != 'n' && Answer != 'N');
			break;
		case 2:
		case 3:
		case 12:
			Balance = Balance - Bet;
			cout << "You lose!\nBalance is now: $" << Balance << endl;
			do {
				cout << "\nDo you want to continue? y/n ";
				cin >> Answer;
				if (Answer == 'N' || Answer == 'n')
				{
					cout << "You cashed out with: $" << Balance << " \nThanks For Playing!" << endl;
					exit(0);
				}
				else
					if (Answer == 'Y' || Answer == 'y')
						cout << "Good Luck\n" << endl;
					else
						cout << "Error! Please choose a valid answer." << endl;
			} while (Answer != 'y' && Answer != 'Y' && Answer != 'n' && Answer != 'N');
			break;
		default:
			Point = Roll;
			cout << "Looks like we're gonna keep rolling!" << endl;
			cout << "If you roll a " << Point << " You win, roll a 7, and you lose.\n" << endl;
			do {
				Roll = ThrowDice();
				cout << "You rolled: " << Roll << "...." << endl;
				if (Roll == Point)
				{
					cout << "You win!" << endl;
					Balance = Balance + Bet;
					do {
						cout << "\nDo you want to continue? y/n ";
						cin >> Answer;
						if (Answer == 'N' || Answer == 'n')
						{
							cout << "You cashed out with: $" << Balance << " \nThanks For Playing!" << endl;
							exit(0);
						}
						else
							if (Answer == 'Y' || Answer == 'y')
								cout << "Good Luck\n" << endl;
							else
								cout << "Error! Please choose a valid answer." << endl;
					} while (Answer != 'y' && Answer != 'Y' && Answer != 'n' && Answer != 'N');
				}
				if (Roll == 7)
				{
					cout << "you lose" << endl;
					Balance = Balance - Bet;
					Roll = Point;
					do {
						cout << "\nDo you want to continue? y/n ";
						cin >> Answer;
						if (Answer == 'N' || Answer == 'n')
						{
							cout << "You cashed out with: $" << Balance << " \nThanks For Playing!" << endl;
							exit(0);
						}
						else
							if (Answer == 'Y' || Answer == 'y')
								cout << "Good Luck\n" << endl;
							else
								cout << "Error! Please choose a valid answer." << endl;
					} while (Answer != 'y' && Answer != 'Y' && Answer != 'n' && Answer != 'N');
				}


			} while (Roll != Point);




		}


	} while (Balance > 0);

	if (Balance <= 0)
		cout << "Looks like you went broke... Time to leave the casino" << endl;
}

