#include<stdio.h>
#include<stdlib.h>
#include <locale.h> 
#include <math.h>

int ConfiguraIdioma();
void crear_tab();
void diferencias();

void spline(float s[50][5]);
int const Tam=50;

void PideDatos(int *Dim,float Sist[][Tam],float s[50][5]);

void Invierte(int Dim, float Sist[][Tam], float Inv[][Tam]);
float x[50][51];
float y[50][4];
int p;
int dat;
float h;

void portada();


int main (){
	
	ConfiguraIdioma();
	portada();
	int repite = 1;

	int opcion = -1;
	
	int salir = 0;
	
	do {

		system("cls");
		
		printf("\n\t------------------------------------------------------------------------------------------------");
		printf("\n\n\t\t\t\t\t\tMENÚ  PRINCIPAL\n");
		printf("\n\t-------------------------------------------------------------------------------------------------\n");
		printf("\n\t\t[1]. Interpolacion(Diferencias divididas, Spline Cúbico)\n");
		printf("\t\t[2]. Salir \n");

		printf("\n\t\tIngrese su opción: [ ]\b\b");

 		scanf("%i",&opcion);
		

		switch (opcion) {

 

			case 1:

				crear_tab();
				salir =1;

				break;
			
			case 2:
				
			
			salir = 1;
			repite = 0;
			
				
			

				break;



			

		}
		
		if (salir == 0){
			printf("\n\n\tQué desea hacer? \n\t1)Regresar al menú principal \n\t2) Salir\n");
			printf("\n\t\tIngrese su opción: [ ]\b\b");
			scanf("%i",&repite);
		}
		
 

	} while (repite ==1  );


	
	
}

void portada ()
{
	printf("Métodos numéricos II\n\n");
    printf("\n Adrian Urtez Montoya ");
    printf("\n Itzel Alexandra Tabaco Gonzalez ");
    printf("\n Roberto Cervantes Gonzalez");
    printf("\n Verenice Tania Silva Velazco ");
	system("pause");
	system ("cls");
}



int ConfiguraIdioma(){	   

	struct lconv *lcPtr;
	setlocale(LC_ALL, "spanish");
	lcPtr = localeconv();
	lcPtr->decimal_point = ".";
	lcPtr->thousands_sep = ",";
	lcPtr->grouping = "3";	
		
}


void crear_tab(){
	
	
	int i,j,n,da,grado,rept,met,aux,regresar;
	float s[50][5];
	float Temp, punto, resultado, ref;
	
	int repite = 1;

	int opcion = -1;
	
	int salir = 0;
	

	
		do {
			do {
			
			system("cls");
			printf("\n\t--------------------------------------------------------------------------------------------------------");
			printf("\n\n\t\t\t\tInterpolacion(Diferencias divididas,Spline Cúbico)\n");
			printf("\n\t------------------------------------------------------------------------------------------------------\n");
			printf("\n\tIngrese los datos de su tablas (Si es necesario, el programa los ordenara)");
			printf("\n\tNumero de puntos registrados : ");
			scanf("%i",&p);	
			for(i=0;i<p;i++){
				
				printf("\n\tIngresa tu x%i: ",i);
				scanf("%f",&x[i][0]);
				
			
			}
		
			
			for(i=0;i<p;i++){
				
				for(j=0;j<p-1;j++){
				   
				      if(x[j][0]>x[j+1][0]){
		
		                        Temp=x[j][0];
		
		                       x[j][0]=x[j+1][0];
		
		                        x[j+1][0]=Temp;}
		 
				}
			}
			
			
				
			for(i=0;i<p;i++){
				
			
				printf("\n\tIngresa el  F(x) de %.3f: ",x[i][0]);
				scanf("%f",&x[i][1]);
		
			}
			printf("\n");
				for(i=0;i<p;i++){
				
				for(j=0;j<2;j++){
				    printf("\t%f\t",x[i][j]);
				    s[i][j] = x[i][j];
				}
					printf("\n");
				
			}
			
			printf("\n\tSus datos son correcto?: 1) Si  2)No:   ");
			scanf("%d",&da);
			system("cls");
			
	}while(da==2);
		
			
	for(j=2;j<p+1;j++){
	
			for(i=0;i<p;i++){
			
				x[i][j] = (x[i+1][j-1]-x[i][j-1])/(x[i+j-1][0]-x[i][0]);
					
			}
	}
	
		do{
		
		
		system("cls");
		
		printf("\n\t--------------------------------------------------------------------------------------------------------");
		printf("\n\n\t\t\t\tInterpolacion(Diferencias divididas,Spline Cúbico)\n");
		printf("\n\t------------------------------------------------------------------------------------------------------\n");
		printf("\n\t\t[1]. Interpolación por diferencias divididas \n");
		
		printf("\t\t[2]. Interpolación con Spline Cubico\n");
		
		
		printf("\t\t[3]. Regresar \n");

		printf("\n\t\tIngrese su opción: [ ]\b\b");

 		scanf("%i",&opcion);
		

		switch (opcion) {

 

			case 1:
				
				diferencias();
		
			break;
	
	
	
			case 2:
				
				spline(s);
				break;

 

			case 3:

			salir = 1;
			repite = 1;
			

				break;

		}
		if(salir !=1){
		
			printf("\n\n\tQué desea hacer? \n\t1) Regresar al menú de interpolar  \n\t2) Interpolar con otra tabla  \n\t3) Regresar al menú principal\n");
			printf("\n\t\tIngrese su opción: [ ]\b\b");
			scanf("%i",&regresar);
			
			if(regresar==3){ 
				salir = 1;
				
			}
			
			if(regresar==1){ 
				repite = 1;
				
			}
			
		}
		
			
		 
	 }while(regresar == 1);
		

	} while (repite ==1 && salir == 0 );
		
		

}

void diferencias(){
		
		int i,j,n,da,grado,rept,met,aux,otab;

    	float Temp, punto, resultado, ref;
	
		do{
	
			do {
			system("cls");
			printf("\n\t--------------------------------------------------------------------------------------------------------");
			printf("\n\n\t\t\t\tInterpolacion Con diferencias divididas\n");
		    printf("\n\t------------------------------------------------------------------------------------------------------\n");
			printf("\n\tQue punto desea interpolar?: ");
			scanf("%f",&punto);
			if(punto < x[0][0] || punto > x[p-1][0]){
				
				printf("\n\tEl punto no esta dentro de la tabla\t\n ");
				system("pause");
			
			}
		
			} while(punto < x[0][0] || punto > x[p-1][0]);
		
			do {
				
			printf("\n\tCual es el grado quiere que sea el grado del polinomio? ");
			scanf("%d",&grado);
			if(p<=grado||grado<1)
				printf("\n\tNo hay puntos suficientes para ese polinomio: ");
			} while(p<=grado||grado<1);
		
		
		if(p<=5){
				aux = grado +2;
			printf("\n\tTabla de diferencias divididas:(Según el grado del polinomio)\n");
			for(i=0;i<grado;i++){
			
		for(j=0;j<aux;j++){
				printf("\t%f",x[i][j]);
				
		}
			aux = aux- 1;
	
		printf("\n");
		}
		}
	
		
	
	
	
		ref = x[0][1];
		
		
		for(i=0;i<grado;i++){
		
			resultado = x[0][i+2];
				for(j=0;j<i+1;j++){	
					
				resultado*=(punto-x[j][0]);
		}
	
			
			
			ref+=resultado;
		}
		
		
		printf("\n\tResultado para %f con un polinomio de grado %i: %f",punto,grado,ref);
		printf("\n\n\tLe gustaria interpolar para otro punto o otro grado de polinomiio con diferencias divididas? 1)Si 2)No:  ");
		scanf("%i",&rept);
	}while(rept==1);
	
	
	
	
}

void spline(float s[50][5]){
		
	int i,j,n;
 
	 int C,Dimension;
	 float Sistema[Tam][Tam],Inversa[Tam][Tam],Resultado[Tam][4], inv[Tam][Tam];
	 float v[Tam],m[Tam];
  
			
			system("cls");
			printf("\n\t--------------------------------------------------------------------------------------------------------");
			printf("\n\n\t\t\t\tInterpolacion Con Spline Cúbico\n");
		    printf("\n\t------------------------------------------------------------------------------------------------------\n");
			
		for(i=0;i<p-1;i++){
			
			s[i][2] = s[i+1][0]-s[i][0];
			
		}
			
		for(i=0;i<p-1;i++){
			
			s[i][3] = (s[i+1][1]-s[i][1])/(s[i][2]);
			
		}	
			
	
	 Dimension = p-2;
	 
	 PideDatos(&Dimension,Sistema,s);
	 
	 Invierte(Dimension,Sistema,Inversa);
	
	 
	 for(i=0;i<Dimension;i++){
	 	v[i] = 6*(s[i+1][3]-s[i][3]);
	 }
	 
	 
	 float sum;
	 sum = 0;
	
	
	for(i=1;i<=Dimension;i++){
	 	
	   	for(j=1;j<=Dimension;j++){
	   	inv[i-1][j-1]=Inversa[i][j];
	 }
	 }
	 m[0]=0;
	 for(i=0;i<Dimension;i++){
	 	
	   	for(j=0;j<Dimension;j++){
	   	sum = sum + v[j]*inv[i][j];
	 }
	 m[i+1] = sum;
	 sum = 0;
	 }
	 
	 
	 for(i=0;i<p-1;i++){
	 	
	 	Resultado[i][0] = (m[i+1]-m[i])/(6*s[i][2]);
	 }
	 
	 for(i=0;i<p-1;i++){
	 	
	 	Resultado[i][1] = m[i]/2;
	 }
	 
	 for(i=0;i<p-1;i++){
	 	
	 	Resultado[i][2] = s[i][3]-(((m[i+1]+2*m[i])/6)*s[i][2]);
	 }
	 for(i=0;i<p-1;i++){
	 	
	 	Resultado[i][3] =s[i][1];
	 }
	 
	 printf("\n\tPolinomios: \n");
	
	 for(i=0;i<p-1;i++){
	 	for(j=0;j<4;j++){
	 	
	 	if(j == 0){
	 		printf("\t%fx^3 ",Resultado[i][j]);
		 }
		 
		 	
	 	if(j == 1){
	 		printf("%+fx^2 ",Resultado[i][j]);
		 }
		 
		 if(j == 2){
	 		printf("%+fx ",Resultado[i][j]);
		 }
	 	
	 
	 	if(j == 3){
	 		printf("%+f  ",Resultado[i][j]);
	 		printf("\t para el intervalo %f  < x < %f ",s[i][0],s[i+1][0]);
		 }
	 }
	
	 	printf("\n\n");
	 }
	
	
}


void PideDatos(int *Dim,float Sist[][Tam],float s[50][5]){

	 int A,B,i,j;
	 
	  
	
	 for(A=1;A<=*Dim;A++){
	 
	  for(B=1;B<=*Dim;B++){
	  Sist[A][B] = 0;
	  }}
	  
	  Sist[1][1] = 2*(s[0][2]+s[1][2]);
	  
	  Sist[2][1] = s[1][2];
	  
	   for(i=1;i<=*Dim;i++){
			
		
			  Sist[i][i+1] = s[i][2];
			  Sist[i+1][i+1] = 2*(s[i][2]+s[i+1][2]);
			  Sist[i+2][i+1] =s[i][2];
			
			
			
		}
  
  
}

		 
		 
		
void Invierte(int Dim, float Sist[][Tam], float Inv[][Tam])
	{
	 int NoCero,Col,C1,C2,A;
	 float Pivote,V1,V2;
	
			
			 
	 
	 for(C1=1;C1<=Dim;C1++) for(C2=1;C2<=Dim;C2++)
	    if (C1==C2) Inv[C1][C2]=1; else Inv[C1][C2]=0;
	 
	 for(Col=1;Col<=Dim;Col++){
	  NoCero=0;A=Col;
	  while(NoCero==0){
	   if((Sist[A][Col]>0.0000001)||((Sist[A][Col]<-0.0000001))){
	    NoCero=1;}
	   else A++;}
	  Pivote=Sist[A][Col];
	  for(C1=1;C1<=Dim;C1++){
	   V1=Sist[A][C1];
	   Sist[A][C1]=Sist[Col][C1];
	   Sist[Col][C1]=V1/Pivote;
	   V2=Inv[A][C1];
	   Inv[A][C1]=Inv[Col][C1];
	   Inv[Col][C1]=V2/Pivote;
	            }
	  for(C2=Col+1;C2<=Dim;C2++){
	   V1=Sist[C2][Col];
	   for(C1=1;C1<=Dim;C1++){
	    Sist[C2][C1]=Sist[C2][C1]-V1*Sist[Col][C1];
	                Inv[C2][C1]=Inv[C2][C1]-V1*Inv[Col][C1];}
	 }}
	
	
	 for(Col=Dim;Col>=1;Col--) for(C1=(Col-1);C1>=1;C1--)
	    {
	        V1=Sist[C1][Col]; 
	        for(C2=1;C2<=Dim;C2++){
	     Sist[C1][C2]=Sist[C1][C2]-V1*Sist[Col][C2];
	     Inv[C1][C2]=Inv[C1][C2]-V1*Inv[Col][C2];
	    }}
}

