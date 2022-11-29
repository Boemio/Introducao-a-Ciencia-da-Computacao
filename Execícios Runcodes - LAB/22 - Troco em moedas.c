#include <stdio.h>

void troco(int valor, int *umreal, int *cinquentacentavos, int *vintecincocentavos, int *dezcentavos, int *cincocentavos, int *umcentavo)
{
    // 1 real
    *umreal = valor/100;
    valor -= (*umreal)*100;

    // 50 centavos
    *cinquentacentavos = valor/50;
    valor -= (*cinquentacentavos)*50;

    // 25 centavos
    *vintecincocentavos = valor/25;
    valor -= (*vintecincocentavos)*25;

    // 10 centavos
    *dezcentavos = valor/10;
    valor -= (*dezcentavos)*10;

    // 5 centavos
    *cincocentavos = valor/5;
    valor -= (*cincocentavos)*5;

    // 1 centavos
    *umcentavo = valor/1;
    valor -= (*umcentavo)*1;
}

int main()
{
    // Inicializando as variáveis
    int moeda1real = 0;
    int moeda50 = 0;
    int moeda25 = 0;
    int moeda10 = 0;
    int moeda5 = 0;
    int moeda1 = 0;
    int valor;

    // Ponteiros
    int *umreal;
    int *cinquentacentavos;
    int *vintecincocentavos;
    int *dezcentavos;
    int *cincocentavos;
    int *umcentavo;

    // Apontando os ponteiros
    umreal = &moeda1real;
    cinquentacentavos = &moeda50;
    vintecincocentavos = &moeda25;
    dezcentavos = &moeda10;
    cincocentavos = &moeda5;
    umcentavo = &moeda1;

    // Calculo das moedas
    scanf("%d", &valor);

    // Função troco
    troco(valor, umreal, cinquentacentavos, vintecincocentavos, dezcentavos, cincocentavos, umcentavo);

    // Printando
    printf("O valor consiste em %d moedas de 1 real\nO valor consiste em %d moedas de 50 centavos\nO valor consiste em %d moedas de 25 centavos\nO valor consiste em %d moedas de 10 centavos\nO valor consiste em %d moedas de 5 centavos\nO valor consiste em %d moedas de 1 centavo\n", *umreal, *cinquentacentavos, *vintecincocentavos, *dezcentavos, *cincocentavos, *umcentavo);

    return 0;
}