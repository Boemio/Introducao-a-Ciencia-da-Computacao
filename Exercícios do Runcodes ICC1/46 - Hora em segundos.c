#include <stdio.h>

int main()
{
    int h, m, s, total;
    
    scanf("%d", &h);
    scanf("%d", &m);
    scanf("%d", &s);
    
    if(h >= 0 && h <= 24 && m >= 0 && m <= 60)
    {
        h = h*3600; 
        m = m*60;
        total = h+m+s;
        printf("%d", total);
    }
    
    else
    {
        printf("HORARIO INVALIDO");
    }
    
    
    
    return 0;
}