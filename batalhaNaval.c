#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nivel Aventureiro
int main() {
    // Tabuleiro 10x10 inicializado com 0 (água)
    int tabuleiro[10][10] = {0};

    // Letras para cabeçalho das colunas
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Definição dos navios (tamanho 3)
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};


    // ======================================
    // Posicionamento do Navio 1 - Horizontal
    // ======================================
    int linha_h = 2;      // Linha 2 (índice 1 no array)
    char coluna_inicial_h = 'C';   // Coluna inicial C
    int coluna_convertida_h = coluna_inicial_h - 'A'; // Convertendo char para int

    for(int i = 0; i < 3; i++) {
        // Verifica limites do tabuleiro
        if(coluna_convertida_h + i >= 10 || linha_h - 1 >= 10) {
            printf("Erro: Navio 1 ultrapassa os limites do tabuleiro na posição (%d, %c)\n", linha_h, coluna_inicial_h + i);
            return 1; // Sai do programa com erro
        }

        // Verifica sobreposição de navios
        if(tabuleiro[linha_h - 1][coluna_convertida_h + i] != 0) {
            printf("Erro: Sobreposição de navios na posição (%d, %c)\n", linha_h, coluna_inicial_h + i);
            return 1; // Sai do programa com erro
        }

        tabuleiro[linha_h - 1][coluna_convertida_h + i] = navio1[i];
    }
    // ======================================
    // Posicionamento do Navio 2 - Vertical
    // ======================================
    int linha_v = 6;     // Linha 6 (índice 5 no array)
    char coluna_inicial_v = 'F'; // Coluna inicial F
    int coluna_convertida_v = coluna_inicial_v - 'A'; // Convertendo char para int

    for(int i = 0; i < 3; i++) {
        // Verifica limites do tabuleiro
        if(linha_v - 1 + i >= 10 || coluna_convertida_v >= 10) {
            printf("Erro: Navio 2 ultrapassa os limites do tabuleiro na posição (%d, %c)\n", linha_v, coluna_inicial_v + i);
            return 1; // Sai do programa com erro
        }

        // Verifica sobreposição de navios
        if(tabuleiro[linha_v - 1 + i][coluna_convertida_v] != 0) {
            printf("Erro: Sobreposição de navios na posição (%d, %c)\n", linha_v + i, coluna_inicial_v);
            return 1; // Sai do programa com erro
        }
        tabuleiro[linha_v - 1 + i][coluna_convertida_v] = navio2[i];
    }

    // ======================================
    // Posicionamento do Navio 3 - Diagonal
    // ======================================
    int linha_d = 8;     // Linha 8 (índice 7 no array)
    char coluna_inicial_d = 'B'; // Coluna inicial B
    int coluna_convertida_d = coluna_inicial_d - 'A'; // Convertendo char para int

    for(int i = 0; i < 3; i++) {
        // Verifica limites do tabuleiro
        if(linha_d - 1 + i >= 10 || coluna_convertida_d + i >= 10) {
            printf("Erro: Navio 3 ultrapassa os limites do tabuleiro na posição (%d, %c)\n", linha_d, coluna_inicial_d + i);
            return 1; // Sai do programa com erro
        }

        // Verifica sobreposição de navios
        if(tabuleiro[linha_d - 1 + i][coluna_convertida_d + i] != 0) {
            printf("Erro: Sobreposição de navios na posição (%d, %c)\n", linha_d + i, coluna_inicial_d + i);
            return 1; // Sai do programa com erro
        }
        tabuleiro[linha_d - 1 + i][coluna_convertida_d + i] = navio2[i];
    }

    // ======================================
    // Posicionamento do Navio 4 - Diagonal
    // ======================================
    int linha_d2 = 8;     // Linha 8 (índice 7 no array)
    char coluna_inicial_d2 = 'H'; // Coluna inicial H
    int coluna_convertida_d2 = coluna_inicial_d2 - 'A'; // Convertendo char para int

    for(int i = 0; i < 3; i++) {
        // Verifica limites do tabuleiro
        if(linha_d2 - 1 + i >= 10 || coluna_convertida_d2 - i < 0) {
            printf("Erro: Navio 4 ultrapassa os limites do tabuleiro na posição (%d, %c)\n", linha_d2, coluna_inicial_d2 - i);
            return 1; // Sai do programa com erro
        }

        // Verifica sobreposição de navios
        if(tabuleiro[linha_d2 - 1 + i][coluna_convertida_d2 - i] != 0) {
            printf("Erro: Sobreposição de navios na posição (%d, %c)\n", linha_d2 + i, coluna_inicial_d2 - i);
            return 1; // Sai do programa com erro
        }
        tabuleiro[linha_d2 - 1 + i][coluna_convertida_d2 - i] = navio2[i];
    }

    // ===================================
    // Exibição do tabuleiro
    // ===================================
    printf(" TABULEIRO BATALHA NAVAL \n");
    printf("  ");
    for (int i = 0; i < 10; i++) {
        printf(" %c ", colunas[i]); // Exibindo as letras das colunas
        
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%2d", i + 1); // Exibindo os números das linhas
        for (int j = 0; j < 10; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }

        printf("\n");
    }



    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
