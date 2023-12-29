#pragma once

#include "pch.h"
#include "Core/VBO.h"
#include "Core/EBO.h";
#include "Core/Program.h"
#include "Core/SceneCamera.h"
#include "Core/Texture.h"
#include "Game/Window.h"

using namespace Engine3D;

class ChunkRenderer
{
public:
	ChunkRenderer(int chunkX, int chunkZ);
	void Render();
	void Update(std::vector<glm::vec3> vertices, std::vector<unsigned int> indices, std::vector<glm::vec2> texCoords);
private:
	int chunkX;
	int chunkZ;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> texCoords;
	std::vector<unsigned int> indices;
	std::unique_ptr<VBO> vbo;
	std::unique_ptr<EBO> ebo;
	std::unique_ptr<Program> program;
	std::unique_ptr<Texture> texture;
	glm::mat4 mvp;
};

