/*
Programa 1

Análisis
    Entradas
    Salidas
    Restricciones
*/
/*
Programa 2

Análisis
    Entradas
    Salidas
    Restricciones
*/
/*
Programa 3

Análisis
    Entradas
    Salidas
    Restricciones
*/

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Prototipo de funciones

//Función principal
int main()
{
    //Variables
    int ejecutarPrograma;

    //Menú que muestra las opciones de los distintos programas
    printf("\n\nBienvenido, antes que nada, ¿qué programa quieres ejecutar?");
    printf("\n\n\t1): Central Meteorológica de México");
    printf("\n\n\t2): Administración de un cine");
    printf("\n\n\t3): Calificaciones alumnos");

    //Ciclo con validación para ejecutar un programa

    do{
        printf("\n\n¿Qué programa desea ejecutar?: ");
        scanf("%i", &ejecutarPrograma);

        if (ejecutarPrograma == 1){
            /* code */
        }
        else if (ejecutarPrograma == 2){
            /* code */
        }
        else if (ejecutarPrograma == 3){
            /* code */
        }
        else{
            system("cls");
            printf("\n\nParece que no has introducido una opción válida, intenta de nuevo");
            printf("\n\n\t1): Central Meteorológica de México");
            printf("\n\n\t2): Administración de un cine");
            printf("\n\n\t3): Calificaciones alumnos");
        }

    } while(ejecutarPrograma != 1 && ejecutarPrograma != 2 && ejecutarPrograma != 3);

    return 0;
}

//Funciones