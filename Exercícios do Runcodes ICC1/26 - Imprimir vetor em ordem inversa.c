#include <stdio.h>

int main()
{
    int vector[100];
    int numero = 0;
    int contador = 0;

    for(int i = 0; i<100; i++)
    {
        scanf("%d", &numero);
        if(numero <= 0)
        {
            break;
        }
        vector[i] = numero;
        contador++;
    }

    for(int num = contador - 1; num != -1; num--)
    {
        printf("%d\n", vector[num]);
    }

    return 0;
}