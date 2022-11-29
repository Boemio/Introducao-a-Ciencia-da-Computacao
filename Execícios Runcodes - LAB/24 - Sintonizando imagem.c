#include <stdio.h>
#include <string.h>

void deslocarCima(int m, int n, int b, char imagem[m][n+1])
{
    char primeiraLinha[n+1]; 

    for(int j = 0; j < b; j++)
    {
        strcpy(primeiraLinha, imagem[0]);
        for(int i = 0; i < m-1; i++)
        {
            strcpy(imagem[i], imagem[i+1]);
            
        }
        strcpy(imagem[m-1], primeiraLinha);
    }
}

void deslocarEsquerda(int m, int n, int d, char imagem[m][n+1])
{
    char aux_proximo;
    char aux_primeiro;

    for(int k = 0; k < d; k++)
    {
        for(int i = 0; i < m; i++)
        {
            aux_primeiro = imagem[i][0];
            for(int j = 0; j < n-1; j++)
            {
                aux_proximo = imagem[i][j+1];
                imagem[i][j] = aux_proximo;
            }
            imagem[i][n-1] = aux_primeiro;
        }
    }
}

int main()
{
    // Lendo o tamanho da tela
    int m; // número de linhas
    int n; // número de colunas
    scanf("%d %d\n", &m, &n);

    // criando a matriz
    char imagem[m][n+1];

    // Lendo o deslocamento
    int b; // deslocamentos para baixo
    int d; // deslocamentos para direita
    scanf("%d %d\n", &b, &d);

    for(int i = 0; i < m; i++)
    {
        scanf("%[^\n]%*c", imagem[i]);
    }

    deslocarEsquerda(m,n,d,imagem);  
    deslocarCima(m, n, b, imagem);

    for(int i = 0; i < m; i++)
    {
        printf("%s\n", imagem[i]);
    }

    return 0;
}

