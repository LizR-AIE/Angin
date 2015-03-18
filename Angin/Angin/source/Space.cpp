#include "Space.h"

Game * Game::m_game = nullptr;
unsigned int Game::m_windowWidth = 1920;
unsigned int Game::m_windowHeight = 1080;
bool Game::m_fullScreen = false;

Space::Space()
{

}

Space::~Space()
{

}

void Space::Create()
{
	m_game = new Space();
}

void Space::Loop()
{
	
}

void Space::Destroy()
{
	if (m_game != nullptr)
		delete m_game;
}