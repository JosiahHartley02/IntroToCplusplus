#pragma once
#include "Character.h"

class Game
{
public:
	void run();
	bool getGameOver() { return m_gameOver; }
	void setGameOver(bool value) { m_gameOver = value; }
private : 
	void start();
	void update();
	void draw();
	void end();
private:
	bool m_gameOver;
	Character m_player1;
	Character m_player2;
};
