#pragma once
#include "pch.h"
#include "Shapes.h"

const int MAX_LENGTH = 16;
const int MAX_HEIGHT = 32;

class Chunk
{
public:
	Chunk();
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> texCoords;
	std::vector<unsigned int> indices;


};

