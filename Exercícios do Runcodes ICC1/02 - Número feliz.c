#include <stdio.h>

int main()
{
    int a;

    scanf("%d", &a);

    if((a%11) == 0)
    {
        printf("FELIZ\n");
    }

    else
    {
        printf("TRISTE\n");
    }

    return 0;
}
