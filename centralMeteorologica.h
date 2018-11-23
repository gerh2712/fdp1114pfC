/*
Programa 1	Central Meteorológica
Análisis
    Entradas: Registros de lluvias en la zona norte,centro y sur
    Salidas: Promedio anua lde la region centro
	         Registro con menor lluvia en la region sur
			 Mes y registro con mayor lluvia en la region norte
			 y la region con mayor lluvia anual
    Restricciones: Solo se aceptan datos mayores de cero
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
#define cls "cls"

void centralMeteorologica();

//Ejecuta el programa 1
void centralMeteorologica(){

	
	int i,j,mesS,mesN;
	float norte[12],centro[12],sur[12],sumaC=0,menorS,mayorN,total_norte=0,total_centro=0,total_sur=0;
	char consulta,meses[12][20] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
	float promedioC;
	
	system(cls);
	p("\n\n\tMeteorologico");
	p("\n\nIngrese los datos que se piden: \n");
	
	//Guardado de datos
	
		for(i=0;i<12;i++){
			p("\nLluvia caida en el mes de [%s] en el NORTE del pais: ",meses[i]);
		    s("%f",&norte[i]);
		}
    
	system(cls);
		for(i=0;i<12;i++){
			p("\nLluvia caida en el mes de [%s] en el CENTRO del pais: ",meses[i]);
		    s("%f",&centro[i]);
		}
	system(cls);
		for(i=0;i<12;i++){
			p("\nLluvia caida en el mes de [%s] en el SUR del pais: ",meses[i]);
		    s("%f",&sur[i]);
		}

	
	//Menu de consulta
	
	do{	
		system(cls);
		p("\n\n\tMenu: ");
		p("\n\na) El promedio anual de la region CENTRO.");
		p("\nb) El mes y registro con menor lluvia en la region SUR.");
		p("\nc) El mes y registro con mayor lluvia en la region NORTE.");
		p("\nd) La region con mayor lluvia anual.");
		p("\ne) Mostrar tabla con todos los datos.");
		p("\nf) Regresar al menu anterior.");
		p("\ng) Salir.");
		p("\n=> ");
		fflush(stdin);
		s("%c",&consulta);
		
		consulta = toupper(consulta);
		
		switch(consulta){
			case 'A':
				for(i=0;i<12;i++){
					sumaC += centro[i];
				}
				promedioC = sumaC/12.0;
				p("\n\nEl promedio de la zona CENTRO es: %.2f [mm] de lluvia.\n\n",promedioC);
				getchar();
				p("\n\nPulsa enter para continuar...");
				getchar();
				promedioC =0;
				sumaC=0;
				break;
			case 'B':
				menorS = sur[0]; // Valor del mes de enero
				mesS=0; // Numero de mes

				//Compara con cada elemento del arreglo
				for(i=1;i<12;i++){
					if (menorS > sur[i]){
						menorS = sur[i];
						mesS = i;
					}
				}
				p("\n\nEl mes que tuvo menor lluvia en la zona SUR fue %s con %.2f [mm] de lluvia.\n\n",meses[mesS],menorS);
				getchar();
				p("\n\nPulsa enter para continuar...");
				getchar();
				break;
			case 'C':
				mayorN = norte[0]; //Valor del mes de enero
				mesN=0; //Mes de enero
				for(i=1;i<12;i++){
					if (norte[i] > mayorN){
						mayorN = norte[i];
						mesN = i;
					}
				}
				p("\n\nEl mes que tuvo mayor lluvia en la zona NORTE fue %s con %.2f [mm] de lluvia.\n\n",meses[mesN],mayorN);
				system("pause");
				break;
			case 'D':
				for(i=0;i<12;i++){
					total_norte += norte[i];
					total_centro += centro[i];
					total_sur += sur[i]; 
				}
				if(total_norte== total_centro && total_norte == total_sur){
					p("\n\nLas tres regiones tuvieron la misma cantidad de lluvia anual de %.2f [mm] de lluvia.\n\n",total_sur);
				}else if(total_norte > total_centro && total_norte > total_sur){
					p("\n\nLa region con mayor lluvia anual es la region NORTE con: %.2f [mm] de lluvia.\n\n",total_norte);
				}else if (total_centro > total_sur){
					p("\n\nLa region con mayor lluvia anual es la region CENTRO con: %.2f [mm] de lluvia.\n\n",total_centro);		
				}else{
					p("\n\nLa region con mayor lluvia anual es la region SUR con: %.2f [mm] de lluvia.\n\n",total_sur);
				}
				getchar();
				p("\n\nPulsa enter para continuar...");
				getchar();
				total_norte=0;
				total_centro=0;
				total_sur=0;
				break;	
			case 'E':
			    p("\n\n\t\tNorte\t\tCentro\t\tSur\n\n\n");
					for(i=0;i<12;i++){
						if(i==8 || i==10 || i==11){
							p("%s\t",meses[i]);
							p("%.2f [mm]\t%.2f [mm]\t%.2f [mm]\n\n",norte[i],centro[i],sur[i]);
							
						}
							
						else{
							p("%s\t",meses[i]);
							p("\t%.2f [mm]\t%.2f [mm]\t%.2f [mm]\n\n",norte[i],centro[i],sur[i]);
						}
							
						
					}


				getchar();
				p("\n\nPulsa enter para continuar...");
				getchar();
			    break;	

			case 'F':
				break;
				
				
			case 'G':
				system(cls);
				p("\n\nGracias por usar el programa hasta luego :D");
				exit(0);
			default:
				p("\n\nAviso: Opcion invalida intentelo de nuevo\n\n");	
				getchar();
				p("\n\nPulsa enter para continuar...");
				getchar();
				break;	
				
				
		}
		
	}while(consulta != 'F');
	

	if(consulta == 'F'){
	    system("cls");
		while(getchar()!='\n');
	    return(menu());
	}


}
