/* 

Dado a estrutura abaixo, implemente uma rotina de cadastro, deve-se consultar o usuário
para continuar. O registro deve ser gerado automaticamente pelo sistema. Utilizar
alocação dinâmica e ponteiros para a estrutura.

struct agenda{
int reg;
char nome[80];
float nota;
}; 

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct agenda{
int reg;
char nome[80];
float nota;
}agenda;

void aloca(agenda **p, int tam);
void cadastro(agenda *p);
void mostra(agenda *p, int tam);

int main()
{
    agenda *ag=NULL;
    int cont=0, op;

    do 
    {
        system("cls");
        printf("--menu--\n1 - cadastro\n2 - mostrar cadastros\n3 - sair\n\n");
        scanf("%i", &op);
        fflush(stdin);
        switch(op)
        {
            case 1:
                aloca(&ag,cont+1);
                cadastro(ag+cont);
                cont++;
                break;
            
            case 2:
                mostra(ag,cont);
                break;
        }

    }
    while(op<3);
}

void aloca(agenda **p, int tam)
{
    if((*p=(agenda*)realloc(*p,tam*sizeof(agenda)))==NULL)
    {
        printf("erro no programa!");
        exit(1);
    }
}

void cadastro(agenda *p)
{
    static int n=1;

    p->reg=n;
    n++;
    printf("\nnome: ");
    gets(p->nome);
    fflush(stdin);

    do 
    {
        printf("nota: ");
        scanf("%f", &p->nota);
        fflush(stdin);
    }
    while(p->nota > 10 || p->nota < 0);

    system("PAUSE");
}

void mostra(agenda *p, int tam)
{
    int i;

    for(i=0;i<tam;i++,p++)
    {
        printf("\nregistro: %i", p->reg);
        printf("\nnome: %s", p->nome);
        printf("\nnota: %.2f", p->nota);
        printf("\n");
    }
    
    system("PAUSE");
}