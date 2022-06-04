#include <stdio.h>

#define FIM_DA_STRING '\0'

// Protótipos das funções

int strtamanho(char str[]); // Função que retorna o tamanho da string

unsigned char strcomparar(char str[], char str2[]); // Função que compara duas strings

void strcopiar(char str2[], char str[]); // Função que copia uma string em outra

void strconcatenar(char str[], char str2[]); // Função que concatena uma string na outra

// Função main

int main()
{
    // Inicializando as variáveis
    char str[100];
    char str2[100];
    char strcopia[100];
    int tamanhoString;
    unsigned char simounao;
    
    // Tamanho da String
    printf("Tamanho da String\n");
    printf("Insira a string para calcular o tamanho: ");
    scanf("%s", str);
    tamanhoString = strtamanho(str);
    printf("O tamanho da string é: %d\n", tamanhoString);

    printf("------------------------------------------------------\n");

    // Comparar duas strings
    printf("Comparar duas Strings\n");
    printf("Insira a primeira string: ");
    scanf("%s", str);
    printf("Insira a segunda string: ");
    scanf("%s", str2);
    simounao = strcomparar(str, str2);
    printf("%d\n", simounao);

    printf("------------------------------------------------------\n");

    // Função que copia uma string na outra
    printf("Copiar uma String\n");
    printf("String a ser copiada: ");
    scanf("%s", str);
    strcopiar(strcopia, str);
    printf("String copiada: %s\n", strcopia);

    printf("------------------------------------------------------\n");

    // Função que concatena uma string na outra
    printf("Concatenar duas Strings\n");
    printf("Primeira string: ");
    scanf("%s", str);
    printf("Segunda string: ");
    scanf("%s", str2);
    strconcatenar(str, str2);
    printf("String concatenada: %s\n", str);

    printf("------------------------------------------------------\n");

    return 0;
}

// Execução das funções

int strtamanho(char str[]) // Execução da função que retorna o tamanho da string
{
    int i = 0;

    while(str[i] != FIM_DA_STRING)
    {
        if(str[i] != FIM_DA_STRING)
        {
            i++;
        }
    }

    return i;
}

unsigned char strcomparar(char str[], char str2[]) // Execução da função que compara uma função com a outra
{
    int boolValue = 1; // Iniciar como true
    int i = 0;

    while(str[i] != FIM_DA_STRING || str2[i] != FIM_DA_STRING)
    {
        if(str[i] != str2[i])
        {
            boolValue = 0;
            break;
        }
        i++;
    }

    return boolValue;
}

void strcopiar(char strcopia[], char str[]) // Execução da função que copia
{
    for(int i = 0; str[i] != FIM_DA_STRING; i++)
    {
        strcopia[i] = str[i];
    }
}

void strconcatenar(char str[], char str2[]) // Execução da função que concatena
{
    int i = 0, j = 0;

    while(str[i] != FIM_DA_STRING)
    {
        if(str[i] != FIM_DA_STRING)
        {
            i++;
        }
    }

    while(str2[j] != FIM_DA_STRING)
    {
        if(str2[j] != FIM_DA_STRING)
        {
            str[i] = str2[j];   
        }
        i++;
        j++;
    }

    str[i] = FIM_DA_STRING;
}
