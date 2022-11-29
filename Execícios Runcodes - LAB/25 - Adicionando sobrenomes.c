#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *nome_inteiro;
    char *ultimo_sobrenome;
    char c;
    int aux = 0;
    char *p;

    nome_inteiro = (char*)calloc(2, sizeof(char));
    if(nome_inteiro == NULL)
    {
        free(nome_inteiro);
        exit(1);
    }

    for(int i = 0; ; i++)
    {
        scanf("%c", &c);

        if(c == '\n' || c == '$')
        {
            if(aux % 2 == 0)
            {
                nome_inteiro[i] = '\0';
                printf("%s", nome_inteiro);
                p = strrchr(nome_inteiro, ' ');
                if(p && *(p+1))
                {
                    ultimo_sobrenome = (char*)calloc(strlen(p+1), sizeof(char));
                    if(ultimo_sobrenome == NULL)
                    {
                        free(nome_inteiro);
                        if(aux > 0)
                        {
                            free(ultimo_sobrenome);
                        }
                        exit(1);
                    }
                    ultimo_sobrenome = (p+1);
                }
                i = 0;
                aux++;
                nome_inteiro = (char*)calloc(2, sizeof(char));
                if(nome_inteiro == NULL)
                {
                    free(nome_inteiro);
                    free(ultimo_sobrenome);
                    exit(1);
                }
            }
            else
            {
                nome_inteiro[i] = '\0';
                printf("%s %s", nome_inteiro, ultimo_sobrenome);
                i = 0;
                aux++;
                nome_inteiro = (char*)calloc(2, sizeof(char));
                if(nome_inteiro == NULL)
                {
                    free(nome_inteiro);
                    free(ultimo_sobrenome);
                    exit(1);
                }
            }
        }

        if(c == '$')
        {
            ultimo_sobrenome = (char*)calloc(1, sizeof(char));
            free(ultimo_sobrenome);
            free(nome_inteiro);
            break;
        }
        
        nome_inteiro[i] = c;
        nome_inteiro = (char*)realloc(nome_inteiro, (i+2)*sizeof(char));
        if(nome_inteiro == NULL)
        {
            free(nome_inteiro);
            if(aux > 0)
            {
                free(ultimo_sobrenome);
            }
            exit(1);
        }
    }

    return 0;
}