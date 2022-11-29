#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    scanf("%s", str);

    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] != 'a' && str[i] != 'A' && str[i] != 'e' && str[i] != 'E' && str[i] != 'i' && str[i] != 'I' && str[i] != 'o' && str[i] != 'O' && str[i] != 'u' && str[i] != 'U')
        {
            printf("%c",str[i]);
        }
    }

    printf("\n");

    return 0;
}