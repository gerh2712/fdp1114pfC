/*
Programa 2

Análisis
    Entradas
        >Cuántos boletos quiere comprar
        >Si el boleto es para adulto o infante 
        >Si es para sala tradicional o 3D
    Salidas
        >El costo total de los boletos comprados
        >Despliegue de la sala 
        >Subtotal Sala tradicional 
        >Subtotal Sala 3D
    Restricciones
        >Sólo se pueden comprar los boletos disponibles
        >El usuario debe de escoger sus asientos
        >Se pide que compren asientos hasta que las salas estén llenas

*/
/*  Includes    */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//Define
#define cls cls

//Prototipo de función 
void administracionCine();
void mensajeTipoSala(char tipoSala, float precioTradicional, float precioNinos);
void llenarMatriz(int sala[][asientos], int salaSize);



//Ejecuta el programa 2
void administracionCine(){

    //Variables y Defines
    #define asientos 4
    #define precioTradicional 50
    #define precio3D 100

    int salaTradicional[asientos][asientos], sala3D[asientos][asientos], numBoletos, numBAdultos, numBNinos;
    float precioNinos;
    char tipoSala;


    //Ciclo que obliga a que se llenen las salas 
    do
    {
        
        //Pregunta el tipo de sala que para la cual quiere adquirir boletes
        do
        {
            printf("\n\nBienvenido, ¿quieres comprar boletos para una sala tradicional o una sala 3D?");
            printf("\n\na)Tradicional\tb)3D\t:  ");
            scanf("%c", &tipoSala);
            while(getchar()!='\n');
            tipoSala = toupper(tipoSala);

            if(tipoSala!='A' && tipoSala!='B'){
                system("cls");
                printf("\n\nPor favor escoge una opción válida...");
            }

        } while (tipoSala!='A' && tipoSala!='B');

        //Según el tipo de sala 
        if(tipoSala=='A'){

            precioNinos = precioTradicional*0.60;

            mensajeTipoSala(tipoSala, precioTradicional, precioNinos);

        }else {

            precioNinos = precio3D*0.60;

            mensajeTipoSala(tipoSala, precioTradicional, precioNinos);

        }

        
        
    } while (1);
    

    return 0;
}

/*  Funciones   */

//Mensaje para el tipo de sala 
void mensajeTipoSala(char tipoSala, float precioTradicional, float precioNinos){

    if(tipoSala=='A'){

            printf("\n\nHas seleccionado una sala tradicional, el precio por boleto de una sala tradicional es %.2f para adultos, y de %.2f para menores de edad", precioTradicional, precioNinos);

        }else {

            printf("\n\nHas seleccionado una sala 3D, el precio por boleto de una sala tradicional es %.2f para adultos, y de %.2f para menores de edad", precioTradicional, precioNinos);

        }

}

//Llena un una sala de cine (la setea) 
void llenarMatriz(int sala[][asientos], int salaSize){
    int i, j;

    for(i=0; i<salaSize; i++){
        
        for( j = 0; j < salaSize; j++){
            
            if(j=0){
                sala[][] = A;
            }

        }
        
    }

}


//Muestra una Matriz 