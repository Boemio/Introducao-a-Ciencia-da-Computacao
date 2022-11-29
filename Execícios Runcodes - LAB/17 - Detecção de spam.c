#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palavrasProibidas(char str[]);

int main()
{
    char str[100];
    char c;
    int contador = 0;
    int yesorno = 0;

    while(scanf("%c", &c) != EOF)
    {    
        str[contador] = c;
        
        if(((int) c) == 10)
        {
            str[contador] = '\0';
            
            if(strlen(str) > 76)
            {
                printf("Spam\n");
                return 0;
            }

            contador = -1;

            yesorno += palavrasProibidas(str);

            if(yesorno >= 2)
            {
                printf("Spam\n");
                return 0;
            }

            contador++;
        }

        contador++;
    }

    printf("Inbox\n");

    return 0;
}

int palavrasProibidas(char str[])
{
    char palavrasProibidas[13][20] = {"gratuito", "atencao", "urgente", "imediato", "zoombie", "oferta", "dinheiro", "renda", "fundo", "limitado", "ajuda", "SOS"};
    int yesorno = 0;

    for(int i = 0; i < 12; i++)
    {
        if(strstr(str, palavrasProibidas[i]))
        {
            yesorno++;
        }
    }

    return yesorno;
}
