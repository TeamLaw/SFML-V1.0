#include "Environment.h"

std::shared_ptr<Room> buildRoom()
{
	std::shared_ptr<Room> room(new Room(sf::Vector2f(random(350, 750), random(350, 750))));
	room->setFillColor(sf::Color::White);
	room->setOutlineColor(sf::Color::Black);
	room->setOutlineThickness(1.0f);
	room->setPosition(100, 100);

	if (player.getCurrentRoom() != nullptr) { room->setEnemy(buildEnemy(room)); }

	delPointers[delCounter] = room;
	delCounter++;

	return room;
}

int buildDoor(std::shared_ptr<Room> room, enum Direction dir, float x, float y)
{
	sf::RectangleShape door;
	door.setFillColor(sf::Color::Magenta);
	if (random(1, 100) < branch)
	{
		if (dir == North || dir == South) { door.setSize(sf::Vector2f(50, 10)); }
		else { door.setSize(sf::Vector2f(10, 50)); }
		door.setPosition(x, y);
		room->addDoor(dir, std::pair<std::shared_ptr<Room>, sf::RectangleShape>(buildRoom(), door));
		return 1;
	}
	return 0;
}

void checkDoors()
{//TODO: Fix bias towards north->south->west->east order, eventually do better procedural generation
	int counter = 0;

	std::shared_ptr<Room> room = player.getCurrentRoom();

RETRY:
	if (!room->getDoors().count(North)) { counter += buildDoor(room, North, room->getPosition().x + (room->getSize().x / 2) - 25, room->getPosition().y - 5); }
	if (!room->getDoors().count(South)) { counter += buildDoor(room, South, room->getPosition().x + (room->getSize().x / 2) - 25, room->getPosition().y + room->getSize().y - 5); }
	if (!room->getDoors().count(West)) { counter += buildDoor(room, West, room->getPosition().x - 5, room->getPosition().y + (room->getSize().y / 2) - 25); }
	if (!room->getDoors().count(East)) { counter += buildDoor(room, East, room->getPosition().x + room->getSize().x - 5, room->getPosition().y + (room->getSize().y / 2) - 25); }
	
	if (minCheck(1) && delCounter < 10) { goto RETRY; }
	branch -= (counter - 1) * 5;

	room->setEntered(true);	
}

void addPrevDoor(enum Direction dir, std::shared_ptr<Room> oldRoom, std::shared_ptr<Room> newRoom, sf::RectangleShape door)
{
	float x, y;
	switch (dir)
	{
	case North:
		x = newRoom->getPosition().x + (newRoom->getSize().x / 2) - 25;
		y = newRoom->getPosition().y - 5;
		player.setPosition(x + 25, y + 10);
		break;
	case South: 
		x = newRoom->getPosition().x + (newRoom->getSize().x / 2) - 25;
		y = newRoom->getPosition().y + newRoom->getSize().y - 5;
		player.setPosition(x + 25, y - 10);
		break;
	case West: 
		x = newRoom->getPosition().x - 5;
		y = newRoom->getPosition().y + (newRoom->getSize().y / 2) - 25;
		player.setPosition(x + 10, y + 25);
		break;
	case East: 
		x = newRoom->getPosition().x + newRoom->getSize().x - 5;
		y = newRoom->getPosition().y + (newRoom->getSize().y / 2) - 25;
		player.setPosition(x - 10, y + 25);
		break;
	}
	door.setPosition(x, y);
	newRoom->addDoor(dir, std::pair<std::shared_ptr<Room>, sf::RectangleShape>(oldRoom, door));
}