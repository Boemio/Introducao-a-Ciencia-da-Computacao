#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int vector[n];
    int somapar = 0;
    int somaimpar = 0;
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&vector[i]);
    }

    for(int num = 0; num<n; num++)
    {
        if(vector[num]%2 == 0)
        {
            somapar += vector[num];
        }    
        else
        {
            somaimpar += vector[num];
        }
    }

    printf("%d\n%d\n",somapar,somaimpar);

    return 0;
}