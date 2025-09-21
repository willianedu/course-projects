#include <stdio.h>

int main() {
    float peso, altura_cm, altura_m, imc;
    char opcao;

    printf("=== CALCULADORA DE IMC ===\n");
    printf("Este programa calcula seu Índice de Massa Corporal (IMC) e classifica sua categoria.\n");
    printf("A altura deve ser informada em centímetros (ex: 175 cm).\n\n");

    do {
        // Entrada de dados
        printf("Digite seu peso (kg): ");
        scanf("%f", &peso);
        printf("Digite sua altura (cm): ");
        scanf("%f", &altura_cm);

        // Conversão de centímetros para metros
        altura_m = altura_cm / 100;

        // Cálculo do IMC
        imc = peso / (altura_m * altura_m);

        // Classificação do IMC
        printf("\nSeu IMC é: %.2f\n", imc);
        printf("Classificação: ");

        if (imc < 18.5) {
            printf("Abaixo do peso.\n");
        } else if (imc < 25) {
            printf("Peso normal.\n");
        } else if (imc < 30) {
            printf("Sobrepeso.\n");
        } else if (imc < 35) {
            printf("Obesidade grau I.\n");
        } else if (imc < 40) {
            printf("Obesidade grau II.\n");
        } else {
            printf("Obesidade grau III.\n");
        }

        // Perguntar se deseja continuar
        printf("\nDeseja calcular novamente? (s/n): ");
        scanf(" %c", &opcao); // Espaço antes de %c para ignorar quebras de linha

    } while (opcao == 's' || opcao == 'S');

    printf("\nObrigado por usar a calculadora de IMC!\n");
    return 0;
}