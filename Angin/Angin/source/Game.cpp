#include "Game.h"

Game * Game::m_game = nullptr;
unsigned int Game::m_windowWidth = 1920;
unsigned int Game::m_windowHeight = 1080;
bool Game::m_fullScreen = false;

Game::Game()
{
	
}

Game::~Game()
{

}

void Game::Create()
{
	m_game = new Game();
}

void Game::Loop()
{

}

void Game::Destroy()
{
	if (m_game != nullptr) 
	{
		delete m_game;
		m_game = nullptr;
	}
}