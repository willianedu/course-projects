#include <stdio.h>
#include <ctype.h> // Biblioteca para usar a função tolower()

// Protótipos das funções
void apresentar_boas_vindas();
void limpar_buffer();
float calcular_imc(float peso, float altura_cm);
void classificar_imc(float imc);

int main() {
    float peso, altura_cm, imc;
    char opcao;

    apresentar_boas_vindas();

    do {
        // --- ENTRADA E VALIDAÇÃO DE DADOS ---
        printf("\nDigite seu peso (em kg): ");
        while (scanf("%f", &peso) != 1 || peso <= 0) {
            printf("Entrada inválida. Por favor, digite um número positivo para o peso: ");
            limpar_buffer();
        }
        limpar_buffer();

        printf("Digite sua altura (em cm): ");
        while (scanf("%f", &altura_cm) != 1 || altura_cm <= 0) {
            printf("Entrada inválida. Por favor, digite um número positivo para a altura: ");
            limpar_buffer();
        }
        limpar_buffer();

        // --- PROCESSAMENTO ---
        imc = calcular_imc(peso, altura_cm);

        // --- SAÍDA DE DADOS ---
        printf("\n----------------------------------\n");
        printf("Seu IMC é: %.2f\n", imc);
        printf("Classificação: ");
        classificar_imc(imc);
        printf("----------------------------------\n");

        // Loop para garantir que a opção seja 's' ou 'n'
        do {
            printf("\nDeseja calcular novamente? (s/n): ");
            scanf("%c", &opcao);
            limpar_buffer();
            
            opcao = tolower(opcao); // Converte para minúscula

            if (opcao != 's' && opcao != 'n') {
                printf("Opção inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
            }
        } while (opcao != 's' && opcao != 'n');

    } while (opcao == 's'); // O laço principal continua apenas se a opção for 's'

    printf("\nObrigado por usar a calculadora de IMC!\n");

    return 0;
}

// Implementação das outras funções...
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void apresentar_boas_vindas() {
    printf("======================================\n");
    printf(" Bem-vindo à Calculadora de IMC\n");
    printf("======================================\n");
}

float calcular_imc(float peso, float altura_cm) {
    if (altura_cm <= 0) {
        return 0.0;
    }
    float altura_m = altura_cm / 100.0;
    return peso / (altura_m * altura_m);
}

void classificar_imc(float imc) {
    if (imc < 18.5) {
        printf("Abaixo do peso.\n");
    } else if (imc >= 18.5 && imc <= 24.9) {
        printf("Peso normal.\n");
    } else if (imc >= 25.0 && imc <= 29.9) {
        printf("Sobrepeso.\n");
    } else if (imc >= 30.0 && imc <= 34.9) {
        printf("Obesidade grau I.\n");
    } else if (imc >= 35.0 && imc <= 39.9) {
        printf("Obesidade grau II.\n");
    } else {
        printf("Obesidade grau III.\n");
    }
}