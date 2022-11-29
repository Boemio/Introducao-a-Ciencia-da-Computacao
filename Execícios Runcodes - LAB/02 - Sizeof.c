#include <stdio.h>

int main()
{
    unsigned char a;
    char b;
    unsigned int c;
    short int d;
    int e;
    long int f;
    unsigned long int g;
    long long int h;
    float i;
    double j;
    long double k;

    printf("%ld\n", sizeof(a));
    printf("%ld\n", sizeof(b));
    printf("%ld\n", sizeof(c));
    printf("%ld\n", sizeof(d));
    printf("%ld\n", sizeof(e));
    printf("%ld\n", sizeof(f));
    printf("%ld\n", sizeof(g));
    printf("%ld\n", sizeof(h));
    printf("%ld\n", sizeof(i));
    printf("%ld\n", sizeof(j));
    printf("%ld\n", sizeof(k));

    return 0;
}