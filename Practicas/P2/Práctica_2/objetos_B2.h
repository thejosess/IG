//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>


const float AXIS_SIZE=5000;
typedef enum{POINTS,EDGES,SOLID_CHESS,SOLID,ALL} _modo;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
public:

  
	_puntos3D();
void 	draw_puntos(float r, float g, float b, int grosor);

vector<_vertex3f> vertices;
};

//*************************************************************************
// clase triángulo
//*************************************************************************

class _triangulos3D: public _puntos3D
{
public:

	_triangulos3D();
//modificados segun la P1
void 	draw_aristas(int grosor);
void    draw_solido();
void 	draw_solido_ajedrez(float r2, float g2, float b2);
void 	draw(_modo modo,float r2, float g2, float b2, float grosor);
void 	change_color (vector<float> color, int size);

vector<_vertex3i> caras;
float r, g, b;
};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

	_cubo(float tam=0.5);
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam=0.5, float al=0.75);
};

//*************************************************************************
// clase objeto ply
//*************************************************************************

class _objeto_ply: public _triangulos3D
{
public:
   _objeto_ply();

int   parametros(char *archivo);
};

//************************************************************************
// objeto por revolución
//************************************************************************

class _rotacion: public _triangulos3D
{
public:
       _rotacion();
void  parametros(vector<_vertex3f> perfil1, int num1);

vector<_vertex3f> perfil; 
int num;
};

class _cono: public _triangulos3D
{
public:
       _cono();
void  parametros(vector<_vertex3f> perfil1,int num1, double altura);

vector<_vertex3f> perfil; 
int num;
int num_aux; //siempre será 1 el número de puntos que tiene el perfil para un cono.
double h;
};

class _cilindro: public _triangulos3D
{
public:
       _cilindro();
void  parametros(vector<_vertex3f> perfil1, int num1);

vector<_vertex3f> perfil; 
int num;
};

