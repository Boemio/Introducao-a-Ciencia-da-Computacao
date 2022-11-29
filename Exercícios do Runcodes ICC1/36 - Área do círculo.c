#include <stdio.h>
#include <math.h>

int main()
{
    double r;
    double a;
    double pi;
    pi = 3.14159;
    
    scanf("%lf", &r);
    a = pow(r, 2)*pi;
    printf("%.4lf", a);
}

