#pragma once
#include <Game.h>
#include <GameManager.h>
#include <SDL.h>

class UITesting : public Game
{
public:
	UITesting();
	virtual ~UITesting();
	virtual void Run();

protected:
	GameManager gameManager;
};