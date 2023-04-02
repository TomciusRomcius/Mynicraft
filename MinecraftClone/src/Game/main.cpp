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

	using clock = std::chrono::high_resolution_clock;
	
	auto t1 = clock::now();
	auto t2 = clock::now();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(.65f, .9f, 1, 1); // Background
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		t1 = t2;
		t2 = clock::now();
		float deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() / 1000000.0f;
		Time::DeltaTime = deltaTime;

		SceneCamera::Move();
		
		world.Render();


		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
