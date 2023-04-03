#include "pch.h"
#include "World.h"
#include "Block.h"

World::World()
{
	mvp = glm::mat4(1.0f);

	m_Chunk = new Chunk();



	m_Vbo = new VBO(m_Chunk->vertices, m_Chunk->texCoords);
	m_Ebo = new EBO(m_Chunk->indices);
	texture = new Texture("Textures/atlas.png");
	m_Program = new Program(new Shader(GL_VERTEX_SHADER, "vertex.shader"),
		new Shader(GL_FRAGMENT_SHADER, "fragment.shader"));
}

void World::AddBlock(const Block& block)
{
	for (auto v : block.GetVertices())
	{
		m_Chunk->vertices.push_back(v);
	}
	for (auto uv : block.GetUV())
	{
		m_Chunk->texCoords.push_back(uv);
	}
	for (auto in : block.GetIndices())
	{
		m_Chunk->indices.push_back(m_Chunk->vertices.size() - block.GetVertices().size() + in);
	}

	delete m_Vbo;
	delete m_Ebo;

	m_Vbo = new VBO(m_Chunk->vertices, m_Chunk->texCoords);
	m_Ebo = new EBO(m_Chunk->indices);
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
