#include "TowerCrawl.h"
#include "Entities.h"
#include "Environment.h"
#include "Screens.h"

time_t t;
Player player;
int branch = 25;
int delCounter = 0;
std::shared_ptr<Room> delPointers[1000];
sf::RenderWindow win(sf::VideoMode(1000, 1000), "test");

int main()
{
	screen_Main winM;
	srand((unsigned)time(&t));

	buildPlayer(buildRoom());
	if (!player.getCurrentRoom()->getEntered()) { checkDoors(); }

	winM.Run(win);

	return EXIT_SUCCESS;
}

bool minCheck(int mod)
{
	for (int i = 0; i < delCounter; i++) { mod += delPointers[i]->getEntered(); }

	return (mod == delCounter);
}
