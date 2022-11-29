#include <stdio.h>

int main()
{
    int x;
    float gasolina;
    double consumo;
    
    scanf("%d", &x);
    scanf("%f", &gasolina);
    consumo = x/gasolina;
    printf("%.3lf", consumo);
    
}
