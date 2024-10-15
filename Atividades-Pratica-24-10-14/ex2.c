/*

Fazer um programa para Diário Eletrônico – este programa se destina a controlar as
notas e a média dos alunos. Consultar o usuário para continuar. Utilizar alocação
dinâmica e ponteiros para a estrutura.

[1] Cadastro - receber os valores digitados pelo usuário. Apenas
um registro é cadastrado por vez.

[2] Controle de Notas - o acesso deve ser feito através do RA. Buscar o registro, mostrar o
nome do aluno para simples conferência, dar a opção de alterar as notas, calcular a média novamente e
apresentar na tela as notas e a média.

struct aluno{
char nome[80];
char RA[7];
float nota[2]; //notas de provas – considerar 2 provas
float media; //média aritmética das provas
};

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
char nome[80];
int RA;
float nota[2]; //notas de provas – considerar 2 provas
float media; //média aritmética das provas
}aluno;

void aloca(aluno **p, int tam);
void cadastro(aluno *p);
void mostra(aluno *p);
void busca(aluno *p, int tam);
void edicao(aluno *p);

int main()
{
    aluno *al=NULL;
    int cont=0, op, op2;

    do
    {
        system("cls");
        printf("--diario eletronico de alunos--");
        printf("\n1 - cadastrar novo aluno\n2 - consultar ou editar aluno existente\n3 - sair\n\n");
        scanf("%i", &op);
        switch(op)
        {
            case 1:
                aloca(&al,cont+1);
                cadastro(al+cont);
                cont++;
                break;

            case 2:
                busca(al,cont);
                break;
        }
    }
    while(op<3);
}

void aloca(aluno **p, int tam)
{
    if((*p=(aluno*)realloc(*p,tam*sizeof(aluno)))==NULL)
    {
        printf("\nerro no programa!");
        exit(1);
    }
}

void cadastro(aluno *p)
{
    int vRA;

    printf("\ndigite o RA do aluno: ");
    scanf("%i", &vRA);
    fflush(stdin);

    p->RA=vRA;

    printf("\ndigite o nome do aluno: ");
    gets(p->nome);
    printf("\nnota prova 1: ");
    scanf("%f",&p->nota[0]);
    printf("\nnota prova 2: ");
    scanf("%f",&p->nota[1]);
    p->media = (p->nota[0] + p->nota[1])/2;

    system("PAUSE");
}

void mostra(aluno *p)
{

        printf("\nRA: %i", p->RA);
        printf("\nnome: %s", p->nome);
        printf("\nnota prova 1: %.2f", p->nota[0]);
        printf("\nnota prova 2: %.2f", p->nota[1]);
        printf("\nmedia: %.2f", p->media);
        printf("\n");
}

void busca(aluno *p, int tam)
{
    int vRA, i, op;
    aluno *encontrado=NULL;

    printf("\ndigite o RA do aluno: ");
    scanf("%i",&vRA);
    fflush(stdin);
    
    for(i=0;i<tam;i++,p++)
        if(vRA == p->RA)
        {
            mostra(p);
            encontrado = &p[i];
        }
    printf("\ndeseja editar as notas?\n1 - sim\n2 - nao\n\n");
    scanf("%i",&op);

    if(op==1)
    {
        printf("\nnota prova 1: ");
        scanf("%f",&encontrado->nota[0]);
        printf("\nnota prova 2: ");
        scanf("%f",&encontrado->nota[1]);
        encontrado->media = (encontrado->nota[0] + encontrado->nota[1])/2;
    }
}