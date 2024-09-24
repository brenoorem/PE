#include <stdio.h>
#include <stdlib.h>

void aloca(float **ptr, int tam);

int main()
{
    float *ptr = NULL;

    aloca(*ptr, 10);

}

void aloca(float **p, int tam)
{
    if((*p=(float*)realloc(*p, tam*sizeof(float))) == NULL)
    {
        printf("Erro na Alocação");
        exit(1);
    }
}