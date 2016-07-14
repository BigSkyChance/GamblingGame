#include <stdlib.h> // use this for random numbers
#include <time.h>

#include "Dice.h"

void InitDice()
{
	srand(time(0)); 		//This sets a starting value for the random number generator
}

int ThrowDice()
{
	return ThrowDie() + ThrowDie();
}




int ThrowDie()

{
	int		Num;

	Num = rand();  // Gives back a random number ranging from 0 to 32767
	Num = Num % 6;  // Gives a value from 0 to 5
	Num++;
	return Num;

	// return (rand() % 6) + 1

}
