#include <stdio.h>

int main()
{
    int numero, c1, c2, c3, c4; 

    scanf("%d", &numero);

    c4 = numero & 255;
    numero = numero >> 8;
    c3 = numero & 255;
    numero = numero >> 8;
    c2 = numero & 255;
    numero = numero >> 8;
    c1 = numero & 255;
    numero = numero >> 8;

    printf("%c%c%c%c\n",c1,c2,c3,c4);

    return 0;
}