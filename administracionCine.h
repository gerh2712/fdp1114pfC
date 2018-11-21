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

/*  Defines */
#define cls "clear"
#define asientos 3

/*  Prototipos  */
void administracionCine();
void mensajeTipoSala(char tipoSala, float precio, float precioNinos);
void systemPause();
void mostrarMatriz(char sala[][asientos], int lugares);
void llenarCeros(char sala[][asientos], int lugares, char letras[], int sizeLetras);
int contarLugares(char sala[][asientos], int lugares);
int asignarLugares(char sala[][asientos], int lugares, char fl, char col);


/*  Función principal   */
void administracionCine()
{
    setlocale(LC_CTYPE, "Spanish");

    //Defines y variables    
    #define precioTradicional 50
    #define precio3D 100

    int numBoletos, numBAdulto, numBNino, lugaresDisponibles, lDSTradicional=asientos, lDS3D=asientos;

    int acuBATradi=0, acuBNTradi=0, acuBTradi=0, acuBA3D=0, acuBN3D=0, acuB3D=0, acuBT;

    char abc[26]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    char salaTradicional[asientos][asientos], sala3D[asientos][asientos];
    llenarCeros(salaTradicional, asientos, abc, 26);
    llenarCeros(sala3D, asientos, abc, 26);

    char tipoSala, confirmarCompra;

    float precioNinos, precioAdultos, sumaPrecio, acuPrecioTradicional=0, acuPrecio3D=0, acuPrecioTotal;

    int contaAsientos=0, i, j;

    char fila, columna; 


    system(cls);
    
     //Ciclo que obliga a que se llenen las salas 
   do
    {
        
        //Pregunta el tipo de sala que para la cual quiere adquirir boletes
        do
        {
            system(cls);
            printf("\n\nBienvenido, ¿quieres comprar boletos para una sala tradicional o una sala 3D?");
            printf("\n\n\ta)Tradicional\tb)3D\t:  ");
            scanf("%c", &tipoSala);
            while(getchar()!='\n');
            tipoSala = toupper(tipoSala);

            if(tipoSala!='A' && tipoSala!='B'){
                system("cls");
                printf("\n\nPor favor escoge una opción válida...");
            }

        } while (tipoSala!='A' && tipoSala!='B');

        //Según el tipo de sala 
        if(tipoSala=='A' && lDSTradicional!=0){

            precioNinos = precioTradicional*0.60;
            contaAsientos=0;
            sumaPrecio=0;
            precioAdultos=0;
            numBAdulto=0;
            numBNino=0;

            mensajeTipoSala(tipoSala, precioTradicional, precioNinos);
            systemPause();
            system(cls);


            //Verifica que solo compre el # de lugares disponibles
            do
            {
                printf("\n\n");
                printf("\n\nLos lugares que tienen un 0 están disponibles: ");
                printf("\n\n");
                mostrarMatriz(salaTradicional, asientos);
                systemPause();
                printf("\n\n");
                printf("\n\n¿Cuántos boletos de adulto quiere comprar?:  ");
                scanf("%i", &numBAdulto);

                printf("\n\n¿Cuántos boletos de niño quiere comprar?:  ");
                scanf("%i", &numBNino);

                numBoletos = numBAdulto + numBNino;
                lugaresDisponibles = contarLugares(salaTradicional, asientos);

                if(numBoletos>lugaresDisponibles){
                    system(cls);
                    printf("\n\nNo tenemos tantos lugares, por favor compra sólo los lugares que tenemos disponibles ...");
                }

            } while (numBoletos>lugaresDisponibles);


            system(cls);
            
            printf("\n\nPor favor selecciona tus [%i] lugares:  ", numBoletos);
            printf("\n\n");
            printf("\n\nLos lugares que tienen un 0 están disponibles: ");
            printf("\n\n");

            systemPause();
        
            //Llena los asientos en la sala
            do
            {
        
                mostrarMatriz(salaTradicional, asientos);

                //Guarda la coordenada de la fila
                printf("\n\nIntroduce la fila del asiento: ");
                scanf("%c", &fila);
                while(getchar()!='\n');
                fila = toupper(fila);
                //printf("\n\n%c", fila);

                //Guarda la coordenada de la columna
                printf("\n\nIntroduce la columna del asiento: ");
                scanf("%c", &columna);
                while(getchar()!='\n');
                columna = toupper(columna);
                //printf("\n\n%c", columna);

                systemPause();

                //Llena la sala
                contaAsientos+= asignarLugares(salaTradicional, asientos, fila, columna);


            } while (contaAsientos<numBoletos);


            systemPause();
            system(cls);

            //Realiza cálculos de costo por la compra
            precioAdultos = numBAdulto * precioTradicional;
            precioNinos*=numBNino;
            sumaPrecio = precioAdultos + precioNinos;

            //Acumuladores
            acuBATradi += numBAdulto;
            acuBNTradi += numBNino;
            acuBTradi += numBAdulto+numBNino;
            acuPrecioTradicional += sumaPrecio;


            //Muestra los lugares escogidos
            printf("\n\nEscogiste los siguientes lugares (tienen un 1):  ");
            mostrarMatriz(salaTradicional, asientos);
        
            //Muestra un mensaje con la información de la compra
            printf("\n\nEl costo total de sus boletos será de:  %.2f", sumaPrecio);
            printf("\n\n\tPrecio por bolestos de adulto:  %.2f", precioAdultos);
            printf("\n\n\tPrecio por boletos de niño:  %.2f", precioNinos);
            
            //Verifica cuántos lugares quedan disponibles
            lDSTradicional = contarLugares(salaTradicional, asientos); 

            systemPause();
            system(cls);


        }else if(tipoSala=='B' && lDS3D!=0){

            precioNinos = precio3D*0.60;
            contaAsientos=0;
            sumaPrecio=0;
            precioAdultos=0;
            numBAdulto=0;
            numBNino=0;

            mensajeTipoSala(tipoSala, precio3D, precioNinos);
            systemPause();
            system(cls);


            //Verifica que solo compre el # de lugares disponibles
            do
            {
                printf("\n\n");
                printf("\n\nLos lugares que tienen un 0 están disponibles: ");
                printf("\n\n");
                mostrarMatriz(sala3D, asientos);
                systemPause();
                printf("\n\n");

                printf("\n\n¿Cuántos boletos de adulto quiere comprar?:  ");
                scanf("%i", &numBAdulto);

                printf("\n\n¿Cuántos boletos de niño quiere comprar?:  ");
                scanf("%i", &numBNino);

                numBoletos = numBAdulto + numBNino;
                lugaresDisponibles = contarLugares(sala3D, asientos);

                if(numBoletos>lugaresDisponibles){
                    system(cls);
                    printf("\n\nNo tenemos tantos lugares, por favor compra sólo los lugares que tenemos disponibles ...");
                }

            } while (numBoletos>lugaresDisponibles);

            system(cls);
            
            printf("\n\nPor favor selecciona tus [%i] lugares:  ", numBoletos);
            printf("\n\n");
            printf("\n\nLos lugares que tienen un 0 están disponibles: ");
            printf("\n\n");

            systemPause();
        
            //Llena los asientos en la sala
            do
            {
        
                mostrarMatriz(sala3D, asientos);

                //Guarda la coordenada de la fila
                printf("\n\nIntroduce la fila del asiento: ");
                scanf("%c", &fila);
                while(getchar()!='\n');
                fila = toupper(fila);
                //printf("\n\n%c", fila);

                //Guarda la coordenada de la columna
                printf("\n\nIntroduce la columna del asiento: ");
                scanf("%c", &columna);
                while(getchar()!='\n');
                columna = toupper(columna);
                //printf("\n\n%c", columna);

                systemPause();

                //Llena la sala
                contaAsientos+= asignarLugares(sala3D, asientos, fila, columna);


            } while (contaAsientos<numBoletos);


            systemPause();
            system(cls);


            //Realiza cálculos de costo por la compra
            precioAdultos = numBAdulto * precio3D;
            precioNinos*=numBNino;
            sumaPrecio = precioAdultos + precioNinos;

            //Acumuladores
            acuBA3D += numBAdulto;
            acuBN3D += numBNino;
            acuB3D += numBAdulto+numBNino;
            acuPrecio3D += sumaPrecio;

            //Muestra los lugares escogidos
            printf("\n\nEscogiste los siguientes lugares (tienen un 1):  ");
            mostrarMatriz(sala3D, asientos);

            //Muestra un mensaje con la información de la compra
            printf("\n\nEl costo total de sus boletos será de:  %.2f", sumaPrecio);
            printf("\n\n\tPrecio por bolestos de adulto:  %.2f", precioAdultos);
            printf("\n\n\tPrecio por boletos de niño:  %.2f", precioNinos);

            //Verifica cuántos asientos quedan disponibles
            lDS3D = contarLugares(sala3D, asientos);                        

            systemPause();           
            system(cls);
            

        }else {
            system(cls);
            printf("\n\nParece que ya no hay lugares diponibles...");
            systemPause();
        }
      
        
    }while(lDSTradicional!=0 || lDS3D!=0);

    
    //Mostrar los resultados finales
    acuPrecioTotal = acuPrecio3D + acuPrecioTradicional;
    acuBT = acuB3D + acuBTradi;

    printf("\n\nSe han terminado las ventas, los resultados del día fueron...");
    printf("\n\n\tGanancias totales: %.2f", acuPrecioTotal);
    printf("\n\n\t\tGanancias en la sala tradicional: %.2f", acuPrecioTradicional);
    printf("\n\n\t\tGanancias en la sala 3D: %.2f", acuPrecio3D);
    printf("\n\n\tTotal de boletos vendidos: %i", acuBT);
    printf("\n\n\t\tBoletos vendidos en la sala tradicional: %i", acuBTradi);
    printf("\n\n\t\t\tBoletos de adulto: %i", acuBATradi);
    printf("\n\n\t\t\tBoletos de niño: %i", acuBNTradi);
    printf("\n\n\t\tBoletos vendidos en la sala 3D: %i", acuB3D);
    printf("\n\n\t\t\tBoletos de adulto: %i", acuBA3D);
    printf("\n\n\t\t\tBoletos de niño: %i", acuBN3D);


    printf("\n\n\nAhora regresaremos al menú principal (escoger un programa)...");

    systemPause();

    return(menu());
}

/*  Funciones   */

//System Pause
void systemPause(){
    printf("\n\nPresione una tecla para continuar...");
    getchar();
}

//Mensaje para el tipo de sala 
void mensajeTipoSala(char tipoSala, float precio, float precioNinos){

    system(cls);

    if(tipoSala=='A'){

        printf("\n\nHas seleccionado una sala tradicional, el precio por boleto de una sala tradicional es %.2f para adultos, y de %.2f para menores de edad", precio, precioNinos);

    }else {

        printf("\n\nHas seleccionado una sala 3D, el precio por boleto de una sala tradicional es %.2f para adultos, y de %.2f para menores de edad", precio, precioNinos);

    }    

}

//Muestra una matriz 
void mostrarMatriz(char sala[][asientos], int lugares){

    int i, j;

    for(i=0; i<lugares; i++){
        printf("\n\n");
        for(j=0; j<lugares; j++){
            printf("%5c", sala[i][j]);
        }
    }

}

//Llena una matriz preconfigurada de ceros y letras. Configura la Sala
void llenarCeros(char sala[][asientos], int lugares, char letras[], int sizeLetras){
    int i, j;
    

    for(i=0; i<lugares; i++){

        for(j=0; j<lugares; j++){

            if(i == 0 && j == 0){

                sala[i][j] = '*';

            }else if(i==0 && j>0){
                
                sala[i][j] = letras[j-1];

            }else if(j==0 && i>0){
                
                sala[i][j] = letras[i-1];
                
            }else {
                sala[i][j] = '0';
            }
        } 
    }
}

//Cuenta los lugares disponibles
int contarLugares(char sala[][asientos], int lugares){
    int i, j, contaLugar=0;
    

    for(i=0; i<lugares; i++){

        for(j=0; j<lugares; j++){

            if(sala[i][j] == '0'){

                contaLugar++;

            }

        } 
    }

    return contaLugar;

}

//Asigna los lugares a la sala
int asignarLugares(char sala[][asientos], int lugares, char fl, char col){
    int i, j, contarAsignados=0;

    for(i=0; i<lugares; i++){

        for(j=0; j<lugares; j++){

            if(sala[i][0] == fl && sala[0][j] == col && sala[i][j] == '0'){
                //En caso de que se encuentre el lugar especificado y esté libre

                sala[i][j] = '1';
                contarAsignados++;
                system(cls);

            }else if(sala[i][0] == fl && sala[0][j] == col && sala[i][j] != '0'){
                //En caso de que se halle el lugar especificado y esté ocupado

                system(cls);
                printf("\n\nEl lugar que escogiste está ocupado");
                printf("\n\n\tEscoge un lugar desocupado:  ");

            }

        } 
    }


    return contarAsignados;

}