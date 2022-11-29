#include <stdio.h>
#include <math.h>

int main()
{
    double peso,altura,imc;
    
    scanf("%lf", &altura);
    scanf("%lf", &peso);
    
    imc = (peso)/(altura*altura);
    
    if(imc < 20)
    {
        printf("Abaixo do peso");
    }
    if(20 < imc && imc < 25)
    {
        printf("Peso Normal");
    }
    if(25 < imc && imc < 30)
    {
        printf("Sobre Peso");
    }
    if(30 < imc && imc < 40)
    {
        printf("Obeso");
    }
    if(imc > 40)
    {
        printf("Obeso Morbido");
    }
    
    return 0;
}
