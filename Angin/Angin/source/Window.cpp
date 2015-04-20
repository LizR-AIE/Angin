#include "Window.h"
#include <iostream>

Window* Window::m_window = nullptr;

Window::Window()
{
	m_sdlWindow = nullptr;
	m_sdlSurface = nullptr;
	m_windowName = nullptr;
}

Window::Window(int a_windowWidth, int a_windowHeight, const char* a_windowName)
{
	m_windowWidth = a_windowWidth;
	m_windowHeight = a_windowHeight;
		
	m_windowName = new char[strlen(a_windowName) + 1];
	strcpy(m_windowName, a_windowName);

	//glfwSetErrorCallback(ErrorCallBack);

	// Init GLFW and check that init passed
	if (!SDL_Init( SDL_INIT_VIDEO ) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return;
	}

	// Create the window
	m_sdlWindow = SDL_CreateWindow(m_windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_windowWidth, m_windowHeight, SDL_WINDOW_SHOWN);

	// Check the window was created successfully
	if (!m_sdlWindow)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		m_sdlWindow = nullptr;
		return;
	}

	//Get window surface
	m_sdlSurface = SDL_GetWindowSurface(m_sdlWindow);

	//Fill the surface white
	SDL_FillRect(m_sdlSurface, NULL, SDL_MapRGB(m_sdlSurface->format, 0xFF, 0xFF, 0xFF));

	//Update the surface
	SDL_UpdateWindowSurface(m_sdlWindow);
}

Window::~Window()
{
	if (m_sdlWindow)
	{
		SDL_DestroyWindow(m_sdlWindow);
	}
	SDL_Quit();

	if (m_windowName != nullptr)
	{
		delete m_windowName;
		m_windowName = nullptr;
	}
}

void Window::Create(int a_windowWidth, int a_windowHeight, const char* a_windowName)
{
	if (m_window == nullptr)
		m_window = new Window(a_windowWidth, a_windowHeight, a_windowName);
}

void Window::Destroy()
{
	if (m_window != nullptr)
	{
		delete m_window;
		m_window = nullptr;
	}
}