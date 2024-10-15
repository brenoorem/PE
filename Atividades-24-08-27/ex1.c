#include <stdio.h>
#include <string.h>

void inverso(char str[25]);
int main()
{
    char str[25], *p_str;
    int i;

    *p_str = str[0];

    printf("Digite um texto: ");
    fgets(p_str, 25, stdin);

    inverso(p_str);
}

void inverso(char str[25])
{
    int i, cont;
    int *p_i, *p_cont;

    p_i = &i;
    p_cont = &cont;

    *p_cont = strlen(str);

    for(i=*p_cont;i>=0;i--)
    {
        printf("%c", str[i]);
    }
}