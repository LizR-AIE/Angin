#pragma once

#define CreateWindow Window::Create
#define CloseWindow Window::Destroy

const class Window
{
public:
	static void Create(unsigned int windowWidth, unsigned int windowHeight, bool fullScreen);
	static void Destroy();
	~Window();


private:
	Window();
	
};

