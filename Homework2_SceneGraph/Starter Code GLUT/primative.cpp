#include "primative.h"


//    v7----- v6
//   /|      /|
//  v3------v2|
//  | |     | |
//  | |v4---|-|v5
//  |/      |/
//  v0------v1
cube::cube() {
	origin  = glm::vec3(0.f,0.f,0.f);
	color = glm::vec3(1.f,1.f,0.f);

	glm::vec3 p0 = glm::vec3(-0.5f,-0.5f,-0.5);
	glm::vec3 p1 = glm::vec3(0.5f,-0.5f,-0.5);
	glm::vec3 p2 = glm::vec3(0.5f,0.5f,-0.5);
	glm::vec3 p3 = glm::vec3(-0.5f,0.5f,-0.5);
	glm::vec3 p4 = glm::vec3(-0.5f,-0.5f,0.5);
	glm::vec3 p5 = glm::vec3(0.5f,-0.5f,0.5);
	glm::vec3 p6 = glm::vec3(0.5f,0.5f,0.5);
	glm::vec3 p7 = glm::vec3(-0.5f,0.5f,0.5);

	points.push_back(p0);
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);

	points.push_back(p1);
	points.push_back(p5);
	points.push_back(p6);
	points.push_back(p2);

	points.push_back(p5);
	points.push_back(p4);
	points.push_back(p7);
	points.push_back(p6);

	points.push_back(p4);
	points.push_back(p0);
	points.push_back(p3);
	points.push_back(p7);

	points.push_back(p3);
	points.push_back(p2);
	points.push_back(p6);
	points.push_back(p7);

	points.push_back(p0);
	points.push_back(p1);
	points.push_back(p5);
	points.push_back(p4);
}


//    v7----- v6
//   /|      /|
//  v3------v2|
//  | |     | |
//  | |v4---|-|v5
//  |/      |/
//  v0------v1
cube::cube(glm::vec3 _origin, glm::vec3 _color) {
	origin = _origin;
	color = _color;

	glm::vec3 p0 = glm::vec3(-0.5f,-0.5f,-0.5) + origin;
	glm::vec3 p1 = glm::vec3(0.5f,-0.5f,-0.5) + origin;
	glm::vec3 p2 = glm::vec3(0.5f,0.5f,-0.5) + origin;
	glm::vec3 p3 = glm::vec3(-0.5f,0.5f,-0.5) + origin;
	glm::vec3 p4 = glm::vec3(-0.5f,-0.5f,0.5) + origin;
	glm::vec3 p5 = glm::vec3(0.5f,-0.5f,0.5) + origin;
	glm::vec3 p6 = glm::vec3(0.5f,0.5f,0.5) + origin;
	glm::vec3 p7 = glm::vec3(-0.5f,0.5f,0.5) + origin;

	points.push_back(p0);
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);

	points.push_back(p1);
	points.push_back(p5);
	points.push_back(p6);
	points.push_back(p2);

	points.push_back(p5);
	points.push_back(p4);
	points.push_back(p7);
	points.push_back(p6);

	points.push_back(p4);
	points.push_back(p0);
	points.push_back(p3);
	points.push_back(p7);

	points.push_back(p3);
	points.push_back(p2);
	points.push_back(p6);
	points.push_back(p7);

	points.push_back(p0);
	points.push_back(p1);
	points.push_back(p5);
	points.push_back(p4);
}

void cube::constructBuffers() {
	vector<float> vertices;
	vector<float> normals;
	vector<float> colors;
	vector<unsigned short> index;
	

	for (int i = 0; i < points.size(); i++ ) {
		vertices.push_back(points[i].x);
		vertices.push_back(points[i].y);
		vertices.push_back(points[i].z);
		vertices.push_back(1.f);
	}

	vbo = vertices;

	for (int i = 0; i < points.size(); i++) {
		colors.push_back(color.r);
		colors.push_back(color.g);
		colors.push_back(color.b);
	}

	cbo = colors;

	index.push_back(0); index.push_back(1); index.push_back(2);
	index.push_back(0); index.push_back(2); index.push_back(3);

	index.push_back(4); index.push_back(5); index.push_back(6);
	index.push_back(4); index.push_back(6); index.push_back(7);

	index.push_back(8); index.push_back(9); index.push_back(10);
	index.push_back(8); index.push_back(10); index.push_back(11);

	index.push_back(12); index.push_back(13); index.push_back(14);
	index.push_back(12); index.push_back(14); index.push_back(15);

	index.push_back(16); index.push_back(17); index.push_back(18);
	index.push_back(16); index.push_back(18); index.push_back(19);

	index.push_back(20); index.push_back(21); index.push_back(22);
	index.push_back(20); index.push_back(22); index.push_back(23);

	ibo = index;

	//    v7----- v6
	//   /|      /|
	//  v3------v2|
	//  | |     | |
	//  | |v4---|-|v5
	//  |/      |/
	//  v0------v1

	normals.push_back(0.f); normals.push_back(0.f);  normals.push_back(1.f);  normals.push_back(0.f);
	normals.push_back(0.f); normals.push_back(0.f);  normals.push_back(1.f);  normals.push_back(0.f); 
	normals.push_back(0.f); normals.push_back(0.f);  normals.push_back(1.f);  normals.push_back(0.f); 
	normals.push_back(0.f); normals.push_back(0.f);  normals.push_back(1.f);  normals.push_back(0.f);

	normals.push_back(1.f); normals.push_back(0.f);  normals.push_back(0.f);  normals.push_back(0.f);
	normals.push_back(1.f); normals.push_back(0.f);  normals.push_back(0.f);  normals.push_back(0.f); 
	normals.push_back(1.f); normals.push_back(0.f);  normals.push_back(0.f);  normals.push_back(0.f); 
	normals.push_back(1.f); normals.push_back(0.f);  normals.push_back(0.f);  normals.push_back(0.f);

	normals.push_back(0.f); normals.push_back(0.f);  normals.push_back(-1.f);  normals.push_back(0.f);
	normals.push_back(0.f); normals.push_back(0.f);  normals.push_back(-1.f);  normals.push_back(0.f); 
	normals.push_back(0.f); normals.push_back(0.f);  normals.push_back(-1.f);  normals.push_back(0.f); 
	normals.push_back(0.f); normals.push_back(0.f);  normals.push_back(-1.f);  normals.push_back(0.f);

	normals.push_back(-1.f); normals.push_back(0.f);  normals.push_back(0.f);  normals.push_back(0.f);
	normals.push_back(-1.f); normals.push_back(0.f);  normals.push_back(0.f);  normals.push_back(0.f); 
	normals.push_back(-1.f); normals.push_back(0.f);  normals.push_back(0.f);  normals.push_back(0.f); 
	normals.push_back(-1.f); normals.push_back(0.f);  normals.push_back(0.f);  normals.push_back(0.f);

	normals.push_back(0.f); normals.push_back(1.f);  normals.push_back(0.f);  normals.push_back(0.f);
	normals.push_back(0.f); normals.push_back(1.f);  normals.push_back(0.f);  normals.push_back(0.f); 
	normals.push_back(0.f); normals.push_back(1.f);  normals.push_back(0.f);  normals.push_back(0.f); 
	normals.push_back(0.f); normals.push_back(1.f);  normals.push_back(0.f);  normals.push_back(0.f);

	normals.push_back(0.f); normals.push_back(-1.f);  normals.push_back(0.f);  normals.push_back(0.f);
	normals.push_back(0.f); normals.push_back(-1.f);  normals.push_back(0.f);  normals.push_back(0.f); 
	normals.push_back(0.f); normals.push_back(-1.f);  normals.push_back(0.f);  normals.push_back(0.f); 
	normals.push_back(0.f); normals.push_back(-1.f);  normals.push_back(0.f);  normals.push_back(0.f);

	nbo = normals;
}