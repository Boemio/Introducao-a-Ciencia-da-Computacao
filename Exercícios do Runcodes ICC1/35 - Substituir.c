#include <stdio.h>
#include <string.h>

#define FIM_DA_LINHA '\0'

int main()
{
    char str[100];
    char str2[100];
    char str3[100];

    scanf("%s", str);
    scanf("%s", str2);
    scanf("%s", str3);

    for(int i = 0; i < strlen(str); i++)
    {
        for(int j = 0; j < strlen(str2); j++)
        {
            if(str[j+i] == str2[0] && str2[1] == FIM_DA_LINHA)
            {
                str[j+i] = str3[0];
            }
            else if(str[j+i] == str2[0] && str[j+i+1] == str2[1])
            {
                str[j+i] = str3[0];
                str[j+i+1] = str3[1];
            }
        }
    }

    printf("%s\n", str);

    return 0;
}