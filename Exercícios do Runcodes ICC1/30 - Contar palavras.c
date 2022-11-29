#include <stdio.h>
#include <string.h>

#define SPACE ' '
#define NEXT '\n'
#define END '\0'

int main()
{
    // Inicializando as variáveis
    char str[3][100];
    int counter = 0;
    char palavras[100][100];
    int aux = 0;
    int resultado;
    int i = 0, j = 0, k = 0, l = 0;
    int u = 0;

    // Lendo as variáveis
    scanf("%[^\n]%*c", &str[0][0]);
    scanf("%[^\n]%*c", &str[1][0]);
    scanf("%[^\n]%*c", &str[2][0]);

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < strlen(str[i]); j++)
        {   
            palavras[k][l] = str[i][j];
            l++;
            if(str[i][j] == SPACE || (j+1) == strlen(str[i]))
            {
                counter++;
                palavras[k][l] = END;
                k++;
                l = 0;
            }
        }
    }
    palavras[k][l] = END;
    resultado = counter+1;

    for(u = 0; u < counter; u++)
    {
        aux = 0;
        for(int i = 0; i < counter; i++)
        {
            if(strcmp(palavras[u], palavras[i]) == 0)
            {
                aux++;
            }
            if(aux > 1)
            {
                resultado = resultado - 1;
                break;
            }
        }
    }

    printf("%d\n", resultado);

    return 0;
}