#include <stdlib.h>
#include <stdio.h>

int main()
{
    int linhas = 5;
    int colunas = 10;

    int **numeros;
   
    numeros = malloc(linhas * sizeof(int*));
    for(int i = 0; i < linhas; i++)
    {
        numeros[i] = malloc(colunas * sizeof(int));
    }
    for(int i = 0; i < linhas; i++) printf("%d \n", numeros[i]);
    for(int i = 0; i < linhas; i++)
    {
        free(numeros[i]);
    }
    free(numeros);
    
}

