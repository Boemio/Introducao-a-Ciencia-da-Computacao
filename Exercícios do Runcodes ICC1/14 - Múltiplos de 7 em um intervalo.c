#include <stdio.h>

int main()
{
    int contador;
    for(int i=10; i<=99999; i++)
    {
        if(i%7 == 0)
        {
            contador++;
        }
    }
    printf("%d", contador);
    return 0;
}