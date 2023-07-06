#include "cabecera.h"
// p es el patrón, size es el tamaño del patron y tablaNext es la tabla "siguiente" asociada a p
// Esta función se encarga de calcular la tabla siguiente
void preKMP(char *p, int size, int *tablaNext){
	int i,j;
	i = 0;
	j = tablaNext[0] = -1;
	while (i < size-1) {
		while (j > -1 && p[i] != p[j]) {
			j = tablaNext[j];
		}
		i++;
		j++;
		if (p[i] == p[j])
			 tablaNext[i] = tablaNext[j];
		else
			tablaNext[i] = j;
	}
}


// s es la cadena madre, p es el patrón, y posiciones es un array de enteros
// que contendrá las posiciones iniciales del patrón p detectado en la cadena s
void KMPSearch(char *cadena, char *patron) {
    int i,j,k; // i índice de S, j índice de P, k índice de posiciones
    int *posInicio, contReinicios = 0;
    int  s_len, p_len;   // Obtener las longitudes de s y p
    p_len = strlen(patron);
    s_len = strlen(cadena);
    posInicio = (int *) malloc(sizeof(int));

    ///medir el tiempo
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    double interval;
    iniciarTiempo(&start,&frequency);

    int tablaNext[p_len];  // Crear la tabla siguiente de P y calcularla
    preKMP(patron, p_len, tablaNext);
    mostrar_tabla(tablaNext, p_len, "Siguiente");
    i = j = k = 0;

    while (i < s_len) {
        while (j > -1 && cadena[i] != patron[j]) {
            j = tablaNext[j];
            contReinicios++;
        }
        i++;
        j++;
        if (j >= p_len) {
            if(k > 0)
                posInicio = (int *) realloc(posInicio, sizeof(int)* (k+1));
            posInicio[k] = i - j;  // Grabamos la primera posición del patrón encontrado
            k++;
            j = 0;
        }
    }
    ///parar de medir el tiempo
    interval = pararTiempo(start,frequency);

    imprimirSol(cadena,patron,posInicio,p_len,k);

    printf(MSSG"\n\nTiempo de busqueda: "RESET ERR"%.10lfs\n"RESET,interval);
    printf(MSSG"Reinicios de busqueda: "RESET TITLE"%d\n\n"RESET,contReinicios);
    system("pause");
    system("cls");
    free(posInicio);
}

