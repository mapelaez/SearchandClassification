#include "cabecera.h"
int main()
{
    system("cls");//limpiar pantalla inicial para que los colores de texto se muestren correctamente al inicio
    char menu;
    char *cadena = NULL;
    cadena = leerCadena("textobusq.txt",cadena);
    char patron[] = "dubadubidu";
    int v1[NUM_1], v2[NUM_2], v3[NUM_3],tipo;
    for (;;)
    {
        leerFichero("numeros50000.txt",v1);
        leerFichero("numeros100000.txt",v2);
        leerFichero("numeros200000.txt",v3);
        //Imprimir menú
        printf(TITLE "\n**MENU DE OPCIONES**\n\n" RESET);
        printf(TITLE"ALGORITMOS DE BUSQUEDA\n"RESET);
        printf("1.- BUSQUEDA DIRECTA\n");
        printf("2.- BUSQUEDA KMP\n");
        printf("3.- BUSQUEDA BM\n\n");
        printf(TITLE"ALGORITMOS DE CLASIFICACION\n"RESET);
        printf("4. BURBUJA\n");
        printf("5. BURBUJA MEJORADA\n");
        printf("6. INSERCION DIRECTA\n");
        printf("7. METODO SHELL\n");
        printf("8. QUICKSORT\n\n");
        printf(ERR "0.- SALIR\n" RESET);
        fflush(stdin);
        //Leer opcion seleccionada por teclado
        printf("\nOPCION: ");scanf("%c", &menu);//solicita al usuario una opción del menú

        switch (menu)
        {
            case '1':
                system("cls");
                busquedaDirecta(cadena,patron);
                break;

            case '2':
                system("cls");
                KMPSearch(cadena,patron);
                break;
            case '3':
                system("cls");
                boyermoore_search(cadena,patron);
                break;
            case '4':
                system("cls");
                printf("\nBURBUJA\n");
                printf("\n50000 canciones\n");
                burbuja(v1,NUM_1);
                escribirFichero("burbuja50000.txt",v1,NUM_1);

                printf("100000 canciones\n");
                burbuja(v2,NUM_2);
                escribirFichero("burbuja100000.txt",v2,NUM_2);

                printf("200000 canciones\n");
                burbuja(v3,NUM_3);
                escribirFichero("burbuja200000.txt",v3,NUM_3);

                break;

            case '5':
                system("cls");
                printf("\nBURBUJA MEJORADA\n");
                printf("\n50000 canciones\n");
                burbujaMejorado(v1,NUM_1);
                escribirFichero("burbujaM50000.txt",v1,NUM_1);

                printf("100000 canciones\n");
                burbujaMejorado(v2,NUM_2);
                escribirFichero("burbujaM100000.txt",v2,NUM_2);

                printf("200000 canciones\n");
                burbujaMejorado(v3,NUM_3);
                escribirFichero("burbujaM200000.txt",v3,NUM_3);

                break;

            case '6':
                system("cls");
                printf("\nINSERCION DIRECTA\n");
                printf("50000 canciones\n");
                InsercionDirecta(v1,NUM_1);
                escribirFichero("directa50000.txt",v1,NUM_1);


                printf("100000 canciones\n");
                InsercionDirecta(v2,NUM_2);
                escribirFichero("directa100000.txt",v2,NUM_2);

                printf("200000 canciones\n");
                InsercionDirecta(v3,NUM_3);
                escribirFichero("directa200000.txt",v3,NUM_3);

                break;

            case '7':
                system("cls");
                printf("\nSHELL\n");
                printf("50000 canciones\n");
                shell(v1,NUM_1);
                escribirFichero("shell50000.txt",v1,NUM_1);

                printf("100000 canciones\n");
                shell(v2,NUM_2);
                escribirFichero("shell_100000.txt",v2,NUM_2);

                printf("200000 canciones\n");
                shell(v3,NUM_3);
                escribirFichero("shell200000.txt",v3,NUM_3);

                break;
            case '8':
                system("cls");
                printf("\nQUICK SORT\n");
                printf("\n1. PIVOTE MEDIO\n");
                printf("\n2. PIVOTE ALEATORIO\n");
                printf("\n3. PIVOTE MEDIANA\n\n");
                printf("Elegir la opcion: ");
                scanf("%d", &tipo);

                system("cls");

                clock_t start,end;
                unsigned long long comparacion = 0, intercambios = 0;
                printf("50000 canciones\n");

                start = clock();
                QuickSort(v1,0,NUM_1,tipo,&comparacion, &intercambios);
                end = clock();
                double tiempo_total = ((double) (end - start)) / CLOCKS_PER_SEC;

                escribirFichero("quick50000.txt",v1,NUM_1);
                printf("comparaciones = %I64u\n", comparacion);
                printf("intercambios = %I64u\n\n", intercambios);
                printf("tardo %lf segundos en ejecutarse\n\n",tiempo_total);

                comparacion = intercambios = 0;
                printf("100000 canciones\n");

                start = clock();
                QuickSort(v2,0,NUM_2,tipo,&comparacion, &intercambios);
                end = clock();
                tiempo_total = ((double) (end - start)) / CLOCKS_PER_SEC;

                escribirFichero("quick100000.txt",v2,NUM_2);
                printf("comparaciones = %I64u\n", comparacion);
                printf("intercambios = %I64u\n\n", intercambios);
                printf("tardo %lf segundos en ejecutarse\n\n",tiempo_total);

                comparacion = intercambios = 0;
                printf("200000 canciones\n");

                start = clock();
                QuickSort(v3,0,NUM_3,tipo,&comparacion, &intercambios);
                end = clock();
                tiempo_total = ((double) (end - start)) / CLOCKS_PER_SEC;

                escribirFichero("quick200000.txt",v3,NUM_3);
                printf("comparaciones = %I64u\n", comparacion);
                printf("intercambios = %I64u\n\n", intercambios);
                printf("tardo %lf segundos en ejecutarse\n\n",tiempo_total);
                break;
            case '0':
                system("cls");
                free(cadena);
                return 0;
                break;
            default:
                system("cls");
                printf(ERR"\nOPCION DE MENU NO DISPONIBLE\n"RESET);
                break;

        }
    }
    free(cadena);
    return 0;
}
