#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    if(a % 2 == 0)
    {
        printf("PAR");
    }
    else if(a <= 0)
    {
        printf("INVALIDO");
    }
    else
    {
        printf("IMPAR");
    }
    return 0;
}
