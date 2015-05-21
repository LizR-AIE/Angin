#include "Window.h"
#include <iostream>

Window* Window::window = nullptr;

Window::Window()
{
	sdlWindow = nullptr;
	sdlSurface = nullptr;
	windowName = nullptr;
}

Window::Window(int a_windowWidth, int a_windowHeight, const char* a_windowName)
{
	windowWidth = a_windowWidth;
	windowHeight = a_windowHeight;
		
	windowName = new char[strlen(a_windowName) + 1];

	strcpy_s(windowName, strlen(a_windowName) + 1, a_windowName);
	
	// Init SDL2 and check that init passed
	if (SDL_Init( SDL_INIT_EVERYTHING ) != 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return;
	}
	/*
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

	SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE, 8);

	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 2);
	*/
	/*
	SDL_WINDOW_FULLSCREEN			fullscreen window
	SDL_WINDOW_FULLSCREEN_DESKTOP	fullscreen window at the current desktop resolution
	SDL_WINDOW_OPENGL				window usable with OpenGL context
	SDL_WINDOW_HIDDEN				window is not visible
	SDL_WINDOW_BORDERLESS			no window decoration
	SDL_WINDOW_RESIZABLE			window can be resized
	SDL_WINDOW_MINIMIZED			window is minimized
	SDL_WINDOW_MAXIMIZED			window is maximized
	SDL_WINDOW_INPUT_GRABBED		window has grabbed input focus
	SDL_WINDOW_ALLOW_HIGHDPI		window should be created in high-DPI mode if supported (>= SDL 2.0.1)
	*/
	// Create the window
	sdlWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_OPENGL);
	
	// Check the window was created successfully
	if (!sdlWindow)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		sdlWindow = nullptr;
		return;
	}

	sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// Getting(creating) the window context
	sdlGLContext = SDL_GL_CreateContext(sdlWindow);

	// Get window surface
	sdlSurface = SDL_GetWindowSurface(sdlWindow);
}

Window::~Window()
{
	if (sdlGLContext)
	{
		SDL_GL_DeleteContext(Window::Get()->GetGLContext());
	}

	if (sdlWindow)
	{
		SDL_DestroyWindow(sdlWindow);
	}
	SDL_Quit();

	if (windowName != nullptr)
	{
		delete windowName;
		windowName = nullptr;
	}
}

void Window::Create(int a_windowWidth, int a_windowHeight, const char* a_windowName)
{
	if (window == nullptr)
		window = new Window(a_windowWidth, a_windowHeight, a_windowName);
}

void Window::Destroy()
{
	if (window != nullptr)
	{
		delete window;
		window = nullptr;
	}
}