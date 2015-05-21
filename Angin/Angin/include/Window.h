#pragma once

#include <SDL.h>

#ifdef ANGIN_EXPORTS
#	define ANGIN_API __declspec(dllexport)
#else
#	define ANGIN_API __declspec(dllimport)
#endif

const class Window
{
public:
	ANGIN_API static void Create(int windowWidth, int windowHeight, const char* windowName);
	ANGIN_API static void Destroy();

	ANGIN_API inline static Window * Get()			{ return window; }

	ANGIN_API inline unsigned int GetWindowWidth()	{ return windowWidth; }
	ANGIN_API inline unsigned int GetWindowHeight() { return windowHeight; }

	ANGIN_API inline SDL_Window		* GetWindow()	{ return sdlWindow; }
	ANGIN_API inline SDL_Surface	* GetSurface()	{ return sdlSurface; }
	ANGIN_API inline SDL_GLContext	* GetGLContext(){ return &sdlGLContext; }

	ANGIN_API ~Window();

private:
	ANGIN_API Window();
	ANGIN_API Window(int windowWidth, int windowHeight, const char * windowName);

	static Window*	window;

	int				windowWidth;
	int				windowHeight;
	char *			windowName;

	SDL_Window *	sdlWindow;
	SDL_Renderer*	sdlRenderer;
	SDL_Surface *	sdlSurface;
	SDL_GLContext	sdlGLContext;

	bool			fullScreen;

};