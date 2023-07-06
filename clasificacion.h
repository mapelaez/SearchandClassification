#ifndef CLASIFICACION_H_INCLUDED
#define CLASIFICACION_H_INCLUDED

#define NUM_1 50000
#define NUM_2 100000
#define NUM_3 200000

void burbuja (int v[], int size);
void burbujaMejorado(int X[], int size);
void InsercionDirecta(int a[], int size);
void shell(int array[], int size);
void calculo_intervalos(int a[], int intervalo, int aux);
int calcular_tamano_incremento(int size);
int calcular_siguiente_incremento(int a[], int aux);
void QuickSort(int a[], int ini, int fin,int tipo, unsigned long long  *comparacion, unsigned long long *intercambios);
void intercambio(int a[], int i, int j);
void ordenarMediana(int b[], int a[]);
void cambio(int *x, int *z);
#endif // CLASIFICACION_H_INCLUDED
