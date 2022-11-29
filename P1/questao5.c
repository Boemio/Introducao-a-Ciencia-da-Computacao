#include <stdio.h>

int main()
{
    int n, contador = 1, vezes = 3, aux;
    float numerador = 2, denominador = 4, potencia = 1, fatorial = 1, resultado = 0;
    scanf("%d", &n);

    for(int i = n; i > 0; i--) //calculando n vezes
    {
        for(int i = vezes; i > 0; i--) //calculando a potencia
        {
            potencia *= numerador;
        }

        aux = denominador;

        while(aux != 1) //calculando o fatorial
        {
            fatorial *= aux;
            aux--;
        }
        
        if(contador % 2 == 0)
        {
            resultado -= (potencia)/(fatorial);
        }
        else
        {
            resultado += (potencia)/(fatorial);
        }

        contador++;
        vezes++;
        numerador++;
        denominador++;
        fatorial = 1;
        potencia = 1;

    }

    printf("%f\n", resultado);

    return 0;
}