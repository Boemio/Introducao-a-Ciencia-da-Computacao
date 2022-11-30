#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TAMANHO_DA_SERIE 20
#define TAMANHO_DA_SUBSEQUENCIA 3

// Protótipos
void preencherSerie(float serieTemporal[]);
void preencherUltima(float ultimaSubsequencia[], float serieTemporal[]);
float calcularMagnitude(float vetor[]);

// Função main
int main()
{
    // Inicializando as variáveis
    float serieTemporal[TAMANHO_DA_SERIE]; // Vetor da série temporal
    float ultimaSubsequencia[TAMANHO_DA_SUBSEQUENCIA]; // Vetor da última subsequência
    float subsequenciaSerie[TAMANHO_DA_SUBSEQUENCIA]; // Vetor da subsequência atual da série
    int indiceSerie[TAMANHO_DA_SUBSEQUENCIA]; // Vetor que guarda o indice da subsequencia atual
    int melhorIndice[TAMANHO_DA_SUBSEQUENCIA]; // Vetor que guarda o indice da melhor subsequencia
    float melhorSubsequencia[TAMANHO_DA_SUBSEQUENCIA]; // Vetor da melhor subsequencia
    float melhorResultado; // Guarda o melhor resultado
    float resultadoSerie; // Guarda  resultado da subsequencia atual da serie
    float magnitudeUltimo; // Guarda a magnitude do vetor ultimaSubsequecia[TAMANHO_DA_SUBSEQUENCIA]
    float magnitudeSerie; // Guarda a magnitude da subsequencia atual da serie

    // Preenchendo a série
    preencherSerie(serieTemporal);

    // Lendo a ultima subsequência
    preencherUltima(ultimaSubsequencia, serieTemporal);

    // Calculando a magnitude da ultima subsequência
    magnitudeUltimo = calcularMagnitude(ultimaSubsequencia);

    // Percorrendo a série 
    for(int i = 0; i < TAMANHO_DA_SERIE - TAMANHO_DA_SUBSEQUENCIA; i++)
    {
        // Zerando o resultado
        resultadoSerie = 0;

        // Lendo a subsequencia da série
        subsequenciaSerie[0] = serieTemporal[i];
        subsequenciaSerie[1] = serieTemporal[i+1];
        subsequenciaSerie[2] = serieTemporal[i+2];
        indiceSerie[0] = i;
        indiceSerie[1] = i+1;
        indiceSerie[2] = i+2;

        // Calcula a magnitude
        magnitudeSerie = calcularMagnitude(subsequenciaSerie);

        // Calcula a similaridade
        for(int i = 0; i < TAMANHO_DA_SUBSEQUENCIA; i++)
        {
            resultadoSerie += ultimaSubsequencia[i]*subsequenciaSerie[i];
        }
        resultadoSerie /= (magnitudeSerie*magnitudeUltimo);

        // Salva a melhor até agora
        if(i == 0 || resultadoSerie > melhorResultado)
        {
            melhorSubsequencia[0] = subsequenciaSerie[0];
            melhorSubsequencia[1] = subsequenciaSerie[1];
            melhorSubsequencia[2] = subsequenciaSerie[2];
            melhorIndice[0] = indiceSerie[0];
            melhorIndice[1] = indiceSerie[1];
            melhorIndice[2] = indiceSerie[2];
            melhorResultado = resultadoSerie;
        }
    }

    // Printando a melhor subsequencia
    for(int i = 0; i < TAMANHO_DA_SUBSEQUENCIA; i++)
    {
        printf("Melhor Subsequencia[%d]: %f\n", melhorIndice[i], melhorSubsequencia[i]);
    }
    printf("-----------------------------------------------------------------\n");
    printf("Similaridade entre as duas subsequencias = %f\n", melhorResultado);

    return 0;
}

// Execução das funções
void preencherSerie(float serieTemporal[])
{
    int funcao;
    float n;
    printf("[1] Função seno\n[2] Função cosseno\n[3] Função customizada\n");
    scanf("%d", &funcao);
    printf("-----------------------------------------------------------------\n");
    if(funcao == 2)
    {
        for(int i = 0; i < TAMANHO_DA_SERIE; i++)
        {
            serieTemporal[i] = cos(i);
        }
    }
    else if(funcao == 1)
    {
        for(int i = 0; i < TAMANHO_DA_SERIE; i++)
        {
            serieTemporal[i] = sin(i);
        }
    }
    else if(funcao == 3)
    {
        for(int i = 0; i < TAMANHO_DA_SERIE; i++)
        {
            printf("Digite o número da posição %d: ", i);
            scanf("%f", &n);
            serieTemporal[i] = n;
        }
        printf("-----------------------------------------------------------------\n");
    }
}

void preencherUltima(float ultimaSubsequencia[], float serieTemporal[])
{
    for(int i = 0; i < TAMANHO_DA_SUBSEQUENCIA; i++)
    {
        ultimaSubsequencia[i] = serieTemporal[(TAMANHO_DA_SERIE - TAMANHO_DA_SUBSEQUENCIA) + i];
    }
}

float calcularMagnitude(float vetor[])
{
    float resultado = 0;
    for(int i = 0; i < TAMANHO_DA_SUBSEQUENCIA; i++)
    {
        resultado += pow(vetor[i], 2);
    }

    resultado = sqrt(resultado);

    return resultado;
}
