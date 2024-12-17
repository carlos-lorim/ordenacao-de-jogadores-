#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int comparacoes = 0;
int trocas = 0;
int numero_de_jogadores = 0;

typedef struct {
    char nome[50];
    char posicao[30];
    char naturalidade[30];
    char clube[30];
    int idade;
} Jogador;

void reset_metrics() {
    comparacoes = 0;
    trocas = 0;
}

void print_structs(Jogador* jogadores, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s,%s,%s,%s,%d\n", jogadores[i].nome, jogadores[i].posicao, jogadores[i].naturalidade, jogadores[i].clube, jogadores[i].idade);
    }
}

void print_metrics(clock_t start, clock_t end) {
    double tempo_execucao = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("%.3f\n%d\n%d\n%zu\n", tempo_execucao, comparacoes, trocas, sizeof(Jogador) * numero_de_jogadores);
}

Jogador* ler_csv(const char* arquivo, int* numero_de_jogadores) {
    FILE* file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", arquivo);
        exit(1);
    }

    // Contar o número de jogadores no arquivo
    char buffer[200];
    while (fgets(buffer, sizeof(buffer), file)) {
        (*numero_de_jogadores)++;
    }

    // Alocar memória para os jogadores
    Jogador* jogadores = (Jogador*)malloc(*numero_de_jogadores * sizeof(Jogador));
    if (jogadores == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    // Voltar para o início do arquivo
    fseek(file, 0, SEEK_SET);

    // Ler os jogadores do arquivo
    int i = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        sscanf(buffer, "%49[^,],%29[^,],%29[^,],%29[^,],%d", jogadores[i].nome, jogadores[i].posicao, jogadores[i].naturalidade, jogadores[i].clube, &jogadores[i].idade);
        i++;
    }

    fclose(file);
    return jogadores;
}

void bubble_sort(Jogador *jogadores, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            comparacoes++;
            if (strcmp(jogadores[j].nome, jogadores[j + 1].nome) > 0) {
                // Troca
                Jogador temp = jogadores[j];
                jogadores[j] = jogadores[j + 1];
                jogadores[j + 1] = temp;
                trocas++;
            }
        }
    }
}

int particionar(Jogador *jogadores, int baixo, int alto) {
    Jogador pivo = jogadores[alto];
    int i = baixo - 1;
    
    for (int j = baixo; j < alto; j++) {
        comparacoes++;
        if (strcmp(jogadores[j].nome, pivo.nome) < 0) {
            i++;
            Jogador temp = jogadores[i];
            jogadores[i] = jogadores[j];
            jogadores[j] = temp;
            trocas++;
        }
    }

    Jogador temp = jogadores[i + 1];
    jogadores[i + 1] = jogadores[alto];
    jogadores[alto] = temp;
    trocas++;

    return i + 1;
}

void quick_sort(Jogador *jogadores, int baixo, int alto) {
    if (baixo < alto) {
        int indice_pivo = particionar(jogadores, baixo, alto);
        quick_sort(jogadores, baixo, indice_pivo - 1);
        quick_sort(jogadores, indice_pivo + 1, alto);
    }
}

void counting_sort(Jogador *jogadores, int n) {
    int idade_max = 100; // Supondo uma idade máxima de 100
    int contagem[idade_max + 1];
    Jogador *ordenado = (Jogador *)malloc(n * sizeof(Jogador));

    // Inicializa o array de contagem
    for (int i = 0; i <= idade_max; i++) {
        contagem[i] = 0;
    }

    // Conta as ocorrências de cada idade
    for (int i = 0; i < n; i++) {
        contagem[jogadores[i].idade]++;
    }

    // Modifica o array de contagem para armazenar as posições dos elementos
    for (int i = 1; i <= idade_max; i++) {
        contagem[i] += contagem[i - 1];
    }

    // Constrói o array ordenado
    for (int i = n - 1; i >= 0; i--) {
        int idade = jogadores[i].idade;
        ordenado[contagem[idade] - 1] = jogadores[i];
        contagem[idade]--;
        trocas++;
    }

    // Copia o array ordenado de volta para o array original
    for (int i = 0; i < n; i++) {
        jogadores[i] = ordenado[i];
    }

    free(ordenado);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <metodo>\n", argv[0]);
        return 1;
    }
    
    int metodo = atoi(argv[1]);
    Jogador *jogadores = ler_csv("jogadores.csv", &numero_de_jogadores);

    clock_t start = clock();
    reset_metrics();
    
    switch (metodo) {
        case 1:
            bubble_sort(jogadores, numero_de_jogadores);
            break;
        case 2:
            quick_sort(jogadores, 0, numero_de_jogadores - 1);
            break;
        case 3:
            counting_sort(jogadores, numero_de_jogadores);
            break;
        default:
            printf("Método inválido\n");
            return 1;
    }

    clock_t end = clock();
    print_structs(jogadores, numero_de_jogadores);
    print_metrics(start, end);

    free(jogadores);
    return 0;
}