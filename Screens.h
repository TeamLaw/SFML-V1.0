#ifndef SCREENS_HPP_INCLUDED
#define SCREENS_HPP_INCLUDED

//Basic Screen Class
#include "TowerCrawl.h"
#include "SFML\Graphics\RenderWindow.hpp"
#include <SFML/Graphics/Text.hpp>
#include "Entities.h"
#include "Environment.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <time.h>
#include <iostream>

extern sf::RenderWindow win;


class screen_Main {

	int alpha_max;
	int alpha_div;
	bool playing;
public:
	screen_Main(void);
	int Run(sf::RenderWindow &);
};

class screen_Battle {
	int alpha_max;
	int alpha_div;
	bool playing;
public:
	screen_Battle(void);
	int Run(sf::RenderWindow &, Enemy *);
};

#endif
