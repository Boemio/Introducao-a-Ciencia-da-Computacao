#include <stdio.h>

int main()
{
    int diaSelecionado;

    scanf("%d", &diaSelecionado);

    printf("         Abril 2021         \n");
    printf(" Do  Se  Te  Qu  Qu  Se  Sa \n");
    printf("                ");
    for(int dia = 1; dia <= 30; dia++)
    {
        if(dia == diaSelecionado)
        {
            printf("(%2d)", dia);
        }
        else
        {
            printf(" %2d ", dia);
        }
        if(dia == 3 || dia == 10 || dia == 17 || dia == 24)
        {
            printf("\n");
        }
    }

    printf("\n");

    return 0;
}