#include "Game.h"

Game * Game::m_game = nullptr;

Game::Game()
{
	
}

Game::~Game()
{

}

void Game::Create()
{
	if (m_game == nullptr)
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