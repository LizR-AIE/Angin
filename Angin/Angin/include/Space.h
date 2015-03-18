#pragma once
#include "Game.h"

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

