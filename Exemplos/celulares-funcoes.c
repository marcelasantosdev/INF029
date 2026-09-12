#include <stdio.h>
#define TAM_CELULARES 3

#define CADASTRO_SUCESSO -1
#define CADASTRO_ERRO -2
#define NAO_ENCONTRADO -3
#define ATUALIZACAO_SUCESSO -4
#define LISTA_VAZIA -5
#define DELETAR_SUCESSO -6


typedef struct{
    int id;
    int ano;
    float preco;
}Celular;

int menu_com_retorno_e_paramentros(int tipo);
int menu_com_retorno();
void menu_vendas();
void menu_cadastros();
int cadastrarCelular(Celular listaCelulares[], int idAtual, int qtdCelulares);
void listarCelulares(Celular listaCelulares[], int qtdCelulares);
int atualizarCelulares(Celular listaCelulares[], int qtdCelulares);
int deletarCelular(int qtdCelulares);


int main(){
    Celular listaCelulares[TAM_CELULARES];

    int sair = 0;
    int idAtual = 1;
    int qtdCelulares = 0;
    while(!sair){ //sair == 0
        int opcao;
        opcao = menu_com_retorno_e_paramentros(1);

        switch (opcao){
            case 0: {
                sair = 1;
                break;
            }
            case 1: {
                int resultado = cadastrarCelular(listaCelulares, idAtual, qtdCelulares);
                if (resultado == CADASTRO_SUCESSO){
                    qtdCelulares++;
                    idAtual++;
                    printf("Cadastro realizado com sucesso\n");
                }

                break;
            }
            case 2: {
                printf("Lista Celulares\n");
                
                listarCelulares(listaCelulares, qtdCelulares);

                break;
            }
            case 3: {
                int retorno = atualizarCelulares(listaCelulares, qtdCelulares);
                if (retorno == NAO_ENCONTRADO) printf("Celular não encontrado!\n");
                else if (retorno == ATUALIZACAO_SUCESSO) printf("Celular atualizado com sucesso \n");

                break;
            }
            case 4: {
                printf("Deletar");
                int retorno = deletarCelular(qtdCelulares);
                if (retorno == LISTA_VAZIA) printf("Não existem celulares cadastrados!\n");
                else if (retorno == DELETAR_SUCESSO) {
                    printf("Exclusão realizada com sucesso!\n");
                    qtdCelulares--;
                }
                
                break;
            }
            default: printf("Opção Inválida");
        }

    }

}


void menu_cadastros(){
    printf("Digite a opção: \n");
    printf("0 - Sair \n");
    printf("1 - Inserir \n");
    printf("2 - Listar \n");
    printf("3 - Atualizar \n");
    printf("4 - Deletar \n");

}

void menu_vendas(){
    printf("Digite a opção: \n");
    printf("0 - Sair \n");
    printf("1 - Comprar \n");
    printf("2 - Ver preços \n");
    printf("3 - Pagar \n");
    printf("4 - Financiar \n");

}

int menu_com_retorno(){
    menu_cadastros();

    int op;

    scanf("%d", &op);

    return op;
}

int menu_com_retorno_e_paramentros(int tipo){

    if (tipo == 1)
        menu_cadastros();
    else if (tipo == 2)
        menu_vendas();

    int op;

    scanf("%d", &op);

    return op;
}

int cadastrarCelular(Celular listaCelulares[], int idAtual, int qtdCelulares){
    printf("Digite o ano: ");
    scanf("%d", &listaCelulares[qtdCelulares].ano);
    printf("Digite o Preço: ");
    scanf("%f", &listaCelulares[qtdCelulares].preco);
    listaCelulares[qtdCelulares].id = idAtual;
    
    return CADASTRO_SUCESSO;
    
    
}

void listarCelulares(Celular listaCelulares[], int qtdCelulares){
    printf("Lista Celulares\n");

    for (int i = 0; i < qtdCelulares; i++)
        printf("%d - %d - %f\n", listaCelulares[i].id, listaCelulares[i].ano, listaCelulares[i].preco);

}


int atualizarCelulares(Celular listaCelulares[], int qtdCelulares){

    listarCelulares(listaCelulares, qtdCelulares);

    printf("Digite o id do celular: \n");
    int id;
    scanf("%d", &id);
    int achou = 0;
    for (int i = 0; i < qtdCelulares; i++){
        if (id == listaCelulares[i].id){
            printf("Digite o ano: ");
            scanf("%d", &listaCelulares[i].ano);
            printf("Digite o Preço: ");
            scanf("%f", &listaCelulares[i].preco);
            achou = 1;
            break;
        }
    }
    if (!achou) return NAO_ENCONTRADO;
    else return ATUALIZACAO_SUCESSO;


}

int deletarCelular(int qtdCelulares){
    if (qtdCelulares == 0) return LISTA_VAZIA;
    else return DELETAR_SUCESSO;
}