#include <stdio.h>

int main()
{
    int rs,n100 = 0,n50 = 0,n20 = 0,n10 = 0,n5 = 0,n2 = 0,n1 = 0;

    

    scanf("%d", &rs);

    if(rs >= 100)
    {
        n100 = rs/100;
        rs -= n100*100;
    }

    if(rs >= 50)
    {
        n50 = rs/50;
        rs -= n50*50;
    }

    if(rs >= 20)
    {
        n20 = rs/20;
        rs -= n20*20;
    }

    if(rs >= 10)
    {
        n10 = rs/10;
        rs -= n10*10;
    }

    if(rs >= 5)
    {
        n5 = rs/5;
        rs -= n5*5;
    }

    if(rs >= 2)
    {
        n2 = rs/2;
        rs -= n2*2;
    }

    if(rs == 1)
    {
        n1 = rs/1;
        rs -= n1;
    }

    printf("%d nota(s) de 100, %d nota(s) de 50, %d nota(s) de 20, %d nota(s) de 10, %d nota(s) de 5, %d nota(s) de 2 e %d moeda(s) de 1.",n100,n50,n20,n10,n5,n2,n1);

    return 0;
}