#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct carro{
    int reg_carro;
    char tipo;
    char status;
}carro;

typedef struct cliente{
    char CPF[13];
    char nome[80];
    int num_reg;
    int dias;
}cliente;

void aloca_carro(carro **p, int tam);
void aloca_cliente(cliente **p, int tam);
void cadastra_carro(carro *p, int tam);
void cadastra_cliente(cliente *p, carro *pcar);
void mostra_carro(carro *p, int tam);
int busca_carro(carro *p, int tam, char tipo_car);
int busca_cliente(cliente *p, int tam, char *vCPF);
void devolucao(cliente *p, carro *pcar, int tam);
int main()
{
    int op;
    carro *car=NULL;
    cliente *cli=NULL;
    int cont=0;

    aloca_carro(&car,15);
    cadastra_carro(car,15);

    do
    {
        system("cls");
        printf("Locadora de Veiculos\n1 - Locacao\n2 - Devolucao\n\n");
        scanf("%i", &op);
        fflush(stdin);
        switch(op)
        {
            case 1:
                mostra_carro(car,15);
                aloca_cliente(&cli,cont+1);
                cadastra_cliente(cli+cont, car);
                cont++;
                system("pause");
                break;
            
            case 2:
                devolucao(cli,car,cont);
                break;

        }
    } while (op != 3);
    
}

void aloca_carro(carro **p, int tam)
{
    if((*p=(carro*)realloc(*p,tam*sizeof(carro)))==NULL)
    {
        printf("Erro no Programa!");
        exit(1);
    }
}

void aloca_cliente(cliente **p, int tam)
{
    if((*p=(cliente*)realloc(*p,tam*sizeof(cliente)))==NULL)
    {
        printf("Erro no Programa!");
        exit(1);
    }
}

void cadastra_carro(carro *p, int tam)
{
    int i;
    for(i=0;i<15;i++,p++)
    {
        p->reg_carro = i+1;
        p->status = 'L';

        if(i<5)
            p->tipo = 'P';

        else if(i>=5 && i<10)
            p->tipo = 'M';
        
        else
            p->tipo = 'G';
    }
}

void cadastra_cliente(cliente *p, carro *pcar)
{
    char tipo_car;
    int num_car;

    printf("Tipo de carro desejado (P/M/G): ");
    scanf("%c", &tipo_car);
    fflush(stdin);
    tipo_car=toupper(tipo_car);
    num_car=busca_carro(pcar,15,tipo_car);
    num_car=p->num_reg;

    if(num_car==-1)
        printf("Nao ha carros disponiveis na categoria!\n\n");
    else
    {
        printf("Nome: ");
        fgets(p->nome,80,stdin);
        fflush(stdin);
        printf("\nCPF: ");
        fgets(p->nome,13,stdin);
        fflush(stdin);
        printf("\nPeriodo do Aluguel (em Dias): ");
        scanf("%i", &(p->dias));
        fflush(stdin);
    }
}

int busca_carro(carro *p, int tam, char tipo_car)
{
    int i;
    for(i=0;i<tam;i++,p++)
    {
        if(p->status == 'L' && p->tipo == tipo_car)
        {
            return p->reg_carro;
            p->status='A';
        }
    }
    return -1;
}

void mostra_carro(carro *p, int tam)
{
    int i;
    for(i=0;i<15;i++,p++)
    {
        printf("Registro: %i\n", p->reg_carro);
        printf("Tipo: %c\n", p->tipo);
        printf("Status: %c\n\n", p->status);
    }
}

void devolucao(cliente *p, carro *pcar, int tam)
{
    char vCPF[13], tip;
    int pos, reg, tempo;

    printf("CPF: ");
    scanf("%s", vCPF);
    fflush(stdin);

    pos = busca_cliente(p,tam,vCPF);

    if(pos==-1)
        printf("CPF Invalido!\n");
    else
    {
        reg = (p+pos)->num_reg;
        (pcar+reg-1)->status='L';
        tip = (pcar+reg-1)->tipo;
        tempo = (p+pos)->dias;

        printf("Tipo do carro: %i\n", tip);
        switch(tip)
        {
            case 'P': printf("\nValor a pagar: %.2f\n\n", tempo*150.00);
					  break;
			case 'M': printf("\nValor a pagar: %.2f\n\n", tempo*200.00);
					  break;
			case 'G': printf("\nValor a pagar: %.2f\n\n", tempo*300.00);
					  break;
        }
        system("pause");
    }
}

int busca_cliente(cliente *p, int tam, char *vCPF)
{
    int i;
    
    for(i=0;i<tam;i++,p++)
    {
        if(strcmp(p->CPF, vCPF)==0)
            {
                printf("Nome: %c", p->nome);
                printf("Registro do Carro: %c", p->num_reg);
                printf("Tempo de Aluguel: %c", p->dias);

                return i;
            }
    }

    return -1;
}