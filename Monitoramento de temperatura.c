#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define FILE_NAME "temperaturas.txt"

// Função para registrar uma nova leitura de temperatura
void registrarTemperatura() {
    FILE *file = fopen(FILE_NAME, "a"); // Abre o arquivo em modo de anexação
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    float temperatura;
    printf("Digite a temperatura registrada: ");
    scanf("%f", &temperatura);
    
    fprintf(file, "%.2f\n", temperatura);
    fclose(file);

    printf("Temperatura registrada com sucesso!\n");
}

// Função para calcular estatísticas das temperaturas registradas
void exibirEstatisticas() {
    FILE *file = fopen(FILE_NAME, "r"); // Abre o arquivo em modo de leitura
    if (file == NULL) {
        printf("Nenhuma temperatura registrada ainda.\n");
        return;
    }

    float temperatura, soma = 0, max = -FLT_MAX, min = FLT_MAX;
    int count = 0;

    while (fscanf(file, "%f", &temperatura) == 1) {
        soma += temperatura;
        if (temperatura > max) max = temperatura;
        if (temperatura < min) min = temperatura;
        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("Nenhuma leitura válida encontrada.\n");
        return;
    }

    printf("\nEstatísticas das Temperaturas:\n");
    printf("Média: %.2f\n", soma / count);
    printf("Máxima: %.2f\n", max);
    printf("Mínima: %.2f\n", min);
}

// Função principal para interação com o usuário
int main() {
    int opcao;

    do {
        printf("\nMonitoramento de Temperaturas\n");
        printf("1. Registrar Temperatura\n");
        printf("2. Exibir Estatísticas\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registrarTemperatura();
                break;
            case 2:
                exibirEstatisticas();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
