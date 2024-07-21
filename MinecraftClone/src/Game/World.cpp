#include "pch.h"
#include "World.h"

extern const int MAX_LENGTH; // Found in Chunk.h

World::World()
{
	for (int chunkX = 0; chunkX < VIEW_DISTANCE; chunkX++)
	{
		for (int chunkZ = 0; chunkZ < VIEW_DISTANCE; chunkZ++)
		{
			chunks.push_back(Chunk(chunkX, chunkZ));
		}
	}
	BlendChunks();
	BlendChunks();
	for (auto& chunk : chunks)
	{
		chunk.GenerateMesh();
	}
}

void World::Render()
{
	for (auto& chunk : chunks)
	{
		chunk.Render();
	}
}

void World::BlendChunks()
{
	for (int i = 0; i < chunks.size(); i++)
	{
		// Blend heightmaps on the z axis by rounding the heightMap values
		if (i + 1 < chunks.size())
		{

			for (int x = 0; x < MAX_LENGTH - BLEND_FACTOR; x++) {
				for (int z = MAX_LENGTH - BLEND_FACTOR; z < MAX_LENGTH; z++) {
					chunks[i].heightMap[x][z] = round((chunks[i].heightMap[x][z - 1] + chunks[i + 1].heightMap[x][0]) / 2);
				}
			}
		}
		// Blend heighmaps on the x axis by rounding the heightMap values
		if (i + VIEW_DISTANCE < chunks.size())
		{
			for (int x = MAX_LENGTH - BLEND_FACTOR; x < MAX_LENGTH; x++) {
				for (int z = 0; z < MAX_LENGTH - BLEND_FACTOR; z++) {
					chunks[i].heightMap[x][z] = round((chunks[i].heightMap[x - 1][z] + chunks[i + VIEW_DISTANCE].heightMap[0][z]) / 2);
				}
				
			}
		}
	}

	for (int i = 0; i < chunks.size(); i++) {
		// Blend corners
		if (i + VIEW_DISTANCE + 1 < chunks.size())
		{
			for (int x = MAX_LENGTH - BLEND_FACTOR; x < MAX_LENGTH; x++) {
				for (int z = MAX_LENGTH - BLEND_FACTOR; z < MAX_LENGTH; z++) {
					chunks[i].heightMap[x][z] = round((chunks[i].heightMap[x - 1][z - 1] + chunks[i + VIEW_DISTANCE + 1].heightMap[0][0]) / 2);
				}
			}
		}
	}
}
