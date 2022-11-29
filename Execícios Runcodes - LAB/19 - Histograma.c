#include <stdio.h>

#define TAMANHO 25
#define COR 5

int main()
{
    // Uma imagem 5x5 com 5 tons diferente que variam de 0-4

    // Declaração das variáveis
    int imagem[TAMANHO];
    int histograma[COR] = {0,0,0,0,0};
    int pixel;
    int maiorPixel = -1;
    int qmaiorPixel;

    for(int i = 0; i < TAMANHO; i++) 
    {
        scanf("%d", &pixel);

        imagem[i] = pixel; // Salvando no vetor imagem
        
        switch(pixel) // Preenchendo o vetor histograma
        {
            case 0:
                histograma[0] += 1;
                break;
            case 1:
                histograma[1] += 1;
                break;
            case 2:
                histograma[2] += 1;
                break;
            case 3: 
                histograma[3] += 1;
                break;
            case 4: 
                histograma[4] += 1;
                break;
        }
    }

    // Printando a coluna da cor 0
    printf("0: |"); 
    for(int j = 0; j < histograma[0]; j++)
    {
        printf("#");
    }
    printf("\n");
    
    // Printando a coluna da cor 1
    printf("1: |");
    for(int j = 0; j < histograma[1]; j++)
    {
        printf("#");
    }
    printf("\n");

    // Printando a coluna da cor 2
    printf("2: |");
    for(int j = 0; j < histograma[2]; j++)
    {
        printf("#");
    }
    printf("\n");

    // Printando a coluna da cor 3
    printf("3: |");
    for(int j = 0; j < histograma[3]; j++)
    {
        printf("#");
    }
    printf("\n");

    // Printando a coluna da cor 4
    printf("4: |");
    for(int j = 0; j < histograma[4]; j++)
    {
        printf("#");
    }
    printf("\n");


    for(int i = 0; i < COR; i++) // Descobrindo qual é o pixel mais presente
    {
        if(histograma[i] > qmaiorPixel)
        {
            maiorPixel = i;
            qmaiorPixel = histograma[i];
        }
    }   

    for(int i = 0; i < TAMANHO; i++) // Printando os indices
    {
        if(imagem[i] == maiorPixel)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}