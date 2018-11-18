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
#define p printf
#define s scanf
//Prototipo de función
void calificacionAlumnos();
float media(int calif[],int n);
float varianza(int calif[],int n);
float desviacion(int calif[],int n);
float moda(int calif[],int n);
void aprobados(int calif[],int n);
void reprobados(int calif[],int n);
void beca(int calif[],int n);
//Ejecuta el programa 3
void calificacionAlumnos(){
    int i,j,calif[100],cntCal=0,cuenta[10],cntModa=0,n,numero,posicion,posicionM;
	float promedio,varianzaT,numVarianza,desviacionT,modaT=0,newModa=0;
	p("\nBienvenido, a partir de las calificaciones de estudiantes que hicieron el examen de ingreso a la Universidad, nos dara informacion estadistica \n ");
	p("Ingrese cuantas calificaciones va a insertar");
	s("%d",&n);
	p("\nIngrese las calificaciones de los Alumnos: ");
	
	for(i=0;i<n;i++){
		p("\n Calificacion %d: ",i+1);
		s("%d",&calif[i]);
	}

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
float media(int calif[],int n){
	int i;
	float promedio,cntCal=0.0;
	for(i=0;i<n;i++){
		cntCal+=calif[i];
	}
	promedio = (cntCal/n);
	return promedio;
}
float varianza(int calif[],int n){
	int i;
	float varianza,numVarianza;
	for(i=0;i<n;i++){
		numVarianza+=pow(calif[i]-media(calif,n),2);
	}
	varianza= numVarianza/(n-1)+0.0;
	return varianza;
}
float desviacion(int calif[],int n){
	float desviacion;
	desviacion = sqrt(varianza(calif,n));
	return desviacion;
}

float moda(int calif[],int n){
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

            }
            if (mod[i]>=mod[j]){
            	pos=i;
            	moda=1;
          	}      
        } 
    }
    if(moda==1){
    	p("\nExiste moda y es %d ".calif[pos]);
    }else{
    	p("\nNo existe moda ");
    }
    for(i=0;i<n;i++){
    	p("\nValor %d del arreglo de cuenta: %d",i,mod[i]);
    }
	return calif[pos];
}

void aprobados(int calif[],int n){
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
void reprobados(int calif[],int n){
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
void beca(int calif[],int n){
	int i,cntBeca=0;
	for(i=0;i<n;i++){
		if(calif[i]>=8 && calif[i]<=10){
			cntBeca++;
		}
	}
	p("\n El numero de aspirantes a beca es de %d",cntBeca);
}