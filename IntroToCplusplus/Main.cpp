#include <iostream>

bool getTrueFalse()
{
	char response[] = "Null";
	bool Yes = NULL;
	bool repeat = true;
	while (repeat == true)
	{
		std::cin >> response;
		if (response[0] == 'y' || response[0] == 'Y')
		{
			Yes = true;
			repeat = false;
		}
		else if (response[0] == 'n' || response[0] == 'N')
		{
			Yes = false;
			repeat = false;
		}
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
		while (correct != true)
		{
			if (Maximum <= 0 || minimum >= Maximum || Maximum - minimum == 1)
			{
				system("CLS");
				std::cout << "You're lying" << std::endl;
				correct = true;
				system("pause");
				system("CLS");
				break;
			}
			std::cout << "Is Your Number Bigger than " << guess << "?" << std::endl;
			bool higher = getTrueFalse();
			if (higher == true)
			{
				minimum = guess;
			}
			else
			{
				Maximum = guess;
			}
			if (Maximum - minimum == 1)
			{
				system("CLS");
				std::cout << "You're lying" << std::endl;
				correct = true;
				system("pause");
				system("CLS");
				break;
			}
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
		}
	}
	return endGame;
}
int main()
{
	bool endGame = false;
	while (endGame == false)
	{
		std::cout << "Think of a number 1 - 100" << std::endl;
		system("pause");
		system("CLS");
		endGame = guessNumber(1, 100);
	}
	return 1;
}