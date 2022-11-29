#include <stdio.h>

#define AREIA '#'
#define AGUA '~'
#define AR ' '
#define CIMENTO '@'
#define LINHA 32
#define COLUNA 64

void copiarMatriz(char matrizCopia[LINHA][COLUNA], char matriz[LINHA][COLUNA])
{
    char temp;

    for(int i = 0; i < LINHA; i++)
    {
        for(int j = 0; j < COLUNA; j++)
        {
            temp = matriz[i][j];
            matrizCopia[i][j] = temp;
        }
    }
}

void fisicaAreia(char matrizCopia[LINHA][COLUNA], char matrizOriginal[LINHA][COLUNA], int i, int j)
{
    char tmp = matrizCopia[i][j];

    if(matrizOriginal[i+1][j] == AR && i != (LINHA-1)) // Caso 1
    {
        matrizCopia[i][j] = matrizCopia[i+1][j];
        matrizCopia[i+1][j] = tmp;
    }
    else if(matrizOriginal[i+1][j] == AGUA && i != (LINHA-1)) // Caso 1
    {
        matrizCopia[i][j] = matrizCopia[i+1][j];
        matrizCopia[i+1][j] = tmp;
    }

    else if(matrizOriginal[i+1][j-1] == AR && i != (LINHA-1) && j != 0) // Caso 2
    {
        matrizCopia[i][j] = matrizCopia[i+1][j-1];
        matrizCopia[i+1][j-1] = tmp;
    }
    else if(matrizOriginal[i+1][j-1] == AGUA && i != (LINHA-1) && j != 0) // Caso 2
    {
        matrizCopia[i][j] = matrizCopia[i+1][j-1];
        matrizCopia[i+1][j-1] = tmp;
    }
    else if(matrizOriginal[i+1][j+1] == AR && i != (LINHA-1) && j != (COLUNA-1)) // Caso 3
    {
        matrizCopia[i][j] = matrizCopia[i+1][j+1];
        matrizCopia[i+1][j+1] = tmp;
    }
    else if(matrizOriginal[i+1][j+1] == AGUA && i != (LINHA-1) && j != (COLUNA-1)) // Caso 3
    {
        matrizCopia[i][j] = matrizCopia[i+1][j+1];
        matrizCopia[i+1][j+1] = tmp;
    }
}

void fisicaAgua(char matrizCopia[LINHA][COLUNA], char matrizOriginal[LINHA][COLUNA], int i, int j)
{
    char tmp = matrizCopia[i][j];

    if(matrizOriginal[i+1][j] == AR && i != (LINHA-1)) // Caso 1
    {
        matrizCopia[i][j] = matrizCopia[i+1][j];
        matrizCopia[i+1][j] = tmp;
    }
    else if(matrizOriginal[i+1][j-1] == AR && i != (LINHA-1) && j != 0) // Caso 2
    {
        matrizCopia[i][j] = matrizCopia[i+1][j-1];
        matrizCopia[i+1][j-1] = tmp;
    }
    else if(matrizOriginal[i+1][j+1] == AR && i != (LINHA-1) && j != (COLUNA-1)) // Caso 3
    {
        matrizCopia[i][j] = matrizCopia[i+1][j+1];
        matrizCopia[i+1][j+1] = tmp;
    }
    else if(matrizOriginal[i][j-1] == AR && j != 0) // Caso 4
    {
        matrizCopia[i][j] = matrizCopia[i][j-1];
        matrizCopia[i][j-1] = tmp;
    }
    else if(matrizOriginal[i][j+1] == AR && j != (COLUNA-1)) // Caso 5
    {
        matrizCopia[i][j] = matrizCopia[i][j+1];
        matrizCopia[i][j+1] = tmp;
    }
}

int main()
{
    char display[LINHA][COLUNA];
    int n_frames;
    int frame_atual;
    int x_posicao_atual;
    int y_posicao_atual;
    int contador = 0;
    char nova_particula;
    char particula_aux;

    // Preenchendo o frame com ar
    for(int i = 0; i < LINHA; i++)
    {
        for(int j = 0; j < COLUNA; j++)
        {
            display[i][j] = AR;
        }
    }

    scanf("%d", &n_frames);

    while(contador < n_frames)
    {
        int n_lido = scanf(" %d: %d %d %c", &frame_atual, &x_posicao_atual, &y_posicao_atual, &nova_particula);

        if(n_lido == EOF)
        {
            frame_atual = n_frames;
        }

        while (contador < frame_atual)
        {
            printf("frame: %d\n", contador+1);
            // Imprimir a matriz
            for(int i = 0; i < LINHA; i++)
            {
                for(int j = 0; j < COLUNA; j++)
                {
                    printf("%c", display[i][j]);
                }
                printf("\n");
            }

            // Calcular a física
            char matrizCopia[LINHA][COLUNA];
            char copiaOriginal[LINHA][COLUNA];
            copiarMatriz(copiaOriginal, display);
            copiarMatriz(matrizCopia, display);
            for(int i = 0; i < LINHA; i++)
            {
                for(int j = 0; j < COLUNA; j++)
                {
                    particula_aux = display[i][j];
                    if(particula_aux == AREIA)
                    {
                        fisicaAreia(matrizCopia, copiaOriginal, i, j);
                    }
                    else if(particula_aux == AGUA)
                    {
                        fisicaAgua(matrizCopia, copiaOriginal, i, j);
                    }
                }
            }
            copiarMatriz(display, matrizCopia);
            contador++;
        }
        
        if(n_lido != EOF)
        {
            display[y_posicao_atual][x_posicao_atual] = nova_particula;
        }
    }

    return 0;
}