//Breno Rosa Orem RA: 248079
//Luis Felype Dias Alencar RA: 248343

#include <stdio.h>
#include <stdlib.h>

void aloca(int **p, int tam);
void leitura(int *p);
void mostra(int *p, int tam);
void soma(int *p, int tam, int **pS, int *qS);

int main()
{
    int *ptr=NULL, cont=0, *ptrSoma=NULL, qSoma=0;
    char op;

    do
    {
        aloca(&ptr,cont+1);
        leitura(ptr+cont);
        cont++;
        printf("\ndeseja continuar? (s/n)\n");
        scanf(" %c", &op);
        fflush(stdin);
    }while (op == 's' || op == 'S');

    printf("\nnumeros digitados:\n");
    mostra(ptr,cont);
    soma(ptr,cont,&ptrSoma,&qSoma);
    printf("\n");
    printf("\nresultados impares das somas:\n");
    mostra(ptrSoma,qSoma);
}

void aloca(int **p, int tam)
{
    if((*p=(int*)realloc(*p,tam*sizeof(int)))==NULL)
    {
        printf("\nerro no programa!");
        exit(1);
    }
}

void leitura (int *p)
{
    printf("\ndigite um numero: ");
    scanf("%i", p);
    fflush(stdin);
}

void mostra(int *p, int tam)
{
    int i;
    for(i=0;i<tam;i++,p++)
    {
        printf("\n%i", *p);
    }
}

void soma(int *p, int tam, int **pS, int *qS)
{
    int i, soma=0;
    for(i=0;i<tam;i++)
    {
        soma=*(p+i)+*(p+i+1);

        if(tam%2==1)
            if(i==tam-1)
                soma = *(p+i);


        if(soma%2==1)
        {
            aloca(pS,*qS+1);
            *(*pS+*qS) = soma;
            (*qS)++;
        }

        i++;
    }
}
