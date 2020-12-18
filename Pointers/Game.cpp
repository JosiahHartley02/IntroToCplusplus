#include "Game.h"
#include <iostream>

bool getYesNo()
{
	char answer[2] = { ' ' };
	while (answer[0] != 'y' && answer[0] != 'Y' && answer[0] != 'n' && answer[0] !='N')
	{
		std::cin >> answer;
	}
	if (answer[0] == 'y' || answer[0] == 'Y')
		return true;
	return false;

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
	m_player1 = new Character(100,9);
	m_enemy[0] = new Character(10, 5, 1);
	m_enemy[1] = new Character(20, 10, 2);
	m_enemy[2] = new Character(30, 15, 3);
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
		draw();
		//Player One Gets a Turn if they're alive
		if (*m_player1->health > 0)
		{
			std::cout << "Enter Y to Attack or N to Skip" << std::endl;
			bool attack = getYesNo();
			if (attack == true)
			{
				m_enemy[level]->takeDamage(*m_player1->damage);
				std::cout << m_player1->name << " hit " << m_enemy[level]->name << " for " << *m_player1->damage << "!" << std::endl;
				system("pause");
			}
			else
			{
				std::cout << m_player1->name << " has skipped their turn!";
				system("pause");
			}
		}
		//Enemy Gets a Turn if they're alive
		if (*m_enemy[level]->health > 0)
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
