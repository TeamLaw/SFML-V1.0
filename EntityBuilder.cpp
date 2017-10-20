#include "Environment.h"

void buildPlayer(std::shared_ptr<Room> room)
{
	player.setMaxHealth(100);
	player.setHealth(100);
	player.setDamage(10);
	player.setCurrentRoom(room);
	player.setFillColor(sf::Color::Green);
	player.center();
}

Enemy buildEnemy(std::shared_ptr<Room> room)
{
	int x = room->getPosition().x + 10, y = room->getPosition().y + 10,
		sizeX = room->getSize().x - 10, sizeY = room->getSize().y - 10;

	Enemy enemy;
	enemy.setMaxHealth(20);
	enemy.setHealth(20);
	enemy.setDamage(4);
	enemy.setFillColor(sf::Color::Red);
	enemy.setPosition(random(x, sizeX), random(y, sizeY));

	return enemy;
}