#include "pch.h"
#include <iostream>
#include "Window.h"
#include "../Core/SceneCamera.h"
#include "World.h"

using namespace Engine3D;

int main()
{
	if (!Window::Initialize("Minycraft", 1280, 720))
		return -1;
	GLFWwindow* window = Window::m_GlfwWindow;

	World world = World();

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		SceneCamera::Move();
		world.Render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
