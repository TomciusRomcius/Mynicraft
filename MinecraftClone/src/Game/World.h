#pragma once
#include "Chunk.h"

using namespace Engine3D;

const int VIEW_DISTANCE = 6;
const int BLEND_FACTOR = 6;

class World
{
public:
	World();
	void Render();
private:
	void BlendChunks();
	std::vector<Chunk> chunks;
};

