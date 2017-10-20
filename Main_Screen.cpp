#include "TowerCrawl.h"
#include "Entities.h"
#include "Environment.h"
#include "screens.h"

screen_Main::screen_Main(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;
	playing = false;
}

int screen_Main::Run(sf::RenderWindow &win)
{
	// Start game loop
	while (win.isOpen())
	{
		// Process events
		sf::Event Event;
		while (win.pollEvent(Event))
		{
			// Close window : exit
			if (Event.type == sf::Event::Closed)
				win.close();

			// A key has been pressed
			if (Event.type == sf::Event::KeyPressed)
			{
				// Escape key : exit
				if (Event.key.code == sf::Keyboard::Escape)
					win.close();
			}
		}
		win.clear();

		player.input();
		win.draw(*player.getCurrentRoom());

		if (player.getCurrentRoom()->getEnemy()->getHealth())
		{
			player.getCurrentRoom()->getEnemy()->followPlayer();
			win.draw(*player.getCurrentRoom()->getEnemy());
		}
		for (auto& r : player.getCurrentRoom()->getDoors()) win.draw(r.second.second);
		win.draw(player);
		win.display();
	}

	return EXIT_SUCCESS;
}