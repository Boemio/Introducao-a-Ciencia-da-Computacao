#include <stdio.h>

int main()
{
    int n, primeiroMaior, primeiroMenor, segundoMaior, segundoMenor, aux;

    scanf("%d", &n);

    scanf("%d", &aux);
    primeiroMaior = aux;
    primeiroMenor = aux;
    segundoMaior = aux;
    segundoMenor = aux;

    for(int i = n-1; i > 0; i--) // lendo n vezes
    {
        scanf("%d", &aux);
        if(aux > primeiroMaior)
        {
            segundoMaior = primeiroMaior;
            primeiroMaior = aux;
        }
        if(aux > segundoMaior && aux != primeiroMaior || primeiroMaior == segundoMaior)
        {
            segundoMaior = aux;
        }
        if(aux < primeiroMenor)
        {
            segundoMenor = primeiroMenor;
            primeiroMenor = aux;
        }
        if(aux < segundoMenor && aux != segundoMenor || primeiroMenor == segundoMenor)
        {
            segundoMenor = aux;
        }
    }

    printf("Primeiro Menor: %d \nSegundo Menor: %d \nPrimeiro Maior: %d \nSegundo Maior: %d \n", primeiroMenor, segundoMenor, primeiroMaior, segundoMaior);

    return 0;
}