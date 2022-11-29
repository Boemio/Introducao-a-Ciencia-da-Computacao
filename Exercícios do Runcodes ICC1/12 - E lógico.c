#include <stdio.h>

int main()
{
    int binario1, binario2, bit1, bit2, decimal = 0, resultadobit = 0, potencia = 1;
    
    scanf("%d %d", &binario1, &binario2);
    
    while(binario1 != -1 && binario2 != -1)
    {
        
        while(binario1 > 0 || binario2 > 0)
        {
            bit1 = (binario1%10);
            bit2 = (binario2%10);
            if(binario1 == 1)
            {
                bit1 = 1;
            }
            if(binario2 == 1)
            {
                bit2 = 1;
            }
            resultadobit += (bit1*bit2)*potencia;
            potencia *= 10;
            binario1 /= 10;
            binario2 /= 10;
        }
        printf("%d ", resultadobit);
        potencia = 0;
        
        for(int i = 0, base2 = 1; resultadobit > 0; i++)
        {
            if(i > 0)
            {
                for(int c = i; c > 0; c--)
                {
                    base2 *= 2;
                }
            }
            decimal += base2 * (resultadobit % 10);
            resultadobit = resultadobit / 10;
            base2 = 1;
        }
        
        printf("%d\n", decimal);
        scanf("%d %d", &binario1, &binario2);
        potencia = 1;
        resultadobit = 0;
        decimal = 0;
    }
    
    return 0;
}