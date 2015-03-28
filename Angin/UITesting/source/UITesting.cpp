#include "UITesting.h"
#include <iostream>

Game * Game::m_game = nullptr;

UITesting::UITesting()
{
	
}

UITesting::~UITesting()
{

}

void UITesting::Create()
{
	if (m_game == nullptr)
		m_game = new UITesting();
}

void UITesting::Loop()
{
	std::cout << "Hello World!" << std::endl;
}

void UITesting::Destroy()
{
	if (m_game != nullptr)
	{
		delete m_game;
		m_game = nullptr;
	}
}

UITesting * UITesting::Get()
{
	return (UITesting*)(Game::m_game);
}