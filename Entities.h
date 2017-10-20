#pragma once

#include "TowerCrawl.h"

class Room;

class Entity : public sf::RectangleShape {
protected:
	float health;
	float maxHealth;
	float damage;
	float experience;
	float speed;
public:
	Entity(sf::Vector2f size, const float s) : RectangleShape(size) { speed = s; }

	void setHealth(float hp) { health = hp; }
	float getHealth() { return health; }
	void setMaxHealth(float maxHp) { maxHealth = maxHp; }
	float getMaxHealth() { return maxHealth; }
	void setDamage(float d) { damage = d; }
	float getDamage() { return damage; }
	void setMovementSpeed(const float s) { speed = s; }
	float getMovementSpeed() { return speed; }
};

class Enemy : public Entity {
	bool isBoss = false;
public:
	Enemy(sf::Vector2f size = { 20, 20 }, const float s = .025) : Entity(size, s) { }

	void followPlayer();
	void interactionPlayer();
};

class Player : public Entity {
	std::shared_ptr<Room> roomLoc = nullptr;
public:
	Player(sf::Vector2f size = { 10, 10 }, const float s = .15) : Entity(size, s) { }

	void setCurrentRoom(std::shared_ptr<Room> r) { roomLoc = r; }
	std::shared_ptr<Room> getCurrentRoom() { return roomLoc; }

	void input();
	void center();
	void doorInteraction();
};

void buildPlayer(std::shared_ptr<Room>);//merge with the classes
Enemy buildEnemy(std::shared_ptr<Room>);

extern Player player;