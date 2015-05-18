#include "InputHandler.h"
#include <SDL_keycode.h>


InputHandler* InputHandler::m_inputHandler = nullptr;

InputHandler::InputHandler()
{
	
}

InputHandler::~InputHandler()
{

}

void InputHandler::Create()
{
	if (m_inputHandler == nullptr)
		m_inputHandler = new InputHandler();
}

void InputHandler::Destroy()
{
	if (m_inputHandler != nullptr)
	{
		delete m_inputHandler;
		m_inputHandler = nullptr;
	}
}