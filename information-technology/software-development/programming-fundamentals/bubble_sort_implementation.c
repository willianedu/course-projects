#include <stdio.h>
#include <string.h> // Biblioteca para usar a função memcpy

#define TAMANHO 10

// Função ÚNICA que implementa o Bubble Sort para ambas as ordens
// O parâmetro 'ordem' controla se a ordenação é crescente (1) ou decrescente (-1)
void bubbleSort(int arr[], int n, int ordem) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // Se a ordem for crescente (1), a condição é arr[j] > arr[j+1]
            // Se a ordem for decrescente (-1), a condição se torna arr[j] * -1 > arr[j+1] * -1, que é o mesmo que arr[j] < arr[j+1]
            if ((arr[j] * ordem) > (arr[j + 1] * ordem)) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função para exibir os elementos de um vetor
void exibirVetor(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Vetor com os dados originais
    int reproducoes_originais[TAMANHO] = {150000, 75000, 300000, 50000, 420000, 250000, 100000, 180000, 90000, 350000};
    int n = TAMANHO;

    printf("=== SISTEMA DE ORDENAÇÃO DE AUDIÊNCIA DE MÚSICAS ===\n\n");

    // Exibir vetor original
    printf("Vetor original (reproduções):\n");
    exibirVetor(reproducoes_originais, n);
    printf("\n");

    // --- Ordenação Crescente ---
    int temp_crescente[TAMANHO];
    memcpy(temp_crescente, reproducoes_originais, sizeof(reproducoes_originais)); // Cria uma cópia do vetor original
    
    bubbleSort(temp_crescente, n, 1); // Chama a função unificada com ordem 1 (crescente)
    printf("Ordenação CRESCENTE (menor para maior):\n");
    exibirVetor(temp_crescente, n);
    printf("\n");

    // --- Ordenação Decrescente ---
    int temp_decrescente[TAMANHO];
    memcpy(temp_decrescente, reproducoes_originais, sizeof(reproducoes_originais)); // Cria outra cópia do vetor original

    bubbleSort(temp_decrescente, n, -1); // Chama a função unificada com ordem -1 (decrescente)
    printf("Ordenação DECRESCENTE (maior para menor):\n");
    exibirVetor(temp_decrescente, n);

    return 0;
}