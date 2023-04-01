#pragma once

#include "Core/VBO.h"
#include "Core/EBO.h"
#include "Core/Program.h"
#include "Shapes.h"
#include "Core/SceneCamera.h"

using namespace Engine3D;

class World
{
public:

	World()
	{
		m_Cube = Cube();
		mvp = glm::mat4(1.0f);

		m_Vbo = std::make_unique<VBO>(m_Cube.vertices);
		m_Ebo = std::make_unique<EBO>(m_Cube.indices);

		m_Program = std::make_unique<Program>(new Shader(GL_VERTEX_SHADER, "vertex.shader"),
											new Shader(GL_FRAGMENT_SHADER, "fragment.shader"));
		m_Program->UseProgram();
	}

	void Render()
	{
		m_Vbo->Bind();
		m_Ebo->Bind();
		m_Program->UseProgram();

		unsigned int id = glGetUniformLocation(m_Program->Id(), "mvp");
		glm::mat4 view = SceneCamera::ViewMatrix();
		glm::mat4 projection = glm::perspective(80, Window::GetWidth() / Window::GetHeight(), .1, 1000);
		glUniform4fv(id, 1, glm::value_ptr(mvp));
		glDrawElements(GL_TRIANGLES, m_Cube.indices.size(), GL_UNSIGNED_INT, 0);
	}
private:
	std::unique_ptr<Program> m_Program;
	std::unique_ptr<VBO> m_Vbo;
	std::unique_ptr<EBO> m_Ebo;
	Cube m_Cube;
	glm::mat4 mvp;
};

