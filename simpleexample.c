#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <Glut/glut.h>

#define kWindowWidth 800
#define kWindowHeight 600

typedef GLfloat point[3]; 

point cube[8] = {
  {-0.5, -0.5, 0.5},
  {0.5, -0.5, 0.5},
  {0.5, 0.5, 0.5},
  {-0.5, 0.5, 0.5},
  {-0.5, -0.5, -0.5},
  {0.5, -0.5, -0.5},
  {0.5, 0.5, -0.5},
  {-0.5, 0.5, -0.5}
};

GLvoid DrawGLScene(void);
void drawCube(void);
void square(point a, point b, point c, point d);
void squareOffset(point a, point b, point c, point d, float offset);
void ChangeSize(GLsizei w, GLsizei h);

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(kWindowWidth, kWindowHeight);
  glutInitWindowPosition(100, 100);
  glutCreateWindow ("doug's opengl example");

  glutDisplayFunc(DrawGLScene);

  glutMainLoop();
  return 0;
}


GLvoid DrawGLScene(void)
{
  glClearColor(0,0,0,0);
  glViewport(0, 0, 800, 600);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity(); 
  gluPerspective(45.0f, 800.0f / 600.0f, 1.0f, 20.0f);

  glMatrixMode(GL_MODELVIEW);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
  glLoadIdentity(); 
  glColor3f(1.0,1.0,1.0); 
  
  glRotatef(45.0, 1.0, 1.0, 0.0);
  glTranslatef(2.3f, -2.0f, -3.0f);
  drawCube(); 
  glLoadIdentity(); 

  glColor3f(1.0,0.0,1.0); 
  glRotatef(10.0, 0.0, 0.0, 1.0);
  glTranslatef(-1.5f, 1.3f, -5.0f);
  drawCube(); 
  // ChangeSize(10.0, 10.0);

  
  glutSwapBuffers();
}

void ChangeSize(GLsizei w, GLsizei h)
{
  GLfloat nRange = 120.0f;
  // Prevent a divide by zero
  if(h == 0)
    h = 1;

  // Set Viewport to window dimensions
  glViewport(0, 0, w, h);

  // Reset coordinate system
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Establish clipping volume (left, right, bottom, top, near, far)
  if (w <= h) 
    glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange*2.0f, nRange*2.0f);
  else 
    glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange*2.0f, nRange*2.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void drawCube()
{
  square(cube[0], cube[1], cube[2], cube[3]); //front
  square(cube[4], cube[5], cube[6], cube[7]); //back
  square(cube[1], cube[2], cube[6], cube[5]); //right face
  square(cube[0], cube[3], cube[7], cube[4]); //left face
  square(cube[2], cube[3], cube[7], cube[6]); //top
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
