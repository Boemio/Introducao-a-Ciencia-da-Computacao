#include <stdio.h>

int main()
{
    int a=0, b=1, temp=0;
    
    printf("%d %d ", a, b);
    
    for(int i=1; i <= 14; i++)
    {
        temp = a+b;
        a = b;
        b = temp;
        printf("%d ", b);
    }
    
    return 0;
}