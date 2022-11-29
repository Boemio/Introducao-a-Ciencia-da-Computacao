#include <stdio.h>

#define TAM 10

int funMaior(int num[]) // Função para achar o maior
{
    int maior;

    maior = num[0];

    for(int i = 1; i < TAM; i++)
    {
        if(num[i] > maior)
        {
            maior = num[i];
        }
    }

    return maior;
}

int funMenor(int num[]) // Função para achar o menor
{
    int menor;
    
    menor = num[0];

    for(int i = 1; i < TAM; i++)
    {
        if(num[i] < menor)
        {
            menor = num[i];
        }
    }

    return menor;
}

float funMedia(int num[]) // Função para achar a média
{
    float media = 0;

    for(int i = 0; i < TAM; i++)
    {
        media += num[i];
    }

    media = (float)media/TAM;

    return media;
}

int funModa(int num[]) // Função para achar a moda
{
    int moda;
    int quantmoda;
    int contador = 0;


    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            if(num[i] == num[j])
            {
                contador++;
            }
        }

        if(contador > quantmoda || i == 0)
        {
            quantmoda = contador;
            moda = num[i];
        }

        contador = 0;
    }

    return moda;
}

int main()
{
    int num[TAM];
    int maior, menor, moda;
    float media;

    for(int i = 0; i < TAM; i++)
    {
        scanf("%d", &num[i]);
    }

    maior = funMaior(num);
    menor = funMenor(num);
    media = funMedia(num);
    moda = funModa(num);

    printf("%d %d %.2f %d\n", maior, menor, media, moda);

    return 0;
}