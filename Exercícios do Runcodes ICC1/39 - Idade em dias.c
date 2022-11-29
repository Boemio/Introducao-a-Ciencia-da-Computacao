#include <stdio.h>

int main()
{
    int anos;
    int meses;
    int dias;
    
    scanf("%d", &dias);
    
    anos = dias/365;
    dias = dias - (365*anos);
    meses = dias/30;
    dias = dias - (30*meses);
    
    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", dias);
    
    return 0;
}
