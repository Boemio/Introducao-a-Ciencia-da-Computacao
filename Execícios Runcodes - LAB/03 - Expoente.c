#include <stdio.h>
#include <math.h>

int main()
{
    float a,b,c;

    scanf("%f", &a);
    scanf("%f", &b);

    c = pow(a,b);

    printf("%.4f", c);

    return 0;
}