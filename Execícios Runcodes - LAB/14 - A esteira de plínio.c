#include <stdio.h>

#define DIREITA '>'
#define ESQUERDA '<'
#define CIMA '^'
#define BAIXO 'v'
#define JUNCAO '#'
#define COMECO '['
#define FIM ']'
#define ESPACO ' '
#define VOID '\n'
#define PONTO '.'

int main()
{
    char esteira[32][65];
    int linha = 0; //linha
    int caractere = 0; //coluna
    int fluxo; //fluxo de direção
    int teste = 0;
    

    for(int linhas = 0; linhas < 32; linhas++)
    {
        for(int colunas = 0; colunas < 65; colunas++)
        {
            scanf("%c", &esteira[linhas][colunas]);
        }
    }

    // Achando o começo
    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < 65; j++)
        {
            if(esteira[i][j] == COMECO)
            {
                linha = i;
                caractere = j;
                break;
            }
        }
    }

    // Percorrendo a esteira até o fim
    while(esteira[linha][caractere] != FIM)
    {
        switch(esteira[linha][caractere])
        {
        case COMECO:
            caractere += 2;
            fluxo = 1;
            break;
        case DIREITA:
            esteira[linha][caractere] = PONTO;
            caractere += 2;
            fluxo = 1;
            break;
        case ESQUERDA:
            esteira[linha][caractere] = PONTO;
            caractere -= 2;
            fluxo = 2;
            break;
        case CIMA:
            esteira[linha][caractere] = PONTO;
            linha--;
            fluxo = 3;
            break;
        case BAIXO:
            esteira[linha][caractere] = PONTO;
            linha++;
            fluxo = 4;
            break;
        case JUNCAO:
            switch (fluxo)
            {
            case 1:
                caractere += 2;
                break;
            case 2:
                caractere -= 2;
                break;
            case 3:
                linha--;
                break;
            case 4:
                linha++;
                break;
            }
        }
        if(esteira[linha][caractere] == PONTO)
        {
            printf("Loop infinito.\n");
            teste = 1;
            break;
        }
        if(esteira[linha][caractere] == ESPACO)
        {
            printf("Falha na esteira.\n");
            teste = 1;
            break;
        }
    }

    if(teste == 0)
    {
        printf("Ok.\n");
    }

    for(int linhas = 0; linhas < 32; linhas++)
    {
        for(int colunas = 0; colunas < 65; colunas++)
        {
            printf("%c", esteira[linhas][colunas]);
        }
    }

    return 0;
}