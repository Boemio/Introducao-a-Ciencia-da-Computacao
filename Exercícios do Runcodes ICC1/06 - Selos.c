#include <stdio.h>

int main()
{
    int dinheiro,selo5,selo3,resto;
    
    scanf("%d", &dinheiro);
    
    selo5 = 0;
    selo3 = 0;
    
    resto = (dinheiro % 5) % 3;
    
    if(dinheiro >= 5)
    {
        selo5 = dinheiro/5;
        dinheiro = dinheiro - (5*selo5);
    }
    
    if(dinheiro >= 3)
    {
        selo3 = dinheiro/3;
        dinheiro = dinheiro - (3*selo3);
    }
    
    if(resto > 0)
    {
        selo5 = selo5 - resto;
        selo3 = selo3 + (resto*2);
    }
    
    printf("Quantidade de selos de 5: %d\n", selo5);
    printf("Quantidade de selos de 3: %d\n", selo3);
    
    return 0;
}
