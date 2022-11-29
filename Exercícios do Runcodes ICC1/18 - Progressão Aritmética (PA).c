#include <stdio.h>

int main()
{
    int primeiro,razao;
    scanf("%d", &primeiro);
    scanf("%d", &razao);
    
    for(int i=1;i<=6;i++)
    {
        printf("%d ", primeiro);
        primeiro += razao;
    }
    return 0;
}