#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM 20

int removerPalavraTabu(char *frase, char *palavra_tabu) {
    int len = strlen(palavra_tabu);
    int contador = 0;
    if (len > 0) {
        char *p = frase;
        while ((p = strstr(p, palavra_tabu)) != NULL) 
        {
            contador++;
            memmove(p, p + len, strlen(p + len) + 1);
        }
    }

    return contador;
}

int main()
{
    char *palavra_tabu;
    char *frase;
    char c;
    int aux = 0;
    int contador = 0;

    palavra_tabu = (char*)calloc(MAX_TAM, sizeof(char));
    if(palavra_tabu == NULL)
    {
        printf("Erro de alocação de memória!\n");
        free(palavra_tabu);
        exit(1);
    }

    scanf("%s\n", palavra_tabu);

    frase = (char*)calloc(2, sizeof(char));
    if(frase == NULL)
    {
        printf("Erro de alocação de memória!\n");
        free(palavra_tabu);
        free(frase);
        exit(1);
    }

    while(1)
    {
        scanf("%c",&c);
        if(c == '$')
        {
            break;
        }
        frase[aux] = c;
        frase = (char*)realloc(frase, (aux+2)*sizeof(char));
        if(frase == NULL)
        {
            printf("Erro de alocação de memória!\n");
            free(palavra_tabu);
            free(frase);
            exit(1);
        }
        aux++;
    }

    contador = removerPalavraTabu(frase, palavra_tabu);

    printf("A palavra tabu foi encontrada %d vezes\nFrase: ", contador);

    for(int i = 0; i < strlen(frase); i++)
    {
        if(frase[i] >= 32 && frase[i] <= 126)
        {
            printf("%c", frase[i]);
        }
    }

    printf("\n");

    free(palavra_tabu);
    free(frase);

    return 0;
}