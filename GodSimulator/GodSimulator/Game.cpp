#include"Game.h"

Game::Game()
{
	rgen = new RandomGenerator;

	pPlayer = new God;
}

void Game::Run()
{
	srand(time(NULL));

	int b = 0;

	string name;
	cin >> name;

	pPlayer->SetName(name);
}