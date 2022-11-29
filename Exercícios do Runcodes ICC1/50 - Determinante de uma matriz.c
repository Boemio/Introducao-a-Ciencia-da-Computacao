#include <stdio.h>

#define linhas 3
#define colunas 3

int main()
{
    int m[3][5];
    int det = 0;

    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            m[i][j+3] = m[i][j];
        }
    }

    det += (m[0][0]*m[1][1]*m[2][2]) + (m[0][1]*m[1][2]*m[2][3]) + (m[0][2]*m[1][3]*m[2][4]);
    det -= (m[0][4]*m[1][3]*m[2][2]) + (m[0][3]*m[1][2]*m[2][1]) + (m[0][2]*m[1][1]*m[2][0]);

    printf("%d\n", det);

    return 0;
}