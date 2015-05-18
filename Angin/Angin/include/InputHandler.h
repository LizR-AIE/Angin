#pragma once

#ifdef ANGIN_EXPORTS
#	define ANGIN_API __declspec(dllexport)
#else
#	define ANGIN_API __declspec(dllimport)
#endif

#include <SDL.h>
#include <SDL_scancode.h>

class InputHandler
{
public:
	//--------------------------------
	// Singleton Related
	//--------------------------------
	ANGIN_API static void Create();
	ANGIN_API static void Destroy();
	ANGIN_API inline static InputHandler * Get(){ return m_inputHandler; }

private:
	// Call Create instead
	ANGIN_API InputHandler();
	// Singleton instance
	static InputHandler * m_inputHandler;

	//--------------------------------
	// Instance Related
	//--------------------------------
public:
	ANGIN_API virtual ~InputHandler();

protected:
	

};

