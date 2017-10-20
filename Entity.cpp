#include "Entities.h"
#include "Environment.h"
#include "Screens.h"

void Player::doorInteraction()
{
	enum Direction dir;
	sf::FloatRect r1 = this->getGlobalBounds();
	sf::FloatRect r2;
	for (auto& r : roomLoc->getDoors())
	{
		r2 = r.second.second.getGlobalBounds();
		if (r1.intersects(r2))
		{
			switch (r.first) { case North: dir = South; break; case South: dir = North; break; case West: dir = East; break; case East: dir = West; break; }

			addPrevDoor(dir, roomLoc, r.second.first, r.second.second);
			roomLoc = r.second.first;
			if (!r.second.first->getEntered()) { checkDoors(); }

			break;
		}
	}
}

void Player::input()
{
	this->doorInteraction();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->move(0, (this->getPosition().y <= roomLoc->getPosition().y ? 0 : -speed));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->move(0, (this->getPosition().y + this->getSize().y >= roomLoc->getPosition().y + roomLoc->getSize().y ? 0 : speed));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move((this->getPosition().x <= roomLoc->getPosition().x ? 0 : -speed), 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move((this->getPosition().x + this->getSize().x >= roomLoc->getPosition().x + roomLoc->getSize().x ? 0 : speed), 0);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {}
}

void Player::center()
{
	this->setPosition((roomLoc->getSize().x / 2) + roomLoc->getPosition().x,
		(roomLoc->getSize().y / 2) + roomLoc->getPosition().y);
}

void Enemy::followPlayer()
{
	this->interactionPlayer();
	this->move(0, (this->getPosition().y < player.getPosition().y ? speed : -speed));
	this->move((this->getPosition().x < player.getPosition().x ? speed : -speed), 0);
}

void Enemy::interactionPlayer()
{
	screen_Battle winB;
	screen_Main winM;

	auto room = player.getCurrentRoom();

	float midx = room->getPosition().x + room->getSize().x / 2, midy = room->getPosition().y + room->getSize().y / 2;

	if (this->getGlobalBounds().intersects(player.getGlobalBounds()))
	{
		this->setFillColor(sf::Color::Cyan);
		int result = winB.Run(win, this);
		if (!result) { player.setPosition(player.getPosition().x + (player.getPosition().x < midx ? 150 : -150), player.getPosition().y + (player.getPosition().y < midy ? 150 : -150)); }
		winM.Run(win);
	}
	else
		this->setFillColor(sf::Color::Red);
}