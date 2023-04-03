#pragma once
#include "pch.h"
#include "Shapes.h"
#include "Block.h"

const int MAX_LENGTH = 8;
const int MAX_HEIGHT = 16;

class Chunk
{
public:
	Chunk(int chunkX, int chunkZ);
	bool IsNeighborAir(glm::vec3 cube);
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> texCoords;
	std::vector<unsigned int> indices;


};

