#include <iostream>


void printArray(int arr[],int length)
{
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << std::endl;
    system("pause");
}

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

int getNumber()
{
	bool loop = true;
	char number = '0';
	while (loop == true)
	{
		std::cin >> number;
		if (number == '1' || number == '2' || number == '3' ||
			number == '4' || number == '5' || number == '6' ||
			number == '7' || number == '8' || number == '9' )
		{
			loop = false;
		}
		else
		{
			std::cout << "please select a valid option" << std::endl;
		}
	}
	return number - 48;
}

void getName(char name[])
{
	std::cout << "Please Enter Your Name" << std::endl;
	bool correct = 0;
	while (correct == 0)
	{
		for (int i = 0; i < 5; i++)
			name[i] = ' ';
		std::cin >> name;
		std::cout << "You entered " << name << " . Is This Correct?" << std::endl;
		correct = getTrueFalse();
	}
	std::cout << "Alright " << name << " !" << std::endl;
	system("pause");
	system("cls");
}

bool checkPositionAvailable(char grid[3][3], int position)
{
	int row = 0;
	int column = -1;
	bool clear = false;
	//converts int position to [][]
	for (int i = 0; i < position; i++)
	{ 
		//increments column value to move right across array

		column += 1;
		//Once passed column 2 or [3], remove 3 units from column and add to row, since a row = 3 columns
		if (column > 2)
		{
			column -= 3;
			row++;
		}
	}
	if (grid[row][column] != 'X' && grid[row][column] != 'O')
		clear = true;
	return clear;
}

bool checkWinner(char grid[3][3], char symbol)
{
	if ((grid[0][0] == symbol && grid[0][1] == symbol && grid[0][2] == symbol) ||
		(grid[1][0] == symbol && grid[1][1] == symbol && grid[1][2] == symbol) ||
		(grid[2][0] == symbol && grid[2][1] == symbol && grid[2][2] == symbol) ||
		(grid[0][0] == symbol && grid[1][0] == symbol && grid[2][0] == symbol) ||
		(grid[0][1] == symbol && grid[1][1] == symbol && grid[2][1] == symbol) ||
		(grid[0][2] == symbol && grid[1][2] == symbol && grid[2][2] == symbol) ||
		(grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) ||
		(grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol))
	{
		return true;
	}
	return false;
}

void start(char name1[], char name2[])
{
	std::cout << "Player One Please Enter Your Name" << std::endl;
	getName(name1);
	std::cout << "Player Two Please Enter Your Name" << std::endl;
	getName(name2);
}

void draw(char grid[3][3], char name1[], char name2[])
{
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << grid[i][j] << "  ";
		}
	std::cout << std::endl;
	}
}

void update(char grid[3][3], char name1[], char name2[], bool p1Winner, bool p2Winner)
{
	draw(grid, name1, name2);
		//Player Ones Turn
		bool p1Loop = true;
		int p1Position = 0;
		std::cout << name1 << " please choose a spot to place your piece [X]" << std::endl;
		while (p1Loop == true)
		{
			p1Position = getNumber();
			bool availablePosition = checkPositionAvailable(grid, p1Position);
			if (availablePosition)
			{
				p1Loop = false;
			}
			else
			{
				std::cout << "Please Select A Valid Spot" << std::endl;
			}
		}
		int column = -1;
		int row = 0;
		for (int i = 0; i < p1Position; i++)
		{
			//increments column value to move right across array
			column += 1;
			//Once passed column 2 or [3], remove 3 units from column and add to row, since a row = 3 columns
			if (column > 2)
			{
				column -= 3;
				row++;
			}
		}
		char symbol = 'X';
		grid[row][column] = symbol;		

		if (checkWinner(grid, symbol))
		{
			p1Winner = true;
		}
		draw(grid, name1, name2);
		//Player Twos Turn
		bool p2Loop = true;
		int p2Position = 0;
		std::cout << name1 << " please choose a spot to place your piece [X]" << std::endl;
		while (p2Loop == true)
		{
			p2Position = getNumber();
			bool availablePosition = checkPositionAvailable(grid, p2Position);
			if (availablePosition)
			{
				p2Loop = false;
			}
			else
			{
				std::cout << "Please Select A Valid Spot" << std::endl;
			}
		}
		column = -1;
		row = 0;
		for (int i = 0; i < p2Position; i++)
		{
			//increments column value to move right across array
			column += 1;
			//Once passed column 2 or [3], remove 3 units from column and add to row, since a row = 3 columns
			if (column > 2)
			{
				column -= 3;
				row++;
			}
		}
		symbol = 'O';
		grid[row][column] = symbol;

		if (checkWinner(grid, symbol))
		{
			p2Winner = true;
		}
	
}

int main()
{
	bool gameOver = false;
	bool p1Won = false;
	bool p2Won = false;
    char playerOnesName[5] = { 'N','A','M','E','!' };
    char playerTwosName[5] = { 'N','A','M','E','!' };
	char grid[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
	start(playerOnesName, playerTwosName);
	while (gameOver == false)
	{
		update(grid,playerOnesName, playerTwosName,p1Won,p2Won);
		draw(grid, playerOnesName, playerTwosName);
	}
}