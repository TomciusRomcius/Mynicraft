#include "pch.h"
#include "Window.h"
#include <Core/Event.h>


GLFWwindow* Window::m_GlfwWindow = nullptr;
int Window::m_Width = 0;
int Window::m_Height = 0;
const char* Window::m_Title = "";


bool Window::Initialize(const char* title, int width, int height)
{
	m_Title = title; m_Width = width; m_Height = height;

	// Initialize GLFW and GLEW


	if (!glfwInit())
	{
		EN_ERROR("Failed to initialize GLFW")
		return false;
	}

	m_GlfwWindow = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
	if (m_GlfwWindow == nullptr)
	{
		EN_ERROR("Failed to create the window")
		return false;
	}

	glfwMakeContextCurrent(m_GlfwWindow);
	if (glewInit() != GLEW_OK)
	{
		EN_ERROR("Failed to initialize GLEW")
		return false;
	}
	Engine3D::DebugLayer::Initialize(m_GlfwWindow);
	Engine3D::Event::Initialize(m_GlfwWindow);
	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, m_Width, m_Height);

	return true;
}
