#include<GL\glut.h>

int black=0,white=1,color=0;
GLint a1=10,b1=10,a2=30,b2=30;

void init (void)
{
  glClearColor (0.0, 0.0,1.0,0.0);
  glMatrixMode (GL_PROJECTION);
  glClear (GL_COLOR_BUFFER_BIT);
  gluOrtho2D (0.0,120.0,0.0,140.0);
}

void lineSegment ()
{
  for(int i=0;i<3;i++)
  {
    if(b2<120)
    {
      a1=10;b1=b2;
      a2=30;b2=b2+20;
    }
    for(int j=0;j<5;j++)
    {
      if(a2<120)
      {
        if(color==black)
        {
          glColor3f(0,0,0);
          glRecti(a1,b1,a2,b2);
          color=1;
          a1=a2;
          a2=a2+20;
        }
        else
        {
          glColor3f(1,1,1);
          glRecti(a1,b1,a2,b2);
          color=0;
          a1=a2;
          a2=a2+20;
        }
      }
    }
    //GLint a1=10,b1=10,a2=30,b2=30;
  }
  glFlush();
}

void main (int argc, char** argv)
{
  glutInit(&argc,argv); //Initialize GLUT.
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // Set display mode.
  glutInitWindowPosition (50,100); //Set top-left display-window position.
  glutInitWindowSize (400,300); //Set display-window width and height.
  glutCreateWindow ("An Example OpenGL Program"); //Create display window.

  init(); // Execute initialization procedure.

  glutDisplayFunc(lineSegment); //send graphics to display window.
  glutMainLoop(); //display everything and wait.
}
