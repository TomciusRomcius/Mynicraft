#include "pch.h"
#include "World.h"

World::World()
{
	mvp = glm::mat4(1.0f);

	m_Chunk = new Chunk();



	m_Vbo = new VBO(m_Chunk->vertices, m_Chunk->texCoords);
	m_Ebo = new EBO(m_Chunk->indices);
	texture = new Texture("Textures/brick.jpg");
	m_Program = new Program(new Shader(GL_VERTEX_SHADER, "vertex.shader"),
		new Shader(GL_FRAGMENT_SHADER, "fragment.shader"));
}

void World::Render()
{
	m_Vbo->Bind();
	m_Ebo->Bind();
	texture->Bind();
	m_Program->UseProgram();
	

	unsigned int id = glGetUniformLocation(m_Program->Id(), "mvp");
	glm::mat4 view = SceneCamera::ViewMatrix();
	glm::mat4 projection = glm::perspective<float>(glm::radians(80.0f),
		(float)Window::GetWidth() / (float)Window::GetHeight(),
		0.1f, 1000.0f);
	mvp = projection * view;
	glUniformMatrix4fv(id, 1, false, glm::value_ptr(mvp));
	glDrawElements(GL_TRIANGLES, m_Chunk->indices.size(), GL_UNSIGNED_INT, 0);
}
