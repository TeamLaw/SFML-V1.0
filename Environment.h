#pragma once

#include "TowerCrawl.h"
#include "Entities.h"

class Room : public sf::RectangleShape {
	bool entered = false;
	std::map<enum Direction, std::pair< std::shared_ptr<Room>, sf::RectangleShape > > doors;
	Enemy enemy;
public:
	Room(sf::Vector2f size = { 100, 100 }) : RectangleShape(size) {}

	void setEnemy(Enemy e) { enemy = e; }
	Enemy * getEnemy() { return &enemy; }
	void setEntered(bool check) { entered = check; }
	bool getEntered() { return entered; }

	std::map<enum Direction, std::pair< std::shared_ptr<Room>, sf::RectangleShape > > getDoors() { return doors; }
	void addDoor(enum Direction dir, std::pair<std::shared_ptr<Room>, sf::RectangleShape> pair) { doors[dir] = pair; }
};

std::shared_ptr<Room> buildRoom();
void addPrevDoor(enum Direction, std::shared_ptr<Room>, std::shared_ptr<Room>, sf::RectangleShape);
void checkDoors();
int buildDoor(std::shared_ptr<Room>, enum Direction, float, float);

extern std::shared_ptr<Room> delPointers[];
extern int delCounter;
