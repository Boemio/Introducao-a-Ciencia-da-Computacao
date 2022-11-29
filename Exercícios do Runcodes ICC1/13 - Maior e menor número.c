#include <stdio.h>

int main()
{
    int a,maior,menor;

    scanf("%d",&a);

    maior = menor = a;

    while(a > 0)
    {
        scanf("%d",&a);

        if(a>maior)
        {
            maior = a;
        }

        else if(a<menor && a > 0)
        {
            menor = a;
        }
    }

    printf("%d\n%d\n", maior, menor);
}