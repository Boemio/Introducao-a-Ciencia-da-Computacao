#include <stdio.h>

int abs(int x)
{
    if(x < 0)
    {
        x *= -1;
    }

    return x;
}

int main()
{
    long long int x1, y1, largura1, altura1;
    long long int x2, y2, largura2, altura2;
    long long int x3, y3, largura3, altura3;
    long long int xmaior, ymaior, mlargura, maltura;

    scanf("%lld %lld %lld %lld", &x1, &y1, &largura1, &altura1);
    scanf("%lld %lld %lld %lld", &x2, &y2, &largura2, &altura2);

    largura1 = largura1 + x1;
    largura2 = largura2 + x2;
    altura1 = altura1 + y1;
    altura2 = altura2 + y2;

    if(x1 > x2)
    {
        xmaior = x1;
    }
    else
    {
        xmaior = x2;
    }
    if(y1 > y2)
    {
        ymaior = y1;
    }
    else
    {
        ymaior = y2;
    }
    if(largura1 < largura2)
    {
        mlargura = largura1;
    }
    else
    {
        mlargura = largura2;
    }
    if(altura1 < altura2)
    {
        maltura = altura1;
    }
    else
    {
        maltura = altura2;
    }

    x3 = xmaior;
    y3 = ymaior;
    largura3 = mlargura - xmaior;
    altura3 = maltura - ymaior;

    if(largura3 < 0 || altura3 < 0)
    {
        printf("MISS\n");
    }
    else
    {
        printf("HIT: %lld %lld %lld %lld\n", x3, y3, largura3, altura3);
    }

    return 0;
}