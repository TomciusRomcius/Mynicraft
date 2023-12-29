#pragma once
#include "Chunk.h"

using namespace Engine3D;

const int VIEW_DISTANCE = 2;

class World
{
public:
	World();
	void Render();
private:
	std::vector<Chunk> chunks;
};

