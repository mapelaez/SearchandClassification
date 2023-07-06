#include "cabecera.h"

void busquedaDirecta(char *cadena, char *patron){

    int tamS = strlen(cadena);
    int tamP = strlen(patron);
    int *posInicio, contReinicios = 0;
    int s, p, k = 0;
    posInicio = (int *) malloc(sizeof(int));

    ///medir el tiempo de busqueda
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    double interval;
    iniciarTiempo(&start,&frequency);

    for(s = 0; s <= tamS - tamP; s++, contReinicios++){
        for(p = 0; p < tamP; p++){
            if(patron[p] != cadena[s + p]){
                break;
            }
        }
        if(p == tamP){
            if(k > 0)
                posInicio = (int *) realloc(posInicio, sizeof(int)* (k+1));
            posInicio[k] = s;
            k++;
        }
    }

    interval = pararTiempo(start,frequency);

    imprimirSol(cadena,patron,posInicio,tamP,k);

    printf(MSSG"\n\nTiempo de busqueda: "RESET ERR"%.10lfs\n"RESET,interval);
    printf(MSSG"Reinicios de busqueda: "RESET TITLE"%d\n\n"RESET,contReinicios-1);
    system("pause");
    system("cls");
}
