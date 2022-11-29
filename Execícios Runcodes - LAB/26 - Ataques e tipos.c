#include <stdio.h>
#include <stdlib.h>

float **alocarMatriz(int m, int n)
{
    float **matriz;

    matriz = (float**)calloc(m,sizeof(float*));
    if(matriz == NULL)
    {
        free(matriz);
        return NULL;
    }
    for(int i = 0; i < m; i++)
    {
        matriz[i] = (float*)calloc(n,sizeof(float));
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

int **alocarMatrizInt(int m, int n)
{
    int **matriz;

    matriz = (int**)calloc(m,sizeof(int*));
    if(matriz == NULL)
    {
        free(matriz);
        return NULL;
    }
    for(int i = 0; i < m; i++)
    {
        matriz[i] = (int*)calloc(n,sizeof(int));
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

void printarMatriz(int **matriz, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void desalocarMemoriaInt(int **matriz, int altura)
{
    for(int i = 0; i < (altura); i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

void desalocarMemoria(float **matriz, int altura)
{
    for(int i = 0; i < (altura); i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

int main()
{
    int m;
    float **matriz_tipos;
    int **matriz_ataques;
    float modificador;
    int poder_ataque;
    int tipo_ataque;
    float poder_total;
    float melhor_poder = -1;
    int melhor_indice;
    int tipo_adversario;
    int x = 0;

    scanf("%d\n", &m);
    matriz_tipos = alocarMatriz(m,m);

    if(matriz_tipos == NULL)
    {
        exit(1);
    }

    matriz_ataques = alocarMatrizInt(1,2);

    if(matriz_ataques == NULL)
    {
        desalocarMemoriaInt(matriz_ataques, 1);
        desalocarMemoria(matriz_tipos, m);
        exit(1);
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%f", &modificador);
            matriz_tipos[i][j] = modificador;
        }
    }

    while (poder_ataque != -1)
    {
        scanf("%d", &poder_ataque);
        if(poder_ataque != -1)
        {
            matriz_ataques[x] = (int*)calloc(2, sizeof(int));
            if(matriz_ataques[x] == NULL)
            {
                desalocarMemoriaInt(matriz_ataques, x);
                desalocarMemoria(matriz_tipos, m);
                exit(1);
            }
            matriz_ataques[x][0] = poder_ataque;
            scanf("%d\n", &tipo_ataque);
            matriz_ataques[x][1] = tipo_ataque;
            x++;
            matriz_ataques = (int**)realloc(matriz_ataques, (1+x)*sizeof(int*));
        }
    } 

    scanf("%d", &tipo_adversario);

    for(int i = 0; i < x; i++) // Percorre as linhas
    {
        poder_total = (((float)matriz_ataques[i][0])*matriz_tipos[i][tipo_adversario]);
        if(poder_total > melhor_poder)
        {
            melhor_poder = poder_total;
            melhor_indice = i;
        }
    }
    
    printf("O melhor ataque possui indice %d e dano %.2f\n", melhor_indice, melhor_poder);

    desalocarMemoriaInt(matriz_ataques, x);
    desalocarMemoria(matriz_tipos, m);

    return 0;
}