//Includes
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "centralMeteorologica.h"
#include "administracionCine.h"
//#include "calificacionAlumnos.h"

//Constantes
#define p printf
#define s scanf
//Define
#define cls "clear"

//Prototipo de funciones
void menu();

//Función principal
int main()
{
    setlocale(LC_CTYPE,"Spanish");
    menu();

}

//Funciones

//Menu

void menu(){
        //Variables
    char decision;
    
    do{
    system(cls);
    //Menú que muestra las opciones de los distintos programas
    p("\n\nBienvenido");
    p("\n\n\ta) Central Meteorologica de Mexico");
    p("\n\n\tb) Administracion de un cine");
    p("\n\n\tc) Calificaciones alumnos");
    p("\n\n\td) Salir");
    p("\n=> ");
    //fflush(stdin);
    s("%c", &decision);
    while(getchar()!='\n');
    

    decision = toupper(decision);

    switch (decision){
        case 'A':
            system(cls);
            centralMeteorologica();
            break;
        case 'B':
            system(cls);              
            administracionCine();
            break;

        case 'C':
            system(cls);
           // calificacionAlumnos();
            break;
        case 'D':
            system(cls);
            p("\n\nGracias por usar el programa :D\n\n");
            exit(0);
        default:
            p("\n\nParece que no has introducido una opción válida, intenta de nuevo\n\n");
			getchar();
			p("\n\nPulsa enter para continuar...");
			getchar();
        }

    } while(decision != 'A' && decision != 'B' && decision != 'C');

    
}
