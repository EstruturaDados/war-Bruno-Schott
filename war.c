#include <stdio.h>
#include <string.h>

// definição da struct territorio
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// funçao para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    // declaração do vetor de structs com capacidade para 5 territórios
    struct Territorio territorios[5];
    
    printf("=== SISTEMA DE CADASTRO DE TERRITORIOS ===\n");
    printf("Vamos cadastrar os 5 territorios iniciais.\n\n");
    
    
    for (int i = 0; i < 5; i++) {
        printf("Cadastrando territorio %d\n", i + 1);
        
        // nome do território
        printf("Nome do Territorio (max 30 caracteres): ");
        scanf("%29[^\n]", territorios[i].nome);
        limparBuffer();
        
        // cor do território
        printf("Cor do Exercito (max 10 caracteres): ");
        scanf("%9[^\n]", territorios[i].cor);
        limparBuffer();
        
        // numero de tropas
        printf("Numero de Tropas: ");
        scanf("%d", &territorios[i].tropas);
        limparBuffer();
        
        printf("\n");
    }
    
    // exibiçao dos dados cadastrados
    printf("=== TERRITORIOS CADASTRADOS ===\n\n");
    
    // percorrendo o vetor para exibir todos os territórios
    for (int i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("  Nome: %s\n", territorios[i].nome);
        printf("  Cor: %s\n", territorios[i].cor);
        printf("  Tropas: %d\n\n", territorios[i].tropas);
    }
    
    return 0;
}
