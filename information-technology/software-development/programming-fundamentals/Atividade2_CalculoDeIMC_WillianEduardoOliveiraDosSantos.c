#include <stdio.h>
#include <ctype.h> // Biblioteca para usar a função tolower()

// Protótipos das funções (declarações antecipadas)
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
        // Loop para garantir que a entrada de peso seja um número válido
        while (scanf("%f", &peso) != 1 || peso <= 0) {
            printf("Entrada inválida. Por favor, digite um número positivo para o peso: ");
            limpar_buffer(); // Limpa a entrada incorreta (ex: "abc")
        }
        limpar_buffer(); // Limpa o '\n' deixado pelo Enter

        printf("Digite sua altura (em cm): ");
        // Loop para garantir que a entrada de altura seja um número válido
        while (scanf("%f", &altura_cm) != 1 || altura_cm <= 0) {
            printf("Entrada inválida. Por favor, digite um número positivo para a altura: ");
            limpar_buffer(); // Limpa a entrada incorreta
        }
        limpar_buffer(); // Limpa o '\n'

        // --- PROCESSAMENTO ---
        imc = calcular_imc(peso, altura_cm);

        // --- SAÍDA DE DADOS ---
        printf("\n----------------------------------\n");
        printf("Seu IMC é: %.2f\n", imc);
        printf("Classificação: ");
        classificar_imc(imc);
        printf("----------------------------------\n");

        printf("\nDeseja calcular novamente? (s/n): ");
        scanf("%c", &opcao);
        limpar_buffer();

    } while (tolower(opcao) == 's'); // Converte a opção para minúscula para a comparação

    printf("\nObrigado por usar a calculadora de IMC!\n");

    return 0;
}

// Função para limpar o buffer de entrada do teclado
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para exibir a mensagem de boas-vindas
void apresentar_boas_vindas() {
    printf("======================================\n");
    printf(" Bem-vindo à Calculadora de IMC\n");
    printf("======================================\n");
}

// Função para calcular o IMC
float calcular_imc(float peso, float altura_cm) {
    if (altura_cm <= 0) {
        return 0.0; // Evita divisão por zero
    }
    float altura_m = altura_cm / 100.0;
    return peso / (altura_m * altura_m);
}

// Função para classificar e imprimir o resultado do IMC
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