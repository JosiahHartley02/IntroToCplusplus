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

void Character::attack(Character other)
{
	other.takeDamage(getDamage());
}

float Character::takeDamage(float damageValue)
{
	m_health -= damageValue;
	return damageValue;
}
