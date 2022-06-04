#include <stdio.h>

#define FIM_DA_STRING '\0'

// Protótipos das funções

int strtamanho(char *pstr); // Função que retorna o tamanho da string

unsigned char strcomparar(char *pstr, char *pstr2); // Função que compara duas strings

void strcopiar(char *pstr, char *pcopia); // Função que copia uma string

void strconcatenar(char *pstr, char *pstr2); // Função que concatena uma string na outra

// Função main

int main()
{
    // Inicializando as variáveis
    char str[100];
    char *pstr;
    char str2[100];
    char *pstr2;
    char strcopia[100];
    char *pcopia;
    int tamanhoString;
    unsigned char simounao;

    // Tamanho da string
    printf("Tamanho da String\n");
    printf("Insira a string para calcular o tamanho: ");
    scanf("%s", str);
    pstr = &str[0];
    tamanhoString = strtamanho(pstr);
    printf("O tamanho da string é: %d\n", tamanhoString);

    printf("------------------------------------------------------\n");

    // Comparar duas strings
    printf("Comparar duas Strings\n");
    printf("Insira a primeira string: ");
    scanf("%s", str);
    pstr = &str[0];
    printf("Insira a segunda string: ");
    scanf("%s", str2);
    pstr2 = &str2[0];
    simounao = strcomparar(pstr, pstr2);
    printf("%d\n", simounao);

    printf("------------------------------------------------------\n");

    // Função que copia uma string na outra
    printf("Copiar uma String\n");
    printf("String a ser copiada: ");
    scanf("%s", str);
    pstr = &str[0];
    pcopia = &strcopia[0];
    strcopiar(str, pcopia);
    printf("String copiada: %s\n", pcopia);

    printf("------------------------------------------------------\n");

    // Função que concatena uma string na outra
    printf("Concatenar duas Strings\n");
    printf("Primeira string: ");
    scanf("%s", str);
    pstr = &str[0];
    printf("Segunda string: ");
    scanf("%s", str2);
    pstr2 = &str2[0];
    strconcatenar(pstr, pstr2);
    printf("String concatenada: %s\n", pstr);

    printf("------------------------------------------------------\n");

    return 0;
}

// Execução das funções

int strtamanho(char *pstr) // Execução da função que retorna o tamanho da string
{
    int i = 0;
    while(*pstr != FIM_DA_STRING)
    {
        if(*pstr != FIM_DA_STRING)
        {
            i++;
        }

        pstr++;
    }

    return i;
}

unsigned char strcomparar(char *pstr, char *pstr2) // Executa a função que compara duas strings
{
    unsigned char boolValue = 1;

    while(*pstr != FIM_DA_STRING || *pstr2 != FIM_DA_STRING)
    {
        if(*pstr != *pstr2)
        {
            boolValue = 0;
            break;
        }
        pstr++;
        pstr2++;
    }

    return boolValue;
}

void strcopiar(char *pstr, char *pcopia) // Executa a função que copia uma string
{
    while(*pstr != FIM_DA_STRING)
    {
        *pcopia = *pstr;
        pstr++;
        pcopia++;
    }
    pcopia++;
    pcopia = FIM_DA_STRING;
}

void strconcatenar(char *pstr, char *pstr2)
{
    while(*pstr != FIM_DA_STRING)
    {
        pstr++;
    }

    while(*pstr2 != FIM_DA_STRING) 
    {
        *pstr = *pstr2;
        pstr++;
        pstr2++;
    }

    *pstr = FIM_DA_STRING;
}