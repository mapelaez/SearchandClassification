#include "cabecera.h"
// Función para mostrar la tabla
void mostrar_tabla(int *t, int size, const char *nombre_tabla) {
     printf(TITLE"Tabla %s: "MSSG"|",nombre_tabla);
     int i;
     for(i = 0; i < size; i++) {
             printf(" %i |", t[i]);
     }
     printf("\n\n"RESET);
}

void iniciarTiempo(LARGE_INTEGER *start, LARGE_INTEGER *frequency){
    ///Medir el tiempo en que encuentra el patron
    QueryPerformanceFrequency(frequency);
    QueryPerformanceCounter(start);
    ///Mide desde aqui

}

double pararTiempo(LARGE_INTEGER start, LARGE_INTEGER frequency){
    LARGE_INTEGER end;
    ///Deja de medir el tiempo de busqueda
    QueryPerformanceCounter(&end);
    return (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;
}
void imprimirSol(char *cadena, char *patron,int *posInicio,int tamP, int posTotal){

    if(posTotal == 0){
        printf(ERR "PATRON NO ENCONTRADO");
        return;
    }

    printf(SUCCESS "PATRON ENCONTRADO\n\n" RESET);

    int s,p;
    printf("Posicion\t");
    for(s = posInicio[0] - 2; s < posInicio[0] + tamP + 2; s++){
        if(s >= posInicio[0] && s < posInicio[0] + tamP)
            printf(SUCCESS);
        printf("|%5.d|"RESET,s);
    }
    printf("\nCadena\t\t");
    for(s = posInicio[0] - 2; s < posInicio[0] + tamP + 2; s++){
        if(s >= posInicio[0] && s < posInicio[0] + tamP)
            printf(TITLE );
        printf("|  %c  |"RESET,cadena[s]);
    }
    printf("\nPatron\t\t");
    for(s = posInicio[0] - 2, p = 0; s < posInicio[0] + tamP + 2; s++){
        if(s >= posInicio[0] && s < posInicio[0] + tamP){
            printf(MSSG "|  %c  |"RESET,patron[p]);
            p++;
        }else
            printf("_______");
    }
    if(posTotal > 1){
        printf(TITLE"\n\nOTRAS POSICIONES DONDE SE HA ENCONTRADO EL PATRON: \n"RESET);
        int i;
        for(i = 1; i < posTotal;i++)
            printf("\t%d- "SUCCESS"%d\n" RESET, i ,posInicio[i]);
    }
}
