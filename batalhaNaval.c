#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

int main() {
    // ===================== DECLARAÇÃO E INICIALIZAÇÃO DO TABULEIRO =====================
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializando o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // ===================== POSICIONAMENTO DOS NAVIOS =====================
    // Vetores representando os navios
    int navio_horizontal[TAMANHO_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};
    int navio_vertical[TAMANHO_NAVIO]   = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};

    // Coordenadas iniciais fixas
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 1;

    // Validação simplificada: garantir que navios estejam dentro do tabuleiro
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        // Posicionar navio horizontal
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
        }

        // Posicionar navio vertical (evita sobreposição)
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] != VALOR_AGUA) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
            }
        } else {
            printf("Erro: sobreposição detectada no posicionamento do navio vertical.\n");
        }
    } else {
        printf("Erro: posição fora dos limites do tabuleiro.\n");
    }

    // ===================== EXIBIÇÃO DO TABULEIRO =====================
    printf("\nTabuleiro (0 = Água, 3 = Navio):\n\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
