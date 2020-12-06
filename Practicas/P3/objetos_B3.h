//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>
#include "file_ply_stl.hpp"

using namespace std;

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
void 	draw_aristas(int grosor);
void    draw_solido();
void 	draw_solido_ajedrez(float r2, float g2, float b2);
void 	draw(_modo modo,float r2, float g2, float b2, float grosor);
void 	change_color (vector<float> color, int size);


vector<_vertex3i> caras;
float r,g,b;
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


class _revolucionPly: public _triangulos3D
{
public:
       _revolucionPly();
void  parametros(char *file);

void  revolucionPly(char *file);


vector<_vertex3f> perfil; 
int num;
};

//************************************************************************
// objeto por revolución
//************************************************************************

class _rotacion: public _triangulos3D
{
public:
       _rotacion();
void  parametros(vector<_vertex3f> perfil, int num, char eje);


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

class _esfera: public _triangulos3D
{
public:
       _esfera();
void  parametros(int n,int m, double radio);

vector<_vertex3f> perfil; 
int num;
int num_aux; //siempre será 1 el número de puntos que tiene el perfil para un cono.
double r;
};


//************************************************************************
// objeto articulado: araña
//************************************************************************

class _abdomen: public _triangulos3D
{
public:
       _abdomen();
void 	draw(_modo modo, float r2, float g2, float b2, float grosor);

float altura, radio;
int n,m;

protected:
_esfera  esfera;
_cono pincho;
};

class _quelicero: public _triangulos3D
{
public:
       _quelicero();
void 	draw(_modo modo, float r2, float g2, float b2, float grosor);

float altura, radio;
int n,m;

protected:
_cilindro  tronco;
_esfera final;

};

class _cabeza: public _triangulos3D
{
public:
       _cabeza();
void 	draw(_modo modo, float r2, float g2, float b2, float grosor);

void setGiroQueliceros(float valor);

float altura, radio;
int n,m;

float giro_queliceros,giro_queliceros_max,giro_queliceros_min;

protected:
_esfera  esfera;

/* Ojos de abajo + grandes */
_esfera ojo1;
_esfera ojo2;
_esfera ojo3;

/* Ojos de arriba + pequeños */
_esfera ojo4;
_esfera ojo5;

/*los queliceros de la araña*/
_quelicero quelicero1;
_quelicero quelicero2;

};

class _pataPunta: public _triangulos3D
{
public:
       _pataPunta();
void 	draw(_modo modo, float r2, float g2, float b2, float grosor);

protected:
_cilindro  cilindro1;
_cono punta;
};


class _pataCentral: public _triangulos3D
{
public:
       _pataCentral();
void 	draw(_modo modo, float r2, float g2, float b2, float grosor);
void setGiroMedio(float valor);

float giro_medio, giro_medio_max, giro_medio_min;

float altura, radio, longitud_pata;
int n,m;

protected:
_rotacion cilindro4;
_cilindro  cilindro2;
_cilindro  cilindro3;
_cono punta;
_esfera articulacion1;
_esfera articulacion2;
_esfera articulacion3;
_pataPunta pataPunta;

};

class _pataExterior: public _triangulos3D
{
public:
       _pataExterior();
void 	draw(_modo modo, float r2, float g2, float b2, float grosor);

float altura, radio;
int n,m;

protected:
_cilindro  cilindro2;
_cilindro  cilindro3;
_cono punta;
_esfera articulacion1;
_esfera articulacion2;
_esfera articulacion3;
_pataPunta pataPunta;

};



class _spider: public _triangulos3D{
public:
       _spider();
void 	draw(_modo modo, float r2, float g2, float b2, float grosor);
void setGiroQueliceros(float valor);
void setGiroPataCentralMedio(float valor);
void setGiroPataCentralSup(float valor);
_cabeza getCabeza();
_cubo cubo;

float giroPataDelanteraSup1,giroPataDelanteraSup2;
float giroPataDelanteraSupMax,giroPataDelanteraSupMin,giroPataDelanteraSupMax1;


protected:
_abdomen abdomen;
_cabeza cabeza;
_pataCentral pataCentral1, pataCentral2, pataCentral3,pataCentral4;
_pataExterior pataExterior1,pataExterior2,pataExterior3,pataExterior4;

};



//************************************************************************
// objeto articulado: tanque
//************************************************************************

class _chasis: public _triangulos3D
{
public:
       _chasis();
void 	draw(_modo modo, float r2, float g2, float b2, float grosor);

float altura;

protected:
_rotacion  rodamiento;
_cubo  base;
};

//************************************************************************

class _torreta: public _triangulos3D
{
public:
       _torreta();
void 	draw(_modo modo, float r2, float g2, float b2, float grosor);

float altura;
float anchura;

protected:
_cubo  base;
_piramide parte_trasera;
};

//************************************************************************

class _tubo: public _triangulos3D
{
public:
       _tubo();
void 	draw(_modo modo, float r2, float g2, float b2, float grosor);

protected:
_rotacion tubo_abierto; // caña del cañón
};


//************************************************************************

class _tanque: public _triangulos3D
{
public:
       _tanque();
void 	draw(_modo modo, float r2, float g2, float b2, float grosor);

float giro_tubo;
float giro_torreta;

float giro_tubo_min;
float giro_tubo_max;

protected:
_chasis  chasis;
_torreta  torreta;
_tubo     tubo;
};

