#include <stdio.h>
#include <string.h>

#define TAMANHO 100

int main()
{
    char str[TAMANHO];

    scanf("%s", str);

    for(int i = 0; i < strlen(str); i++)
    {
        if((int)str[i] < 97)
        {
            str[i] = str[i] + 32;
        }
    }

    printf("%s\n", str);

    return 0;
}