#include <stdio.h>

#define TAM 10
#define TAM_HAB 5
#define AGUA 0
#define NAVIO 3
#define EFEITO 5

// Inicializa o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Posiciona um navio de tamanho 3 na horizontal
void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (coluna + i < TAM)
            tabuleiro[linha][coluna + i] = NAVIO;
    }
}

// Posiciona um navio de tamanho 3 na vertical
void posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (linha + i < TAM)
            tabuleiro[linha + i][coluna] = NAVIO;
    }
}

// Cria uma matriz em forma de cone apontando para baixo
void criarMatrizCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Centro da linha (meio da matriz)
            int meio = TAM_HAB / 2;
            if (j >= meio - i && j <= meio + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria uma matriz em forma de cruz
void criarMatrizCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria uma matriz em forma de octaedro (losango)
void criarMatrizOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    int meio = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Aplica a matriz de habilidade sobre o tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int matriz[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int offset = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = origemLinha + i - offset;
            int coluna = origemColuna + j - offset;

            // Validação de limites
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (matriz[i][j] == 1 && tabuleiro[linha][coluna] == AGUA)
                    tabuleiro[linha][coluna] = EFEITO;
            }
        }
    }
}

// Exibe o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n");
    printf("0 = Água, 3 = Navio, 5 = Habilidade\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Posiciona dois navios
    posicionarNavioHorizontal(tabuleiro, 2, 2);
    posicionarNavioVertical(tabuleiro, 6, 5);

    // Cria as matrizes de habilidade
    criarMatrizCone(cone);
    criarMatrizCruz(cruz);
    criarMatrizOctaedro(octaedro);

    // Define pontos de origem no tabuleiro
    int origemConeLinha = 1, origemConeColuna = 5;
    int origemCruzLinha = 5, origemCruzColuna = 2;
    int origemOctaLinha = 7, origemOctaColuna = 7;

    // Aplica as habilidades
    aplicarHabilidade(tabuleiro, cone, origemConeLinha, origemConeColuna);
    aplicarHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzColuna);
    aplicarHabilidade(tabuleiro, octaedro, origemOctaLinha, origemOctaColuna);

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}