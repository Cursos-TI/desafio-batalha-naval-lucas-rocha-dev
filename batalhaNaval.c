#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nivel Novato concluído
int main() {
    int tabuleiro[10][10] = {0};
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};


    // Navio 1 - Horizontal na linha 3, coluna E
    int linha_selecionada = 3;
    int coluna_selecionada = 'E'; 
    char coluna_selecionada_convertida = coluna_selecionada - 'A'; // Convertendo char para int

    for(int i = 0; i < 3; i++) {
        tabuleiro[linha_selecionada - 1][coluna_selecionada_convertida + i] = navio1[i];
    }

    // Navio 2 - Vertical na linha 6, coluna B
    linha_selecionada = 6;
    coluna_selecionada = 'B'; 
    coluna_selecionada_convertida = coluna_selecionada - 'A'; // Convertendo char para int
    for(int i = 0; i < 3; i++) {
        tabuleiro[linha_selecionada - 1 + i][coluna_selecionada_convertida] = navio2[i];
    }


    // Exibição do tabuleiro
    printf(" TABULEIRO BATALHA NAVAL \n");
    printf(" ");
    for (int i = 0; i < 10; i++) {
        printf(" %c ", colunas[i]); // Exibindo as letras das colunas
        
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%d", i + 1); // Exibindo os números das linhas

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
