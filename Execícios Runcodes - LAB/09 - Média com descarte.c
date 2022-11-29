#include <stdio.h>

int main()
{
    double a,b,c,d,media;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    scanf("%lf", &d);

    if(a<=b && a<=c && a<=d)
    {
        a = 0;
    }
    else if(b<=a && b<=c && b<=d)
    {
        b = 0;
    }
    else if(c<=b && c<=a && c<=d)
    {
        c = 0;
    }
    else if(d<=b && d<=c && d<=a)
    {
        d = 0;
    }

    media = (a+b+c+d)/3;
    printf("%.4lf\n", media);

    return 0;
}