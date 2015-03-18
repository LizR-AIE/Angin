#pragma once

#define WindowWidth Game::GetWindowWidth()
#define WindowHeight Game::GetWindowHeight()
#define FullScreen Game::IsFullScreen()

class Game
{
public:
	static void Create(){ m_game = new Game(); }
	virtual void Loop(){};
	static void Destroy(){ if (m_game != nullptr) delete m_game; }

	static Game * Get(){ return m_game;	}

	static unsigned int GetWindowWidth(){ return m_windowWidth; }
	static unsigned int GetWindowHeight(){ return m_windowHeight; }
	static bool IsFullScreen() { return m_fullScreen; }

	virtual ~Game(){}

protected:
	Game(){}
	static Game * m_game;

private:
	static unsigned int m_windowWidth;
	static unsigned int m_windowHeight;
	static bool m_fullScreen;
};