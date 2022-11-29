#include <stdio.h>

int main()
{
    int a, centena, unidade, dezena;

    scanf("%d", &a);
    
    if((a/100) > 0 && (a/100) < 10)
    {
        centena = (a/100);
        dezena = (a - (centena*100))/10;
        unidade = a - ((centena*100) + (dezena*10));

        if(centena == unidade)
        {
            printf("SIM\n");
        }
        else
        {
            printf("NAO\n");
        }
    }

    else
    {
        printf("INVALIDO\n");
    }


    return 0;
}
