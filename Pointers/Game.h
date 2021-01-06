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
	int saveData();
	int loadData();
private:
	bool m_gameOver;
	int m_level = 0;
	int m_saveSlot = 0;
	Character* m_player1;
	Character* m_enemy[3];
public:
	int* saveSlot = &m_saveSlot;
};
