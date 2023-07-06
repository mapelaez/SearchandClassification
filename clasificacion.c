#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "clasificacion.h"
#include "leer.h"

void burbuja (int v[], int size){
    clock_t start,end;
    double tiempo_total;
    int i, j, interc;
    unsigned long long comparacion = 0, intercambio = 0;
    start = clock();
    for(i = 0; i < size-1; i++){
        for(j = i+1; j < size; j++){
            comparacion++;
            if(v[j] < v[i]){
                intercambio++;
                interc = v[j];
                v[j] = v[i];
                v[i] = interc;
            }
        }
    }
    end = clock();
    tiempo_total = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("comparaciones = %I64u\n", comparacion);
    printf("intercambios = %I64u\n", intercambio);
    printf("tardo %lf segundos en ejecutarse\n\n",tiempo_total);
}

void burbujaMejorado(int X[], int size){
    clock_t start,end;
    double tiempo_total;
    unsigned long long comparacion = 0,intercambio = 0;
    int bandera = 1,i,j,interc;
    start = clock();
    for(i = 0; i < size - 1 && bandera == 1;i++) //* si en el paso anterior no hubo cambios se detiene ciclo */
	  {
		bandera = 0;
		for(j = 0;j < size - i - 1;j++) /* las comparaciones van dismuyendo a medida que se efectuan los pasos */
		  {
            comparacion++;
			if(X[j] > X[j+1])
			  {
                intercambio++;
				bandera = 1; /* indica si se han realizados cambios o no */
				interc = X[j];
				X[j] = X[j+1];
				X[j+1] = interc;
            }
        }
    }
    end = clock();
    tiempo_total = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("comparaciones = %I64u\n", comparacion);
    printf("intercambios = %I64u\n", intercambio);
    printf("tardo %lf segundos en ejecutarse\n\n",tiempo_total);
}

void InsercionDirecta(int a[], int size){
    clock_t start,end;
    double tiempo_total;
    int pivote;
    int j,i;
    unsigned long long comparacion = 0;
    unsigned long long intercambio = 0;
    start = clock();
    for(i = 1; i < size; i++){
        pivote = a[i];
        j = i-1;
        comparacion++;
        while(j >= 0 && pivote < a[j]){
            comparacion++;
            intercambio++;
            a[j+1] = a[j];
            j--;
            }
    intercambio++;
    a[j+1] = pivote;
    }
    intercambio++;
    end = clock();
    tiempo_total = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("comparaciones = %I64u\n", comparacion);
    printf("intercambios = %I64u\n\n", intercambio);
    printf("tardo %lf segundos en ejecutarse\n\n", tiempo_total);
}

void shell(int array[], int size){
    clock_t start,end;
    double tiempo_total;
    unsigned long long comparacion = 0;
    unsigned long long intercambio = 0;
    int i, j, intervalo, temp,aux = 0;

    start = clock();

    intervalo = calcular_tamano_incremento(size);
    int a[intervalo];
    calculo_intervalos(a,intervalo,aux);

    comparacion++;
    while(intervalo >= 1){
        for(i = intervalo; i < size; i++){
            j = i;
            temp = array[i];
            comparacion++;
            while((j >= intervalo) && (array[j - intervalo] > temp)){
                comparacion++;
                array[j] = array[j - intervalo];
                intercambio++;
                j = j - intervalo;
            }
            intercambio++;
            array[j] = temp;
        }
        intervalo = calcular_siguiente_incremento(a,aux);
        aux = aux - 1;
    }

    end = clock();
    tiempo_total = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("comparaciones = %I64u\n", comparacion);
    printf("intercambios = %I64u\n\n", intercambio);
    printf("tardo %lf segundos en ejecutarse\n\n",tiempo_total);
}


int calcular_tamano_incremento(int size){
    int intervalo;
    intervalo = log2(size) - 1;
    return intervalo;
}

int calcular_siguiente_incremento(int a[], int aux){
    return a[aux];
}

void calculo_intervalos(int a[], int intervalo, int aux){
    int i;
    a[0] = 1;
    for(i = 1; i <= intervalo; i++){
        a[i] = 2 * i + 1;
    }
    aux = intervalo - 1;
    intervalo = a[intervalo];
}

void cambio(int *x, int *z){
    int aux;
    aux = *x;
    *x = *z;
    *z = aux;
}

void ordenarMediana(int b[], int a[]){
    int i,j;
    for(i = 0;i < 3-1;i++) {
      for(j = 0;j < 3-i-1;j++) {
         if(a[j] > a[j+1])
            cambio(&b[j],&b[j+1]);
      }
   }
}


void intercambio(int a[], int i, int j) {
     int interc;
     interc = a[i];
     a[i] = a[j];
     a[j] = interc;
}

/* a[] --> Vector de números
   ini --> Posicion inicial del vector
   fin --> Posicion final del vector
*/
void QuickSort(int a[], int ini, int fin,int tipo, unsigned long long  *comparacion, unsigned long long *intercambios) {
    int pivote,medio = 0,aux1,aux2,aux3;
    int i,j;
     // Caso vector con 1 solo número --> No hacer nada
     if(ini >= fin){
        return;
    }

     // Caso vector con 2 números --> Comprobar si es necesario ordenarlos
    if(ini+1 == fin){
        (*comparacion)++;
        if(a[ini] > a[fin]){  // No están ordenados los dos números, intercambiar
            (*intercambios)++;
            intercambio(a, ini, fin);
        }
        return;
    }

     // Resto de casos --> vector con 3 números o más

     // Pivote --> La posición de mitad del vector
     switch(tipo){
            case 1:
                medio = (ini+fin)/2;
                break;
            case 2:
                medio = rand() % fin;
                break;
            case 3:
                aux1 = ini; // primer numero del aux
                aux2 = (ini+fin)/2;
                aux3 = fin;
                int b[] = {aux1,aux2,aux3}; // b[3] es un auxiliar para calcular la madiana entre el intervalo
                ordenarMediana(b,a);
                if(b[1] == aux1){
                    medio = ini;
                }
                if(b[1] == aux2){
                    medio = (ini+fin)/2;
                }
                else{
                    medio = fin;
                }
                break;
     }

     // Intercambiar pivote por el último elemento
     (*intercambios)++;
     intercambio(a, medio, fin);
     pivote = a[fin];

     // empezamos la particion
     for(i=ini,j=fin-1;;){
        while((i <= fin-1) && (a[i]<pivote)){
            (*comparacion)++;
            i++;
        }
        while((j >= ini) && (pivote <a[j])){
           (*comparacion)++;
           j--;
        }

        if(i<j){  // Todavía no se han intercambiado los índices, intercambiar números
            (*intercambios)++;
            intercambio(a,i,j);
            i++; j--;
        }

        else  // Se han intercambiando los índices, fin de la particion
            break;
     }

    //colocación del pivote en su sitio
    (*intercambios)++;
    intercambio (a, i, fin);
    //termina particion; //llamadas recursivas
    QuickSort(a, ini, i-1,tipo, comparacion, intercambios);  // Vector de la izquierda del pivote
    QuickSort(a, i+1, fin,tipo, comparacion, intercambios);  // Vector de la derecha del pivote
}

