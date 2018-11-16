/*
Programa 1	Central Meteorológica

Análisis
    Entradas
    Salidas
    Restricciones
*/

//TODO: CAMBIAR VARIABLES POR CONSTANTES PARA LOS ARREGLOS

//Includes
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Constantes
#define p printf
#define s scanf

void centralMeteorologica();

//Ejecuta el programa 1
void centralMeteorologica(){

	
	int i,mesS,mesN,tiempo=12;
	float norte[tiempo],centro[tiempo],sur[tiempo],sumaC=0,menorS,mayorN,total_norte=0,total_centro=0,total_sur=0;
	char consulta,meses[12][20] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
	float promedioC;
	
	system("cls");
	p("\n\n\tMeteorológico");
	p("\n\nIngrese los datos que se piden: \n");
	
	//Guardado de datos
	
	for(i=0; i<tiempo; i++ ){
		    p("\nLluvia caida en el norte en el mes de  %s es: ",meses[i]);
		    s("%f",&norte[i]);
    }
    
	system("cls");
	for(i=0; i<tiempo; i++){
		p("\nLluvia caida en el centro en el mes de %s es: ",meses[i]);
		s("%f",&centro[i]);
	}
	system("cls");
	for(i=0; i<tiempo; i++){
		p("\nLluvia caida en el sur en el mes de %s es: ",meses[i]);
		s("%f",&sur[i]);
		    
	}
	
	//Menu de consulta
	
	do{	
		system("cls");
		p("\n\n\t¿Qué información quiere consultar?: ");
		p("\n\na) El promedio anual de la región CENTRO.");
		p("\nb) El mes y registro con menor lluvia en la región SUR.");
		p("\nc) El mes y registro con mayor lluvia en la región NORTE.");
		p("\nd) La región con mayor lluvia anual.");
		p("\ne) Regresar al menu anterior.");
		p("\nf) Salir.");
		p("\n=> ");
		fflush(stdin);
		s("%c",&consulta);
		
		consulta = toupper(consulta);
		
		switch(consulta){
			case 'A':
				for(i=0;i<tiempo;i++){
					sumaC += centro[i];
				}
				promedioC = sumaC/tiempo + .0;
				p("\n\nEl promedio de la zona Centro es: %.2f [mm] de lluvia.\n\n",promedioC);
				system("pause");
				promedioC =0;
				sumaC=0;
				break;
			case 'B':
				menorS = sur[0]; // Valor del mes de enero
				mesS=0; // Numero de mes

				//Compara con cada elemento del arreglo
				for(i=1;i<tiempo;i++){
					if (menorS > sur[i]){
						menorS = sur[i];
						mesS = i;
					}
				}
				p("\n\nEl mes que tuvo menor lluvia en la zona Sur fue %s con %.2f [mm] de lluvia.\n\n",meses[mesS],menorS);
				system("pause");
				break;
			case 'C':
				mayorN = norte[0]; //Valor del mes de enero
				mesN=0; //Mes de enero
				for(i=1;i<tiempo;i++){
					if (norte[i] > mayorN){
						mayorN = norte[i];
						mesN = i;
					}
				}
				p("\n\nEl mes que tuvo mayor lluvia en la zona Norte fue %s con %.2f [mm] de lluvia.\n\n",meses[mesN],mayorN);
				system("pause");
				break;
			case 'D':
				for(i=0;i<tiempo;i++){
					total_norte += norte[i];
					total_centro += centro[i];
					total_sur += sur[i]; 
				}
				if(total_norte== total_centro && total_norte == total_sur){
					p("\n\nLas tres regiones tuvieron la misma cantidad de lluvia anual de %.2f [mm] de lluvia.\n\n",total_sur);
				}else if(total_norte > total_centro && total_norte > total_sur){
					p("\n\nLa region con mayor lluvia anual es la region Norte con: %.2f [mm] de lluvia.\n\n",total_norte);
				}else if (total_centro > total_sur){
					p("\n\nLa region con mayor lluvia anual es la region Centro con: %.2f [mm] de lluvia.\n\n",total_centro);		
				}else{
					p("\n\nLa region con mayor lluvia anual es la region Sur con: %.2f [mm] de lluvia.\n\n",total_sur);
				}
				system("pause");
				total_norte=0;
				total_centro=0;
				total_sur=0;
				break;	
			case 'E':
				break;	
				
				
			case 'F':
				system("cls");
				p("\n\nGracias por usar el programa hasta luego :D");
				exit(0);
			default:
				p("\n\nAviso: Opción invalida intentelo de nuevo\n\n");	
				system("pause");
				break;	
				
				
		}
		
	}while(consulta != 'E');
	
	
	if(consulta == 'E'){
	    system("cls");
	    return(menu());
	}


}