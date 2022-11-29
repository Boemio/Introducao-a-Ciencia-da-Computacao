#include <stdio.h>

#define ESPACO ' '
#define FIM_DA_LINHA '\n'
#define TAB '\t'
#define R '\r'

int main()
{
    char letra;
    int n_linhas = 0, n_palavras = 0, n_chars = 1, nova_palavra = 0;

    scanf("%c", &letra);

    while(scanf("%c", &letra) != EOF)
    {
        n_chars++;
        if((letra == ESPACO || letra == TAB || letra == R) && nova_palavra == 0)
        {
            n_palavras++;
            nova_palavra = 1;
        }
        else if(letra == FIM_DA_LINHA)
        {
            n_linhas++;
            if(nova_palavra == 0)
            {
                n_palavras++;
            }
            nova_palavra = 1;
        }
        else
        {
            nova_palavra = 0;
        }
    }

    printf("Linhas\tPalav.\tCarac.\n");
    printf("%d\t%d\t%d\n", n_linhas, n_palavras, n_chars);
}