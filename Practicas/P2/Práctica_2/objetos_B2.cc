//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "objetos_B2.h"
#include "file_ply_stl.hpp"


//*************************************************************************
// _puntos3D
//*************************************************************************

_puntos3D::_puntos3D()
{
}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
int i;
glPointSize(grosor);
glColor3f(r,g,b);
glBegin(GL_POINTS);
for (i=0;i<vertices.size();i++){
	glVertex3fv((GLfloat *) &vertices[i]);
	}
glEnd();
}




//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D()
{
  r = 0.0;
	g = 0.5;
	b = 0.7;
  //color por defecto
}

//cambiar color

void _triangulos3D::change_color (vector<float> color, int size){
	r = color[size-3];
	g = color[size-2];
	b = color[size-1];
}


//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(int grosor)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
//utiliza poligon mode es diferente al de punto
glLineWidth(grosor);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}

//*************************************************************************
// dibujar en modo sólido
//*************************************************************************

void _triangulos3D::draw_solido()
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
//utiliza poligon mode es diferente al de punto
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}

//*************************************************************************
// dibujar en modo sólido con apariencia de ajedrez
//*************************************************************************

void _triangulos3D::draw_solido_ajedrez(float r2, float g2, float b2)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
//utiliza poligon mode es diferente al de punto
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	
	if(i%2==0)
		glColor3f(r,g,b);
	else
	glColor3f(r2,g2,b2);
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}



//*************************************************************************
// dibujar con distintos modos
//*************************************************************************

void _triangulos3D::draw(_modo modo, float r2, float g2, float b2, float grosor)
{
switch (modo){
	case POINTS:draw_puntos(r, g, b, grosor);break;
	case EDGES:draw_aristas(grosor);break;
	case SOLID_CHESS:draw_solido_ajedrez(r2, g2, b2);break;
	case SOLID:draw_solido();break;
  case ALL: draw_puntos(r2, g2, b2, grosor); draw_aristas(grosor); draw_solido_ajedrez(r2, g2, b2); break;
	}
}

//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{
//vertices
vertices.resize(8); 
vertices[0].x=0;vertices[0].y=0;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=0;vertices[2].z=0;
vertices[3].x=0;vertices[3].y=0;vertices[3].z=0;
//repeticion de lo que tengo pero cambiado la altura
vertices[4].x=0;vertices[4].y=tam;vertices[4].z=tam;
vertices[5].x=tam;vertices[5].y=tam;vertices[5].z=tam;
vertices[6].x=tam;vertices[6].y=tam;vertices[6].z=0;
vertices[7].x=0;vertices[7].y=tam;vertices[7].z=0;
//Cubo no centrado

// triangulos
caras.resize(12);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
caras[1]._0=1;caras[1]._1=5;caras[1]._2=4;
//la cara de atrás es igual cambiando la y
caras[2]._0=3;caras[2]._1=2;caras[2]._2=7;
caras[3]._0=2;caras[3]._1=6;caras[3]._2=7;
//la de los lados
caras[4]._0=0;caras[4]._1=3;caras[4]._2=7;
caras[5]._0=0;caras[5]._1=7;caras[5]._2=4;

caras[6]._0=1;caras[6]._1=2;caras[6]._2=5;
caras[7]._0=2;caras[7]._1=6;caras[7]._2=5;

//arriba y abajo
caras[8]._0=4;caras[8]._1=5;caras[8]._2=6;
caras[9]._0=4;caras[9]._1=6;caras[9]._2=7;

caras[10]._0=0;caras[10]._1=1;caras[10]._2=3;
caras[11]._0=1;caras[11]._1=2;caras[11]._2=3;

}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{

//vertices 
vertices.resize(5); 
vertices[0].x=-tam;vertices[0].y=0;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=0;vertices[2].z=-tam;
vertices[3].x=-tam;vertices[3].y=0;vertices[3].z=-tam;
vertices[4].x=0;vertices[4].y=al;vertices[4].z=0;

caras.resize(6);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
caras[1]._0=1;caras[1]._1=2;caras[1]._2=4;
caras[2]._0=2;caras[2]._1=3;caras[2]._2=4;
caras[3]._0=3;caras[3]._1=0;caras[3]._2=4;
caras[4]._0=3;caras[4]._1=1;caras[4]._2=0;
caras[5]._0=3;caras[5]._1=2;caras[5]._2=1;
}

//*************************************************************************
// clase objeto ply
//*************************************************************************


_objeto_ply::_objeto_ply() 
{
   // leer lista de coordenadas de vértices y lista de indices de vértices
 
}



int _objeto_ply::parametros(char *archivo)
{
int n_ver,n_car;

vector<float> ver_ply ;
vector<int>   car_ply ;
 
_file_ply::read(archivo, ver_ply, car_ply );

n_ver=ver_ply.size()/3;
n_car=car_ply.size()/3;

printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

vertices.resize(n_ver);
caras.resize(n_car);

for (int i=0; i<n_ver; i++){
  vertices[i].x=ver_ply[3*i];
  vertices[i].y=ver_ply[3*i+1];
  vertices[i].z=ver_ply[3*i+2];
  //ver_ply es tres veces mas graned que vertices matrices.
}

for (int i=-0; i<n_car; i++){
  caras[i]._0=car_ply[3*i];
  caras[i]._1=car_ply[3*i+1];
  caras[i]._2=car_ply[3*i+2];
  //ver_ply es tres veces mas graned que vertices matrices.
}

return(0);
}


//************************************************************************
// objeto por revolucion
//************************************************************************

_rotacion::_rotacion()
{

}


void _rotacion::parametros(vector<_vertex3f> perfil, int num)
{
int i,j;
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;

/* tratamiento de los vértice*/

//num numero de lados
//num_aux es el numero de puntos del perfil

num_aux=perfil.size();
vertices.resize(num_aux*num+2);
//vas a tener vertices segun: num_aux*num, numero de lados * numero de puntos perfil
//+2 para las tapas, un punto para la tapa de arriba y otro para la tapa de abajo. Esos puntos centrales de las tapas.

//aqui obtienes el resto de puntos al revolucionar con senos y cosenos
for (j=0;j<num;j++)
  {for (i=0;i<num_aux;i++)
     {
      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
      vertice_aux.y=perfil[i].y;
      vertices[i+j*num_aux]=vertice_aux;
     }
  }

// tratamiento de las caras 

caras.resize((num_aux-1)*2*num+2*num);

// tienes tres puntos, entonces puedes tener 2 caras. Esas caras son dobles, entonce será 2(n-1)
//Pero como además ese poligo puede tener mas de un lado, seŕa 2(n-1)*m

// y ese 2*num final es 2m que es suponiendo las tapas. Cada tapa tendrá las mismas caras que número de lados, 
//al ser dos tapas pues 2*num  

//TODO
//falta cara, vertice, cuña esa
//tratamiento especial?

//TODO Cono
//hacerlo objeto revolucion cualquiera, tratamiento especial lado, cara, 
//casos particuales de cono y esfera que son especiales.
//este es el caso especial del cilindro.
//cilindro lo extiendes y tienes para cualquier punto

//para caso del cono es como está este en los vertices solo giras solo un punto y quitas de ahí el segundo for
//linea 280
//la tapa solo tiene una, entonces las caras sería caras.resize((num_aux-1)*2*num)
//no tiene parte lateral.
//	vertices[num_aux*num].y=0;  tapa inferior
//tapa superior 
//   vertices[num_aux*num+1].y=altura_cono; 


//TODO esfera
//caso del perfil, girar punto y obtienes semi circuferencia.
//

//si tipo es x, cono, esfera, objeto n, cilindro, etc
//cuatro tipos de solidos que hay que hacer.
//tratamiento especial segun el caso, cono no tiene x cosas min 57

//TODO cuatros clases distintas y todas hijas de triaungulo o hgijas de rotacion todas
//revisar eso

//TODO 
//perfil lo estamos haciendo de abajo hacía arriba, permitir que se pueda hacre de las dos formas.
//a la hora de crear las caras es difernete si empiezas por arriba o abajo, a la hora de unir las caaras
//eje de la generatriz ese punto del PDFd
//tambien puedo hacerlo dado un perfil empeszando por arriba que es diferente al que estña hecho ahora
//lo mas facil
//si la altura del ultimo punto sea > altura que tenga primer punto. Seria que estoy empezando por abajo
//si la altura del ultimo punto sea < altura que tenga primer punto. Seria que estoy empezando por arriba
//HACER COMPROBARACION Y EN CASO DE HABER EMPEZADO POR ARRIBA EL PERFIL LE DAS LA VUELTA A LOS PUNTOS DEL PERFIL.
//dado el perfil son dos puntos por ejemplo, le das la vuelta a esos dos puntos.
//creas otro perfil donde permutas la posicón, los de arriba los pasas abajo y así.
//y depsues ya tienes el codigo normal, donde HACER ESO??.  
//PARA CUALQUIER CASO

//TODO
//

//TODO
//CARA QUE FALTA PARA QUE NO SEA DEGENERADO
//nosotros extenderlo para solidio cualquier, el lo hace para cilindro
//perfil con solo dos puntos, si tiene mas no SRIVE, CAMBIAR.
//dibujarlo con otros puntos y comprobar
//por eso solo tienes un for, ya que con dos puntos solo tienes que crear dos caras, revisar dibujos

//enganche de las caras
int c=0;
   for (j=0;j<num-1;j++)
    {
		caras[c]._0=j*2;
		caras[c]._1=j*2+1;
		caras[c]._2=(j+1)*2+1;

		c=c+1; //ahora construyes el otro triangulo
		caras[c]._0=(j+1)*2+1;	//esto sería el +1  de abajo
		caras[c]._1=(j+1)*2;	//primer punto del ultimo perfil para abajo es el -2 deabajo.
		caras[c]._2=j*2;		//sería el 0 de abajo
		//caras[c]._2=(j+1)%num*2;
		c=c+1;
		//EL 0, 1 Y 2 QUE ORDEN?
		//antes era 0, 2, 1
		//para todas las caras, usas un for para cualquier numero
		//con tres sería un for para cuatro caras, en bloques de eso en el for
		//si haces hasta num, coredumped
		//comentarios dicen que si no se puede generalizar con modulo
    }
	//ese num-1 para no enganchar la ultima cara porque nos saldría generado ya que repites puntos


	//cierre para cilindro

		//enganchas los ultimos perfiles con los primeros.
		//penultimo serían num_aux*num -2 
		//ultimo serían num_aux*num -1 

		//PRIMERO SIMEPRE TRIANGULO SUPERIOR

		//Lo del 0,1,2 creo que solo afecta a colores
		//que son esos 0 2 y 1 en caras?, los tres puntos de una cara triangulo.
		//los puntos 0 y 1 son los dos primeros puntos del perfil
		caras[c]._0=num_aux*num -2; 
		caras[c]._1=num_aux*num -1; 
		caras[c]._2=1;
		//con esto haces el primer triangulo de la cara final.
		//al hacer como arriba, primero cara superior y luego cara inferior, rspectas eso y colores salen bien.
		//tiene que casar con la primer parte de arriba

		c=c+1; //ahora construyes el otro triangulo
		caras[c]._0=1; //el otro ultimo punto sin contar los dos de las tapas. Por eso es -1 y -2. Es el ultimo porque. El de abajo es el ultimo punto porque lo hacemos de abajo arriba?	
		caras[c]._1=0 ;
		caras[c]._2=num_aux*num-2;
		//este tiene que cassar con la segunda parte de arriba
		c=c+1;

		//min 40 lo de modulo

		//como enganchar esto para un forma generica?, sería en vez de dos -numero_lados_perfil, el ultimo punto del perfil serían num_aux-1;
		//seria
		//caras[c]._0=num_aux*num -num_aux; 
		//caras[c]._1=num_aux*num -1; 
		//caras[c]._2=num_aux-1;

		//num-1 sería poner %num
		//todos los j+1 sería %num

		//caras[c]._1=num_aux*num -1; 
		//caras[c]._1=0; 
		//caras[c]._2=num_aux*num -num_aux;
		//este no seguro
		
		//poner sentido contrario agujas del reloj


 // tapa inferior

//TODO enganche tapas falta

if (fabs(perfil[0].x)>0.0)
  {
	vertices[num_aux*num].x=0.0; 
	vertices[num_aux*num].y=perfil[0].y; 
	//altura que coincida con la altura del primer punto del perfil

	//arriba sería igual a -radio para la esfera
	//esto no termino de entenderlo
	//añadiendo el vertice nuevo creo?? 
	//esos dos vertices adicionales?
   	vertices[num_aux*num].z=0.0;

 for (j=0;j<num-1;j++)
     {caras[c]._0=num_aux*num;
      caras[c]._1=j*2;
      caras[c]._2=(j+1)*2;
	  	  //sentido contrario agujas reloj?
      c=c+1;
	  //Revisar esto, unes punto central que es num_aux*num con los puntos inferiores
	  //revisar esos puntos inferiores.
     }
  }

 // tapa superior
if (fabs(perfil[num_aux-1].x)>0.0)
  {

   vertices[num_aux*num+1].x=0.0; 
   vertices[num_aux*num+1].y=perfil[num_aux-1].y; 
   //altura que concida con el ultimo punto del perfil, es decir el de abajo
   vertices[num_aux*num+1].z=0.0;

    for (j=0;j<num-1;j++)
     {caras[c]._0=num_aux*num+1; //el punto siguiente<
      caras[c]._2=(j+1)*2+1;
	  caras[c]._1=j*2+1;
	  //sentido contrario agujas reloj?
      c=c+1;
     }
	 //unes con puntos superiores en eso de las caras, con el punto centrar para la tapa como pivote
 }

}
