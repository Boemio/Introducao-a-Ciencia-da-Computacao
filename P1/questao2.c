#include <stdio.h>

int main()
{
    int saque, n100 = 0, n50 = 0, n20 = 0, n10 = 0, n5 = 0, n2 = 0;

    scanf("%d", &saque);

    if((saque % 5) == 3) // corrigindo caso resto 3
    {
        n2 = 4;
        saque -= 8;
    }
    if((saque % 5) == 1) // corrigindo caso resto 1
    {
        n2 = 3;
        saque -= 6;
    }
    n100 += saque/100;
    saque -= 100*n100;
    n50 += saque/50;
    saque -= 50*n50;
    n20 += saque/20;
    saque -= 20*n20;
    n10 += saque/10;
    saque -= 10*n10;
    n5 += saque/5;
    saque -= 5*n5;
    n2 += saque/2;
    saque -= 2*n2;

    printf("%d nota(s) de 100 reais \n%d nota(s) de 50 reais \n%d nota(s) de 20 reais \n%d nota(s) de 10 reais \n%d nota(s) de 5 reais \n%d nota(s) de 2 reais\n", n100, n50, n20, n10, n5, n2);

    return 0;
}