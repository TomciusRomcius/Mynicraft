#include "pch.h"
#include "World.h"

World::World()
{
	chunks.push_back(Chunk(1, 1));
}

void World::Render()
{
	for (auto& chunk : chunks)
	{
		chunk.Render();
	}
}
