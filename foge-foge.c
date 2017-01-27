#include "stdlib.h"
#include "stdio.h"
#include "foge-foge.h"

int linhas;
int colunas;
char **mapa;

void main()
{
    leMapa();

    for (int i = 0; i < linhas; i++)
    {
        printf("%s \n", mapa[i]);
    }

    liberaMapa();
}
/*
######################
# Funções Auxiliares #
######################
*/
void leMapa()
{
    FILE *f;
    f = fopen("mapa.txt", "r");
    if (f == 0)
    {
        printf("Não foi possível ler o mapa");
        exit(1);
    }
    
    fscanf(f, "%d %d", &linhas, &colunas);
    alocaMapa();

    for (int i = 0; i < linhas; i++)
    {
       fscanf(f, "%s", mapa[i]);
    }
    
    fclose(f);
}

void alocaMapa()
{
    mapa = malloc(sizeof(int*) * linhas);
    for(int i = 0; i < linhas; i++)
    {
        mapa[i] = malloc(colunas + 1 * sizeof(int));
    }
}

void liberaMapa()
{
    for(int i = 0; i < linhas; i++)
    {
        free(mapa[i]);
    }
    free(mapa);
}