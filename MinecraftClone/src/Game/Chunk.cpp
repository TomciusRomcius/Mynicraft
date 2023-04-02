#include "pch.h"
#include "Chunk.h"
#include "PerlinNoise.hpp"

Chunk::Chunk()
{
	/*
	x = 0

	for (x = 0; x < maxwidth)
	for (y = 0; y < maxwidth)
	vertx.append(x, y, 0);

	i = 0

	foreach vertex ()
	indices.append(i)
	indices.append(i + maxheight + 1)
	indices.append(i + maxheight  + 1)

	indices.append(i)
	indices.append(i + maxheight * maxheight)
	indices.append(i + maxheight * maxheight + 1)

	i++;

	*/

	siv::PerlinNoise::seed_type seed{ 50 };
	siv::PerlinNoise perlin{seed};
	

	for (int x = 0; x < MAX_LENGTH; x++)
	{
		for (int y = 0; y < MAX_HEIGHT; y++)
		{
			for (int z = 0; z < MAX_LENGTH; z++)
			{
				vertices.push_back(glm::vec3(x, y, z));
			}
		}
	}
	int i = 0;
	for (auto v : vertices)
	{

		indices.push_back(i);
		indices.push_back(i + 1);
		indices.push_back(i + MAX_LENGTH + 1);

		indices.push_back(i);
		indices.push_back(i + MAX_LENGTH + 1);
		indices.push_back(i + MAX_LENGTH);

		indices.push_back(i);
		indices.push_back(i + MAX_LENGTH);
		indices.push_back(i + MAX_LENGTH * MAX_HEIGHT + MAX_LENGTH);

		indices.push_back(i);
		indices.push_back(i + MAX_LENGTH * MAX_HEIGHT + MAX_LENGTH);
		indices.push_back(i + MAX_LENGTH * MAX_HEIGHT);

		indices.push_back(i + 1);
		indices.push_back(i + MAX_LENGTH + 1);
		indices.push_back(i + MAX_LENGTH * MAX_HEIGHT + 1);

		indices.push_back(i + 1);
		indices.push_back(i + MAX_LENGTH * MAX_HEIGHT + 1);
		indices.push_back(i + MAX_LENGTH * MAX_HEIGHT + MAX_LENGTH + 1);
		i++;
	}
}
