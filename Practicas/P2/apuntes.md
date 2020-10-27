##Práctica 2

Mirar guión
hacerlas con blender y luego exportar al formato plyt.

tapas al considerar de abajo hacía a arriba y el punto de mas abajo es el primero. No hemos puesto ninggun puesto en el eje x y eso al girar sobre el eje, faltaría uno. NUNCA PONER PUNTO EN EL EJE DE GIRO.      
Como hacer tapa? -> creas un nuevo punto sobre el eje x y lo enganchans con el resto de puntos pero esse punto tapa no estaba en el perfil inicial.   
Para el tema del PLY miras los puntos e indices, tienes que ponerle cara seguro. Y el objeto por revolución hacerlo diferente al que hay en el PDF.  

##Pide la práctica.
* Clase para los objetos PLY
* Crear un objeto por revolución (QUE NO TENGA TRIANGULOS DEGENERADOS, ESTO ES POR LOS PUNTOS REPETIDOS COMO ARRIBA)
* Se pueda invertir del vector del perfil  
valor de y negativo en el ply del ojboeto ajedrez, que se pueda empezar tambien por la parte superior del objeto ene vez de la inferior.
* Tres casos particulares de objetos por revolución. Cono, cilindro y esfera. Podemos tener tratamientos distintos por las tapas.      
Por el cono: El perfil sería solo un punto en el eje  x desplazado. ---------x-----. Luego tienes que crear las tapas, un punto en el 0,0 y ese punto engancharlo con el resto de puntos.con todos hacer igual![eo](./imagenes/1.png). Luego le das cierta altura en el eje y y ese punto lo  encganchas co el resto de la base y y al girarlo.![eo](./imagenes/2.png).La tapa superior no puede ser como el peón.    
Por el cilindro:En este las tapas si son planas.Los dos puntos pueden ser apoyados en el eje  x y por encima o los dos por encima del eje x.![eo](./imagenes/3.png). Luego vas unidiendo puntos y para las tapas vas enganchando.![eo](./imagenes/4.png)   
Por la esfera:sobre el eje de la x, es un poco mas, a la hora de colocar el punto para las tapas, no puede estar a la misma altura del ultimo punto, tiene que ser un pooco mas alto.![eo](./imagenes/5.png). Que altura que habría que darle a esos puntos para la tapa? inicial y final será lo que mide el radio de la esfera no el ultimo punto, el RADIO. ![eo](./imagenes/6.png)
ver_ply divido entre 3 //mirar codigo.
ver_ply es de una sola dimensión y lo guardamos en un vector de tres componentes. n_puntos y n_car.

element face 1 PONERLO ESO SEGURO.   
Optimizar objetos y no ponter TANTAS CARAS. EL radio para una esera y giras el radio para generar puntos de perfil y a partir de esos puntos de perfil los vuelves a girar apraa generar esfera.  
Hay gente que pone puntos edl perfil en el objeto ply NO ES ASÍ. Es un objeto tipo esfera y revolución y se le pasa solo radio y numeors lados y lonigutd y latitus para que se haga.



# Código modificado
MIRAR LO QUE COPIE EN SUCIO EN LA CARPETA ESA

# APuntes push matrix
Basicamente metes y sacas de la pila la matriz con la que vas as trabjar para no afecatar al resto de objetos y que queden intactos 

glPushMatrix(); // La función glPushMatrix() realiza una copia de la matriz superior y la pone encima de la pila, de tal forma que las dos matrices superiores son iguales, al llamar a la función glPushMatrix() se duplica la matriz superior. Las siguientes transformaciones que se realizan se aplican sólo a la matriz superior de la pila, quedando la anterior con los valores que tenía en el momento de llamar a la función glPushMatrix().
glPopMatrix(); La función glPopMatrix() elimina la matriz superior, quedando en la parte superior de la pila la matriz que estaba en el momento de llamar a la función glPushMatrix().

Código BUENO -> http://aide-comp-graf.blogspot.com/2007/03/previo-practica-2_06.html


# Teoria

si con 2 puntos perfil tienes 1 caras, 3 puntos perfil, 2 caras, 4 puntos 3 caras. //mirar videos
n puntos en el perfil, será n-1 caras., (n-1)*2 caras (cada cara de arriba son dos). 

https://github.com/Jumacasni/IG-UGR