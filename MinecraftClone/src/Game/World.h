#pragma once

#include "Core/VBO.h"
#include "Core/EBO.h"
#include "Core/Program.h"
#include "Shapes.h"
#include "Core/SceneCamera.h"
#include "Window.h"
#include "Chunk.h"

using namespace Engine3D;

class World
{
public:

	World()
	{
		mvp = glm::mat4(1.0f);

		m_Chunk = Chunk();



		m_Vbo = new VBO(m_Chunk.vertices);
		m_Ebo = new EBO(m_Chunk.indices);

		m_Program = new Program(new Shader(GL_VERTEX_SHADER, "vertex.shader"),
											new Shader(GL_FRAGMENT_SHADER, "fragment.shader"));
	}

	void Render()
	{
		m_Vbo->Bind();
		m_Ebo->Bind();
		m_Program->UseProgram();

		unsigned int id = glGetUniformLocation(m_Program->Id(), "mvp");
		glm::mat4 view = SceneCamera::ViewMatrix();
		glm::mat4 projection = glm::perspective<float>(80.0f,
													  (float)Window::GetWidth() / (float)Window::GetHeight(),
													   0.1f, 1000.0f);
		mvp = projection * view;
		glUniformMatrix4fv(id, 1, false, glm::value_ptr(mvp));
		glDrawElements(GL_TRIANGLES, m_Chunk.indices.size(), GL_UNSIGNED_INT, 0);
	}
private:
	Program* m_Program;
	VBO* m_Vbo;
	EBO* m_Ebo;
	Chunk m_Chunk;
	glm::mat4 mvp;
};

