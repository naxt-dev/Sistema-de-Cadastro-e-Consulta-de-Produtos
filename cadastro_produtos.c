#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct produto{
    int codigo_produto;
    int qtd_estoque;
    char nome_produto[50];
    float preco_produto;
};

int main() {
    int menu, qtd_cadastro = 0;
    struct produto produtos[10];
    
    
    
    printf("------------::: Sistema de Cadastro e Consulta de Produtos :::------------\n");
    do{
        for(int cont=0;cont<1;cont++){
            printf("\n------::: Menu :::------\n\n");
            printf("1 - Cadastrar produto.\n2 - Listar produtos.\n3 - Sair.\n");
            printf("Escolha uma opção do menu: ");
            scanf("%d",&menu);
            getchar();
            if (menu > 3 || menu < 1){
                printf("\nOpção inválida, tente novamente.\n");
                cont--;
            }
        }
        
        
        
        switch (menu){ // Menu de opções
            case 1:  // Opção de cadastro de Produtos
            printf("\n\n\n------------::: Opção selecionada: Cadastro de produtos :::------------\n");
            for (int cont=0;cont<1;cont++){
                printf("\nEscolha quantos produtos quer cadastrar(numeros inteiros e não negativos): ");
                scanf("%d",&qtd_cadastro);
                getchar();
                if (qtd_cadastro < 0){
                    printf("\nQuantidade inválida, tente novamente com um numero inteiro e não negativo.\n");
                    cont--;
                }
            }
            
            for (int cont=0;cont<qtd_cadastro;cont++){
                printf("\n---::: %d° produto de %d:::---",cont + 1,qtd_cadastro);
                printf("\nDigite o nome do produto: ");
                fgets(produtos[cont].nome_produto,sizeof(produtos[cont].nome_produto),stdin);
                produtos[cont].nome_produto[strcspn(produtos[cont].nome_produto, "\n")] = '\0';
                printf("\nDigite o código do produto: ");
                scanf("%d",&produtos[cont].codigo_produto);
                getchar();
                printf("\nDigite o preço do produto: ");
                scanf("%f",&produtos[cont].preco_produto);
                getchar();
                printf("\nDigite a quantidade em estoque do produto: ");
                scanf("%d",&produtos[cont].qtd_estoque);
                getchar();
            }
            break;
            
            
            
            case 2: // Opção de listagem de produtos cadastrados
            printf("\n\n\n------------::: Opção selecionada: Lista de produtos cadastrados:::------------\n\n");
            
            if (qtd_cadastro<=0){
                printf("Não há produtos cadastrados ainda, utilize a opção 1 para cadastrar produtos.");
                printf("\n\n\n");
            } else {
                printf("------------::: Produtos cadastrados: %d :::------------",qtd_cadastro);
                for(int cont=0;cont<qtd_cadastro;cont++){
                    printf("\n\nNome do produto: %s",produtos[cont].nome_produto);
                    printf("\nCodigo do produto: %d",produtos[cont].codigo_produto);
                    printf("\nPreço do produto: R$ %.2f",produtos[cont].preco_produto);
                    printf("\nQuantidade em estoque do produto: %d",produtos[cont].qtd_estoque);
                    if (produtos[cont].qtd_estoque != 0 && produtos[cont].preco_produto != 0){
                        printf("\nValor total R$ em estoque: R$ %.2f",produtos[cont].qtd_estoque * produtos[cont].preco_produto);
                    } else {
                        printf("\nValor total R$ em estoque: R$ 0.00");
                    }
                }
            }
            printf("\n\n\n");
            break;
        }
        
        
        
    } while (menu != 3);
    
    printf("\n\n------------:::   Você selecionou sair do programa   :::------------");
    printf("\nPrograma encerrado.");

    return 0;
}
