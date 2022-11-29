#include <stdio.h>

int main()
{
    int vector1[5];
    int vector2[3];
    int contador = 0;

    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &vector1[i]);
    }

    for(int j = 0; j < 3; j++)
    {
        scanf("%d", &vector2[j]);
    }

    for(int k = 0; k <= 2; k++)
    {
        if(vector2[0] == vector1[k] && vector2[1] == vector1[k+1] && vector2[2] == vector1[k+2])
        {
            contador += 1;
            break;
        }
    }

    if(contador >= 1)
    {
        printf("SIM\n");
    }

    else
    {
        printf("NAO\n");
    }

    return 0;
}