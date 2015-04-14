#include "Space.h"

Game * Game::m_game = nullptr;

Space::Space()
{
	
}

Space::~Space()
{

}

void Space::Create()
{
	if (m_game == nullptr)
		m_game = new Space();
}

void Space::Loop()
{
	
}

void Space::Destroy()
{
	if (m_game != nullptr)
	{
		delete m_game;
		m_game = nullptr;
	}
}