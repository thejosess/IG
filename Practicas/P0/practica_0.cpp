#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>


void Circle (GLfloat radio, GLfloat cx, GLfloat cy, GLint n, GLenum modo) { 
   int i; 

   if (modo==GL_LINE) 
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); 
   else if (modo==GL_FILL) 
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
   else 
      glPolygonMode(GL_FRONT_AND_BACK, GL_POINT); 

   glBegin( GL_POLYGON ); 
      for (i=0;i<n;i++) 
         glVertex2f( cx+radio*cos(2.0*M_PI*i/n),cy+radio*sin(2.0*M_PI*i/n)); 
   glEnd(); 

} 


void Ejes (int width)
{   
    glLineWidth(width);
    glBegin(GL_LINES);
       glColor3f(1.0,0.0,0.0);
       glVertex3f(-1.0,0.0,0.0);
       glVertex3f(1.0,0.0,0.0);
       //eje X

       glColor3f(0.0,1.0,0.0);
       glVertex3f(0.0,-1.0,0.0);
       glColor3f(1.0,1.0,0.0);
       glVertex3f(0.0,1.0,0.0);   
       //eje Y

       //ejes desde -1 a 1 tanto el x como el y
    glEnd();
   
       
}


void Monigote ()
{
  
 
// cara
   glLineWidth(1);
   glColor3f(1.0,0.8,0.6);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_POLYGON);
      glVertex3f(-0.2,0.0,0.0);
      glVertex3f(0.2,0.0,0.0);
      glVertex3f(0.2,0.55,0.0);
      glVertex3f(-0.2,0.55,0.0);
   glEnd(); 

   //la linea negra que delimita la carra
   glColor3f(0.0,0.0,0.0);
   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   glBegin(GL_POLYGON);
      glVertex3f(-0.2,0.0,0.0);
      glVertex3f(0.2,0.0,0.0);
      glVertex3f(0.2,0.55,0.0);
      glVertex3f(-0.2,0.55,0.0);
   glEnd(); 


   glColor3f(0.0,0.0,0.0);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_POLYGON);
      glVertex3f(-0.3,0.4,0.0);
      glVertex3f(0.3,0.4,0.0);
      glVertex3f(0.3,0.55,0.0);
      glVertex3f(-0.3,0.55,0.0);
   glEnd(); 


   glColor3f(0.0,0.0,0.0);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_POLYGON);
      glVertex3f(-0.2,0.55,0.0);
      glVertex3f(0.2,0.55,0.0);
      glVertex3f(0.2,0.65,0.0);
      glVertex3f(-0.2,0.65,0.0);
   glEnd(); 


   glColor3f(0.3, 0.45, 1.0);
   Circle(0.06,-0.1,0.3,12, GL_FILL);

   glColor3f(0.3, 0.45, 1.0);
   Circle(0.06,0.1,0.3,12, GL_FILL);

   glColor3f(1.0, 0.0, 0.0);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_TRIANGLES);
      glVertex3f(0, 0.2, 0);
      glVertex3f(0.1, 0.1, 0);
      glVertex3f(-0.1, 0.1, 0);
   glEnd(); 

   
}


static void Init( )
{
   glShadeModel(GL_FLAT);
   //FLAT O SMOTH
}

//REVISAR PDF otra forma de hacer separando modelo de su contrucción
//así puedo reutilizarlo enjavascript por ejemplo


static void Reshape( int width, int height )
{
    glViewport(0, 0, (GLint)width, (GLint)height);
    //tamaño de la ventana, sería desde -1 a 1
    glOrtho (-1.0, 1.0,-1.0, 1.0, -10, 10.0);
}

static void Display( )
{

  glClearColor(0.5,0.5,0.5,0.0);
  glClear( GL_COLOR_BUFFER_BIT );
   
  
   
   Ejes(6);
   Monigote();
   
   glFlush();
   //glFlush — force execution of GL commands in finite time

}


static void Keyboard(unsigned char key, int x, int y )
{
 
  if (key==27)
      exit(0);

}


int main( int argc, char **argv )
{
   glutInit(&argc,argv);
   glutInitDisplayMode( GLUT_RGB );

   glutInitWindowPosition( 20, 100 );
   glutInitWindowSize(500, 500 );
   //de forma interna el tamaño es -1, 1 pero luego en la practica se puede redimensionar?
   glutCreateWindow("Practica 0 IG");


   Init();

   glutReshapeFunc(Reshape);
   glutDisplayFunc(Display);
   glutKeyboardFunc(Keyboard);
   //les pasas las funciones que hemos hecho
  
   glutMainLoop( );

   return 0;
}

