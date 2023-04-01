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

	Background bg = Background();

	VBO* vbo = new VBO(bg.vertices);
	EBO* ebo = new EBO(bg.indices);
	Program* program = new Program(new Shader(GL_VERTEX_SHADER, "backgroundvert.shader"),
		new Shader(GL_FRAGMENT_SHADER, "backgroundfrag.shader"));
	World world = World();

	using clock = std::chrono::high_resolution_clock;
	
	auto t1 = clock::now();
	auto t2 = clock::now();

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		t1 = t2;
		t2 = clock::now();
		float deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() / 1000000.0f;
		Time::DeltaTime = deltaTime;

		SceneCamera::Move();
		
		vbo->Bind();
		ebo->Bind();
		program->UseProgram();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		world.Render();


		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
