#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nivel Novato concluído
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
    int coluna_inicial_h = 'C';   // Coluna inicial C
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


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

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
