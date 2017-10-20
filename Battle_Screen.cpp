#include "screens.h"

screen_Battle::screen_Battle(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;
	playing = false;
}

int screen_Battle::Run(sf::RenderWindow &App, Enemy * enemy)
{
	App.setTitle("Fight!");
	//get player health
	//int Health = game::GameLogic::THE_PLAYER.health;
	playing = true;

	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}
	//PLAYER SHAPE-----------------------------------------
	sf::RectangleShape Player;
	sf::Texture texPlayer;
	if (!texPlayer.loadFromFile("knight.jpg"))
	{
		std::cerr << "Knight didnt load";
	}
	Player.setTexture(&texPlayer, true);
	Player.setSize(sf::Vector2f(400.f, 400.f));
	Player.setPosition(20, 500);
	//end PLAYER SHAPE--------------------------------------

	//Monster SHAPE-----------------------------------------
	sf::RectangleShape RectEnemy;
	sf::Texture texPlayer1;
	if (!texPlayer1.loadFromFile("Domo.png"))
	{
		std::cerr << "Domo.png didnt load";
	}
	RectEnemy.setTexture(&texPlayer1, true);
	RectEnemy.setSize(sf::Vector2f(300.f, 300.f));
	RectEnemy.setPosition(580, 100);
	//end Monster SHAPE--------------------------------------

	//ButtonA SHAPE-----------------------------------------
	sf::RectangleShape ButtonA;
	sf::Text Attack;
	Attack.setFont(font);
	ButtonA.setTexture(&texPlayer1, true);
	ButtonA.setSize(sf::Vector2f(500.f, 100.f));
	ButtonA.setPosition(0, 900);
	//end ButtonA SHAPE--------------------------------------

	//ButtonA SHAPE-----------------------------------------
	sf::RectangleShape ButtonF;
	sf::Text Flee;
	Flee.setFont(font);
	ButtonF.setTexture(&texPlayer1, true);
	ButtonF.setSize(sf::Vector2f(500.f, 100.f));
	ButtonF.setPosition(500, 900);
	//end ButtonA SHAPE--------------------------------------

	sf::CircleShape shape(50.f, 10);
	shape.setFillColor(sf::Color::Red);


	sf::Text attack;
	attack.setPosition(200, 200);
	attack.setString("ATTACK!");
	attack.setFont(font);
	attack.setCharacterSize(30);
	attack.setFillColor(sf::Color::Black);

	sf::Text mouse;
	mouse.setPosition(300, 300);

	mouse.setFont(font);
	mouse.setCharacterSize(30);
	mouse.setFillColor(sf::Color::Black);
	sf::Event event;
	while (App.isOpen())
	{
		while (App.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				// Escape key : exit
				if (event.key.code == sf::Keyboard::Escape)
				{
					return 0;
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))//Mouse Clicked
			{
				//sf::Vector2i pos3 = sf::Mouse::getPosition(App);
				enemy->setHealth(0);
				return 1	;
			}
		}
		App.clear(sf::Color::White);
		App.draw(RectEnemy);
		App.draw(attack);
		App.draw(Player);
		//App.draw(ButtonA);
		//App.draw(ButtonF);
		App.display();
	}

	return EXIT_SUCCESS;
}