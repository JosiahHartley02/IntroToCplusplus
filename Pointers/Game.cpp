#include "Game.h"
#include <iostream>

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
	player1 = new Character(100,10);
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
		player1->setLetter(i, newName[i]);
	}
}

void Game::update()
{
	system("pause");
}

void Game::draw()
{
	/*std::cout << *m_enemy[level].name << " health: " << *m_enemy[level].health << " damage: " << m_enemy[level].getDamage() << std::endl;*/
	std::cout << *player1->name << " health: " << *player1->health << "damage: " << player1->getDamage() << std::endl;
}

void Game::end()
{
	delete player1;
}
