#include <stdio.h>
#include <stdlib.h>

void aloca(float **ptr, int tam);
void leitura(float *ptr);
void mostra(float *p, int cont);
void media(float *p, int tam, float **pM, int *qM);

int main()
{
    float *ptr = NULL, *ptrMaior=NULL;
    int cont=0, qMaior=0;
    char op;
    
    do
    {
        aloca(&ptr,cont+1);
        leitura(ptr+cont);
        cont++;
        printf("\ndeseja continuar? (s/n)\n");
        scanf(" %c",&op);
    }
    while (op != 'n' && op != 'N');

    printf("\nnumeros digitados:\n");
    mostra(ptr,cont);
    media(ptr,cont,&ptrMaior,&qMaior);
    printf("\nnumeros maiores que media:\n");
    mostra(ptrMaior,qMaior);
}//main

void aloca (float **ptr, int tam)
{
    if((*ptr=(float*)realloc(*ptr,tam*sizeof(int)))==NULL)
    {
        printf("erro no programa!");
        exit(1);
    }
}//aloca

void leitura(float *p)
{
    printf("\ndigite um numero: ");
    scanf("%f", p);
    fflush(stdin);
}//leitura

void mostra(float *p, int tam)
{
    int i;
    for(i=0;i<tam;i++,p++)
        printf("%.2f\n",*p);
}

void media(float *p, int tam, float **pM, int *qM)
{
    int i;
    float m;

    for(i=0;i<tam;i++)
        m+=*(p+i);

    m/=tam;
    printf("\na media dos numeros e: %.2f\n",m);

    for(i=0;i<tam;i++)
        if(*(p+i)>m)
        {
            aloca(pM,*qM);
            *(*pM+*qM) = *(p+i);
            (*qM)++;
        }
}