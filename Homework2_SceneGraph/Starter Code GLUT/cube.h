#ifndef CUBE
#define CUBE
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

	glm::vec3 origin;
	glm::vec3 color;

	vector<float> vbo;
	vector<float> ibo;
	vector<float> cbo;
	vector<float> nbo;

	vector<glm::vec3> points;

	// Constructs the buffers to be passed out
	void constructBuffers();
	
};

#endif