#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// definição da struct Territorio
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// função para cadastrar os territórios
void cadastrarTerritorios(struct Territorio *mapa, int totalTerritorios) {
    printf("Vamos cadastrar os %d territorios do nosso mundo.\n", totalTerritorios);
    
    for (int i = 0; i < totalTerritorios; i++) {
        printf("\nCadastrando territorio %d\n", i + 1);
        
        printf("Nome do Territorio: ");
        scanf("%29[^\n]", mapa[i].nome);
        limparBuffer();
        
        printf("Cor do Exercito: ");
        scanf("%9[^\n]", mapa[i].cor);
        limparBuffer();
        
        printf("Numero de Tropas: ");
        scanf("%d", &mapa[i].tropas);
        limparBuffer();
    }
}

// função para exibir o mapa atual
void exibirMapa(struct Territorio *mapa, int totalTerritorios) {
    printf("\n=== MAPA DO MUNDO - ESTADO ATUAL ===\n");
    printf("------------------------------------\n");
    
    for (int i = 0; i < totalTerritorios; i++) {
        printf("%d. %s (Exercito %s, Tropas: %d)\n", 
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
    printf("------------------------------------\n");
}

// função de ataque entre territórios
void atacar(struct Territorio* atacante, struct Territorio* defensor) {
    printf("\n--- FASE DE ATAQUE ---\n");
    
    // simulação dos dados de batalha
    int dadoAtacante = (rand() % 6) + 1; // 1 a 6
    int dadoDefensor = (rand() % 6) + 1; // 1 a 6
    
    printf("O atacante %s rolou um dado e tirou: %d\n", atacante->nome, dadoAtacante);
    printf("O defensor %s rolou um dado e tirou: %d\n", defensor->nome, dadoDefensor);
    
    if (dadoAtacante > dadoDefensor) {
        // vitória do atacante
        printf("VITORIA DO ATAQUE! O defensor perdeu 1 tropa.\n");
        
        defensor->tropas--;
        
        // se o defensor ficou sem tropas, o território é conquistado
        if (defensor->tropas <= 0) {
            printf("CONQUISTA! %s agora pertence ao exercito %s!\n", 
                   defensor->nome, atacante->cor);
            
            // transfere metade das tropas do atacante para o defensor
            defensor->tropas = atacante->tropas / 2;
            atacante->tropas -= defensor->tropas;
            
            // muda a cor do território conquistado
            strcpy(defensor->cor, atacante->cor);
        }
    } else if (dadoAtacante < dadoDefensor) {
        // vitória do defensor
        printf("VITORIA DA DEFESA! O atacante perdeu 1 tropa.\n");
        atacante->tropas--;
    } else {
        // empate - ambos perdem 1 tropa
        printf("EMPATE! Ambos os exercitos perderam 1 tropa.\n");
        atacante->tropas--;
        defensor->tropas--;
    }
}

// função para liberar a memória alocada
void liberarMemoria(struct Territorio* mapa) {
    free(mapa);
    printf("Memoria liberada com sucesso!\n");
}

// função para verificar se um ataque é válido
int ataqueValido(struct Territorio* atacante, struct Territorio* defensor, int indiceAtacante, int indiceDefensor, int totalTerritorios) {
    if (indiceAtacante < 0 || indiceAtacante >= totalTerritorios) {
        printf("Territorio atacante invalido!\n");
        return 0;
    }
    
    if (indiceDefensor < 0 || indiceDefensor >= totalTerritorios) {
        printf("Territorio defensor invalido!\n");
        return 0;
    }
    
    if (indiceAtacante == indiceDefensor) {
        printf("Nao pode atacar o proprio territorio!\n");
        return 0;
    }
    
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("Nao pode atacar um territorio da mesma cor!\n");
        return 0;
    }
    
    if (atacante->tropas <= 1) {
        printf("Territorio atacante precisa ter pelo menos 2 tropas!\n");
        return 0;
    }
    
    return 1;
}

int main() {
    // inicializar a semente para numeros aleatórios
    srand(time(NULL));
    
    struct Territorio *mapa;
    int totalTerritorios;
    int opcao;
    
    printf("=== SISTEMA DE BATALHA DE TERRITORIOS ===\n");
    
    // solicitar o número total de territórios
    printf("Quantos territorios deseja cadastrar? ");
    scanf("%d", &totalTerritorios);
    limparBuffer();
    
    if (totalTerritorios <= 0) {
        printf("Numero de territorios deve ser maior que zero!\n");
        return 1;
    }
    
    // alocação dinâmica de memória para os territórios
    mapa = (struct Territorio*)calloc(totalTerritorios, sizeof(struct Territorio));
    
    if (mapa == NULL) {
        printf("Erro: Falha ao alocar memoria!\n");
        return 1;
    }
    
    // cadastrar os territórios
    cadastrarTerritorios(mapa, totalTerritorios);
    
    // loop principal do jogo
    do {
        exibirMapa(mapa, totalTerritorios);
        
        printf("\n--- FASE DE ATAQUE ---\n");
        printf("Escolha o territorio atacante (1 a %d, ou 0 para sair): ", totalTerritorios);
        scanf("%d", &opcao);
        limparBuffer();
        
        if (opcao == 0) {
            break;
        }
        
        int indiceAtacante = opcao - 1;
        
        if (indiceAtacante < 0 || indiceAtacante >= totalTerritorios) {
            printf("Territorio invalido!\n");
            continue;
        }
        
        printf("Escolha o territorio defensor (1 a %d): ", totalTerritorios);
        scanf("%d", &opcao);
        limparBuffer();
        
        int indiceDefensor = opcao - 1;
        
        // validar o ataque
        if (ataqueValido(&mapa[indiceAtacante], &mapa[indiceDefensor], 
                        indiceAtacante, indiceDefensor, totalTerritorios)) {
            
            // realizar o ataque
            atacar(&mapa[indiceAtacante], &mapa[indiceDefensor]);
            
            // exibir resultado atualizado
            printf("\n--- RESULTADO ATUALIZADO ---\n");
            printf("Atacante: %s (Tropas: %d)\n", 
                   mapa[indiceAtacante].nome, mapa[indiceAtacante].tropas);
            printf("Defensor: %s (Tropas: %d)\n", 
                   mapa[indiceDefensor].nome, mapa[indiceDefensor].tropas);
        }
        
        // verificar se algum jogador venceu (tem todos os territórios da mesma cor)
        int vitoria = 1;
        char corVencedor[10];
        strcpy(corVencedor, mapa[0].cor);
        
        for (int i = 1; i < totalTerritorios; i++) {
            if (strcmp(mapa[i].cor, corVencedor) != 0) {
                vitoria = 0;
                break;
            }
        }
        
        if (vitoria) {
            printf("\n=== FIM DE JOGO ===\n");
            printf("O exercito %s conquistou todos os territorios!\n", corVencedor);
            break;
        }
        
        printf("\nPressione Enter para continuar para o proximo turno...");
        limparBuffer();
        
    } while (1);
    
    // liberar memória alocada
    liberarMemoria(mapa);
    
    printf("Jogo encerrado. Obrigado por jogar!\n");
    return 0;
}
