#include <stdio.h>

int main()
{
    // Inicializando as variáveis
    int n; // Colunas
    int l; // Número de lugares na fila 
    int p; // Quantidade posições na fila que já foram deslocadas pelo astronauta atual
    int x = 0; // Linha atual
    int y = 0; // Coluna atual
    int aux;
    int limite = 2;

    scanf("%d",&n); // Lendo n
    scanf("%d", &p); // Lendo p 

    l = n * n; // Calculando l

    aux = p-1; // Criando uma variável auxiliar

    // Esquerda para a direita
    for(int i = 0; i < n-1; i++)
    {
        if(aux > 0)
        {
            x++;
            aux--;
        }
    }
    // Cima para baixo
    for(int i = 0; i < n-1; i++)
    {
        if(aux > 0)
        {
            y++;
            aux--;
        }
    }
    // Direita para a esquerda
    for(int i = 0; i < n-1; i++)
    {
        if(aux > 0)
        {
            x--;
            aux--;
        }
    }

    // Último loop
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < (n - limite); j++) // Baixo para cima
        {
            if(aux > 0)
            {
                y--; 
                aux--;
            }
        }

        for(int j = 0; j < (n - limite); j++) // Esquerda para a direita
        {
            if(aux > 0)
            {
                x++;
                aux--;
            }
        }
        limite++;
        for(int j = 0; j < (n - limite); j++) // Cima para baixo
        {
            if(aux > 0)
            {
                y++;
                aux--;
            }
        }

        for(int j = 0; j < (n - limite); j++) // Direita para a esquerda
        {
            if(aux > 0)
            {
                x--;
                aux--;
            }
        }
        limite++;
    }

    if(p > l) // Caso p > l, o astronauta já está fora
    {
        printf("O astronauta ja saiu em missao ha %d chamadas.\n", (p-l));
    }

    else if(p == l) // Caso p == l, chegou a vez do astronauta
    {
        printf("O astronauta esta na posicao: %d %d\nPreste atencao, astronauta, chegou a sua vez!\n", y, x);
    }

    else // Qualquer outro caso, ele ainda está esperando a vez dele
    {
        printf("O astronauta esta na posicao: %d %d\nAinda faltam %d chamadas para a sua vez!\n", y, x, (l-p));
    }

    return 0;
}