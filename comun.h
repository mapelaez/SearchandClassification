#ifndef COMUN_H
    #define COMUN_H
    #define TAM 40000

    void mostrar_tabla(int *t, int size, const char *nombre_tabla);
    void imprimirSol(char *cadena, char *patron,int *posInicio,int tamP, int posTotal);
    void iniciarTiempo(LARGE_INTEGER *start, LARGE_INTEGER *frequency);
    double pararTiempo(LARGE_INTEGER start, LARGE_INTEGER frequency);

#endif // COMUN_H
