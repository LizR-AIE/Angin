#pragma once

#ifdef ANGIN_EXPORTS
#	define ANGIN_API __declspec(dllexport)
#else
#	define ANGIN_API __declspec(dllimport)
#endif

class Game
{
public:
	ANGIN_API static void Create();
	ANGIN_API virtual void Loop();
	ANGIN_API static void Destroy();
	ANGIN_API virtual ~Game();

	ANGIN_API inline static Game * Get(){ return m_game; }
	
protected:
	ANGIN_API Game();
	static Game * m_game;
};