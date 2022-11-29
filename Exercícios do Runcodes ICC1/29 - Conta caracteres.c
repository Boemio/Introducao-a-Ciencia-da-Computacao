#include <stdio.h>
#include <string.h>

#define TAMANHO 20

int main()
{
    char str[TAMANHO];
    scanf("%s", str);
    char auxiliar[strlen(str)];
    int aux = 0;
    int aux2 = 1;

    auxiliar[0] = str[0];

    for(int i = 0; i < strlen(str); i++)
    {
        for(int j = 0; j < strlen(str); j++)
        {
            if(auxiliar[j] == str[i])
            {
                aux = 0;
                break;
            }
            aux++;
        }
        if(aux > 0)
        {
            auxiliar[aux2] = str[i];
            aux2++; 
        }
    }
    auxiliar[aux2] = '\0';

    printf("%ld\n", strlen(auxiliar));

    return 0;
}