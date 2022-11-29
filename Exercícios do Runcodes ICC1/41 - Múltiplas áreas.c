#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    float pi;
    float triangulo;
    float circulo;
    float trapezio;
    float quadrado;
    float retangulo;
    pi = 3.14159;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    
    /* a) área do triângulo que tem A por base e C por altura. */
    
    triangulo = (a*c)/2;
    printf("%.3f\n", triangulo);
    
    /* b) a área do círculo de raio C. */
    
    circulo = pow(c, 2)*pi;
    printf("%.3f\n", circulo);
    
    /* c) a área do trapézio que tem A e B por bases e C por altura. */
    
    trapezio = ((a+b)*c)/2;
    printf("%.3f\n", trapezio);
    
    /* d) a área do quadrado que tem lado B */
    
    quadrado = pow(b, 2);
    printf("%.3f\n", quadrado);
    
    /* e) a área do retângulo que tem lados A e B. */
    
    retangulo = a*b;
    printf("%.3f\n", retangulo);
    
    return 0;
}

