//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include <GL/glut.h>
#include <ctype.h>
#include <math.h>
#include <vector>
#include "objetos_B2.h"


using namespace std;

// tipos
typedef enum{CUBO, PIRAMIDE, OBJETO_PLY, ROTACION,ROTACIONY,ROTACIONZ,CILINDRO, CONO,ESFERA, REVOLUCION_PLY} _tipo_objeto;
_tipo_objeto t_objeto=CUBO;
_modo   modo=POINTS;
bool change_color = false;
std::vector<float> color;


// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Size_x,Size_y,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int Window_x=50,Window_y=50,Window_width=450,Window_high=450;


// objetos
_cubo cubo;
_piramide piramide(0.85,1.3);
_objeto_ply  ply; 
_rotacion rotacion; 
_revolucionPly revolucionPly;
_cilindro cilindro;
_cono cono ;
_esfera esfera;
_rotacion rotaciony;
_rotacion rotacionz;
// _objeto_ply *ply1;


//**************************************************************************
//
//***************************************************************************

void clean_window()
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection()
{

glMatrixMode(GL_PROJECTION);
glLoadIdentity();

// formato(x_minimo,x_maximo, y_minimo, y_maximo,plano_delantero, plano_traser)
//  plano_delantero>0  plano_trasero>PlanoDelantero)
glFrustum(-Size_x,Size_x,-Size_y,Size_y,Front_plane,Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación*ply1 de vista (posicionar la camara)
//***************************************************************************

void change_observer()
{

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis()
{
	
glDisable(GL_LIGHTING);
glLineWidth(2);
glBegin(GL_LINES);
// eje X, color rojo
glColor3f(1,0,0);
glVertex3f(-AXIS_SIZE,0,0);
glVertex3f(AXIS_SIZE,0,0);
// eje Y, color verde
glColor3f(0,1,0);
glVertex3f(0,-AXIS_SIZE,0);
glVertex3f(0,AXIS_SIZE,0);
// eje Z, color azul
glColor3f(0,0,1);
glVertex3f(0,0,-AXIS_SIZE);
glVertex3f(0,0,AXIS_SIZE);
glEnd();
}


//**************************************************************************
// Funcion que dibuja los objetos
//****************************2***********************************************

void draw_objects()
{

switch (t_objeto){
	
	case CUBO: 
		if(change_color){
			cubo.change_color(color, color.size());
			color.clear();
			change_color = false;
		}

		cubo.draw(modo,0.0,1.0,0.0,4);
	break;

	case PIRAMIDE: 
		if(change_color){
			piramide.change_color(color,color.size());
			color.clear();
			change_color = false;
		}

		piramide.draw(modo,0.0,1.0,0.0,4);
	break;

	case OBJETO_PLY: 
		if(change_color){
			ply.change_color(color,color.size());
			color.clear();
			change_color = false;
		}

		ply.draw(modo,0.0,1.0,0.3,4);
	break;

	case ROTACION:
		if(change_color){
			rotacion.change_color(color,color.size());
			color.clear();
			change_color = false;
		}

		rotacion.draw(modo,0.0,1.0,0.0,4);
	break;

	case ROTACIONY:
	if(change_color){
		rotaciony.change_color(color,color.size());
		color.clear();
		change_color = false;
	}

	rotaciony.draw(modo,0.0,1.0,0.0,4);
	break;

	case ROTACIONZ:
	if(change_color){
		rotacionz.change_color(color,color.size());
		color.clear();
		change_color = false;
	}

	rotaciony.draw(modo,0.0,1.0,0.0,4);
	break;

	case CILINDRO: 
		if(change_color){
			cilindro.change_color(color,color.size());
			color.clear();
			change_color = false;
		}

		cilindro.draw(modo,0.0,1.0,0.0,4);
	break;

	case CONO: 
		if(change_color){
			cono.change_color(color,color.size());
			color.clear();
			change_color = false;
		}	
	cono.draw(modo,0.0,1.0,0.0,4);
	break;

	case ESFERA: 
		if(change_color){
			esfera.change_color(color,color.size());
			color.clear();
			change_color = false;
		}	
	esfera.draw(modo,0.0,1.0,0.0,5);
	break;

	case REVOLUCION_PLY: 
		if(change_color){
			revolucionPly.change_color(color,color.size());
			color.clear();
			change_color = false;
		}	
	revolucionPly.draw(modo,0.0,1.0,0.0,4);
	break;


	}
}


//**************************************************************************
//
//***************************************************************************

void draw(void)
{

clean_window();
change_observer();
draw_axis();
draw_objects();
glutSwapBuffers();
}



//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1,int Alto1)
{
float Aspect_ratio;

Aspect_ratio=(float) Alto1/(float )Ancho1;
Size_y=Size_x*Aspect_ratio;
change_projection();
glViewport(0,0,Ancho1,Alto1);
glutPostRedisplay();
}


//**********-o*****************************************************************
// Funcion llamada cuando se aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_key(unsigned char Tecla1,int x,int y)
{
switch (toupper(Tecla1)){
	case 'Q':exit(0);
	case '1':modo=POINTS;break;
	case '2':modo=EDGES;break;
	case '3':modo=SOLID;break;
	case '4':modo=SOLID_CHESS;break;
	case '5':modo=ALL;break;

	case 'P':t_objeto=PIRAMIDE;break;
	case 'C':t_objeto=CUBO;break;
	case 'O':t_objeto=OBJETO_PLY;break;	
	case 'R':t_objeto=ROTACION;break;
	case 'D':t_objeto=CILINDRO;break;
	case 'L':t_objeto=CONO;break;
	case 'E':t_objeto=ESFERA;break;
	case 'F':t_objeto=REVOLUCION_PLY;break;
	case 'Y':t_objeto=ROTACIONY;break;
	case 'Z':t_objeto=ROTACIONZ;break;



	//cambiar colores
	case '7': color.push_back(1); color.push_back(1); color.push_back(0); change_color = true; break;
	case '8': color.push_back(1); color.push_back(0); color.push_back(1); change_color = true; break;
	case '9': color.push_back(0); color.push_back(0.5); color.push_back(0.5); change_color = true; break;

	}
glutPostRedisplay();
}

//***************************************************************************
// Funcion l-olamada cuando se aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_key(int Tecla1,int x,int y)
{

switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}
glutPostRedisplay();
}



//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void)
{

// se inicalizan la ventana y los planos de corte
Size_x=0.5;
Size_y=0.5;
Front_plane=1;
Back_plane=1000;

// se incia la posicion del observador, en el eje z
Observer_distance=4*Front_plane;
Observer_angle_x=0;
Observer_angle_y=0;

// se indica cua*ply1l sera el color para limpiar la ventana	(r,v,a,al)
// blanco=(1,1,1,1) rojo=(1,0,0,1), ...
glClearColor(1,1,1,1);

// se habilita el z-bufer
glEnable(GL_DEPTH_TEST);
change_projection();
glViewport(0,0,Window_width,Window_high);



}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************


int main(int argc, char *argv[] )
{
 



// perfil 

vector<_vertex3f> perfil2,  perfil3, perfil1, perfil3_contrario,perfil2_contrario, perfil2y, perfil2z;
_vertex3f aux;

//si ves las cosas de un nunico color es que he putno un punto sobre el eeje de giro


aux.x=1.0; aux.y=1.0; aux.z=0.0;
perfil1.push_back(aux);

//aqui es donde cambias los puntos del perfil, de lugar.
//bug raro si coinciden con los eje min 1:08
//si comentas el de abajo debería de salir un cono bien, o si pones en la x 0.1
aux.x=1.0; aux.y=-1.0; aux.z=0.0;
perfil2.push_back(aux);
aux.x=1.0; aux.y=1.0; aux.z=0.0;
perfil2.push_back(aux);

aux.x=1.0; aux.y=-1.0; aux.z=0.0;
perfil3.push_back(aux);
aux.x=1; aux.y=0.5; aux.z=0.0;
perfil3.push_back(aux);
aux.x=1.0; aux.y=1.0; aux.z=0.0;
perfil3.push_back(aux);

aux.x=1.0; aux.y=1.0; aux.z=0.0;
perfil1.push_back(aux);


aux.x=1.0; aux.y=1.0; aux.z=0.0;
perfil3_contrario.push_back(aux);
aux.x=1; aux.y=0.5; aux.z=0.0;
perfil3_contrario.push_back(aux);
aux.x=1.0; aux.y=-1.0; aux.z=0.0;
perfil3_contrario.push_back(aux);

aux.x=1; aux.y=0.5; aux.z=0.0;
perfil2_contrario.push_back(aux);
aux.x=1.0; aux.y=-1.0; aux.z=0.0;
perfil2_contrario.push_back(aux);


aux.x=1.0; aux.y=1.0; aux.z=0.0;
perfil2y.push_back(aux);
aux.x=-1.0; aux.y=1.0; aux.z=0.0;
perfil2y.push_back(aux);

aux.x=0.0; aux.y=1.0; aux.z=1.0;
perfil2z.push_back(aux);
aux.x=-0.0; aux.y=1.0; aux.z=-1.0;
perfil2z.push_back(aux);

char ejex = 'x';
char ejey = 'y';
char ejez = 'z';

rotacion.parametros(perfil2,20, ejex);
rotaciony.parametros(perfil2y,20,ejey);
rotacionz.parametros(perfil2z,20,ejez);


cilindro.parametros(perfil2,20);
cono.parametros(perfil1,6,3);
esfera.parametros(5,6,2);
//esfera.parametros(5,2,2);



// se llama a la inicialización de glut
glutInit(&argc, argv);

// se indica las caracteristicas que se desean para la visualización con OpenGL
// Las posibilidades son:
// GLUT_SIMPLE -> memoria de imagen simple
// GLUT_DOUBLE -> memoria de imagen doble
// GLUT_INDEX -> memoria de imagen con color indizado
// GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
// GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
// GLUT_DEPTH -> memoria de profundidad o z-bufer
// GLUT_STENCIL -> memoria de estarcido_rotation Rotation;
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

// posicion de la esquina inferior izquierdad de la ventana
glutInitWindowPosition(Window_x,Window_y);

// tamaño de la ventana (ancho y alto)
glutInitWindowSize(Window_width,Window_high);

// llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
// al bucle de eventos)
glutCreateWindow("PRACTICA - 2");

// asignación de la funcion llamada "dibujar" al evento de dibujo
glutDisplayFunc(draw);
// asignación de la funcion llamada "change_window_size" al evento correspondiente
glutReshapeFunc(change_window_size);
// asignación de la funcion llamada "normal_key" al evento correspondiente
glutKeyboardFunc(normal_key);
// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
glutSpecialFunc(special_key);

// funcion de inicialización
initialize();

// creación del objeto ply
ply.parametros(argv[1]);

revolucionPly.parametros(argv[2]);



//ply1 = new _objeto_ply(argv[1]);

// inicio del bucle de eventos
glutMainLoop();
return 0;
}
