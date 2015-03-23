#include "Space.h"

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
	{
		delete m_game;
		m_game = nullptr;
	}
}