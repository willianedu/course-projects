#include <stdio.h>
#include <math.h>

#define DIAS 30
#define MAX_TEMP 40 // Ajustado para um gráfico mais compacto
#define MIN_TEMP -10

// Função para limpar o buffer de entrada do teclado
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para desenhar o gráfico de temperaturas (com barras)
void desenharGrafico(float temps[]) {
    printf("\nGráfico de Temperaturas do Mês (Celsius):\n");
    
    for (int linha = MAX_TEMP; linha >= MIN_TEMP; linha--) {
        // Não desenha a linha do zero para não poluir o gráfico
        if (linha == 0) continue; 
        
        printf("%3d |", linha);
        
        for (int dia = 0; dia < DIAS; dia++) {
            int temp_arredondada = round(temps[dia]);
            
            // Lógica para desenhar BARRAS em vez de pontos
            if ((linha > 0 && linha <= temp_arredondada) || (linha < 0 && linha >= temp_arredondada)) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("|\n");
    }
    
    // Linha do eixo X (eixo zero)
    printf("  0 +");
    for (int i = 0; i < DIAS; i++) printf("---");
    printf("+\n");
    
    // Legendas dos dias (ajustada para 1, 5, 10...)
    printf("      ");
    for (int dia = 0; dia < DIAS; dia++) {
        if ((dia + 1) % 5 == 0) {
            printf("%-5d", dia + 1);
        }
    }
    printf("\n      Dias do Mês\n");
}

int main() {
    float temperaturas[DIAS];
    float soma = 0, media, maior, menor;
    
    printf("=== REGISTRO DE TEMPERATURAS MENSAL ===\n");
    printf("Digite as temperaturas máximas de cada dia do mês (entre %d°C e %d°C):\n", MIN_TEMP, MAX_TEMP);
    
    // Entrada de dados com validação
    for (int i = 0; i < DIAS; i++) {
        printf("Dia %d: ", i + 1);
        
        // Loop de validação de entrada
        while (scanf("%f", &temperaturas[i]) != 1 || temperaturas[i] < MIN_TEMP || temperaturas[i] > MAX_TEMP) {
            printf("Entrada inválida. Digite uma temperatura entre %d e %d: ", MIN_TEMP, MAX_TEMP);
            limpar_buffer();
        }
        
        soma += temperaturas[i];
        
        if (i == 0) {
            maior = temperaturas[i];
            menor = temperaturas[i];
        } else {
            if (temperaturas[i] > maior) maior = temperaturas[i];
            if (temperaturas[i] < menor) menor = temperaturas[i];
        }
    }
    
    // Cálculos
    media = soma / DIAS;
    
    // Exibição dos resultados
    printf("\n=== RESULTADOS ===\n");
    printf("Temperatura média do mês: %.2f°C\n", media);
    printf("Maior temperatura registrada: %.2f°C\n", maior);
    printf("Menor temperatura registrada: %.2f°C\n", menor);
    
    // Desenha o gráfico
    desenharGrafico(temperaturas);
    
    return 0;
}