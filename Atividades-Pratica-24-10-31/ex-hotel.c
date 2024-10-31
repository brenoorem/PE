#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hospede
{
    int quarto; // número do quarto
    char nome[80];
    int acompanhante; // quantidade de acompanhantes
    char categoria; // [S]olteiro / [F]amiliar
    int dias; // tempo de permanência – em dias
}hospede;

typedef struct quarto
{
    int num; // número do quarto
    char categoria; // [S]olteiro / [F]amiliar
    char status; // [L]ivre / [O]cupado
}quarto;

void aloca_quarto(quarto **p, int tam);
void cadastra_quarto(quarto *p, int tam);
void aloca_hospede(hospede **p, int tam);
void cadastra_hospede(hospede *p, quarto *pquar);
int busca_quarto(quarto *pquar, int tam, char cat);
void mostra_quarto(quarto *p, int tam);
void mostra_hospede(hospede *p, int tam);
void checkout(quarto *q, hospede *h, int tamQ, int tamH);

int main()
{
    int op, cont=0;
    hospede *phos=NULL;
    quarto *pquar=NULL;

    aloca_quarto(&pquar,15);
    cadastra_quarto(pquar,15);

    do
    {
        system("cls");
        printf("controle de hotel");
        printf("\n\n");
        printf("[1] - check-in\n[2] - check-out\n[3] - mostra quartos\n[4] - mostra hospedes\n[5] - sair\n\n");
        scanf("%i", &op);
        fflush(stdin);
        printf("\n");

        switch(op)
        {
            case 1:
                aloca_hospede(&phos,cont+1);
                cadastra_hospede((phos+cont),pquar);
                cont++;
                printf("cadastro finalizado!"); 
                break;
            case 2:
                checkout(pquar,phos,15,cont);
                break;
            case 3:
                mostra_quarto(pquar,15);
                break;
            case 4:
                mostra_hospede(phos,cont);
                break;
        }
    }while(op!=5);
}

void aloca_quarto(quarto **p, int tam)
{
    if((*p=(quarto*)realloc(*p,tam*sizeof(quarto)))==NULL)
    {
        printf("erro no programa!\n");
        exit(1);
    }
}

void cadastra_quarto(quarto *p, int tam)
{
    int i;

    for(i=0;i<tam;i++,p++)
    {
        p->num = i+1;
        p->status = 'L';

        if(i<5)
            p->categoria = 'S';
        else
            p->categoria = 'F';
    }
}

void aloca_hospede(hospede **p, int tam)
{
    if((*p=(hospede*)realloc(*p,tam*sizeof(hospede)))==NULL)
    {
        printf("erro no programa!\n");
        exit(1);
    }
}

void cadastra_hospede(hospede *p, quarto *pquar)
{
    printf("nome: ");
    gets(p->nome);
    fflush(stdin);
    printf("tempo de permanencia (em dias): ");
    scanf("%i", &p->dias);
    fflush(stdin);
    
    do
    {
        printf("quantidade de acompanhantes (max. 3): ");
        scanf("%i", &p->acompanhante);
        fflush(stdin);
    }while(p->acompanhante<0 || p->acompanhante>3);

    if(p->acompanhante==0)
        p->categoria='S';
    else
        p->categoria='F';

    p->quarto = busca_quarto(pquar,15,p->categoria);

    if(p->quarto==-1)
        printf("\nnao ha quartos na categoria disponiveis\n");
    else
        printf("\ncadastro com sucesso - quarto = %i\n\n",p->quarto);
    
    system("pause");
}

int busca_quarto(quarto *pquar, int tam, char cat)
{
    int i;

    for(i=0;i<tam;i++,pquar++)
    {
        if(pquar->categoria==cat && pquar->status == 'L')
        {
            pquar->status = 'O';
            return(pquar->num);
        }
    }

    return -1;
}

void mostra_quarto(quarto *p, int tam)
{
    int i;

    for(i=0;i<tam;i++,p++)
    {
        printf("numero: %i\ncategoria: %c\nstatus: %c\n\n", p->num,p->categoria,p->status);
    }

    system("pause");
}

void mostra_hospede(hospede *p, int tam)
{
    int i;

    for(i=0;i<tam;i++,p++)
    {
        printf("nome: %s\nquarto: %i\nacompanhantes: %i\ncategoria: %c\ndias: %i\n\n", p->nome,p->quarto,p->acompanhante,p->categoria,p->dias);
    }

    system("pause");
}

void checkout(quarto *q, hospede *h, int tamQ, int tamH)
{
    int numero, i;
    
    printf("quarto a ser encerrado: ");
    scanf("%i", &numero);
    printf("\n");
    fflush(stdin);

    for(i=0;i<tamQ;i++,q++)
    {
        if(numero==q->num)
        {
            printf("nome: %s\nquarto: %i\nacompanhantes: %i\ncategoria: %c\ndias: %i\n\n", h->nome,h->quarto,h->acompanhante,h->categoria,h->dias);

            if(h->categoria == 'S')
                printf("valor a ser pago: R$%i\n\n", (h->dias)*85);
            else
                printf("valor a ser pago: R$%i\n\n", (h->dias)*(h->acompanhante)*45);
            
            q->status = 'L';
        }
    }

    system("pause");
}