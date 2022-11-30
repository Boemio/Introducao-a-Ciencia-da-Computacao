#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float **alocar_matriz(int w, int h)
{
    float **matriz;
    matriz = (float**)calloc(w, sizeof(float*));

    for(int i = 0; i < w; i++)
    {
        matriz[i] = (float*) calloc(h, sizeof(float));
        if(matriz[i] == NULL)
        {
            printf("Erro ao alocar a matriz");
            for(int k = 0; k < i; k++)
            {
                free(matriz[k]);
            }
            free(matriz);
            return NULL;
        }
    }

    return matriz;
}

void desalocar_memoria(float **matriz, int w)
{
    for(int i = 0; i < w; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

float **clarearEscurecer(float fator, float **matriz, int w, int h)
{
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < h; j++)
        {
            matriz[i][j] *= fator;
            if(matriz[i][j] > 1.00)
            {
                matriz[i][j] = 1.00;
            }
        }
    }

    return matriz;
}

float **inverterHorizontal(float **matriz, int w, int h)
{
    float **matrizcopia = alocar_matriz(w,h);

    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < h; j++)
        {
            matrizcopia[i][j] = matriz[i][j];
        }
    }
    
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            matriz[j][i] = matrizcopia[w-j-1][i];
        }
    }
    desalocar_memoria(matrizcopia,w);

    return matriz;
}

float **inverterVertical(float **matriz, int w, int h)
{
    float **matrizcopia = alocar_matriz(w,h);

    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < h; j++)
        {
            matrizcopia[i][j] = matriz[i][j];
        }
    }

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            matriz[j][i] = matrizcopia[j][h-i-1];
        }
    }

    desalocar_memoria(matrizcopia,w);

    return matriz;
}

float **rotacionar90(float **matriz, int w, int h)
{
    float **nova_matriz = alocar_matriz(h,w);

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            nova_matriz[i][j] = matriz[j][i];
        }
    }

    desalocar_memoria(matriz,w);

    return nova_matriz;
}

float **aumentarReduzir(float **matriz, int w, int h, int novoW, int novoH)
{
    float **nova_matriz = alocar_matriz(novoW, novoH);
    float fatorEscalaW = (float)novoW/(float)w;
    float fatorEscalaH = (float)novoH/(float)h;

    for(int i = 0; i < novoW; i++)
    {
        for(int j = 0; j < novoH; j++)
        {
            nova_matriz[i][j] = matriz[(int)((float)i/fatorEscalaW)][(int)((float)j/fatorEscalaH)];
        }
    }

    desalocar_memoria(matriz, w);

    return nova_matriz;
}

void salvarMatriz(FILE *arq_saida, float **matriz, int w, int h)
{
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < h; j++)
        {
            fprintf(arq_saida, "%.2f ", matriz[i][j]);
        }
        fprintf(arq_saida, "\n");
    }
}

int main()
{
    // Declaração das variáveis
    float pixel;
    float fator;
    int menu;
    char hv[20];
    char direcao[20];
    int temp;
    float fator_de_escala;
    char nome_arquivo[100];
    int novoW, novoH;
    
    // Criando o ponteiro para arquivos
    FILE *arq_entrada;
    FILE *arq_saida;

    // Abrindo o arquivo
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);
    arq_entrada = fopen(nome_arquivo, "r");
    arq_saida = fopen("output.img", "w");
    
    // Testando se existe
    if(arq_entrada == NULL)
    {
        printf("Erro ao carregar o arquivo de entrada\n");
        exit(1);
    }
    if(arq_saida == NULL)
    {
        printf("Erro ao carregar o arquivo de saída\n");
        exit(1);
    }

    // w = width, h = height
    int w, h;

    // Lendo w e h e pritando o valor na tela
    fscanf(arq_entrada, "%d %d\n", &w, &h);

    // Criando uma matriz dinâmica
    float **matriz = alocar_matriz(w, h);
    if(matriz == NULL)
    {
        fclose(arq_entrada);
        fclose(arq_saida);
        exit(1);
    }

    // Carregando os dados do arquivo
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < h; j++)
        {
            fscanf(arq_entrada, "%f", &pixel);
            matriz[i][j] = pixel;
        }
    }

    // Criando um menu
    printf("------------------------------------------------------------\n");
    printf("                            MENU                            \n");
    printf("------------------------------------------------------------\n");
    printf("(1) Clarear ou escurecer a imagem\n");
    printf("(2) Inverter horizontalmente ou verticalmente a imagem\n");
    printf("(3) Rotacionar a imagem 90° à esquerda ou à direita\n");
    printf("(4) Aumentar ou reduzir a imagem a um fator de escala x\n");
    printf("(0) Sair\n");
    printf("------------------------------------------------------------\n");
    scanf("%d", &menu);
    printf("------------------------------------------------------------\n");
    
    switch(menu)
    {
    case 1: // Clarear ou escurecer
        printf("Por qual fator a imagem deverá ser clareada/escurecida? ");
        scanf("%f", &fator);
        matriz = clarearEscurecer(fator, matriz, w, h);

        if(matriz == NULL)
        {
            fclose(arq_entrada);
            fclose(arq_saida);
            exit(1);
        }

        fprintf(arq_saida, "%d %d\n", w, h);
        break;
    
    case 2: // Inverter horizontalmente ou verticalmente a imagem
        printf("Inverter na horizontal ou na vertical? ");
        scanf("%s", hv);

        if((strcmp(hv, "Horizontal") == 0) || (strcmp(hv, "horizontal") == 0))
        {
            matriz = inverterHorizontal(matriz, w, h);
        }

        else if((strcmp(hv, "Vertical") == 0) || (strcmp(hv, "vertical") == 0))
        {
            matriz = inverterVertical(matriz, w, h);
        }

        if(matriz == NULL)
        {
            fclose(arq_entrada);
            fclose(arq_saida);
            exit(1);
        }

        fprintf(arq_saida, "%d %d\n", w, h);
        break;

    case 3: // Rotacionar a imagem 90° à esquerda ou à direita
        printf("Rotacionar para a esquerda ou para a direita? ");
        scanf("%s", direcao);
        if((strcmp(direcao, "Direita") == 0) || (strcmp(direcao, "direita") == 0))
        {
            matriz = rotacionar90(matriz, w, h);
            temp = h;
            h = w;
            w = temp;
            matriz = inverterHorizontal(matriz, w, h);
        }
        else if((strcmp(direcao, "Esquerda") == 0) || (strcmp(direcao, "esquerda") == 0))
        {
            matriz = rotacionar90(matriz, w, h);
            temp = h;
            h = w;
            w = temp;
        }

        if(matriz == NULL)
        {
            fclose(arq_entrada);
            fclose(arq_saida);
            exit(1);
        }

        fprintf(arq_saida, "%d %d\n", w, h);

        break;
    
    case 4: // Aumentar ou reduzir a imagem a um fator de escala x. Por exemplo, se x=1.5, então aumenta 50%. Se x=0.5 então reduz 50%.
        printf("Qual é o fator de escala? ");
        scanf("%f", &fator_de_escala);
        novoH = (int)((float)h*fator_de_escala);
        novoW = (int)((float)w*fator_de_escala);

        matriz = aumentarReduzir(matriz, w, h, novoW, novoH);
        
        h = novoH;
        w = novoW;

        fprintf(arq_saida, "%d %d\n", w, h);

        break;

    default:
        printf("Erro ao confirmar a operação\n");
        exit(1);
        break;
    }
    
    // Salvar o output da matriz IMG gerada e fechar tudo
    salvarMatriz(arq_saida, matriz, w, h);
    
    desalocar_memoria(matriz,w);
    
    fclose(arq_entrada);
    fclose(arq_saida);

    return 0;
}
