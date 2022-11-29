#include <stdio.h>

int main()
{
    int n, sequencia, primo_anterior = 3, divisores = 0, divisores_aux = 0;

    scanf("%d", &n); //lendo quantos números estarão na sequencia

    for(int i=1; i<=n; i++) //repetindo o mesmo tanto que o n
    {
        scanf("%d", &sequencia); //lendo o número
        for(int divisor = (sequencia); divisor > 0; divisor--) //checando se é primo
        {
            if(sequencia % divisor == 0) //se é divisivel
            {
                divisores++;
            }
        }

        if(divisores <= 2)
        {
            printf("%d é primo.\n", sequencia);
        }

        else
        {
            printf("%d não é primo, o primo anterior é ", sequencia);
            while(sequencia >= 3)
            {
                for(int a = sequencia; a > 0; a--)
                {
                    if(sequencia % a == 0)
                    {
                        divisores_aux++;
                    }
                }
                if(divisores_aux <= 2)
                {
                    primo_anterior = sequencia;
                    printf("%d.\n", primo_anterior);
                    break;
                }

                sequencia--;
                divisores_aux = 0;
            }
        }

        divisores = 0;
    }

    return 0;
}