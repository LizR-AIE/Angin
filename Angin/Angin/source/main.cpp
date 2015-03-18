#ifdef _SPACE
#include "Space.h"
#else
#include "Game.h"
#endif

int main()
{
	//CreateWindow(WindowWidth, WindowHeight, FullScreen);
#ifdef _Space
	Space::Create();
	Space::Get()->Loop();
	Space::Destroy();
#else
	Game::Create();
	Game::Get()->Loop();
	Game::Destroy();
#endif
	//CloseWindow();

	return 0;
}