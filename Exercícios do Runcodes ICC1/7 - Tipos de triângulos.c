#include <stdio.h>
#include <math.h>

int main()
{
    float a,b,c,a2;

    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);

    if(b>a && b>c)
    {
        a2 = b;
        b = a;
    }

    else if(c>a && c>b)
    {
        a2 = c;
        c = a;
    }
    else
    {
        a2 = a;
    }

    if(a2>=(b+c))
    {
        printf("NAO FORMA TRIANGULO\n");
    }

    else
    {
        if(pow(a2,2) == (pow(b,2)+pow(c,2)))
        {
            printf("TRIANGULO RETANGULO\n");
        }

        if(pow(a2,2) > (pow(b,2)+pow(c,2)))
        {
            printf("TRIANGULO OBTUSANGULO\n");
        }

        if(pow(a2,2) < (pow(b,2)+pow(c,2)))
        {
            printf("TRIANGULO ACUTANGULO\n");
        }

        if(a2 == b && b == c)
        {
            printf("TRIANGULO EQUILATERO\n");
        }

        else if(a2 == b || b == c || a2 == c)
        {
            printf("TRIANGULO ISOSCELES\n");
        }
    }

    return 0;
}