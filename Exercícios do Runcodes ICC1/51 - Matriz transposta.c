#include <stdio.h>

#define linhas 2
#define colunas 3

int main()
{
    int m[linhas][colunas];

    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    for(int j = 0; j < colunas; j++)
    {
        for(int i = 0; i < linhas; i++)
        {
            printf("%d ", m[i][j]);
        }

        printf("\n");
    }

    return 0;
}