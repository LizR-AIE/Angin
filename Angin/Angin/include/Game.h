#pragma once

#ifdef ANGIN_EXPORTS
#	define ANGIN_API __declspec(dllexport)
#else
#	define ANGIN_API __declspec(dllimport)
#endif

#include <SDL.h>


class Game
{
	//--------------------------------
	// Singleton Related
	//--------------------------------
public:
	ANGIN_API static void Create();
	ANGIN_API static void Destroy();
	ANGIN_API inline static Game * Get(){ return m_game; }

protected:
	// Call Create instead
	ANGIN_API Game();
	// Singleton instance
	static Game * m_game;

	//--------------------------------
	// Instance Related
	//--------------------------------
public:
	ANGIN_API virtual ~Game();
	ANGIN_API virtual void Run();
	ANGIN_API virtual void Update(float deltaTime){};
	ANGIN_API virtual void Render(){};
	// Time since the game was launched
	ANGIN_API virtual float TimeSinceLaunch();

protected:
	ANGIN_API void PollEvents();
	// Call this only once per frame
	ANGIN_API void UpdateDeltaTime();
	
	float deltaTime;
	
private:
	Uint32 thisTotalTicks;
	Uint32 lastTotalTicks;
	float timeSinceLaunch;
};