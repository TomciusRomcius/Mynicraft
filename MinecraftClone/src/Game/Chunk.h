#pragma once
#include "pch.h"
#include "Shapes.h"
#include "Block.h"

const int MAX_LENGTH = 32;
const int MAX_HEIGHT = 32;
const float HEIGHT_VARIATION = 1000.0f;

class Chunk
{
public:
	Chunk(int chunkX, int chunkZ);
	void GenerateMesh();
	bool IsNeighborAir(glm::vec3 cube);
    std::array<std::array<int, MAX_LENGTH>, MAX_LENGTH> heightMap;
	std::unordered_set<glm::vec3> airBlockPositions;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> texCoords;
	std::vector<unsigned int> indices;
	std::function<float(float, float)> octave2D_01;

};

