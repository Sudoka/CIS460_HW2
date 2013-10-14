#include "primative.h"

//####################################################################################################################
//    v7----- v6
//   /|      /|
//  v3------v2|
//  | |     | |
//  | |v4---|-|v5
//  |/      |/
//  v0------v1
cube::cube() {
	origin  = glm::vec4(0.f,0.f,0.f,1.0);
	color = glm::vec3(1.f,1.f,0.f);

	glm::vec4 p0 = glm::vec4(-0.5f,-0.5f,0.5,1.f);
	glm::vec4 p1 = glm::vec4(0.5f,-0.5f,0.5,1.f);
	glm::vec4 p2 = glm::vec4(0.5f,0.5f,0.5,1.f);
	glm::vec4 p3 = glm::vec4(-0.5f,0.5f,0.5,1.f);
	glm::vec4 p4 = glm::vec4(-0.5f,-0.5f,-0.5,1.f);
	glm::vec4 p5 = glm::vec4(0.5f,-0.5f,-0.5,1.f);
	glm::vec4 p6 = glm::vec4(0.5f,0.5f,-0.5,1.f);
	glm::vec4 p7 = glm::vec4(-0.5f,0.5f,-0.5,1.f);

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
	origin = glm::vec4(_origin,1.0);
	color = _color;

	glm::vec4 p0 = glm::vec4(-0.5f,-0.5f,0.5,1.f);
	glm::vec4 p1 = glm::vec4(0.5f,-0.5f,0.5,1.f);
	glm::vec4 p2 = glm::vec4(0.5f,0.5f,0.5,1.f);
	glm::vec4 p3 = glm::vec4(-0.5f,0.5f,0.5,1.f);
	glm::vec4 p4 = glm::vec4(-0.5f,-0.5f,-0.5,1.f);
	glm::vec4 p5 = glm::vec4(0.5f,-0.5f,-0.5,1.f);
	glm::vec4 p6 = glm::vec4(0.5f,0.5f,-0.5,1.f);
	glm::vec4 p7 = glm::vec4(-0.5f,0.5f,-0.5,1.f);

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

void cube::transformPoints(glm::mat4 mat) {
	for (int i = 0; i < points.size(); i++) {
		points[i] = points[i] * mat;
	}
}

//################################################################################################################################


sphere::sphere() {

}

sphere::sphere(glm::vec3 _origin, glm::vec3 _color) {
}

void sphere::transformPoints(glm::mat4 mat) {
}

void sphere::constructBuffers() {
	vector<float> vertices;
	vector<float> normals;
	vector<float> colors;
	vector<unsigned short> index;
}

//###############################################################################################################################
/*void DrawCircle(float cx, float cy, float r, int numSegments) 
{ 
	glBegin(GL_LINE_LOOP); 
	for(int ii = 0; ii < numSegments; ii++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(ii) / float(numSegments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 

	} 
	glEnd(); 
}*/
cylinder::cylinder() {
	float height = 2;
	numSegments = 24;
	int radius = 1;
	origin  = glm::vec4(0.f,0.f,0.f,1.0);
	color = glm::vec3(0.f,1.f,0.f);
	
	//sides
	for (int i = 0; i < numSegments; i++) {
		float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);//get the current angle 

		float x = radius * cosf(theta);//calculate the x component 
		float z = radius * sinf(theta);//calculate the y component 

		points.push_back(glm::vec4(x,0.f,z,1.f));
		points.push_back(glm::vec4(x,height,z,1.f));
	}

	// bottom
	for (int i = 0; i < numSegments; i++) {
		float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);//get the current angle 

		float x = radius * cosf(theta);//calculate the x component 
		float z = radius * sinf(theta);//calculate the y component 

		points.push_back(glm::vec4(x,0.f,z,1.f));
	}

	//top
	for (int i = 0; i < numSegments; i++) {
		float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);//get the current angle 

		float x = radius * cosf(theta);//calculate the x component 
		float z = radius * sinf(theta);//calculate the y component

		points.push_back(glm::vec4(x,height,z,1.f));
	}
}

cylinder::cylinder(glm::vec3 _origin, glm::vec3 _color) {
	origin = glm::vec4(_origin,1.0);
	color = _color;
	numSegments = 24;
	int radius = 1;
	for (int i = 0; i < numSegments; i++) {
		float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);//get the current angle 

		float x = _origin.x + radius * cosf(theta);//calculate the x component 
		float z = _origin.z + radius * sinf(theta);//calculate the y component 

		points.push_back(glm::vec4(x,0.f,z,1.f));
		points.push_back(glm::vec4(x,1.f,z,1.f));
	}
}

void cylinder::transformPoints(glm::mat4 mat) {
	for (int i = 0; i < points.size(); i++) {
		points[i] = points[i] * mat;
	}
}

void cylinder::constructBuffers() {
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
	
	colors.push_back(1.f);
	colors.push_back(1.f);
	colors.push_back(1.f);

	colors.push_back(1.f);
	colors.push_back(1.f);
	colors.push_back(1.f);

	colors.push_back(1.f);
	colors.push_back(1.f);
	colors.push_back(1.f);

	colors.push_back(1.f);
	colors.push_back(1.f);
	colors.push_back(1.f);

	for (int i = 4; i < points.size(); i++) {
		colors.push_back(color.r);
		colors.push_back(color.g);
		colors.push_back(color.b);
	}

	cbo = colors;

	// mid section normals
	for (int i = 0; i < numSegments*2 - 2;) {
		glm::vec4 a1;
		glm::vec4 a2;
		a1 = points[i+1] - points[i];
		a2 = points[i+3] - points[i+1];

		glm::vec3 a3 = glm::cross(glm::vec3(a1.x,a1.y,a1.z),glm::vec3(a2.x,a2.y,a2.z));

		a3 = glm::normalize(a3);
		
		normals.push_back(a3.x);
		normals.push_back(a3.y);
		normals.push_back(a3.z);
		normals.push_back(0.f);

		normals.push_back(a3.x);
		normals.push_back(a3.y);
		normals.push_back(a3.z);
		normals.push_back(0.f);

		i+=2;
	}

	glm::vec4 a1 = points[points.size() - 2] - points[points.size() - 1];
	glm::vec4 a2 = points[0] - points[points.size() - 2];
	glm::vec3 a3 = -glm::cross(glm::vec3(a1.x,a1.y,a1.z),glm::vec3(a2.x,a2.y,a2.z));
	a3 = glm::normalize(a3);

	normals.push_back(a3.x);
	normals.push_back(a3.y);
	normals.push_back(a3.z);
	normals.push_back(0.f);

	normals.push_back(a3.x);
	normals.push_back(a3.y);
	normals.push_back(a3.z);
	normals.push_back(0.f);

	// bottom normals
	for (int i = 0; i < numSegments; i++) {
		normals.push_back(0.f); normals.push_back(-1.f);  normals.push_back(0.f);  normals.push_back(0.f);
	}

	// top normals
	for (int i = 0; i < numSegments; i++) {
		normals.push_back(0.f); normals.push_back(1.f);  normals.push_back(0.f);  normals.push_back(0.f);
	}

	nbo = normals;

	for (int i = 0; i <= numSegments*2-2;i++) {
		index.push_back(i);
		index.push_back(i+1);
		index.push_back(i+2);
	}

	index.push_back(points.size() - 2);
	index.push_back(points.size() - 1);
	index.push_back(0);
	
	index.push_back(points.size() - 1);
	index.push_back(0);
	index.push_back(1);

	// 012
	// 023
	// 034

	int startindex = numSegments*2;
	for (int i = 1; i <= numSegments - 2;i++) {
		index.push_back(startindex);
		index.push_back(startindex + i);
		index.push_back(startindex + i + 1);
	}
	startindex = numSegments*3;
	for (int i = 1; i <= numSegments - 2;i++) {
		index.push_back(startindex);
		index.push_back(startindex + i);
		index.push_back(startindex + i + 1);
	}

	ibo = index;
}

//###############################################################################################################################