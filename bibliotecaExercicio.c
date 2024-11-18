// exmeplo de uma biblioteca basico onde eu apenas tenho um CRUD simples, cadastrar;
// ler; modificar; deletar; create, read, update and delete.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_LIVROS 50
#define MAX_CARACTERES 100
#define SALVAR_ARQUIVO 'salvarArquivo.txt'

typedef struct
{
    char nome[MAX_CARACTERES];
    char autor[MAX_CARACTERES];
    int paginas;
    float preco;
} Livro;

Livro livro[TOTAL_LIVROS];
int totallivros = 0;

void cadastrarLivro()
{
    if (totallivros == TOTAL_LIVROS)
    {
        printf("Lista de livros cheia!\n");
        return;
    }

    Livro novoLivro;
    printf("Digite o nome do livro: ");
    scanf(" %[^\n]", novoLivro.nome);
    printf("Digite o autor do Livro: ");
    scanf(" %[^\n]", novoLivro.autor);
    printf("Quantidade de paginas: ");
    scanf(" %d", &novoLivro.paginas);
    printf("Qual o preco do Livro: ");
    scanf(" %f", &novoLivro.preco);

    livro[totallivros++] = novoLivro;
}

void mostrarLivros()
{
    system("cls");
    if (totallivros == 0)
    {
        printf("Nenhum livro cadastrado ainda!\n");
        return;
    }
    
    for (int i = 0; i < totallivros; i++)
    {
        printf("+++++++++++++++++++++++\n");
        printf("Livro %d\n", i+1);
        printf("Titulo: %s", livro[i].nome);
        printf("\nAutor: %s", livro[i].autor);
        printf("\nQuantidade de paginas: %d", livro[i].paginas);
        printf("\nPreco: %.2f\n", livro[i].preco);
    }
    return;
}

void modificarLivro(){
    char modificador[MAX_CARACTERES];
    printf("Qual o nome do livro que voce quer modificar: ");
    scanf(" %[^\n]", modificador);

    for (int i = 0; i < totallivros; i++)
    {
        if (strcmp(livro[i].nome, modificador) == 0)
        {
            printf("Novo nome do livro: ");
            scanf(" %[^\n]", livro[i].nome);
            printf("Novo autor do livro: ");
            scanf(" %[^\n]", livro[i].autor);
            printf("Novo n de pag do livro: ");
            scanf(" %d\n", &livro[i].paginas);
            printf("Novo preco do livro: ");
            scanf(" %f\n", &livro[i].preco);
        }
        
    }
    return;
}

void menuInicial(){
    int opcao;
    system("cls");    

    do {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Mostrar todos os livros\n");
        printf("3. Modificar informacoes\n");
        printf("4. Deletar\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarLivro();
                break;
            case 2:
                mostrarLivros();
                break;
            case 3:
                modificarLivro();
                break;
            case 4:
                //deletarLivro();
                break;
            case 5:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 5);
}

int main()
{   
    menuInicial();
    

    return 0;
}