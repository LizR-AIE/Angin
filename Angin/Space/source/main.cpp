#include <Window.h>
#include "Space.h"

int main()
{
	CreateWindow(1600, 720, false);
	Begin();
	Run();
	End();
	CloseWindow();

	return 0;
}