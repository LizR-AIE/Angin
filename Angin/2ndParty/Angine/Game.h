#pragma once

#define WindowWidth Game::GetWindowWidth()
#define WindowHeight Game::GetWindowHeight()
#define FullScreen Game::IsFullScreen()

class Game
{
public:
	static void Create();
	virtual void Loop();
	static void Destroy();
	virtual ~Game();

	inline static Game * Get(){ return m_game; }
	inline static unsigned int GetWindowWidth(){ return m_windowWidth; }
	inline static unsigned int GetWindowHeight(){ return m_windowHeight; }
	inline static bool IsFullScreen() { return m_fullScreen; }

protected:
	Game();
	static Game * m_game;

private:
	static unsigned int m_windowWidth;
	static unsigned int m_windowHeight;
	static bool m_fullScreen;
};