#include <iostream>
#include <Window.h>
#include "UITesting.h"
#include <GLFW\glfw3.h>

int main()
{
	Window::Create(1280, 720, "UITesting");

	UITesting::Create();

	while (!glfwWindowShouldClose(Window::Get()->GetWindow()))
	{
		UITesting::Get()->Loop();
	}

	UITesting::Destroy();

	Window::Destroy();
	return 0;
}