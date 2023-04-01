#pragma once

#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "../Core/Log.h"
#include "../Core/DebugLayer.h"

class Window
{
public:
	static bool Initialize(const char* title, int width, int height);
	static GLFWwindow* m_GlfwWindow;
	static int GetWidth()
	{
		return m_Width;
	}
	static int GetHeight()
	{
		return m_Height;
	}
private:
	static const char* m_Title;
	static int m_Width;
	static int m_Height;
};

