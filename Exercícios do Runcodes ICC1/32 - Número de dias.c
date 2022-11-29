#include <stdio.h>

int conversor(char c);

int main()
{
    char data[11];
    int dia = 0;

    scanf("%s", data);

    dia += (conversor(data[0])*10) + (conversor(data[1]));
    dia += ((conversor(data[3])*10) + (conversor(data[4]))) * 31;
    dia += ((conversor(data[6]))*1000 + (conversor(data[7]))*100 + (conversor(data[8]))*10 + (conversor(data[9]))) * 365;

    printf("%d\n", dia);

    return 0;
}

int conversor(char c)
{
    int resultado;

    switch(c)
    {
        case '0':
            resultado = 0;
            break;
        case '1':
            resultado = 1;
            break;
        case '2':
            resultado = 2;
            break;
        case '3':
            resultado = 3;
            break;
        case '4':
            resultado = 4;
            break;
        case '5':
            resultado = 5;
            break;
        case '6':
            resultado = 6;
            break;
        case '7':
            resultado = 7;
            break;
        case '8':
            resultado = 8;
            break;
        case '9':
            resultado = 9;
            break;
    }

    return resultado;
}