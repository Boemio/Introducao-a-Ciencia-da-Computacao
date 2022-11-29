/* Faça um programa que leia o salário fixo do vendedor e o total de vendas efetuadas por ele no mês (em dinheiro). 
Sabendo que este vendedor ganha 15% de comissão sobre suas vendas efetuadas, informar o total a receber no final do mês,
com duas casas decimais.

A entrada são 2 valores de dupla precisão (double) com duas casas decimais, 
representando o salário fixo do vendedor e montante total das vendas efetuadas por este vendedor, respectivamente.
Imprima o total que o funcionário deverá receber (use double).

*/

#include <stdio.h>

int main()
{
    double salario, vendas, total;    
   
    scanf("%lf", &salario);
    scanf("%lf", &vendas);
    total = salario + (vendas*0.15);
    printf("%.2lf", total);
    
    return 0;
}
