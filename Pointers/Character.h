#pragma once
class Character
{
public:
	Character();
	Character(float health, float damage);
	Character(float health, float damage, int enemy);

	void attack(Character* other);
	float takeDamage(float damageValue);
	float getDamage() { return m_damage; }
	float getHealth() { return m_health; }
	void setLetter(int index, char letter)
	{
		if(index < 10 && index > 0)
			name[index] = letter; 
	}
	char name[10] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
	float* health = &m_health;
	float* damage = &m_damage;

private:
	float m_health;
	float m_damage;

};

