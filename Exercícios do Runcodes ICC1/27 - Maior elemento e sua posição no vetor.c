#include <stdio.h>

int main()
{
    float vector[5];
    int posicao;
    float maior = -999999999;

    for(int i = 0; i < 5; i++)
    {
        scanf("%f", &vector[i]);
    }

    for(int num = 0; num < 5; num++)
    {
        if(vector[num] > maior)
        {
            maior = vector[num];
            posicao = num;
        }
    }

    printf("%.1f\n%d\n", maior, posicao);

    return 0;
}
