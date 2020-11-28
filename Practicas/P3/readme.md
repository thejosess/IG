# Práctica 3 ~ José Santos Salvador 


make
./practica_objetos_B3 beethoven copa



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