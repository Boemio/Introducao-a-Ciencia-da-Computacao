#include <stdio.h>

int main()
{
    int a, decA = 0, b, decB = 0, potencia = 1;
    
    scanf("%d %d",&a,&b);
    
    while(a != -1 && b != -1)
    {
        potencia = 1;
        
        while(a > 0)
        {
            if (a%2 == 1)
            {
                decA += 1*potencia;
            }
            potencia *= 10;
            a /= 2;   
        }
        
        potencia = 1;
        
        while(b > 0)
        {
            if (b%2 == 1)
            {
                decB += 1*potencia;
            }
            potencia *= 10;
            b /= 2; 
        }
        
        printf("%d %d\n", decA, decB);
        scanf("%d %d",&a,&b);
        decA = 0;
        decB = 0;
    }
    
    return 0;
}