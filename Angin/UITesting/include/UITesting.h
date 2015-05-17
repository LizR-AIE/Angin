#pragma once
#include <Game.h>

class UITesting : public Game
{
public:
	UITesting();
	virtual ~UITesting();
	
	static void Create();
	static void Destroy();
	static UITesting * Get();

	virtual void Run();

protected:
	virtual void Update(float deltaTime);
	virtual void Render();
};