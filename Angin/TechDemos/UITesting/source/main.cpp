#include <Window.h>
#include "UITesting.h"

#ifdef _DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
#endif

int main(int argc, char* args[])
{
	{
		Window::Create(1280, 720, "UITesting");
		{
			UITesting::Create();
			UITesting::Get()->Run();
			UITesting::Destroy();
		}
		Window::Destroy();
	}

#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}