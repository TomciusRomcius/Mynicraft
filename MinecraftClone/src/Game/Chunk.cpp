#include "pch.h"
#include "Chunk.h"
#include "PerlinNoise.hpp"

Chunk::Chunk(int chunkX, int chunkZ)
	: chunkX(chunkX), chunkZ(chunkZ), chunkRenderer(chunkX, chunkZ)
{
	vertices = {};
	indices = {};
	texCoords = {};
	airBlockPositions = {};

	std::random_device rd;
	unsigned int seed = rd();
	siv::PerlinNoise perlin{ seed };

	// Callback for initial heightmap
	// Used for blending between chunks
	this->octave2D_01 = [&](float x, float y) { return perlin.octave2D_01(x, y, 2, 0.5f); };

	// Generate heightmap
	for (int x = 0; x < MAX_LENGTH; x++) {
		for (int z = 0; z < MAX_LENGTH; z++) {
			int height = round(perlin.octave2D_01(x * 0.1, z * 0.1, 2, 0.5f) * MAX_HEIGHT);
			heightMap[x][z] = height;
		}
	}
	GenerateMesh();
	chunkRenderer.Update(vertices, indices, texCoords);
}

void Chunk::Render()
{
	chunkRenderer.Render();
}

void Chunk::GenerateMesh()
{	
	// Generate air blocks
	for (int x = 0; x < MAX_LENGTH; x++)
	{
		for (int z = 0; z < MAX_LENGTH; z++)
		{
			airBlockPositions.insert({ x, heightMap[x][z], z });
		}
	}

	// Generate missing air blocks due to big height differences
	for (int x = 0; x < MAX_LENGTH; x++) {
		for (int z = 0; z < MAX_LENGTH; z++) {
			for (int dx = -1; dx <= 1; dx++)
			{
				for (int dz = -1; dz <= 1; dz++)
				{
					if (dx == 0 && dz == 0) continue;
					if (x + dx < 0 || x + dx >= MAX_LENGTH || z + dz < 0 || z + dz >= MAX_LENGTH) continue;
					int diff = heightMap[x][z] - heightMap[x + dx][z + dz];
					if (diff > 1)
					{
						for (int i = 1; i <= diff; i++)
						{
							airBlockPositions.insert({ x + dx, heightMap[x][z] - i, z + dz});
						}
					}
				}
			}
		}
	}

	// Generate blocks
	std::vector<Block> blocks;

	for (auto& airBlock : airBlockPositions)
	{
		blocks.push_back(Block({ airBlock, { 0, 0 }, 3 }));
	}

	// Generate mesh
	for (int i = 0; i < blocks.size(); i++)
	{
		for (auto& v : blocks[i].m_Vertices)
		{
			vertices.push_back(v);
		}
		for (auto& in : blocks[i].m_Indices)
		{
			indices.push_back(in + i * 24); // 24 vertices in a cube
		}
		for (auto& uv : blocks[i].m_TexCoords)
		{
			texCoords.push_back(uv);
		}
	}
}