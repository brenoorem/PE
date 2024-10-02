#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    char nome [30];
    int idade;
    float nota;
}
aluno;

aluno cadastro();

int main()
{
    aluno alu[10];
    char op;
    int i, cont=0;

    do 
    {
        system("clear");
        printf("\n--cadastro de alunos--\n");
        if(cont<10)
        {
            alu[cont] = cadastro();
            cont++;
        }
        else
        {
            printf("\ncadastro lotado!");
        }
        printf("\ndeseja continuar? (s/n)\n");
        scanf("%c", &op);
        fflush(stdin);
    }
    while(op!='n' && op!='N');

    for(i=0;i<cont;i++)
    {
        printf("aluno %i\n", i+1);
        printf("\nnome do aluno: ");
        puts(alu[i].nome);
        printf("idade do aluno: %i", alu[i].idade);
        printf("\nnota do aluno: %.1f", alu[i].nota);
        printf("\n-------------------");
    }
}

aluno cadastro()
{
    aluno alu;
    
    printf("\ndigite o nome\n");
    scanf("%s", alu.nome);
    fflush(stdin);
    printf("\ndigite a idade\n");
    scanf("%i", &alu.idade);
    fflush(stdin);
    do 
    {
        printf("\ndigite a nota (0-10)\n");
        scanf("%f", &alu.nota);
        fflush(stdin);
    }
    while(alu.nota<0 || alu.nota>10);
    

    return alu;
}