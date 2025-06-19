#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para verificar se há sobreposição
int verificarSobreposicao(int tabuleiro[TAM][TAM], int coords[][2], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int linha = coords[i][0];
        int coluna = coords[i][1];
        if (tabuleiro[linha][coluna] != AGUA) {
            return 1; // há sobreposição
        }
    }
    return 0;
}

// Função para posicionar navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int coords[][2], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int linha = coords[i][0];
        int coluna = coords[i][1];
        tabuleiro[linha][coluna] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializar o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ---------------- NAVIO HORIZONTAL ----------------
    int navioH[TAM_NAVIO][2] = {
        {1, 2}, {1, 3}, {1, 4}
    };

    // ---------------- NAVIO VERTICAL ----------------
    int navioV[TAM_NAVIO][2] = {
        {3, 7}, {4, 7}, {5, 7}
    };

    // ---------------- NAVIO DIAGONAL ↘ (i == j) ----------------
    int navioD1[TAM_NAVIO][2] = {
        {6, 6}, {7, 7}, {8, 8}
    };

    // ---------------- NAVIO DIAGONAL ↙ (i + j == 9) ----------------
    int navioD2[TAM_NAVIO][2] = {
        {2, 7}, {3, 6}, {4, 5}
    };

    // ---------------- POSICIONAMENTO E VALIDAÇÃO ----------------
    if (!verificarSobreposicao(tabuleiro, navioH, TAM_NAVIO))
        posicionarNavio(tabuleiro, navioH, TAM_NAVIO);

    if (!verificarSobreposicao(tabuleiro, navioV, TAM_NAVIO))
        posicionarNavio(tabuleiro, navioV, TAM_NAVIO);

    if (!verificarSobreposicao(tabuleiro, navioD1, TAM_NAVIO))
        posicionarNavio(tabuleiro, navioD1, TAM_NAVIO);

    if (!verificarSobreposicao(tabuleiro, navioD2, TAM_NAVIO))
        posicionarNavio(tabuleiro, navioD2, TAM_NAVIO);

    // ---------------- EXIBIÇÃO DO TABULEIRO ----------------
    printf("TABULEIRO BATALHA NAVAL (0 = Água, 3 = Navio):\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
