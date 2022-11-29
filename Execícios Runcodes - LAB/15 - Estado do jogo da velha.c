#include <stdio.h>
#include <stdlib.h>

int main()
{
    char jogoVelha[3][3];
    int scoreO = 0;
    int scoreX = 0;
    int hifen = 0;

    for(int linhas = 0; linhas < 3; linhas++)
    {
        for(int colunas = 0; colunas < 3; colunas++)
        {
            scanf(" %c", &jogoVelha[linhas][colunas]);
        }
    }

    // Ganhar na horizontal
    for(int linhas = 0; linhas < 3; linhas++)
    {
        for(int colunas = 0; colunas < 3; colunas++)
        {
            if(jogoVelha[linhas][colunas] == 'x')
            {
                scoreX++;
            }
            if(jogoVelha[linhas][colunas] == 'o')
            {
                scoreO++;
            }
            if(jogoVelha[linhas][colunas] == '-')
            {
                hifen++;
            }
            if(scoreO == 3)
            {
                printf("o ganhou\n");
                exit(0);
            }
            if(scoreX == 3)
            {
                printf("x ganhou\n");
                exit(0);
            }
        }

        scoreO = 0;
        scoreX = 0;
    }

    // Ganhar na vertical
    for(int colunas = 0; colunas < 3; colunas++)
    {
        for(int linhas = 0; linhas < 3; linhas++)
        {
            if(jogoVelha[linhas][colunas] == 'x')
            {
                scoreX++;
            }
            if(jogoVelha[linhas][colunas] == 'o')
            {
                scoreO++;
            }
            if(scoreO == 3)
            {
                printf("o ganhou\n");
                exit(0);
            }
            if(scoreX == 3)
            {
                printf("x ganhou\n");
                exit(0);
            }
        }
        scoreO = 0;
        scoreX = 0;
    }

    // Ganhar na diagonal
    for(int linhas = 0, colunas = 2; linhas < 3; linhas++, colunas--)
    {
        if(jogoVelha[linhas][colunas] == 'x')
        {
            scoreX++;
        }
        if(jogoVelha[linhas][colunas] == 'o')
        {
            scoreO++;
        }
        if(scoreO == 3)
        {
            printf("o ganhou\n");
            exit(0);
        }
        if(scoreX == 3)
        {
            printf("x ganhou\n");
            exit(0);
        }
    }
    scoreO = 0;
    scoreX = 0;

    for(int linhas = 0, colunas = 0; linhas < 3; linhas++, colunas++)
    {
        if(jogoVelha[linhas][colunas] == 'x')
        {
            scoreX++;
        }
        if(jogoVelha[linhas][colunas] == 'o')
        {
            scoreO++;
        }
        if(scoreO == 3)
        {
            printf("o ganhou\n");
            exit(0);
        }
        if(scoreX == 3)
        {
            printf("x ganhou\n");
            exit(0);
        }
    }
    
    if(hifen > 0)
    {
        printf("em jogo\n");
    }
    else
    {
        printf("empate\n");
    }
}
