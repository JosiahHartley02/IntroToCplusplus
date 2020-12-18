#include "Game.h"
#include <iostream>
#include <fstream>

bool getYesNo()
{
	char answer[5] = { ' ' };
	while (answer[0] != 'y' && answer[0] != 'Y' && answer[0] != 'n' && answer[0] !='N')
	{
		std::cin >> answer;
	}
	if (answer[0] == 'y' || answer[0] == 'Y')
		return true;
	return false;

}

int attackSkipSave()
{
	char answer[2] = { ' ' };
	while (answer[0] != 'y' && answer[0] != 'Y' && answer[0] != 'n' && answer[0] != 'N' && answer[0] != 's' && answer[0] != 'S')
	{
		std::cin >> answer;
	}
	if (answer[0] == 'y' || answer[0] == 'Y')
		return 1;
	else if (answer[0] == 'n' || answer[0] == 'N')
		return 0;
	else
		return 2;


}

int saveData(Character* player)
{
	std::fstream file;
	file.open("savedData.txt", std::ios::out);
	if (!file.is_open())
		return 3;
	file << *player->health << std::endl;
	file << *player->damage << std::endl;
	file << *player->level << std::endl;
	for (int i = 0; i < 10; i++)
		file << player->name[i];

	file.close();
	return 1;
}

int loadData(Character* player)
{
	std::fstream file;
	file.open("savedData.txt", std::ios::in);
	if (!file.is_open())
		return -1;
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
			m_player1->setLetter(i, newName[i - 1]);
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
	while (*m_player1->health > 0 && *m_enemy[level]->health > 0)
	{
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
