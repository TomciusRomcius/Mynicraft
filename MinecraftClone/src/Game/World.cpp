#include "pch.h"
#include "World.h"
#include "Block.h"

World::World()
{
	mvp = glm::mat4(1.0f);
	std::vector<Chunk> chunks;

	/*
	for (int x = 0; x < 8; x++)
		for (int z = 0; z < 8; z++)
		{
			chunks.push_back(Chunk(x, z));
		}	
		*/

	chunks.push_back(Chunk(0, 0));
	int n = 0;
	for (auto& chunk : chunks)
	{
		for (auto& v : chunk.vertices)
		{
			m_Vertices.push_back(v);
		}

		for (auto& uv : chunk.texCoords)
		{
			m_TexCoords.push_back(uv);
		}
		for (auto& in : chunk.indices)
		{
			m_Indices.push_back(in + n * chunk.vertices.size());
		}
		n++;
	}
	
	m_Vbo = new VBO(m_Vertices, m_TexCoords);
	m_Ebo = new EBO(m_Indices);
	m_Texture = new Texture("Textures/atlas.png");
	m_Program = new Program(new Shader(GL_VERTEX_SHADER, "vertex.shader"),
		new Shader(GL_FRAGMENT_SHADER, "fragment.shader"));
}

void World::AddBlock(const Block& block)
{
	for (const auto& v : block.m_Vertices)
	{
		m_Vertices.push_back(v);
	}
	for (const auto& uv : block.m_TexCoords)
	{
		m_TexCoords.push_back(uv);
	}
	for (const auto& in : block.m_Indices)
	{
		//m_Chunk->indices.push_back(m_Chunk->vertices.size() - block.m_Vertices.size() + in);
	}

	delete m_Vbo;
	delete m_Ebo;

	m_Vbo = new VBO(m_Vertices, m_TexCoords);
	m_Ebo = new EBO(m_Indices);
}

void World::Render()
{
	m_Vbo->Bind();
	m_Ebo->Bind();
	m_Texture->Bind();
	m_Program->UseProgram();
	
	unsigned int id = glGetUniformLocation(m_Program->Id(), "mvp");
	glm::mat4 view = SceneCamera::ViewMatrix();
	glm::mat4 projection = glm::perspective<float>(glm::radians(80.0f),
		(float)Window::GetWidth() / (float)Window::GetHeight(),
		0.1f, 1000.0f);
	mvp = projection * view;
	glUniformMatrix4fv(id, 1, false, glm::value_ptr(mvp));
	glDrawElements(GL_TRIANGLES, m_Indices.size(), GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, m_Chunk->vertices.size());
}
