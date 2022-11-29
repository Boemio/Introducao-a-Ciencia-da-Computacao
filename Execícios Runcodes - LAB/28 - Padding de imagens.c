#include <stdio.h>
#include <stdlib.h>

int **alocarMatriz(int largura, int altura, int padding)
{
    int **matriz;

    matriz = (int **) calloc((altura + (padding*2)), sizeof(int*));
    if(matriz == NULL)
    {
        printf("Erro de alocação de memória!\n");
        free(matriz);
        return NULL;
    }

    for(int i = 0; i < (altura + (padding*2)); i++)
    {
        matriz[i] = (int *) calloc((largura + (padding*2)), sizeof(int));
        if(matriz[i] == NULL)
        {
            printf("Erro de alocação de memória!\n");
            for(int j = 0; j < i; j++)
            {
                free(matriz[j]);
            }
            free(matriz);

            return NULL;
        }
    }

    return matriz;
}

void printarMatriz(int **matriz, int largura, int altura, int padding)
{
    for(int i = 0; i < (altura+(padding*2)); i++)
    {
        for(int j = 0; j < (largura+(padding*2)); j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void desalocarMemoria(int **matriz, int largura, int altura, int padding)
{
    for(int i = 0; i < (altura + (padding*2)); i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

int main()
{
    int largura;
    int altura;
    int padding;
    int pixel;
    int aux = 0;
    int *vetorNum;
    int **matriz;

    scanf("%d", &largura);
    scanf("%d", &altura);

    vetorNum = (int*) calloc((largura*altura), sizeof(int)); // Aloca o vetor que irá receber os números
    if(vetorNum == NULL)
    {
        printf("Erro de alocação de memória!\n");
        free(vetorNum);
        exit(1);
    }

    for(int i = 0; i < (largura*altura); i++) // Recebe os números
    {
        scanf("%d", &pixel);
        vetorNum[i] = pixel;
    }
    
    scanf("%d", &padding);
    matriz = alocarMatriz(largura, altura, padding);
    if(matriz == NULL)
    {
        free(vetorNum);
        exit(1);
    }
    
    for(int i = 0; i < (altura+(padding*2)); i++)
    {
        for(int j = 0; j < (largura+(padding*2)); j++)
        {
            if(i >= padding && i <= (altura+padding-1) && j >= padding && j <= (largura+padding-1))
            {
                matriz[i][j] = vetorNum[aux];
                aux++;
            }
        }
    }

    printarMatriz(matriz, largura, altura, padding);

    printf("\n");
    for(int i = 0; i < (largura*altura); i++)
    {
        printf("%d ", vetorNum[i]);
        if((i+1) % largura == 0)
        {
            printf("\n");
        }
    }

    desalocarMemoria(matriz, largura, altura, padding);
    free(vetorNum);

    return 0;
}