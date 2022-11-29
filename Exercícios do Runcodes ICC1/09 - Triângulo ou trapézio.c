#include <stdio.h>
#include <math.h>

int main()
{
    float a,b,c;
    float perimetro, area;
    
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    
    if(fabs(b-c) < a && a < b+c)
    {
        perimetro = a+b+c;
        printf("Perimetro = %.1f", perimetro);
    }
    
    else if(fabs(a-c) < b && b < a+c)
    {
        perimetro = a+b+c;
        printf("Perimetro = %.1f", perimetro);
    }
    
    else if(fabs(a-c) < c && c < b+a)
    {
        perimetro = a+b+c;
        printf("Perimetro = %.1f", perimetro);
    }
    
    else
    {
        area = ((a+b)*c)/2;
        printf("Area = %.1f", area);
    }
    
    return 0;
}
