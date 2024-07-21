#pragma once
#include "pch.h"
#include "Shapes.h"
#include "Block.h"
#include "Game/ChunkRenderer.h"

const int MAX_LENGTH = 16;
const int MAX_HEIGHT = 32;
const float HEIGHT_VARIATION = 10000.0f;

using namespace Engine3D;

class Chunk
{
public:
	Chunk(int chunkX, int chunkZ);
	void Render();
    std::array<std::array<int, MAX_LENGTH>, MAX_LENGTH> heightMap;
	std::vector<unsigned int> indices;
	std::function<float(float, float)> octave2D_01;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> texCoords;
	void GenerateMesh();
private:
	ChunkRenderer chunkRenderer;
	// Mesh stuff
	int chunkX;
	int chunkZ;
	std::unordered_set<glm::vec3> airBlockPositions;
};

