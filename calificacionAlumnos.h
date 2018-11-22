/*
Programa 3

Análisis
    Entradas: El arreglo que contiene las calificaciones
    Salidas: Media aritmetica,Varianza,Desviacion Estandar,Moda,Alumnos reprobados y aprobados(Cantidad y porcentaje),Aspirantes a Beca.
    Restricciones: Solamente numeros enteros del 0 al 10
*/
//Define.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define p printf
#define s scanf
#define cls "cls"
//Prototipo de función
void calificacionAlumnos();
float media(float calif[],int n);
float varianza(float calif[],int n);
float desviacion(float varianza);
float moda(float calif[],int n);
void aprobados(float calif[],int n);
void reprobados(float calif[],int n);
void beca(float calif[],int n);
void mostrarArreglo(float calif[],int n);
void menuCalificaciones(float calif[],int n);
//Ejecuta el programa 3
void calificacionAlumnos(){
    int i,j,cntCal=0,cuenta[10],cntModa=0,n,numero,posicion,posicionM;
	float promedio=0,varianzaT=0,numVarianza=0,desviacionT=0,modaT=0,newModa=0,calif[100];
	p("\nBienvenido, a partir de las calificaciones de estudiantes que hicieron el examen de ingreso a la Universidad, el programa nos dara informacion estadistica. \n ");
	p("Ingrese cuantas calificaciones va a insertar\n");
    p("=> ");
	s("%d",&n);
	p("\nIngrese las calificaciones de los Alumnos: ");
	
	for(i=0;i<n;i++){
		p("\n Calificacion del alumno %d: ",i+1);
		s("%f",&calif[i]);
	}
	system(cls);
    //Imprimir arreglo. 
    mostrarArreglo(calif,n);
	//Calculo de la Media
	promedio = media(calif,n);
	p("\n El promedio de las calificaciones es: \t %.2f",promedio);
	//Calculo de Varianza
	varianzaT= varianza(calif,n);
	p("\n La varianza de las calificaciones es: \t %.2f",varianzaT);
	//Calculo de Desviacion Estandar
	desviacionT = desviacion(varianzaT);
	p("\n La Desviacion Estandar de las calificaciones es: \t %.2f",desviacionT);
	//Calculo de la Moda
    moda(calif,n);
	//modaT = moda(calif,n);
    //p("\nLa moda es: %.2f",modaT);
    
    //Alumnos aprobados y reprobados
    aprobados(calif,n);
    reprobados(calif,n);
    //Aspirantes a Beca
    beca(calif,n);
	getchar();
	p("\n\nPulsa enter para continuar...");
	getchar();

	menuCalificaciones(calif,n);
}
float media(float calif[],int n){
	int i;
	float promedio,cntCal=0.0;
	for(i=0;i<n;i++){
		cntCal+=calif[i];
	}
	promedio = (cntCal/n);
	return promedio;
}
float varianza(float calif[],int n){
	int i;
	float varianza,numVarianza=0;
	for(i=0;i<n;i++){
		numVarianza+=pow(calif[i]-media(calif,n),2);
	}
	varianza= numVarianza/(n-1)+0.0;
	return varianza;
}
float desviacion(float varianza){
	float desviacion;
	desviacion = sqrt(varianza);
	return desviacion;
}

float moda(float calif[],int n){
	int i,j, moda=0,valorModa,modaFinal,lugar;
	int  mod[100];
	float pos;
	for(i=0;i<n;i++){
		mod[i] =0;
		for(j=0;j<n;j++){
			if(calif[i]==calif[j]){
				mod[i]= mod[i]+1;
			}
		}
		
	}
/*	for(i=0;i<n;i++){
		p("Valor %d es %d",i,mod[i]);
	}*/
	//Hasta aqui me parece esta bien
	moda=0;
	for(i=0;i<n;i++){
		if(mod[i]>moda){
			moda = mod[i];
			pos= calif[i];
			lugar=i;
			valorModa=1;
		}else if (mod[i]==moda && calif[i]!=pos){
			valorModa=0;
		}
	}
	if(valorModa==1){
		modaFinal = lugar;
		p("\n La moda es: \t %.2f",pos);
		
	}else if (valorModa==0){
		p("\n No existe moda");
	}
	return calif[modaFinal];
}

void aprobados(float calif[],int n){
	int i,aprobados=0;
	float porcentaje;
	for(i=0;i<n;i++){
		if(calif[i]>=6 && calif[i]<=10){
			aprobados++;
		}
	}
	porcentaje = (aprobados/(n*1.0))*100.0;
	p("\n De los %d alumnos %d aprobaron, porcentaje de reprobados: \t %.2f\n",n,aprobados,porcentaje);
}
void reprobados(float calif[],int n){
	int i,reprobados=0;
	float porcentaje=0;
	for(i=0;i<n;i++){
		if(calif[i]<6 && calif[i]>=0){
			reprobados++;
		}
	}
	porcentaje= (reprobados/(n*1.0))*100.0;
	p("\n De los %d alumnos %d reprobaron, porcentaje de reprobados: \t %.2f\n",n,reprobados,porcentaje);
}
void beca(float calif[],int n){
	int i,cntBeca=0;
	for(i=0;i<n;i++){
		if(calif[i]>=8 && calif[i]<=10){
			cntBeca++;
		}
	}
	p("\n El numero de aspirantes a beca es de: \t %d",cntBeca);
}
void mostrarArreglo(float calif[],int n){
    int i;
    p("\n ");
    p("[ ");
    for(i=0;i<n;i++){
    	p(" %.2f",calif[i]);
        p(" , ");
    }
    p(" ]");
}
void menuCalificaciones(float calif[], int n){
    int decision;
    int i,j,cntCal=0,cuenta[10],cntModa=0,numero,posicion,posicionM;
	float promedio=0,varianzaT=0,numVarianza=0,desviacionT=0,modaT=0,newModa=0;
    do{
		system(cls);
        p("\n¿Quiere ver algun dato en especifico?\n");
        p("1.- Promedio\n2.- Varianza\n3.- Desviacion Estandar\n4.- Moda\n5.- Alumnos aprobados y reprobados\n6.- Aspirantes a Beca\n7.- Imprimir Calificaciones\n8.- Salir");
        p("=>");
        s("%d",&decision);
        switch(decision){
            case 1:
                promedio = media(calif,n);
                p("\n El promedio de las calificaciones es: %.2f",promedio);
				getchar();
				p("\n\nPulsa enter para continuar...");
				getchar();
                break;

            case 2:
                varianzaT= varianza(calif,n);
                p("\n La varianza de las calificaciones es: %.2f",varianzaT);
                getchar();
				p("\n\nPulsa enter para continuar...");
				getchar();
				break;
            case 3:
                desviacionT = desviacion(varianzaT);
                p("\n La Desviacion Estandar de las calificaciones es: %.2f",desviacionT);
				getchar();
				p("\n\nPulsa enter para continuar...");
				getchar();
                break;
            case 4:
                moda(calif,n);
				getchar();
				p("\n\nPulsa enter para continuar...");
				getchar();
                break;
            case 5:
                aprobados(calif,n);
                reprobados(calif,n);
				getchar();
				p("\n\nPulsa enter para continuar...");
				getchar();
                break;
            case 6:
                beca(calif,n);
				getchar();
				p("\n\nPulsa enter para continuar...");
				getchar();
                break;
            case 7:
                mostrarArreglo(calif,n);
				getchar();
				p("\n\nPulsa enter para continuar...");
				getchar();
                break;
            case 8:
                p("Saliendo del programa, retornando al menu.");
				getchar();
				p("\n\nPulsa enter para continuar...");
				getchar();
                return(menu());

                break;
            default:
                p("\nOpcion Invalida, inserte una opcion correcta");
				getchar();
				p("\n\nPulsa enter para continuar...");
				getchar();
        }
    }while(decision);
}