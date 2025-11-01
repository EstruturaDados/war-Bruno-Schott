#include <stdio.h>
#include <string.h> // Para usar strcspn

// Função para limpar o buffer de entrada
void limparBuffer() {
    while (getchar() != '\n');
}

int main() {
    char territorio1[50], territorio2[50], territorio3[50], territorio4[50], territorio5[50];
    char cor1[50], cor2[50], cor3[50], cor4[50], cor5[50];
    int tropas1, tropas2, tropas3, tropas4, tropas5;

    printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo.\n");
    
    // Território 1
    printf("\nCadastrando territorio 1\n");
    printf("Nome do Territorio: ");
    scanf("%[^\n]", territorio1);
    limparBuffer();
    
    printf("Cor do Territorio: ");
    scanf("%[^\n]", cor1);
    limparBuffer();
    
    printf("Numero de Tropas: ");
    scanf("%d", &tropas1);
    limparBuffer();
    
    // Território 2
    printf("\nCadastrando territorio 2\n");
    printf("Nome do Territorio: ");
    scanf("%[^\n]", territorio2);
    limparBuffer();
    
    printf("Cor do Territorio: ");
    scanf("%[^\n]", cor2);
    limparBuffer();
    
    printf("Numero de Tropas: ");
    scanf("%d", &tropas2);
    limparBuffer();
    
    // Território 3
    printf("\nCadastrando territorio 3\n");
    printf("Nome do Territorio: ");
    scanf("%[^\n]", territorio3);
    limparBuffer();
    
    printf("Cor do Territorio: ");
    scanf("%[^\n]", cor3);
    limparBuffer();
    
    printf("Numero de Tropas: ");
    scanf("%d", &tropas3);
    limparBuffer();
    
    // Território 4
    printf("\nCadastrando territorio 4\n");
    printf("Nome do Territorio: ");
    scanf("%[^\n]", territorio4);
    limparBuffer();
    
    printf("Cor do Territorio: ");
    scanf("%[^\n]", cor4);
    limparBuffer();
    
    printf("Numero de Tropas: ");
    scanf("%d", &tropas4);
    limparBuffer();
    
    // Território 5
    printf("\nCadastrando territorio 5\n");
    printf("Nome do Territorio: ");
    scanf("%[^\n]", territorio5);
    limparBuffer();
    
    printf("Cor do Territorio: ");
    scanf("%[^\n]", cor5);
    limparBuffer();
    
    printf("Numero de Tropas: ");
    scanf("%d", &tropas5);
    limparBuffer();
    
    // Exibindo os dados cadastrados
    printf("\n=== TERRITORIOS CADASTRADOS ===\n");
    printf("\n");

    // Território 1
    printf("Territorio 1:\n");
    printf("Nome: %s\n", territorio1);
    printf("Cor: %s\n", cor1);
    printf("Tropas: %d\n\n", tropas1);
    
    // Território 2
    printf("Territorio 2:\n");
    printf("Nome: %s\n", territorio2);
    printf("Cor: %s\n", cor2);
    printf("Tropas: %d\n\n", tropas2);
    
    // Território 3
    printf("Territorio 3:\n");
    printf("Nome: %s\n", territorio3);
    printf("Cor: %s\n", cor3);
    printf("Tropas: %d\n\n", tropas3);
    
    // Território 4
    printf("Territorio 4:\n");
    printf("Nome: %s\n", territorio4);
    printf("Cor: %s\n", cor4);
    printf("Tropas: %d\n\n", tropas4);
    
    // Território 5
    printf("Territorio 5:\n");
    printf("Nome: %s\n", territorio5);
    printf("Cor: %s\n", cor5);
    printf("Tropas: %d\n", tropas5);
    
    return 0;
}
