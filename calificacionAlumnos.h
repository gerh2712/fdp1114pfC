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
#define cls cls
//Prototipo de función
void calificacionAlumnos();
float media(float calif[],int n);
float varianza(float calif[],int n);
float desviacion(float calif[],int n);
float moda(float calif[],int n);
void aprobados(float calif[],int n);
void reprobados(float calif[],int n);
void beca(float calif[],int n);
void mostrarArreglo(float calif[],int n);
//Ejecuta el programa 3
void calificacionAlumnos(){
    int i,j,cntCal=0,cuenta[10],cntModa=0,n,numero,posicion,posicionM;
	float promedio,varianzaT,numVarianza,desviacionT,modaT=0,newModa=0,calif[100];
	p("\nBienvenido, a partir de las calificaciones de estudiantes que hicieron el examen de ingreso a la Universidad, el programa nos dara informacion estadistica. \n ");
	p("Ingrese cuantas calificaciones va a insertar\n");
    p("=> ");
	s("%d",&n);
	p("\nIngrese las calificaciones de los Alumnos: ");
	
	for(i=0;i<n;i++){
		p("\n Calificacion del alumno %d: ",i+1);
		s("%d",&calif[i]);
	}
    //Imprimir arreglo. 
    mostrarArreglo(calif,n);
	//Calculo de la Media
	promedio = media(calif,n);
	p("\n El promedio de las calificaciones es: %.2f",promedio);
	//Calculo de Varianza
	varianzaT= varianza(calif,n);
	p("\n La varianza de las calificaciones es: %.2f",varianzaT);
	//Calculo de Desviacion Estandar
	desviacionT = desviacion(calif,n);
	p("\n La Desviacion Estandar de las calificaciones es: %.2f",desviacionT);
	//Calculo de la Moda
    moda(calif,n);
	//modaT = moda(calif,n);
    //p("\nLa moda es: %.2f",modaT);
    
    //Alumnos aprobados y reprobados
    aprobados(calif,n);
    reprobados(calif,n);
    //Aspirantes a Beca
    beca(calif,n);
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
	float varianza,numVarianza;
	for(i=0;i<n;i++){
		numVarianza+=pow(calif[i]-media(calif,n),2);
	}
	varianza= numVarianza/(n-1)+0.0;
	return varianza;
}
float desviacion(float calif[],int n){
	float desviacion;
	desviacion = sqrt(varianza(calif,n));
	return desviacion;
}

float moda(float calif[],int n){
	int i,j, moda,pos;
	int  mod[100];
    for (i=0;i<n;i++) {
        mod[i]=0;
    	for (j=0;j<n;j++){
			if (calif[i]==calif[j]){
				mod[i]++;
			}          
		}   
    }
	moda=0;
    for (i=1 ; i<n ; i++){
        for (j=1 ;j<n;j++){
            if(calif[i]!=calif[j]){
                if (mod[i]>=mod[j]){
            	    pos=i;
            	    moda=1;
          	    }    
            }
              
        } 
    }
    if(moda==1){
    	p("\nExiste moda y es %d ",
        calif[pos]);
    }else{
    	p("\nNo existe moda ");
    }
    for(i=0;i<n;i++){
    	p("\nValor %d del arreglo de cuenta: %d",i,mod[i]);
    }
	return calif[pos];
}

void aprobados(float calif[],int n){
	int i,aprobados=0;
	float porcentaje;
	for(i=0;i<n;i++){
		if(calif[i]>=6 && calif[i]<=10){
			aprobados++;
		}
	}
	porcentaje = (aprobados/n)*100+.0;
	p("\n De los %d alumnos %d aprobaron, porcentaje de reprobados: %.2f\n",n,aprobados,porcentaje);
}
void reprobados(float calif[],int n){
	int i,reprobados=0;
	float porcentaje=0;
	for(i=0;i<n;i++){
		if(calif[i]<6 && calif[i]>=0){
			reprobados++;
		}
	}
	porcentaje= (reprobados/n)*100+.0;
	p("\n De los %d alumnos %d reprobaron, porcentaje de reprobados: %.2f\n",n,reprobados,porcentaje);
}
void beca(float calif[],int n){
	int i,cntBeca=0;
	for(i=0;i<n;i++){
		if(calif[i]>=8 && calif[i]<=10){
			cntBeca++;
		}
	}
	p("\n El numero de aspirantes a beca es de %d",cntBeca);
}
void mostrarArreglo(float calif[],int n){
    int i;
    p("\n ");
    p("[ ");
    for(i=0;i<n;i++){
    	p(" %.2f",i,calif[i]);
        p(" , ");
    }
    p(" ]");
}
void menuCalificaciones(){
    int decision;
    do{
        p("\n¿Quiere ver algun dato en especifico?\n");
        p("1.- Promedio\n2.-Varianza\n3.-Desviacion Estandar\n4.-Moda\n5.-Alumnos aprobados y reprobados\n6.- Aspirantes a Beca\n7.- Imprimir Calificaciones\n8.-Salir");
        p("=>");
        s("%d",decision);
        switch(decision){
            case 1:
                promedio = media(calif,n);
                p("\n El promedio de las calificaciones es: %.2f",promedio);
                break;
            case 2:
                varianzaT= varianza(calif,n);
                p("\n La varianza de las calificaciones es: %.2f",varianzaT);
                break;
            case 3:
                desviacionT = desviacion(calif,n);
                p("\n La Desviacion Estandar de las calificaciones es: %.2f",desviacionT);
                break;
            case 4:
                moda(calif,n);
                break;
            case 5:
                aprobados(calif,n);
                reprobados(calif,n);
                break;
            case 6:
                beca(calif,n);
                break;
            case 7:
                mostrarArreglo(calif,n);
                break;
            case 8:
                p("Saliendo del programa, retornando al menu.");
                exit(0);
                return (menu());
                break;
            default:
                p("\nOpcion Invalida, inserte una opcion correcta");
        }
    }while(decision);
}