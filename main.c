#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
typedef struct {
    char nome[31];        // '\0'
    char idade[3];        // '\0'
    char cpf[15];         // "xxx.xxx.xxx-xx" + '\0'
    char telefone[15];    // "(xx)xxxxx-xxxx" + '\0'
    char prioridade[11];  // '\0'
    char tomou_vacina[4]; // "Sim" ou "Nao" + '\0'
    char data_vacina[11]; // formato "DD/MM/AAAA" + '\0'
} Funcao;

/**
 * Buscar registro na lista pelo CPF
 * ----------------------------------
 * Percorre um array de Funcao comparando o campo 'cpf' de cada elemento
 * com a string fornecida. Se encontrar, retorna o índice; senão retorna -1.
 *
 * Parâmetros:
 *   lista     - ponteiro para o primeiro elemento do array de Funcao
 *   quantidade- número de elementos válidos no array
 *   cpf_busca - string contendo o CPF a ser buscado
 *
 * Retorno:
 *   índice i (0 ≤ i < quantidade) se encontrou; -1 caso contrário
 */
int buscarPorCPF(Funcao *lista, int quantidade, const char *cpf_busca) {
    // percorre todos os registros
    for (int i = 0; i < quantidade; i++) {
        // strcmp retorna 0 se strings forem idênticas
        if (strcmp(lista[i].cpf, cpf_busca) == 0) {
            return i;  // encontrado, retorna posição
        }
    }
    return -1;  // não encontrou
}

/**
 * Editar campos de um registro
 * --------------------------------------
 * Para cada campo textual do registro, exibe o valor atual e
 * faz uma nova leitura com fgets(). Se o usuário apertar apenas ENTER,
 * mantém o valor anterior; caso contrário, atualiza.
 *
 * Parâmetros:
 *   f - ponteiro para o registro de Funcao a ser editado
 *
 * Observações:
 *   - usamos um buffer local de 64 bytes para ler a linha inteira,
 *     independente do tamanho final do campo na struct.
 *   - strcspn(buffer, "\n") localiza o '\n' e o substitui por '\0'.
 *   - strncpy garante que a cópia não ultrapasse o tamanho do campo,
 *     evitando overflow. Ao final, asseguramos terminação nula.
 */
void editarRegistro(Funcao *f) {
    char buffer[64];  // buffer para leitura de linha completa

    // 1) Editar nome
    printf("Nome atual     : %s\n", f->nome);
    printf("Novo nome (ENTER para manter): ");
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] != '\n') {  // se o usuário digitou algo
        buffer[strcspn(buffer, "\n")] = '\0';  // remove '\n'
        strncpy(f->nome, buffer, sizeof(f->nome)-1);
        f->nome[sizeof(f->nome)-1] = '\0';     // garante terminação nula
    }

    // 2) Editar idade
    printf("Idade atual    : %s\n", f->idade);
    printf("Nova idade (ENTER para manter): ");
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] != '\n') {
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(f->idade, buffer, sizeof(f->idade)-1);
        f->idade[sizeof(f->idade)-1] = '\0';
    }

    // 3) Editar telefone
    printf("Telefone atual : %s\n", f->telefone);
    printf("Novo telefone (ENTER para manter): ");
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] != '\n') {
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(f->telefone, buffer, sizeof(f->telefone)-1);
        f->telefone[sizeof(f->telefone)-1] = '\0';
    }

    // 4) Editar prioridade
    printf("Prioridade atual: %s\n", f->prioridade);
    printf("Nova prioridade (ENTER para manter): ");
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] != '\n') {
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(f->prioridade, buffer, sizeof(f->prioridade)-1);
        f->prioridade[sizeof(f->prioridade)-1] = '\0';
    }

    // 5) Editar tomou vacina
    printf("Tomou vacina? (atual: %s)\n", f->tomou_vacina);
    printf("Resposta [Sim/Não] (ENTER para manter): ");
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] != '\n') {
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(f->tomou_vacina, buffer, sizeof(f->tomou_vacina)-1);
        f->tomou_vacina[sizeof(f->tomou_vacina)-1] = '\0';
    }

    // 6) Editar data da vacina
    printf("Data da vacina (DD/MM/AAAA) (atual: %s)\n", f->data_vacina);
    printf("Nova data (ENTER para manter): ");
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] != '\n') {
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(f->data_vacina, buffer, sizeof(f->data_vacina)-1);
        f->data_vacina[sizeof(f->data_vacina)-1] = '\0';
    }

    printf("\n Registro atualizado com sucesso! \n\n");
}


int main() {
    setlocale(LC_ALL,"Portuguese_Brazil");

    return 0;
}
