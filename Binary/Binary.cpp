#include "Binary.h"
#include <fstream>
#include <iostream>

struct SaveThisBinary
{
	int health;
	int attack;
};

SaveThisBinary Information;

void Binary::run()
{
	std::fstream file;
	file.open("playerData.dat", std::ios::in | std::ios::binary);
	if (!file.is_open())
	{
		save();
	}
	printInfo();
	load();
	printInfo();
}

void Binary::save()
{
	Information.attack = 10;
	Information.health = 100;
	std::fstream file;
	file.open("playerData.dat", std::ios::out | std::ios::binary);
	file.write((char*)&Information, sizeof(SaveThisBinary));
	file.close();
}

void Binary::load()
{
	std::fstream file;
	file.open("playerDate.dat", std::ios::in | std::ios::binary);
	file.read((char*)&Information, sizeof(SaveThisBinary));
	file.close();
}

void Binary::printInfo()
{
	std::cout <<Information.health << std::endl;
	std::cout << Information.attack << std::endl;
	system("pause");
}
