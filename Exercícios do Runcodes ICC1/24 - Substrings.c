#include <stdio.h>
#include <string.h>

#define FIM_DA_LINHA '\0'

int main()
{
    char str[100];
    char str2[100];
    int contador = 0;

    scanf("%s", str);
    scanf("%s", str2);

    for(int i = 0; i < strlen(str); i++)
    {
        for(int j = 0; j < strlen(str2); j++)
        {
            if(str[i+j] == str2[j])
            {
                contador++;
            }
        }

        if(contador == strlen(str2))
        {
            printf("SIM\n");
            break;
        }

        contador = 0;
    }

    if(contador == 0)
    {
        printf("NAO\n");
    }

    return 0;
}