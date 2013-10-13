/**
 * A note about the demo chair
 *
 * This has evolved over time from when OpenGL's immediate mode was still the norm.
 * This code would use glut, glPushMatrix, glPopMatrix, glScaled, and glTranslated...all of which you can't
 * Instead think of how this could be made into a simple scene graph so that scoping handles the transformation
 * matrix.
 *
 * The principles behind the transformations can easily be translated to the course's linear algebra
 * package, and you would replace the glutSolidCube with a cube drawn with a VBO.  The takeaway here
 * is that by simply making a draw command that uses a VBO to draw a 1 x 1 x 1 cube, you can make a
 * more complex piece of furniture.  This built-from-basics approach will make the raytracer easier.
 *
 * Cory
 */

#include <gl/glut.h>

void drawChair() {

	float chairColor[] = {0.0f, 0.0f, 1.0f, 1.0f};//{0.5f, 0.6f, 0.9f, 1.0f};
	
	// draw legs
	glPushMatrix();
	glTranslated(0.4, 0.0, 0.4);
	glScaled(0.2, 0.8, 0.2);
	glutSolidCube(1.0);	//would draw a cube that is 1 x 1 x 1
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-0.4, 0.0, 0.4);	//different translation values
	glScaled(0.2, 0.8, 0.2);
	glutSolidCube(1.0);	//note that I again draw a cube that is 1 x 1 x 1, but now it will be seen somewhere else
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-0.4, 0.0, -0.4);
	glScaled(0.2, 0.8, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.4, 0.0, -0.4);
	glScaled(0.2, 0.8, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();
	
	// draw seat
	glPushMatrix();
	glTranslated(0.0, 0.8, 0.0);
	glScaled(1.0, 0.2, 1.0);	//this time the scale values of the cube are changed
	glutSolidCube(1.0);	//still draw a cube of 1 x 1 x 1, but it will be scaled so it won't look like a cube OR like the legs
	glPopMatrix();

	// draw backrest
	glPushMatrix();
	glTranslated(-0.4, 1.0, 0.0);
	glScaled(0.2, 1.0, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();		
}