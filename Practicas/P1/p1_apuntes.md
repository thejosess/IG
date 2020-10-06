arista, lleno y ajedrez es sobre la clase triangulo??
colorear y tal.

para hacer zoom con con avPag o rePag


separado en dos partes

donde se crean los solidos que no depende de Open GL, eso hacerlo en archivos diferentes.
objetos.cc se pueden separar en dos archivos 
en un archivo la implementación de open gl que es como draw puntos
y otro archivos que no sea depende de Opengl como matrices
clase piramide
piramide::piramide
vertices y todo eso

objetos.h
poner un color por defecto? a cada uno?

void cambiarGrosor(int i) //ajuagstar el grosors
void cambiar_rojo(float r);
void cambiar_verde(float g);
void cambiar_azul(float b);

.h
vector<vetext car>caras
triangulos3d
int grosor; como atributo
float r,g,b;


LO MISMO DEL GROSOR SE PODRIA HACRE CON COLORES
que tuviese un atributo color y metodo para cambiar color


PUEDES CAMBIAR EL CODIGO POR COMPLETO
--------------

haacer la lista de vertices que tiene cubo 
y tr


vertices 8 al cubo
triangulos tambien fijar como se hace con piramide.

glutSwapBuffer evita el parpadeo


en practica 1
draw_objetocs 
ahii puedes poner piramide.draw puntos 



------------------

Intentar pasar estas practicas y modelos con javascript mediante el navegador y con WebGL. -> Mirar marcadores de hardzone 



primero haces puntos, dibujas puntos
cubo centrado al origen
o un punto que sea esquina
//SEGUIR LAS TRANSPARENCIA DEL TEMA 2 para ver como ver los puntos que se colocan en sentido contrario a las agujas del reloj.
En c se empiezan con el 0 (punto).
0,0,tam

MIRAR TRANSPARENCIA 8 DEL TEMA 2
empeazndo desde 0
es no centrado

mirar codigo y cambiar modelos 

lo ultimo para no hacer tener wque compilarlo
arreglar lo de las variables globales

cada cara de un color distinto
cada punto de un color distinto
que se pueda fijar el color como hemos dicho arriba 

poner teclas para cambiar el color?