#include <stdio.h>
#include <stdlib.h>

void aloca(int **p, int tam);
void leitura(int *p);
void par(int *p, int tam, int **pp, int *qp);
void mostra(int *p, int tam);

int main ()
{
    int *ptr=NULL, cont=0, *ppar=NULL, qpar=0;
    char op;

    do
    {
        aloca(&ptr, cont+1);
        leitura(ptr+cont);
        cont++;
        printf("\nDeseja continuar?(S/N)\n");
        scanf("%c",&op);
    }while(op == 'S' || op == 's');
    
    par(ptr, cont, &ppar, &qpar);
    printf("\n Numeros Inseridos: \n");
    mostra(ptr,cont);
}

void aloca(int **p, int tam)
{
    if((*p=(int*)realloc(*p,tam*sizeof(int)))== NULL)
    {
        printf("Erro no Programa!");
        exit(1);
    }
}

void leitura(int *p)
{
    printf("\nDigite um Numero: ");
    scanf("%i", p);
    fflush(stdin);
}

void par(int *p, int tam, int **pp, int *qp)
{

    int i, sub;
    for(i=0;i<=(tam/2);i++)
    {
        if(i==(tam/2))
            if(tam%2 ==0)
                sub=*(p+(tam/2));
            else
            {
                printf("Input de Numeros impares!");
                break;
            }

        sub=*(p+i)-*(p+tam-i-1);
        
        if(sub%2 == 0)
        {
            aloca(pp,*qp+1);
            *(*pp+*qp)=sub;
            (*qp)++;
        }
    }

    printf("\n Numeros Subtraidos:\n");
    mostra(*pp,*qp-1);
}

void mostra(int *p, int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("\n%i\n", *(p+i));
    }
}
