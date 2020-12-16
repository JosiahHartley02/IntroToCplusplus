#include "Character.h"

Character::Character()
{
	m_health = 100;
	m_damage = 10;
}

Character::Character(float health, float damage)
{
	m_health = health;
	m_damage = damage;
}

Character::Character(float health, float damage, int enemy)
{
	m_health = health;
	m_damage = damage;
	switch(enemy)
		case 1:
			name[0] = 'T';
			name[1] = 'r';
			name[2] = 'o';
			name[3] = 'l';
			name[4] = 'l';
			return;
		case2:
			name[0] = 'O';
			name[1] = 'g';
			name[2] = 'r';
			name[3] = 'e';
			return;
		case3:
			name[0] = 'G';
			name[1] = 'o';
			name[2] = 'l';
			name[3] = 'e';
			name[4] = 'm';
			return;

}

void Character::attack(Character* other)
{
	other->takeDamage(getDamage());
	
}

float Character::takeDamage(float damageValue)
{
	m_health -= damageValue;
	return damageValue;
}