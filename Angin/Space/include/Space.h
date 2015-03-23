#pragma once
#include <Game.h>

#define Begin Space::Create
#define Run Game::Get()->Loop
#define End Space::Destroy

class Space : public Game
{
public:
	static void Create();
	virtual void Loop();
	static void Destroy();

	virtual ~Space();

protected:
	Space();

private:

};

