#include "cabecera.h"

char * leerCadena(char *nombre_fichero,char * cadena){
    char linea[TAM]; // Para guardar la linea de cada fichero
    //Abrimos el fichero
    FILE *fp = fopen(nombre_fichero,"r");

    // Comprobar que no hay error al abrir
    if(fp == NULL){
        printf(ERR "ERROR DE LECTURA DEL ARCHIVO"RESET);
    }else{
        // Recorremos cada linea del fichero
        if(fgets(linea,TAM,fp)!=NULL){
            int len = strlen(linea);
            cadena = (char *) malloc(sizeof(char) * len + 1);
            strcpy(cadena, linea);
        }else
        {
            printf(ERR "ARCHIVO VACIO"RESET);
        }
    }
    fclose(fp);
    return cadena;
}


void leerFichero(char *nombre_fichero, int v[]) {

    char linea[500]; // Para guardar la linea de cada fichero
    int i = 0;
    //Abrimos el fichero
    FILE *fp = fopen(nombre_fichero,"r");
    // Comprobar que no hay error al abrir
    if(fp == NULL){
            printf("Error de lectura del archivo");
            return;
    }

    // Recorremos cada linea del fichero
    while(fgets(linea,500,fp)!=NULL){
           v[i] = atoi(linea);
           i++;
           //system("PAUSE");     // COMENTAR PARA EJECUCION REAL
    }
    fclose(fp);
}

void escribirFichero(char *nombre_fichero, int v[], int size){

    FILE *fp = fopen(nombre_fichero,"w");
    int i;
    if(fp == NULL){
            printf("Error de lectura del archivo");
            return;
    }

    for(i = 0;i < size;i++){
        fprintf(fp, "%d\n", v[i]);
    }

    fclose(fp);
}
