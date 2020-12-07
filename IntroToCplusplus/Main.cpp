#include <iostream>

bool getTrueFalse()
{
	char response[] = "Null";
	bool Yes = NULL;
	bool repeat = true;
	//While This should repeat,
	while (repeat == true)
	{
		std::cin >> response;
		//Tests to see if the first letter that the user inputted was a y
		if (response[0] == 'y' || response[0] == 'Y')
		{
			Yes = true;
			repeat = false;
		}
		//tests to see if the first letter that the user inputted was a n
		else if (response[0] == 'n' || response[0] == 'N')
		{
			Yes = false;
			repeat = false;
		}
		//tests to see if the first letter was not y or n
		else
		{
			std::cout << "Please Enter Either Y or N" << std::endl;
		}
	}
	return Yes;
}
bool guessNumber(int min, int max)
{
	bool endGame = false;
	int minimum = min - 1;
	int Maximum = max;
	int guess = (min + max) / 2;
	bool correct = false;
	//Asks if the player chose 50 since its the first guess always its discouraged
	std::cout << "Is Your Number " << guess << " ?" << std::endl;

	correct = getTrueFalse();
	if (correct == true)
	{
		std::cout << "Pick a Harder Number" << std::endl;
		system("pause");
		system("CLS");
	}
	else
	{
		//Until the Game Gets the Number Right, It Will Loop Through These Questions
		while (correct != true)
		{
			//Is Your Number Bigger than The Middle of the max and min of the current guess
			std::cout << "Is Your Number Bigger than " << guess << "?" << std::endl;
			bool higher = getTrueFalse();
			//If Your Number is Bigger, then its safe to say that the minimum is at least the current guess
			if (higher == true)
			{
				minimum = guess;
			}
			//If Your Number is Smaller, then its sage to say that the maximum is at most the current guess
			else
			{
				Maximum = guess;
			}
			//Tests if The Player Lied Just then
			if (Maximum - minimum == 1)
			{
				system("CLS");
				std::cout << "You're lying" << std::endl;
				correct = true;
				system("pause");
				system("CLS");
				break;
			}
			//Creates a new guess with the new max or min
			guess = (minimum + Maximum) / 2;
			std::cout << "Is Your Number " << guess << "?" << std::endl;
			correct = getTrueFalse();
			if (correct == true)
			{
				std::cout << "Told you I could do it!" << std::endl;
				std::cout << "Do You Wanna End The Game?" << std::endl;
				endGame = getTrueFalse();
				system("pause");
			}
			system("CLS");

			//Tests To See if the Player lied Just Then
			if (Maximum <= 0 || minimum >= Maximum || Maximum - minimum == 1)
			{
				system("CLS");
				std::cout << "You're lying" << std::endl;
				correct = true;
				system("pause");
				system("CLS");
				break;
			}
		}
	}
	return endGame;
}
int main()
{
	bool endGame = false;
	//Main Game Loop
	while (endGame == false)
	{
		//Player Thinkgs of a Number
		std::cout << "Think of a number 1 - 100" << std::endl;
		system("pause");
		system("CLS");
		//Guessing Game Loop
		endGame = guessNumber(1, 100);
	}
	return 1;
}