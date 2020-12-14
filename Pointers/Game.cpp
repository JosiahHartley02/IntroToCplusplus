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
	m_player1 = Character(10,10);
	m_player2 = Character(10, 10);
}

void Game::update()
{
	m_player1.attack(m_player2);
}

void Game::draw()
{
	std::cout << "Player2 health is :" << m_player2.getHealth();
}

void Game::end()
{
}
