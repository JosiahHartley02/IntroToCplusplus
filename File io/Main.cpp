#include <iostream>
#include <fstream>
#include "Character.h"

int main()
{
	Character player = Character();
	player.health = 100;
	player.damage = 5;

	//Saving to a text file example

	//Create an instance of a file stream
	std::fstream file;

	//Search for the file with the name given in the first argument
	//If no file with this name exists, one with the name is created
	//the name is created Then "std::ios::out" is used to say that we
	//want to output data to the text file.
	file.open("save.txt", std::ios::out | std::ios::binary);

	//Checks to see if the file is not open, if it is not open, return
	//24 as an error message for troubleshooting
	if (!file.is_open())
	{
		return 24;
	}
	//Write player stats to the text file
	file.write((char*)&player, sizeof(player));

	//Close the file when we're done
	file.close();

	
	//Example of loading from a text file
	Character player2 = Character();

	//Search for a file that has the name given in the first argument.
	//The "std::ios::in" argument is used to say that we want to get
	//input from the file.
	file.open("save.txt", std::ios::in | std::ios::binary);

	if (!file.is_open())
	{
		return 44;
	}
	//Reads the player stats from the text file.
	file.read((char*)&player, sizeof(player));
	
	//Closes the file once we're done
	file.close();


	return 0;
}