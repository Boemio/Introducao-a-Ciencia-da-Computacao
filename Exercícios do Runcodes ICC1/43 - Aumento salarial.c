#include <stdio.h>

int main()
{
    double salario, reajuste, nsalario;
    
    scanf("%lf", &salario);
    
    if(salario <= 400)
    {
        reajuste = salario*0.15;
        nsalario = salario + reajuste;
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 15 %%", nsalario, reajuste);
    }
    if(salario > 400.01 && salario <= 800)
    {
        reajuste = salario*0.12;
        nsalario = salario + reajuste;
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 12 %%", nsalario, reajuste);
    }
    if(salario > 800.01 && salario <= 1200)
    {
        reajuste = salario*0.1;
        nsalario = salario + reajuste;
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 10 %%", nsalario, reajuste);
    }
    if(salario > 1200.01 && salario <= 2000)
    {
        reajuste = salario*0.07;
        nsalario = salario + reajuste;
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 7 %%", nsalario, reajuste);
    }
    if(salario > 2000.01)
    {
        reajuste = salario*0.04;
        nsalario = salario + reajuste;
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 4 %%", nsalario, reajuste);
    }
    
    return 0;
}