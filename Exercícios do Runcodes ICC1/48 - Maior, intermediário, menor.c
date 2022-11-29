#include <stdio.h>

int main()
{
    int a,b,c;
    
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    
    if(a > b && b > c)
    {
        printf("maior eh o %d, intermediario eh o %d e menor eh o %d", a, b, c);
    }
    
    if(a > c && c > b)
    {
        printf("maior eh o %d, intermediario eh o %d e menor eh o %d", a, c, b);
    }
    
    if(b > c && c > a)
    {
        printf("maior eh o %d, intermediario eh o %d e menor eh o %d", b, c, a);
    }
    
    if(b > a && a > c)
    {
        printf("maior eh o %d, intermediario eh o %d e menor eh o %d", b, a, c);
    }
    
    if(c > b && b > a)
    {
        printf("maior eh o %d, intermediario eh o %d e menor eh o %d", c, b, a);
    }
    
    if(c > a && a > b)
    {
        printf("maior eh o %d, intermediario eh o %d e menor eh o %d", c, a, b);
    }
    
    return 0;    
}
