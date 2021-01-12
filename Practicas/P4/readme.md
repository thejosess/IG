# Práctica 4 ~ José Santos Salvador 

make   

./practica_objetos_B4 beethoven copa

## Metodos disponibles

	case 'Q':exit(0);
	case '1':modo=POINTS;animacion = false;break;
	case '2':modo=EDGES;animacion = false;break;
	case '3':modo=SOLID;animacion = false;break;
	case '4':modo=SOLID_CHESS;animacion = false;break;
	case '5':modo=ALL;animacion = false;break;
	//cambiar colores
	case '7': color.push_back(1); color.push_back(1); color.push_back(0); change_color = true; animacion = false;break;
	case '8': color.push_back(1); color.push_back(0); color.push_back(1); change_color = true; animacion = false;break;
	case '9': color.push_back(0); color.push_back(0.5); color.push_back(0.5); change_color = true; animacion = false;break;

	//iluminacion
	case 'M':modo=SOLID_ILLUMINATED_FLAT;animacion = false;break;
    case 'N':modo=SOLID_ILLUMINATED_GOURAUD;animacion = false;break;

	case 'P':t_objeto=PIRAMIDE;animacion = false;break;
	case 'C':t_objeto=CUBO;animacion = false;break;
	case 'O':t_objeto=OBJETO_PLY;animacion = false;break;	
	case 'R':t_objeto=ROTACION;animacion = false;break;
	case 'D':t_objeto=CILINDRO;animacion = false;break;
	case 'L':t_objeto=CONO;animacion = false;break;
	case 'E':t_objeto=ESFERA;animacion = false;break;
	case 'F':t_objeto=REVOLUCION_PLY;animacion = false;break;
	case 'Y':t_objeto=ROTACIONY;animacion = false;break;
	case 'Z':t_objeto=ROTACIONZ;animacion = false;break;
    case 'T':t_objeto=ARTICULADO;animacion = false;break;
	case 'A':
		if(animacion)
			animacion = false;
		else
			animacion = true;
		//pulsando otra vez en A se para
	break;
	case 'S':t_objeto=SPIDER;animacion = false;break;
 	case 'B':valor+=0.5;if(valor>4) valor=4; cout<< "valor: " << valor;break;
	case 'V':valor-=0.5;if(valor<0) valor=0.5;break; 


## Transformaciones y rotaciones disponibles

	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;

	case GLUT_KEY_F1:spider.setGiroPataPuntaSup(-valor);break;
	case GLUT_KEY_F2:spider.setGiroPataPuntaSup(valor);break;

	case GLUT_KEY_F3:spider.setGiroPataPuntaInf(-valor);break;
	case GLUT_KEY_F4:spider.setGiroPataPuntaInf(valor);break;

	case GLUT_KEY_F5:spider.setGiroQueliceros(-valor);break;
	case GLUT_KEY_F6:spider.setGiroQueliceros(valor);break;
	case GLUT_KEY_F7:;spider.setGiroPataCentralSup(-valor);break;
	case GLUT_KEY_F8:spider.setGiroPataCentralSup(valor);break;
	case GLUT_KEY_F9:;spider.setGiroPataExteriorSup(-valor);break;
	case GLUT_KEY_F10:spider.setGiroPataExteriorSup(valor);break;
	case GLUT_KEY_F11:;spider.setGiroPataExteriorInf(-valor);break;
	case GLUT_KEY_F12:spider.setGiroPataExteriorInf(valor);break;

	//mover iluminacion
	case GLUT_KEY_INSERT:alfa+=5;break;
	case GLUT_KEY_END:alfa-=5;break;
	//son las teclas insert y end o fin en español

## Ejercicio de texturas realizado en clase

En la carpeta de ejercicio_textura se hace

	make
	./ejemplo

