#include <stdio.h>

int main()
{
    int n=1,par=0,impar=-1;
    
    while(n>0)
    {
        if(n%2==0)
        {
            par++;
        }
        
        else
        {
            impar++;
        }
        
        scanf("%d", &n);
    }
    printf("%d\n%d",impar,par);
    return 0;
}