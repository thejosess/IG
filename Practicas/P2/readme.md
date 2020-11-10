# Práctica 1 IG ~ José Santos Salvador

    if (toupper(Tecla1)=='Q') exit(0);

    if (toupper(Tecla1)=='P'){ modo=0; glutPostRedisplay();}
    if (toupper(Tecla1)=='L'){ modo=1; glutPostRedisplay();}
    if (toupper(Tecla1)=='S'){ modo=2; glutPostRedisplay();}
    if (toupper(Tecla1)=='A'){ modo=3; glutPostRedisplay();}
    //añadido
    if (toupper(Tecla1)=='T'){ modo=4; glutPostRedisplay();}

    //cambiar color
    if (Tecla1=='5'){ color=1; glutPostRedisplay();}
    if (Tecla1=='6'){ color=2; glutPostRedisplay();}
    if (Tecla1=='7'){ color=3; glutPostRedisplay();}

    if (Tecla1=='1'){ objeto=0; glutPostRedisplay();}
    if (Tecla1=='2'){ objeto=1; glutPostRedisplay();}


* Creación de la clase cubo y su visualización (6 pt.) **REALIZADO (objeto 1)**
* Creación del código que permite visualizar en modo relleno. (2pt) **REALIZADO (modo 2)**
* Creación del código que permite visualizar en modo ajedrez. (2pt) **REALIZADO (objeto 3)**

* Adicionalmente se ha añadido el cambio de color de los objetos **(color1,2,3)** y un nuevo modo **(modo 4)** que permite visualizar todos los modos de visualización a la vez (aristas, punto y ajedrez)

# Práctica 2 IG ~ José Santos Salvador

## Métodos disponibles

	case 'Q':exit(0);
	case '1':modo=POINTS;break;
	case '2':modo=EDGES;break;
	case '3':modo=SOLID;break;
	case '4':modo=SOLID_CHESS;break;
	case '5':modo=ALL;break;
	//cambiar colores
	case '7': color.push_back(1); color.push_back(1); color.push_back(0); change_color = true; break;
	case '8': color.push_back(1); color.push_back(0); color.push_back(1); change_color = true; break;
	case '9': color.push_back(0); color.push_back(0.5); color.push_back(0.5); change_color = true; break;

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

He añadido adicionalmente (realizado en la parte voluntario de la P1) cambiar los colores de los objetos. Para ello he añadido tres atributos float a _triangulos3D (r,g,b) para guarden un color y un método change_color (vector<float> color, int size) que te permite cambiar el color de las figuras.  Además también se puede visualizar todos los modos a la vez (modo=ALL), añadido como extra también en la P1

Para las clases de cono, cilindro y esfera he heredado de _triangulos3D y he realizado las modificaciones pertinentes en parametros. Cada uno de estos métodos tiene las peculiaridades necesarias para generar un cilindro, un cono y una esfera.

    void _cilindro::parametros(vector<_vertex3f> perfil, int num)

    void _cono::parametros(vector<_vertex3f> perfil, int num, double altura)

    void _esfera::parametros(int n,int m, double radio)

En el desarrollo de la clase para generar un objeto de revolución a partir de un perfil difinido en un fichero PLY, he creado la clase _revolucionPly que hereda de _triangulos3D y en el método parametros se crea el objeto

    void _revolucionPly::parametros(char *file){


## Evaluación

* Creación de una clase para los objetos PLY. Dado el conjunto de datos del fichero, la clase permite introducirlos según las estructuras de datos ya definidas (2 pts.). **REALIZADO (OBJETO_PLY)**
* Creación de una clase para obtener objetos por barrido circular sin que contenga triángulos degenerados y puntos repetidos. (3 pts.). **REALIZADO (ROTACION)**
* Permitir que se pueda meter el vector de puntos de la generatriz en cualquier sentido (1 pt.) **REALIZADO (en la clase rotacion, método parametros)**  

    
        //Permitir que se pueda meter el vector de puntos de la generatriz en cualquier sentido
        //si se introduce de arriba a abajo, lo cambiamos de orden para que sea de abajo a arriba.
        if(perfil[num_aux].y < perfil[0].y) {
            //lo que hacemos es cambiar de orden el perfil, para que sea de abajo a arriba
            cout<<"Cambiando perfil de orden"<<endl;
            
            j=num_aux-1;
            for(i=0; i<num_aux/2; i++){
                vertice_aux = perfil[i];
                perfil[i]=perfil[j];
                perfil[j]=vertice_aux;
                j--;
            }
        }

* Creación de la clase para dibujar un cono. (1 pt.) **REALIZADO (CONO)**
* Creación de la clase para dibujar un cilindro. (1 pt.) **REALIZADO (CILINDRO)**
* Creación de la clase para dibujar un esfera. (1 pt.) **REALIZADO (ESFERA)**
* Creación de la clase que permite generar un objeto de revolución a partir de un perfil definido en un fichero PLY. (1 pt.) **REALIZADO (REVOLUCION_PLY)**

## Extra

* Permitir que la curva generatriz se pueda definir en cualquier eje. (2 pt.) **REALIZADO (ROTACIONY, ROTACIONZ)**     

Para la realización de la parte extra he añadido un nuevo parametro a la función parametros de _rotacion, siendo char eje. Donde esta variable indice el eje de la curva generatriz (si es x, será en el eje x y así con el resto de ejes)

    void _rotacion::parametros(vector<_vertex3f> perfil, int num, char eje)


Según el eje definido se generarán los puntos de una forma u otra

    	if(eje == 'y'){
		for (j=0;j<num;j++){
			for (i=0;i<num_aux;i++){
				vertice_aux.x=perfil[i].x;
				vertice_aux.z=-perfil[i].y*sin(2.0*M_PI*j/(1.0*num))+
								perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
				vertice_aux.y=perfil[i].y*cos(2.0*M_PI*j/(1.0*num))+
								perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
				vertices[i+j*num_aux]=vertice_aux;
			}
		}
	}
	else if(eje == 'x'){
		for (j=0;j<num;j++)
		{
			for (i=0;i<num_aux;i++){
				vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
								perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
				vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
								perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
				vertice_aux.y=perfil[i].y;
				vertices[i+j*num_aux]=vertice_aux;
			}
		}
	}
	else if(eje == 'z'){
		for (j=0;j<num;j++)
		{
			for (i=0;i<num_aux;i++){
				vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))-
								perfil[i].y*sin(2.0*M_PI*j/(1.0*num));
				vertice_aux.z=-perfil[i].z;
				vertice_aux.y=perfil[i].y*cos(2.0*M_PI*j/(1.0*num))+
								perfil[i].x*sin(2.0*M_PI*j/(1.0*num));
				vertices[i+j*num_aux]=vertice_aux;
			}
		}
		
		ejez = true;
	}

Y a la hora de crear las tapas tambien es necesario tener en cuenta el eje. Es importante notar que hago uso de una variable booleana ejez, para entrar en el if de tapa inferior y tapa superior porque al tener el punto en el z, no entra en el if. Por eso si está definido en el eje z, se pone esa variable a true y entra para la creación de las tapas.

    	// tapa inferior
	if (fabs(perfil[0].x)>0.0 || ejez){
		if(eje == 'y'){
			vertices[num_aux*num].x=perfil[0].x;
			vertices[num_aux*num].y=0.0; 
			vertices[num_aux*num].z=0.0;
		}
		else if(eje == 'x'){
			vertices[num_aux*num].x=0.0; 
			vertices[num_aux*num].y=perfil[0].y; 
			vertices[num_aux*num].z=0.0;
		}
		else if (eje == 'z'){
			vertices[num_aux*num].x=0.0; 
			vertices[num_aux*num].y=0.0; 
			vertices[num_aux*num].z=perfil[num_aux-1].z;
			//esto es debido a que es en el eje z
		}

		for (j=0;j<num;j++){
			caras[c]._0=num_aux*num;
			caras[c]._1=j*num_aux;
			caras[c]._2=((j+1)%num)*num_aux;
			c=c+1;
		}
	}

	// tapa superior
	if (fabs(perfil[num_aux-1].x)>0.0 || ejez)
	{
		if(eje == 'y'){
			vertices[num_aux*num+1].x=perfil[num_aux-1].x; 
			vertices[num_aux*num+1].y=0.0;
			vertices[num_aux*num+1].z=0.0;
		}else if( eje == 'x'){
			vertices[num_aux*num+1].x=0.0; 
			vertices[num_aux*num+1].y=perfil[num_aux-1].y;
			vertices[num_aux*num+1].z=0.0;
		}
		else if( eje == 'z'){
			vertices[num_aux*num+1].x=0.0; 
			vertices[num_aux*num+1].y=0.0;
			vertices[num_aux*num+1].z=perfil[0].z;
		}

		for (j=0;j<num;j++){	
			caras[c]._0=num_aux*num+1;
			caras[c]._1=j*num_aux+num_aux-1;
			caras[c]._2=((j+1)%num)*num_aux+num_aux-1;
			c=c+1;
		}
	}
