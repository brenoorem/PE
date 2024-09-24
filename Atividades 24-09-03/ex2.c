#include <stdio.h>
#include <stdlib.h>

void temp_mes(float *p_temp_dia, int tam);
void maior_temp(float *t, int tam);
int media_temp(float *t, int tam);
void abaixo_da_media(float *t, int tam, float media_temp);
int main()
{
    int i, dias;
    float temp_dia[31], media;

    printf("Quantidade de Dias: ");
    scanf("%i", &dias);
    fflush(stdin);

    temp_mes(temp_dia, dias);
    maior_temp(temp_dia, dias);
    media = media_temp(temp_dia, dias);

    printf("\n\nA temperatura media mensal foi: %.2f\n\n", media);

    abaixo_da_media(temp_dia, dias, media);
}

void temp_mes(float *p_temp_dia, int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("Qual foi a temperatura do dia %i? ", i+1);
        scanf("%f", p_temp_dia++);
    }
}

void maior_temp(float *t, int tam)
{
    int i, dia; 
    float maior;
    dia = 1;
    maior = *t;
    for(i=0;i<tam;i++,t++)
    {
        if(maior < *t)
        {
            maior = *t;
            dia = i+1;
        }
    }

    printf("\nA maior temperatura ocorreu no dia %i e foi: %.2f", dia, maior);
}

int media_temp(float *t, int tam)
{
    int i;
    float soma, media;

    for (i=0;i<tam;i++, t++)
    {
        soma = soma + *t;
    }

    media = soma/tam;

    return media;
}

void abaixo_da_media(float *t, int tam, float media_temp)
{
    int i, dia;
    dia = 1;

    printf("As temperaturas abaixo da média esse mes foram:\n");

    for(i=0;i<tam;i++,t++)
    {
        if(*t<media_temp)
        {
            printf("%.2f graus no dia %i\n", *t, dia);
            dia++;
        }   
    }

}