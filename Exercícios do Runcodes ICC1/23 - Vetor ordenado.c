#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int vector[n];
    int temp;
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vector[i]);
    }

    for(int j = 0; j < n; j++)
    {
        for(int k = 0; k < n-1; k++)
        {
            if(vector[k] > vector[k+1])
            {
                temp = vector[k];
                vector[k] = vector[k+1];
                vector[k+1] = temp;
            }
        }
    }

    for(int l = n-1; l >= 0; l--)
    {
        printf("%d\n", vector[l]);
    }

    return 0;
}