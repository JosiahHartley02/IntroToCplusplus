#pragma once
class Character
{
public:
	Character();
	Character(float health, float damage);

	void attack(Character other);
	float takeDamage(float damageValue);
	float getDamage() { return m_damage; }

private:
	float m_health;
	float m_damage;
};

