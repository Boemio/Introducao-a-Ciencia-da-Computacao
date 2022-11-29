#include <stdio.h>

int main()
{
    double a,b;
    int c;
    
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%d", &c);
    
    if(c == 1)
    {
        a = a + b;
        printf("%.1lf", a);
    }
    
    else if(c == 2)
    {
        a = a - b;
        printf("%.1lf", a);
    }
    
    else if(c == 3)
    {
        a = a * b;
        printf("%.1lf", a);
    }
    
    else if(c == 4)
    {
        a = a/b;
        printf("%.1lf", a);
    }
    
    else
    {
        printf("-1");
    }
    
    return 0;
}