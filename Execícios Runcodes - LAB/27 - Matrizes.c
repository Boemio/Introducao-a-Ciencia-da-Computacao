#include <stdio.h>
#include <stdlib.h>

int **alocarMatriz(int linhas,int colunas)
{
    int **matriz;

    matriz = (int**)calloc(linhas, sizeof(int*));
    if(matriz == NULL)
    {
        free(matriz);
        return NULL;
    }

    for(int i = 0; i < linhas; i++)
    {
        matriz[i] = (int*)calloc(colunas, sizeof(int));
        if(matriz[i] == NULL)
        {
            printf("Erro de alocação de memória! \n");
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

void printarMatriz(int **matriz, int linhas, int colunas)
{
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void desalocarMatriz(int **matriz, int linhas, int colunas)
{
    for(int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

int main()
{
    int linhas;
    int colunas;
    int num;
    int somatorio = 0;
    int aux = 0;
    int **matriz;
    int **transposta;
    int *vetorResultado;

    scanf("%d", &linhas);
    scanf("%d", &colunas);

    matriz = alocarMatriz(linhas, colunas);
    if(matriz == NULL)
    {
        exit(1);
    }

    for(int i = 0; i < linhas; i++) // Lendo os números da matriz
    {
        for(int j = 0; j < colunas; j++)
        {
            scanf("%d", &num);
            matriz[i][j] = num;
        }
    }

    transposta = alocarMatriz(colunas, linhas);
    if(transposta == NULL)
    {
        desalocarMatriz(matriz, linhas, colunas);
        exit(1);
    }

    for(int i = 0; i < colunas; i++)
    {
        for(int j = 0; j < linhas; j++)
        {
            transposta[i][j] = matriz[j][i];
        }
    }

    vetorResultado = (int*)calloc((linhas*linhas), sizeof(int));
    if(vetorResultado == NULL)
    {
        desalocarMatriz(matriz, linhas, colunas);
        desalocarMatriz(transposta, colunas, linhas);
        free(vetorResultado);
        exit(1);
    }

    for(int i = 0; i < linhas; i++) // Linha matriz 
    {
        for(int j = 0; j < linhas; j++) // Coluna transposta
        {
            for(int k = 0; k < colunas; k++) // Elemento
            {
                somatorio += matriz[i][k]*transposta[k][j];
            }

            vetorResultado[aux] = somatorio;
            aux++;
            somatorio = 0;
        }
    }
    
    printf("%d %d ", linhas, linhas);

    for(int i = 0; i < linhas*linhas; i++)
    {
        printf("%d ",vetorResultado[i]);
    }
    printf("\n");

    desalocarMatriz(matriz, linhas, colunas);
    desalocarMatriz(transposta, colunas, linhas);
    free(vetorResultado);
    
    return 0;
}