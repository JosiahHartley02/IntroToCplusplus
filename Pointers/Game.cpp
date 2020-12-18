#include "Game.h"
#include <iostream>
#include <fstream>

bool getYesNo()
{
	//Allocates answer spot
	char answer[5] = { ' ' };
	//until the answer is something worth something, repeat
	while (answer[0] != 'y' && answer[0] != 'Y' && answer[0] != 'n' && answer[0] !='N')
	{
		std::cin >> answer;
	}
	//if the answer was yes return a true
	if (answer[0] == 'y' || answer[0] == 'Y')
		return true;
	//if it was anything else and made it this far its safe to assume it was n or false
	return false;

}

int attackSkipSave()
{
	//Allocate an answer spot
	char answer[5] = { ' ' };
	//Until the answer is something valueable repeat getting answer
	while (answer[0] != 'y' && answer[0] != 'Y' && answer[0] != 'n' && answer[0] != 'N' && answer[0] != 's' && answer[0] != 'S')
	{
		std::cin >> answer;
	}
	//if it was yes return 1 or true
	if (answer[0] == 'y' || answer[0] == 'Y')
		return 1;
	//if it was a no return 0 or false
	else if (answer[0] == 'n' || answer[0] == 'N')
		return 0;
	//if it was anything else its safe to assume it was an S so returns a 2
	else
		return 2;


}

int saveData(Character* player)
{
	//new instance of file stream
	std::fstream file;
	//open the file
	file.open("savedData.txt", std::ios::out);
	//if file doesnt open return error code -1
	if (!file.is_open())
		return -1;
	//save important data line by line
	file << *player->health << std::endl;
	file << *player->damage << std::endl;
	file << *player->level << std::endl;
	for (int i = 0; i < 10; i++)
		file << player->name[i];
	//always close file after opening
	file.close();
	//returns a true, it did save
	return 1;
}

int loadData(Character* player)
{
	//new instance of file stream
	std::fstream file;
	//open the file 
	file.open("savedData.txt", std::ios::in);
	//test to see if the file has opened if not return error code -2
	if (!file.is_open())
		return -2;
	//overwrite current m_player1 values and current level
	file >> *player->health;
	file >> *player->damage;
	file >> *player->level;
	file >> player->name;
	return *player->level;
}

void Game::run()
{
	start();
	while (!m_gameOver)
	{
		update();
		draw();
	}
	end();
}

void Game::start()
{
	//Initialize all actors in this first "scene"
	m_player1 = new Character(100,9);
	m_enemy[0] = new Character(10, 5, 1);
	m_enemy[1] = new Character(20, 10, 2);
	m_enemy[2] = new Character(30, 15, 3);

	std::fstream file;
	//Check to see if there is a save file
	bool savedData = false;
	bool loadedSavedData = false;
	//Attempts to open the save data text file but will not create one if it does not exist
	file.open("savedData.txt", std::ios::out | std::ios::_Nocreate);
	//We test to see if the program was able to find and open the save Data
	if (file.is_open())
	{
		//If it is opened its safe to assume it exists and we can now close it.
		savedData = true;
		file.close();
	}
	//Now that we know whether or not there is a save file, if there is we can ask the player if they wish to load.
	bool load = false;
	if (savedData)
	{
		std::cout << "Would You Like To Load your old save? Enter Y or N" << std::endl;
		load = getYesNo();
		system("cls");
	}
	if (load)
	{
		level = loadData(m_player1);
		loadedSavedData = true;
	}
	if (!loadedSavedData)
	{
		bool loop = true;
		char answer[10];
		bool answerAnswered = false;
		char newName[10];

		while (loop)
		{
			std::cout << "Player, What is Your Name?" << std::endl;
			std::cin >> newName;
			while (!answerAnswered)
			{
				std::cout << "You put " << newName << ", is this correct?" << std::endl;
				std::cin >> answer;
				if (answer[0] != 'y' && answer[0] != 'Y' && answer[0] != 'n' && answer[0] != 'N')
				{
					std::cout << "Please Enter Either Y or N";
				}
				else if (answer[0] == 'Y' || answer[0] == 'y')
				{
					answerAnswered = true;
					loop = false;
				}
			}
		}

		for (int i = 0; i < 10; i++)
		{
			m_player1->setLetter(i, newName[i]);
		}
	}
	
}

void Game::draw()
{
	if(m_gameOver)
	{
		return;
	}
	system("cls");
	std::cout << m_player1->name << " Health: " << *m_player1->health << " Damage: " << *m_player1->damage << std::endl;
	std::cout << m_enemy[level]->name << " Health: " << *m_enemy[level]->health << " Damage: " << *m_enemy[level]->damage << std::endl;
}

void Game::update()
{
	//Loops in update untill either character's health value is equal to or less than 0
	while (*m_player1->health > 0 && *m_enemy[level]->health > 0)
	{
		//used this to prevent the enemy from sucker punching player when they save
		bool enemyStunned = false;
		draw();
		//Player One Gets a Turn if they're alive
		if (*m_player1->health > 0)
		{
			std::cout << "Enter Y to Attack, N to Skip or S to Save" << std::endl;
			int attack = attackSkipSave();
			if (attack == 1)
			{
				m_enemy[level]->takeDamage(*m_player1->damage);
				std::cout << m_player1->name << " hit " << m_enemy[level]->name << " for " << *m_player1->damage << "!" << std::endl;
				system("pause");
			}
			else if (attack == 0)
			{
				std::cout << m_player1->name << " has skipped their turn!";
				system("pause");
			}
			else if (attack == 2)
			{
				saveData(m_player1);
				enemyStunned = true;
			}
				
		}
		//Enemy Gets a Turn if they're alive and not stunned
		if (*m_enemy[level]->health > 0 && enemyStunned == false)
		{
			m_player1->takeDamage(*m_enemy[level]->damage);
			std::cout << m_enemy[level]->name << " hit " << m_player1->name << " for " << *m_enemy[level]->damage << "!" << std::endl;
			system("pause");
		}
	}
	if (*m_player1->health > 0)
	{
		std::cout << m_player1->name << " has defeated " << m_enemy[level]->name << "!" << std::endl;
		level++;
		*m_player1->level = level;
		if (level > 2)
			m_gameOver = true;
		system("pause");
	}
	else
	{
		std::cout << m_player1->name << " has been defeated by " << m_enemy[level]->name << "!" << std::endl;
		system("pause");
		m_gameOver = true;
	}
}

void Game::end()
{
	delete m_player1;
	delete m_enemy[0];
	delete m_enemy[1];
	delete m_enemy[2];

}
