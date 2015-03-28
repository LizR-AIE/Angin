#pragma once

#include <GLFW\glfw3.h>

#ifdef ANGIN_EXPORTS
#	define ANGIN_API __declspec(dllexport)
#else
#	define ANGIN_API __declspec(dllimport)
#endif

const class Window
{
public:
	ANGIN_API static void Create(int windowWidth, int windowHeight, const char* windowName);
	ANGIN_API static void Destroy();

	ANGIN_API inline static Window * Get() { return m_window; }

	ANGIN_API inline unsigned int GetWindowWidth() { return m_windowWidth; }
	ANGIN_API inline unsigned int GetWindowHeight() { return m_windowHeight; }

	ANGIN_API inline GLFWwindow * GetWindow() { return m_glfwWindow; }

	ANGIN_API ~Window();

private:
	ANGIN_API Window();
	ANGIN_API Window(int windowWidth, int windowHeight, const char * windowName);

	static Window*	m_window;

	int				m_windowWidth;
	int				m_windowHeight;
	char *			m_windowName;

	GLFWwindow *	m_glfwWindow;

	bool			m_fullScreen;

};