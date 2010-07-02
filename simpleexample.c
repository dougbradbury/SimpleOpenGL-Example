#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <Glut/glut.h>

#define kWindowWidth 400
#define kWindowHeight 300

typedef GLfloat point[3]; 

point cube[8] = {
		{-0.5, -0.5, 1.0},
		{0.5, -0.5, 1.0},
		{0.5, 0.5, 1.0},
		{-0.5, 0.5, 1,0},
	{-0.5, -0.5, -1.0},
	{0.5, -0.5, -1.0},
	{0.5, 0.5, -1.0},
	{-0.5, 0.5, -1,0}
		
};

GLvoid DrawGLScene(void);
void drawCube(void);
void square(point a, point b, point c, point d);
void squareOffset(point a, point b, point c, point d, float offset);

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(kWindowWidth, kWindowHeight);
  glutInitWindowPosition(100, 100);
  glutCreateWindow ("simple opengl example");

  glutDisplayFunc(DrawGLScene);

  glutMainLoop();
  return 0;
}

GLvoid DrawGLScene(void)
{
  glClear(GL_COLOR_BUFFER_BIT); 
  glColor3f(1.0,1.0,1.0); 
  glLoadIdentity(); 

  drawCube(); 
  glutSwapBuffers();
}

void drawCube()
{
  square(cube[0], cube[1], cube[2], cube[3]);
  square(cube[4], cube[5], cube[6], cube[7]);
  square(cube[1], cube[2], cube[5], cube[6]); //right face
  square(cube[0], cube[3], cube[7], cube[4]); //left face
  square(cube[2], cube[3], cube[6], cube[7]); //top
  square(cube[0], cube[1], cube[5], cube[4]); //bottom
}

void square(point a, point b, point c, point d) 
{
  glBegin(GL_LINE_LOOP);
  glVertex3fv(a); 
  glVertex3fv(b); 
  glVertex3fv(c); 
  glVertex3fv(d); 
  glEnd();     
}
