//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>


const float AXIS_SIZE=5000;
typedef enum{POINTS,EDGES,SOLID_CHESS,SOLID} _modo;

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
void 	draw_aristas(float r, float g, float b, int grosor);
void    draw_solido(float r, float g, float b);
void 	draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2);
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

vector<_vertex3i> caras;
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
void  parametros(vector<_vertex3f> perfil1,float altura_tapa_sup, float altura_tapa_inf, int num1);
//tapa superioer en esfera es radio y tapa finerior es -raido.
vector<_vertex3f> perfil; 
int num;
};

class _esfera: public _rotacion
{
public:
       _esfera(float radio, int n1, int n2);
	   //creas perfil y llamar a parametros con ese perfil
	   //constructor donde revolucionas para formarlo
	   //n1 numeros puntos para generar esfera mirar dibujos,
	   //n2 numero puntos que generas luego, numero de lados, latitud n1 y longitud n2

		//esfera crea peril y luego llama rotacion parametros con ese perfil crados y con le n2 va a ser el nunmero de lados
		//de esa esfera en parametros, y quiezas en parametros hay ue poner una altura

int num;
};

class _esfera: public _triangulos3D
{
public:
//perfil no le pasas porque lo hace a partir del radio
//el constructor lo tiene que hacre todo
       _esfera(float radio, int n1, int n2);


int num;
};

class _cono: public _rotacion
{
public:
	//lalamsa a rotacion y el perfil del cono sería el punto unicamente, radio,0,0
	//esos puntos es num1 de arriba rotacion
       _cono(float radio,float altura, int n);
	   //añadirle a rotacion int altura? girara perfil y con la altura que creara la tapa superior
	   //creas perfil y llamar a parametros con ese perfil
	   //constructor donde revolucionas para formarlo
	   //n1 numeros puntos para generar esfera mirar dibujos
	   //n2 numero puntos para los lados  que generas luego, latitud n1 y longitud n2

	//cramos perfil, llamamoes a parametro con un punto en el perfil, tapa superior es la altura, 
	//rtapa inferior tendŕia valor de 0 y n sería el número de lados que tiene el cono.

int num;
};

//y si haces el de arriba heredando con triangulos3D? cual sería la diferenciia?
//
