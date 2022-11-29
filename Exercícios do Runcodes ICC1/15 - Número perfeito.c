#include <stdio.h>

int main()
{
    int a, soma = 0;
    
    scanf("%d", &a);
    
    for(int i=(a/2); i>=1; i--)
    {
        if((a%i)==0)
        {
            soma += i;
        }
    }
    
    if(soma == a)
    {
        printf("SIM");
    }
    else
    {
        printf("NAO");
    }
    
    return 0;
}