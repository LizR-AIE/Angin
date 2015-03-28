#include "Window.h"
#include <iostream>

Window* Window::m_window = nullptr;

void ErrorCallBack(int error, const char* description)
{
	std::cout << "An error has occurred. Error number: " << error << ". " << description << std::endl;
}

Window::Window(){}

Window::Window(int a_windowWidth, int a_windowHeight, const char* a_windowName)
{
	m_windowWidth = a_windowWidth;
	m_windowHeight = a_windowHeight;
		
	m_windowName = new char[strlen(a_windowName)];
	strcpy(m_windowName, a_windowName);

	glfwSetErrorCallback(ErrorCallBack);

	// Init GLFW and check that init passed
	if (!glfwInit())
	{
		return;
	}

	// Create the window
	m_glfwWindow = glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowName, nullptr, nullptr);

	// Check the window was created successfully
	if (!m_glfwWindow)
	{
		glfwTerminate();
		m_glfwWindow = nullptr;
		return;
	}

	// Make the window current : find out what that means
	glfwMakeContextCurrent(m_glfwWindow);
}

Window::~Window()
{
	if (m_glfwWindow)
	{
		glfwDestroyWindow(m_glfwWindow);
	}
	glfwTerminate();
}

void Window::Create(int a_windowWidth, int a_windowHeight, const char* a_windowName)
{
	if (m_window == nullptr)
		m_window = new Window(a_windowWidth, a_windowHeight, a_windowName);
}

void Window::Destroy()
{
	if (m_window != nullptr)
	{
		delete m_window;
		m_window = nullptr;
	}
}