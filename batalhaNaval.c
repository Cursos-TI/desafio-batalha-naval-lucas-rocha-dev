#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nivel MESTRE
int main() {
    // Tabuleiro 10x10 inicializado com 0 (água)
    int tabuleiro[10][10] = {0};

    // Letras para cabeçalho das colunas
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Definição dos navios (tamanho 3)
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};
    int navio3[3] = {3, 3, 3};
    int navio4[3] = {3, 3, 3};

    // Definição das Matrizes de Habilidade (5x5)
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};


    // Construção da Matriz em Cone (Triângulo expandindo para baixo)
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
            // j >= (centro - i) e j <= (centro + i)
                if (j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1;
            }
        }
    }

    // Construção da Matriz em Cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) cruz[i][j] = 1;
        }
    }

    // Construção da Matriz em Octaedro (Losango)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Soma das distâncias ao centro (2,2)
            int dist_i = (i >= 2) ? i - 2 : 2 - i;
            int dist_j = (j >= 2) ? j - 2 : 2 - j;
            if (dist_i + dist_j <= 2) octaedro[i][j] = 1;
        }
    }

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
        tabuleiro[linha_d - 1 + i][coluna_convertida_d + i] = navio3[i];
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
        tabuleiro[linha_d2 - 1 + i][coluna_convertida_d2 - i] = navio4[i];
    }


    // ======================================
    // Sobreposição das Habilidades no Tabuleiro
    // ======================================
    // Pontos de Origem (Centro da matriz 5x5 no tabuleiro 10x10)
    int origemCone[2] = {2, 2};     // Topo superior esquerdo
    int origemCruz[2] = {5, 2};     // Meio esquerda
    int origemOcta[2] = {2, 7};     // Topo direita

    // Função de sobreposição lógica (aplicada via loops)
    // Para cada habilidade, percorremos a matriz 5x5 e somamos ao ponto de origem
    
    // Aplicando CONE
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int destinoL = origemCone[0] + (i - 2); // Centraliza a matriz no ponto
            int destinoC = origemCone[1] + (j - 2);
            // Verifica limites e se a matriz de habilidade tem efeito (1)
            if (destinoL >= 0 && destinoL < 10 && destinoC >= 0 && destinoC < 10) {
                if (cone[i][j] == 1) tabuleiro[destinoL][destinoC] = 5;
            }
        }
    }

    // Aplicando CRUZ
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int destinoL = origemCruz[0] + (i - 2);
            int destinoC = origemCruz[1] + (j - 2);
            if (destinoL >= 0 && destinoL < 10 && destinoC >= 0 && destinoC < 10) {
                if (cruz[i][j] == 1) tabuleiro[destinoL][destinoC] = 5;
            }
        }
    }

    // Aplicando OCTAEDRO
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int destinoL = origemOcta[0] + (i - 2);
            int destinoC = origemOcta[1] + (j - 2);
            if (destinoL >= 0 && destinoL < 10 && destinoC >= 0 && destinoC < 10) {
                if (octaedro[i][j] == 1) tabuleiro[destinoL][destinoC] = 5;
            }
        }
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

    return 0;
}
