#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char invertido[100];
    int i = 0;
    int contador = 0;

    scanf("%s", str);

    while(i != strlen(str))
    {
        invertido[i] = str[(strlen(str) - 1) - i];
        i++;
    }
    invertido[i] = '\0';
    i = 0;

    while(i != strlen(str))
    {
        if(invertido[i] == str[i])
        {
            contador++;
        }
        i++;
    }

    if(contador == strlen(str))
    {
        printf("SIM\n");
    }
    else
    {
        printf("NAO\n");
    }

    return 0;
}