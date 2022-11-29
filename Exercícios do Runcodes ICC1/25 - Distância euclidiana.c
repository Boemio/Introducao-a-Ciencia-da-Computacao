#include <stdio.h>
#include <math.h>

int main()
{
    float cordenada1[3];
    float cordenada2[3];
    float resultado = 0;

    scanf("%f", &cordenada1[0]);
    scanf("%f", &cordenada1[1]);
    scanf("%f", &cordenada1[2]);
    scanf("%f", &cordenada2[0]);
    scanf("%f", &cordenada2[1]);
    scanf("%f", &cordenada2[2]);

    for(int i = 0; i<3; i++)
    {
        resultado += (cordenada2[i] - cordenada1[i])*(cordenada2[i] - cordenada1[i]);
    }

    resultado = sqrt(resultado);
    printf("%f\n", resultado);

    return 0;
}