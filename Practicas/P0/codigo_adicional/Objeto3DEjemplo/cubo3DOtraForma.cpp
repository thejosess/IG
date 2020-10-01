/*
 * OGL01Shape3D.cpp: 3D Shapes
 */
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
 
/* Global variables */
char title[] = "3D Shapes";

// Visualizando en modo puntos
void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
glPointSize(grosor);
glColor3f(r,g,b);
glBegin( GL_POINTS ) ;
for(int i=0 ; i < Vertices.size() ; i++ )
glVertex3f( vertices[i].x, vertices[i].y, vertices[i].z );
glEnd() ;
}

// alternativa con vertex array
void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
glPointSize(grosor);
glColor3f(r,g,b);
glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
glDrawArrays(GL_POINTS,0,vertices.size());
}


 
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}
 
/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
  int n_puntos=5;
float *puntos, *colores;
puntos=(float *)malloc(3*n_puntos*sizeof(float));
colores=(float *)malloc(3*n_puntos*sizeof(float));

glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
puntos[0]=1.0; puntos[1]=1.0; puntos[2]=0.0;
puntos[3]=3.0; puntos[4]=1.0; puntos[5]=0.0;
puntos[6]=3.5; puntos[7]=2.4; puntos[8]=0.0;
puntos[9]=2.0; puntos[10]=3.5; puntos[11]=0.0;
puntos[12]=0.5; puntos[13]=2.4; puntos[14]=0.0;
colores[0]=0.0; colores[1]=0.0; colores[2]=1.0;
colores[3]=0.0; colores[4]=0.0; colores[5]=1.0;
colores[6]=0.5; colores[7]=0.0; colores[8]=1.0;
colores[9]=1.0; colores[10]=0.0; colores[11]=1.0;
colores[12]=0.5; colores[13]=0.0; colores[14]=1.0;
glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(3,GL_FLOAT,0,& (puntos[0]));
glEnableClientState(GL_COLOR_ARRAY);
glColorPointer(3,GL_FLOAT,0,& (colores[0]));
glDrawArrays(GL_POLYGON,0,n_puntos);
puntos[12]=1.0; puntos[13]=1.5; puntos[14]=0.0;
colores[9]=0.5; colores[10]=1.0; colores[11]=0.2;
glTranslatef(-4.0,-4.0,0.0);
glDrawArrays(GL_POLYGON,0,n_puntos);


}
 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
 
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
