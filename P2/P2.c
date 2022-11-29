#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM 100

void desalocarMemoria(char **matriz, int num_pessoas) // Certo
{
    for(int i = 0; i < num_pessoas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

void desalocarMemoriaInt(int **matriz, int num_pessoas) // Certo
{
    for(int i = 0; i < num_pessoas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

char **alocarMatrizNomes(int num_pessoas) // Certo
{
    char **matriz_nomes;
    matriz_nomes = (char**)calloc(num_pessoas, sizeof(char*));

    if(matriz_nomes == NULL)
    {
        printf("Erro na alocação de memória\n");
        return NULL;
    }

    for(int i = 0; i < num_pessoas; i++)
    {
        matriz_nomes[i] = (char*)calloc(num_pessoas, sizeof(char));
        if(matriz_nomes[i] == NULL)
        {
            printf("Erro na alocação de memória\n");
            for(int j = 0; j < i; j++)
            {
                free(matriz_nomes[j]);
            }
            free(matriz_nomes);
            return NULL;
        }
    }
    return matriz_nomes;
}

int **alocarMatrizInimizade(int num_pessoas) // Certo
{
    int **matriz_inimizade;
    matriz_inimizade = (int**)calloc(num_pessoas, sizeof(int*));

    if(matriz_inimizade == NULL)
    {
        printf("Erro na alocação de memória\n");
        return NULL;
    }

    for(int i = 0; i < num_pessoas; i++)
    {
        matriz_inimizade[i] = (int*)calloc(num_pessoas, sizeof(int));
        if(matriz_inimizade[i] == NULL)
        {
            printf("Erro na alocação de memória\n");
            for(int j = 0; j < i; j++)
            {
                free(matriz_inimizade[j]);
            }
            free(matriz_inimizade);
            return NULL;
        }
    }
    return matriz_inimizade;
}

void imprimirNomes(char **matriz_nomes, char **matriz_sobrenomes, int num_nomes) // Certo
{
    for(int i = 0; i < num_nomes; i++)
    {
        printf("%d %s %s\n", i, matriz_nomes[i], matriz_sobrenomes[i]);
    }
}

void imprimirInimizadesPrimos(char **matriz_nomes, char **matriz_sobrenomes, int **matriz_inimizade, int num_nomes) // Certo
{
    for(int i = 0; i < num_nomes; i++)
    {
        printf("Inimigos de %s %s que possuem o mesmo sobrenome: \n", matriz_nomes[i], matriz_sobrenomes[i]);
        for(int j = 0; j < num_nomes; j++)
        {
            if((matriz_inimizade[i][j] == 1) && (strcmp(matriz_sobrenomes[j], matriz_sobrenomes[i]) == 0))
            {
                printf("\t%s %s\n", matriz_nomes[j], matriz_sobrenomes[j]);
            }
        }
    }
    
}

void alterar_inimizade(int **matriz_inimizade, int num_nomes, char **matriz_nomes) // Eu tinha interpretado essa parte errado na hora da prova, essa é a versão correta:
{
    int contador = 0;
    int relacao;
    int id;
    char aux1;
    char aux2;

    printf("Digite o ID da pessoa desejada: ");
    scanf("%d", &id);

    for(int i = 0; i < num_nomes; i++) // Pessoa 2
    {
        contador = 0;
        for(int j = 0; j < strlen(matriz_nomes[id]); j++) // Caractere pessoa 1
        {
            aux1 = matriz_nomes[id][j];
            for(int k = 0; k < strlen(matriz_nomes[i]); k++) // Caractere pessoa 2
            {
                aux2 = matriz_nomes[i][k];
                if(aux1 == aux2 && id != i)
                {
                    contador++;
                    if(contador >= 2)
                    {
                        relacao = matriz_inimizade[id][i];
                        if(relacao == 0)
                        {
                            matriz_inimizade[id][i] = 1;
                            matriz_inimizade[i][id] = 1;
                        }
                        else if(relacao == 1)
                        {
                            matriz_inimizade[id][i] = 0;
                            matriz_inimizade[i][id] = 0;
                        }
                    }
                    break;
                }
            }

            if(contador >= 2)
            {
                break;
            }
        }
    }
}

void imprimirPossiveisAmigos(int **matriz_inimizade, int num_nomes, char **matriz_nomes, char **matriz_sobrenomes) // Certo
{
    for(int i = 0; i < num_nomes; i++)
    {
        printf("Possiveis amigos de %s %s: \n", matriz_nomes[i], matriz_sobrenomes[i]);
        for(int j = 0; j < num_nomes; j++)
        {
            if(matriz_inimizade[i][j] == 1)
            {
                for(int k = 0; k < num_nomes; k++)
                {
                    if(matriz_inimizade[k][j] == 1 && k != i && matriz_inimizade[k][i] != 1) // Tinha esquecido de conferir se eles eram inimigos também
                    {
                        printf("\t%s %s\n", matriz_nomes[k], matriz_sobrenomes[k]);
                    }
                }
            }
        }
    }
}

void ordenarSobrenomes(char **matriz_nomes, char **matriz_sobrenomes, int num_nomes) 
{
    char straux_sobrenomes[MAX_TAM];
    char straux_nomes[MAX_TAM];

    for(int j = 0; j < num_nomes; j++) // Eu tinha esquecido desse for  
    {
        for(int i = 0; i < num_nomes-1; i++)
        {
            if((matriz_sobrenomes[i][0]) < (matriz_sobrenomes[i+1][0])) // Decrescente
            {
                strcpy(straux_sobrenomes, matriz_sobrenomes[i+1]);
                strcpy(straux_nomes, matriz_nomes[i+1]);
                strcpy(matriz_sobrenomes[i+1], matriz_sobrenomes[i]);
                strcpy(matriz_nomes[i+1], matriz_nomes[i]);
                strcpy(matriz_sobrenomes[i], straux_sobrenomes);
                strcpy(matriz_nomes[i], straux_nomes);
            }
        }
    }
}

int main()
{
    int menu;
    FILE *ponteiro_arq;
    int num_pessoas;
    char **matriz_nomes;
    char **matriz_sobrenomes;
    char aux_nomes[MAX_TAM];
    char aux_sobrenomes[MAX_TAM];
    int aux_id;
    int **matriz_inimizade;
    int aux_relacao;

    printf("Menu:\n[1] Ler arquivo de dados\n[2] Imprimir inimizades com nomes em comum\n[3] Converter as inimizades\n[4] Identificar possiveis amigos\n[5] Ordenar pessoas conforme primeiro nome\n[6] Salvar arquivo de dados\n[0] Sair\n");
    
    do
    {
        printf("Digite a sua opção: ");
        scanf("%d", &menu);

        switch (menu)
        {
            case 0:
                desalocarMemoria(matriz_nomes, num_pessoas);
                desalocarMemoria(matriz_sobrenomes, num_pessoas);
                desalocarMemoriaInt(matriz_inimizade, num_pessoas);
                printf("Bye!\n");
            case 1: // Ler arquivo de dados
                // Abrindo o arquivo
                ponteiro_arq = fopen("entrada.txt", "r");

                // Lendo o número de pessoas
                fscanf(ponteiro_arq, "%d\n", &num_pessoas);

                // Lendo os nomes das pessoas
                matriz_nomes = alocarMatrizNomes(num_pessoas);
                matriz_sobrenomes = alocarMatrizNomes(num_pessoas);
                if(matriz_nomes == NULL || matriz_sobrenomes == NULL)
                {
                    fclose(ponteiro_arq);
                    exit(1);
                }
                for(int i = 0; i < num_pessoas; i++)
                {
                    fscanf(ponteiro_arq, "%d %s %s\n", &aux_id, aux_nomes, aux_sobrenomes);
                    strcpy(matriz_nomes[aux_id], aux_nomes);
                    strcpy(matriz_sobrenomes[aux_id], aux_sobrenomes);
                }

                // Lendo a matriz inimizade
                matriz_inimizade = alocarMatrizInimizade(num_pessoas);
                if(matriz_inimizade == NULL)
                {
                    fclose(ponteiro_arq);
                    exit(1);
                }
                for(int i = 0; i < num_pessoas; i++)
                {
                    for(int j = 0; j < num_pessoas; j++)
                    {
                        fscanf(ponteiro_arq, "%d ", &aux_relacao);
                        matriz_inimizade[i][j] = aux_relacao;
                    }
                }

                fclose(ponteiro_arq);

                break;
            case 2: // Imprimir inimizades com sobrenomes em comum
                imprimirInimizadesPrimos(matriz_nomes, matriz_sobrenomes, matriz_inimizade, num_pessoas);
                break;
            case 3: // Função que muda a inimizade caso alguém tenha mais de 2 caracteres iguais ao primeiro nome
                alterar_inimizade(matriz_inimizade, num_pessoas, matriz_nomes);
                break;
            case 4: // Identificar possiveis amigos
                imprimirPossiveisAmigos(matriz_inimizade, num_pessoas, matriz_nomes, matriz_sobrenomes);
                break;
            case 5: // Ordenar conforme sobrenome
                ordenarSobrenomes(matriz_nomes, matriz_sobrenomes, num_pessoas);
                break;
            case 6:
                ponteiro_arq = fopen("entrada.txt", "w");
                if(ponteiro_arq == NULL)
                {
                    printf("Erro ao abrir o arquivo");
                    fclose(ponteiro_arq);
                    exit(1);
                }

                fprintf(ponteiro_arq, "%d\n", num_pessoas);

                for(int i = 0; i < num_pessoas; i++)
                {
                    fprintf(ponteiro_arq, "%d %s %s\n", i, matriz_nomes[i], matriz_sobrenomes[i]);
                }

                for(int i = 0; i < num_pessoas; i++)
                {
                    for(int j = 0; j < num_pessoas; j++)
                    {
                        fprintf(ponteiro_arq, "%d ", matriz_inimizade[i][j]);
                    }
                    fprintf(ponteiro_arq, "\n");
                }
                fclose(ponteiro_arq);
                break;
            
            default:
                printf("Opção inválida!\n");
                break;
        }
    }while(menu != 0);

    return 0;
}