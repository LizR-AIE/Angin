#pragma once
#include <Game.h>


class UITesting : public Game
{
public:
	static	void Create();
	virtual void Loop();
	static	void Destroy();

	static UITesting * Get();

	virtual ~UITesting();
protected:

private:
	UITesting();
};