#pragma once
#include <Game.h>
#include <SDL.h>

class UITesting : public Game
{
public:
	static	void Create();
	virtual void Loop();
	static	void Destroy();

	static UITesting * Get();

	virtual ~UITesting();
protected:
	virtual void Update(float DeltaTime);
	virtual void Render();

private:
	UITesting();

	SDL_Surface* helloWorld;
};