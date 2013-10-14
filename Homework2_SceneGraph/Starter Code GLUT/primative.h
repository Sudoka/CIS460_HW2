#ifndef PRIMATIVE
#define PRIMATIVE
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtx/transform.hpp"
#include <vector>

using namespace std;

class cube {
public:
	// construct unit cube at origin
	cube();
	// construct specified cube at x,y,z with r,g,b values
	cube(glm::vec3 _origin, glm::vec3 _color);

	glm::vec4 origin;
	glm::vec3 color;

	vector<float> vbo;
	vector<unsigned short> ibo;
	vector<float> cbo;
	vector<float> nbo;

	vector<glm::vec4> points;
	void transformPoints(glm::mat4 mat);
	// Constructs the buffers to be passed out
	void constructBuffers();
};

class sphere {
public:
	glm::vec4 origin;
	glm::vec3 color;
	sphere();
	sphere(glm::vec3 _origin, glm::vec3 _color);
	vector<float> vbo;
	vector<unsigned short> ibo;
	vector<float> cbo;
	vector<float> nbo;
	vector<glm::vec4> points;
	void transformPoints(glm::mat4 mat);
	// Constructs the buffers to be passed out
	void constructBuffers();

};

class cylinder {
public:
	int numSegments;
	glm::vec4 origin;
	glm::vec3 color;
	cylinder();
	cylinder(glm::vec3 _origin, glm::vec3 _color);
	vector<float> vbo;
	vector<unsigned short> ibo;
	vector<float> cbo;
	vector<float> nbo;
	vector<glm::vec4> points;
	void transformPoints(glm::mat4 mat);
	// Constructs the buffers to be passed out
	void constructBuffers();
};

class primative : public cube, public sphere, public cylinder {
};

#endif