#pragma once
#include "Log.h"
class  Texture
{
public:
	Texture(const char* path);
	~Texture();
	void Bind();
private:
	unsigned int id;
};

