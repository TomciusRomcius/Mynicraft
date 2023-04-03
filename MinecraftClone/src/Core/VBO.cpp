#include "pch.h"
#include "VBO.h"

namespace Engine3D
{
	VBO::VBO(const std::vector<glm::vec3>& vertices, const std::vector<glm::vec3>& normals, const std::vector<glm::vec2> texCoords)
	{
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glGenBuffers(1, &id);

		EN_TRACE("Creating vertex buffer object id = " + std::to_string(id));

		glBindBuffer(GL_ARRAY_BUFFER, id);

		unsigned int verticesSize = vertices.size() * sizeof(glm::vec3);
		unsigned int normalsSize = normals.size() * sizeof(glm::vec3);
		unsigned int texCoordsSize = texCoords.size() * sizeof(glm::vec2);

		glBufferData(GL_ARRAY_BUFFER, verticesSize + texCoordsSize, vertices.data(), GL_STATIC_DRAW);

		glBufferSubData(GL_ARRAY_BUFFER, 0, verticesSize, vertices.data());
		glBufferSubData(GL_ARRAY_BUFFER, verticesSize, normalsSize, normals.data());
		glBufferSubData(GL_ARRAY_BUFFER, verticesSize + normalsSize, texCoordsSize, texCoords.data());

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)verticesSize);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(verticesSize + normalsSize));
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

	}
	VBO::VBO(const std::vector<glm::vec3>& vertices, const std::vector<glm::vec2> texCoords)
	{
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glGenBuffers(1, &id);

		EN_TRACE("Creating vertex buffer object id = " + std::to_string(id));

		glBindBuffer(GL_ARRAY_BUFFER, id);

		unsigned int verticesSize = vertices.size() * sizeof(glm::vec3);
		unsigned int texCoordsSize = texCoords.size() * sizeof(glm::vec2);

		glBufferData(GL_ARRAY_BUFFER, verticesSize + texCoordsSize, 0, GL_STATIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0, verticesSize, vertices.data());
		glBufferSubData(GL_ARRAY_BUFFER, verticesSize, texCoordsSize, texCoords.data());
		

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), nullptr);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*)verticesSize);
		glEnableVertexAttribArray(1);

	}
	VBO::VBO(const std::vector<glm::vec3>& vertices)
	{
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glGenBuffers(1, &id);

		EN_TRACE("Creating vertex buffer object id = " + std::to_string(id));

		glBindBuffer(GL_ARRAY_BUFFER, id);

		glBufferData(GL_ARRAY_BUFFER, vertices.size() * 3 * sizeof(float), vertices.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
		glEnableVertexAttribArray(0);
	}

	void VBO::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
		glBindVertexArray(vao);
	}

	VBO::~VBO()
	{
		EN_TRACE("Deleting vertex buffer object id = " + std::to_string(id));

		glDeleteBuffers(1, &id);
	}
}
