#include "cabecera.h"
void prepare_badcharacter_heuristic(const char *p, int size, int D1[ALPHABET_SIZE]) {

 int i;

 for (i = 0; i < ALPHABET_SIZE; i++)
     D1[i] = -1;

 for (i = 0; i < size; i++) {
     int t = (size_t)p[i] - 97 ; // Obtiene el código ascii de la letra del patron en la posicion i
     D1[t] = i;
 }

}

// Funcion auxiliar necesaria para calcular la tabla D2.
void compute_prefix(const char* str, int size, int result[]) {
 int q;
 int k;
 result[0] = 0;

 k = 0;
 for (q = 1; q < size; q++) {
     while (k > 0 && str[k] != str[q])
         k = result[k-1];

     if (str[k] == str[q])
         k++;
     result[q] = k;
 }
}

// Funcion para calcular la tabla D2 (regla del buen sufijo).
// p es el patron, size es el tamaño del patrón y D2 es la tabla que se debe rellenar
// en la funcion
void prepare_goodsuffix_heuristic(const char *p, int size, int D2[]) {

 char *left = (char *) p;
 char *right = left + size;
 char reversed[size+1];
 char *tmp = reversed + size;
 int i;

 *tmp = 0;
 while (left < right)
     *(--tmp) = *(left++);

 int prefix_normal[size];
 int prefix_reversed[size];

 compute_prefix(p, size, prefix_normal);
 compute_prefix(reversed, size, prefix_reversed);

 for (i = 0; i <= size; i++) {
     D2[i] = size - prefix_normal[size-1];
 }

 for (i = 0; i < size; i++) {
     const int j = size - prefix_reversed[i];
     const int k = i - prefix_reversed[i]+1;

     if (D2[j] > k)
         D2[j] = k;
 }
}


/*
 * Algoritmo de busqueda Boyer-Moore
 * s es la cadena madre, p es el patrón, y posiciones es un array de enteros
 * que contendrá las posiciones iniciales del patrón p detectado en la cadena s cuando acabe el algoritmo
 */
void boyermoore_search(char *cadena, char *patron) {
    /*
    * Calcula el tamaño de las cadenas
    */
    int  s_len, p_len, contReinicios = 0, *posInicio;
    p_len = strlen(patron);
    s_len = strlen(cadena);
    posInicio = (int *) malloc(sizeof(int));
    /*
    * Comprobaciones simples
    */
    if(s_len == 0)
         return;
    if(p_len == 0)
         return;
    if(p_len > s_len)
         return;

    ///medir el tiempo
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    double interval;
    iniciarTiempo(&start,&frequency);

    //Obtener tablas D1 y D2
    int D1[ALPHABET_SIZE];  // D1 = mal caracter
    int D2[p_len+1]; // D2 = buen sufijo

    prepare_badcharacter_heuristic(patron, p_len, D1);
    prepare_goodsuffix_heuristic(patron, p_len, D2);

    mostrar_tabla(D1,ALPHABET_SIZE, "D1");
    mostrar_tabla(D2,p_len, "D2");

    // Busqueda Boyer-Moore

    int j = 0, i = 0; // indice de la cadena s
    int k = 0;
    while(i <= (s_len - p_len))
    {
        j = p_len;  // indice del patron p (desde el ultimo caracter)
        while(j > 0 && patron[j-1] == cadena[i+j-1])
            j--;

        if(j > 0)
        {
            contReinicios++;
            int z = D1[((size_t) cadena[i+j-1])-97];
            int m;
            if(z < j && (m = j-z-1) > D2[j])
                i+= m;
            else
                i+= D2[j];
        }else{
            if(k > 0)
                posInicio = (int *) realloc(posInicio, sizeof(int)* (k+1));
            posInicio[k] = i; // Grabamos la posición incial donde se ha encontrado el patrón
            k++;
            i++;
        }
    }
    ///parar de medir el tiempo
    interval = pararTiempo(start,frequency);

    imprimirSol(cadena,patron,posInicio,p_len, k);

    printf(MSSG"\n\nTiempo de busqueda: "RESET ERR"%.10lfs\n"RESET,interval);
    printf(MSSG"Reinicios de busqueda: "RESET TITLE"%d\n\n"RESET,contReinicios);
    system("pause");
    system("cls");
    free(posInicio);
}
