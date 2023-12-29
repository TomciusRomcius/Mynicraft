#include "pch.h"
#include "ChunkRenderer.h"

ChunkRenderer::ChunkRenderer(int chunkX, int chunkZ)
	: chunkX(chunkX), chunkZ(chunkZ), mvp(glm::mat4(1.0f)) { }

void ChunkRenderer::Update(std::vector<glm::vec3> vertices, std::vector<unsigned int> indices, std::vector<glm::vec2> texCoords)
{
	this->vertices = vertices;
	this->indices = indices;
	this->texCoords = texCoords;
	vbo = std::make_unique<VBO>(vertices, texCoords);
	ebo = std::make_unique<EBO>(indices);
	int v = GL_VERTEX_SHADER;
	Shader vertexShader = Shader(GL_VERTEX_SHADER, "vertex.shader");
	Shader fragmentShader = Shader(GL_FRAGMENT_SHADER, "fragment.shader");
	program = std::make_unique<Program>(&vertexShader, &fragmentShader);
	texture = std::make_unique<Texture>("Textures/atlas.png");
}

void ChunkRenderer::Render()
{
	vbo->Bind();
	ebo->Bind();
	texture->Bind();
	program->UseProgram();

	unsigned int id = glGetUniformLocation(program->Id(), "mvp");
	glm::mat4 view = SceneCamera::ViewMatrix();
	glm::mat4 projection = glm::perspective<float>(glm::radians(80.0f),
		(float)Window::GetWidth() / (float)Window::GetHeight(),
		0.1f, 1000.0f);
	mvp = projection * view;
	glUniformMatrix4fv(id, 1, false, glm::value_ptr(mvp));
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}
