#pragma once
class Character
{
public:
	Character();
	Character(float health, float damage);
	Character(float health, float damage, int enemy);

	void attack(Character* other);
	float takeDamage(float damageValue);

	/*float getDamage() { return damage; }
	float getHealth() { return health; }*/

	void setLetter(int index, char letter)
	{
		if(index < 10 && index >= 0)
			name[index] = letter; 
	}
	char name[10] = { 0,0,0,0,0,0,0,0,0,0};

private:
	float m_health;
	float m_damage;
	int m_exp;
public:
	int* exp = &m_exp;
	float* health = &m_health;
	float* damage = &m_damage;
};

