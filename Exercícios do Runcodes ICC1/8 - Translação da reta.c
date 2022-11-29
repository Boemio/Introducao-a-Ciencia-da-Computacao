#include <stdio.h>

int main()
{
    int a,b,c,b2;
    float x;
    
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    
    b2=b+c;
    x= -(b2/(float)a);
    
    
    printf("%.2f\n", x);
    
    return 0;
}
