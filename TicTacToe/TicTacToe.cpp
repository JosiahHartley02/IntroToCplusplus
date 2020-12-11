#include <iostream>


void printArray(int arr[],int length)
{
	//Simply Prints The Current Grid 
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
			std::cout << "Please type in your response again." << std::endl;
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
	//Returns a players input 1-9
	bool loop = true;
	char number = '0';
	//Until a valid number has been entered
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
	//since number is a char, and this function is an int, converting char to int is as simple as subtracting 48, ASCII TABLE for Reference
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

bool checkCatEyes(char grid[3][3], char symbol)
{
	if (grid[0][0] != '1' && grid[0][1] != '2' && grid[0][2] != '3'
		&& grid[1][0] != '4' && grid[1][1] != '5' && grid[1][2] != '6'
		&& grid[2][0] != '7' && grid[2][1] != '8' && grid[2][2] != '9')
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

int update(char grid[3][3], char name1[], char name2[])
{
	draw(grid, name1, name2);
	//Player Ones Turn
	bool winner = false;
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
	int p1Column = -1;
	int p1Row = 0;
	for (int i = 0; i < p1Position; i++)
	{
		//increments column value to move right across array
		p1Column += 1;
		//Once passed column 2 or [3], remove 3 units from column and add to row, since a row = 3 columns
		if (p1Column > 2)
		{
			p1Column -= 3;
		p1Row++;
		}
	}
	char p1Symbol = 'X';
	grid[p1Row][p1Column] = p1Symbol;

	if (checkWinner(grid, p1Symbol))
	{
		return 1;
	}
	else if (checkCatEyes(grid, p1Symbol))
	{
		return 3;
	}
	draw(grid, name1, name2);
	//Player Twos Turn
	bool p2Loop = true;
	int p2Position = 0;
	std::cout << name2 << " please choose a spot to place your piece [O]" << std::endl;
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
	//Converts 1-9 to [0-2][0-2]
	int column = -1;
	int row = 0;
	//adds tallies for the amount of times that p2 said (1-9) going [0][0],[0][1],[0][2],[1][0]
	for (int i = 0; i < p2Position; i++)
	{
		//increments column value to move right across array
		column += 1;
		//Once passed column 2, remove 3 units from column and add to row, since a row = 3 columns
		if (column > 2)
		{
			column -= 3;
			row++;
		}
	}
	char symbol = 'O';
	grid[row][column] = symbol;

	if (checkWinner(grid, symbol))
	{
		return 2;
	}
	else if (checkCatEyes(grid, p1Symbol))
	{
		return 3;
	}
}

int main()
{
	bool loop = true;
    char playerOnesName[5] = { 'N','A','M','E','!' };
    char playerTwosName[5] = { 'N','A','M','E','!' };
	char grid[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
	start(playerOnesName, playerTwosName);
	while (loop)
	{
		int winner = update(grid, playerOnesName, playerTwosName);
		if(winner == 1)
		{
			system("cls");
			std::cout << "Congratulations " << playerOnesName << " !" << std::endl;
			system("pause");
		}
		else if (winner == 2)
		{
			system("cls");
			std::cout << "Congratulations " << playerTwosName << " !" << std::endl;
			system("pause");
		}
		else if (winner == 3)
		{
			system("cls");
			std::cout << "Uh Oh, Seems Like A Tie To Me!" << std::endl;
			system("pause");
		}
		if (winner == 1 || winner == 2 || winner == 3)
		{
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					grid[i][j] = (char)((i * 3) + j + 49);
		}
	}
}