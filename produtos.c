#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#define tamanho_descricao 30
#define tamanho_catalogo 10
enum Categorias{ELETRODOMESTICO=1, FERRAMENTA, VESTUARIO};
typedef struct{
    int codigo;
    char descricao[tamanho_descricao];
    int estoque;
    enum Categorias categorias;
}produto;
produto vector[tamanho_catalogo];
void IHC_listar_catalogo(){
    for (int i=0; i<tamanho_catalogo; i++){
        printf("%d\nDESCRICAO: %s\nESTOQUE: %d\nTIPO: %d\n\n",vector[i].codigo, vector[i].descricao, 
        vector[i].estoque, vector[i].categorias);
    }
}
bool IHC_inserir_produto(produto*vector, int counter, int c){
    if((c<1) || (c>3)){
        return false;
    }
    else{
        vector[counter].codigo=(counter+1);
        vector[counter].categorias=c;
        fflush(stdin);
        printf("Digite a descricao do produto que quer adicionar:\n");
        fgets(vector[counter].descricao, tamanho_descricao, stdin);
        vector[counter].descricao[strcspn(vector[counter].descricao,"\n")]=0;
        return true;
    }
}
bool IHC_remover_produto(produto*vector, int code){
    if ((code<=0) || (code>10)){
        return false;
    }
    else{
        for (int i=code; i<(tamanho_catalogo-1); i++){
            vector[i-1]=vector[i];
        }
        return true;
    }
}
bool IHC_atualizar_estoque(produto*vector, int code, int quantidade){
    if ((code<=0) || (code>10)){
        return false;
    }
    else{
        printf("Digite a quantidade do estoque:\n");
        scanf("%d", &quantidade);
        for(int i=0; i<tamanho_catalogo; i++){
            if ((vector[i].codigo==code)){
                vector[i].estoque=quantidade;
                return true;
            }
        }
    }
}
bool IHC_aumentar_estoque(produto*vector, int code, int quantidade){
    if ((code<=0) || (code>10)){
        return false;
    }
    else{
        printf("Digite a quantidade do estoque:\n");
        scanf("%d", &quantidade);
        for (int i=0; i<tamanho_catalogo; i++){
            if((vector[i].codigo==code) && (quantidade>vector[i].estoque)){
                vector[i].estoque=quantidade;
                printf("Atualizacao concluida.\n");
                return true;
            }
            else if (i==tamanho_catalogo-1){
                return false;
            }
        }
    }
}
bool IHC_diminuir_estoque(produto*vector, int code, int quantidade){
    if ((code<=0) || (code>10)){
        return false;
        }
    else{
        printf("Digite a quantidade do estoque:\n");
        scanf("%d", &quantidade);
        for (int i=0; i<tamanho_catalogo; i++){
            if((vector[i].codigo==code) && (quantidade<vector[i].estoque)){
                vector[i].estoque=quantidade;
                printf("Atualizacao concluida.\n");
                return true;
                }
            else if (i==tamanho_catalogo-1){
                return false;
            }
        }
    }
}
int main(){
    int operacao, counter=0, v=0, c=0, code=0, quantidade=0;
    while (v!=1){
        printf("\nDIGITE O VALOR DA OPERACAO, SENDO 1=LISTAR CATALOGO, 2=INSERIR PRODUTO, 3=REMOVER PRODUTO, "
        "4=ATUALIZAR ESTOQUE, 5=AUMENTAR ESTOQUE E 6=DIMINUIR ESTOQUE. QUALQUER OUTRA ENTRADA=SAIR:\n");
        scanf("%d", &operacao);
        switch(operacao){
            case(1):
            IHC_listar_catalogo();
            break;
            case(2):
            printf("Digite a categoria do produto, 1=eletrodomestico, 2=ferramenta e 3=vestuario:\n");
            scanf("%d", &c);
            if (IHC_inserir_produto(vector, counter, c)){
                counter++;
            }
            else{
                printf("Valor invalido, verifique a categoria.\n");
            }
            break;
            case(3):
            printf("Digite o codigo do produto que deseja remover:\n");
            scanf("%d", &code);
            if(IHC_remover_produto(vector, code)==false){
                printf("Codigo invalido, verifique se o produto existe");
            }
            else{
                printf("Produto removido!\n");
            }
            break;
            case(4):
            printf("Digite o codigo do produto que deseja editar o estoque:\n");
            scanf("%d", &code);
            if (IHC_atualizar_estoque(vector, code, quantidade)==false){
                printf("Algo deu errado, verifique se o produto com o codigo %d existe\n", code);
            }
            else{
                printf("Estoque atualizado com sucesso!\n");
            }
            break;
            case(5):
            printf("Digite o codigo do produto que voce quer editar:\n");
            scanf("%d", &code);
            if(IHC_aumentar_estoque(vector, code, quantidade)==false){
                printf("Codigo invalido, produto sem estoque anterior ou valor digitado menor que o anterior.\n");
            }
            break;
            case(6):
            printf("Digite o codigo do produto que voce quer editar:\n");
            scanf("%d", &code);
            if(IHC_diminuir_estoque(vector, code, quantidade)==false){
                printf("Codigo invalido, produto sem estoque anterior ou valor digitado maior que o anterior.\n");
            }
            break;
            default:
            printf("operação invalida, saindo do programa");
            v=1;
            break;
        scanf("%d");
        }
    }
    return 0;
}