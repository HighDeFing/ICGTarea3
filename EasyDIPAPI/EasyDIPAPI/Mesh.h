#pragma once

#ifndef __ED_MESH__
#define __ED_MESH__

#include <glad/glad.h>
#include "glm/gtx/string_cast.hpp"
#include "EDpch.h"
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <vector>
#include <cstddef>
#include "shaders/Shader.h"

using std::vector;

extern Shader* bwShader;

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
};

class Mesh {
	static Mesh* instance;
	static unsigned int VBO, VAO, EBO;
	vector<Vertex> vertices;
	vector<unsigned int> indices;

	~Mesh();
public:
	bool mallado;
	bool points;
	bool back_face_culling;
	bool zbuffer;
	bool relleno;
	glm::vec4 colorrelleno;
	glm::vec4 colormesh;
	glm::vec4 colorpoints;
	void MeshCreate(vector<Vertex> vertices, vector<unsigned int> indices);
	void Draw();
	void Bind();
	void setupMesh();
	void DrawNormals();
	void create_BoundingBox(glm::vec3 min, glm::vec3 max);
	static Mesh* Instance();
};
#endif // !__ED_MESH__
