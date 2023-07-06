#ifndef BM_H
    #define BM_H
    #define ALPHABET_SIZE 25  // Tamaño del alfabeto espanol
    void prepare_badcharacter_heuristic(const char *p, int size, int D1[ALPHABET_SIZE]);
    void compute_prefix(const char* str, int size, int result[]);
    void prepare_goodsuffix_heuristic(const char *p, int size, int D2[]);
    void boyermoore_search(char *cadena, char *patron);
#endif // BM_H
