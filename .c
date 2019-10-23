#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct elemento{
    int num;
    struct elemento *prox;
};

typedef struct elemento* Pilha;
typedef struct elemento Elem;

Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_Pilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int insere_Pilha(Pilha* pi, int valor){
    if(pi == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->num = valor;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int remove_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL){
        return 0;}
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    Elem* no = *pi;
    while(no != NULL){
        printf("%d\n",no->num);
        no = no->prox;
    }
}

int main(){
    int valor,insere,tamanho,remover,opt;

    Pilha *pi=cria_Pilha();
    do{
    printf("0. Sair:\n");
    printf("1. Listar pilha:\n");
    printf("2. Inserir na pilha:\n");
    printf("3. Remover da pilha:\n");
    printf("4. Tamanho da pilha:\n");
    printf("opcao:");
    scanf("%i",&opt);
    switch(opt){
        case(0):
        break;
        case(1):
        printf("pilha:\n");
        imprime_Pilha(pi);
        break;
        case(2):
            printf("entre com um numero:\n");
            scanf("%i",&valor);
            insere= insere_Pilha(pi,valor);
            printf("inserido com sucesso!\n");
        break;;
        case(3):
            remover = remove_Pilha(pi);
            if (remover == 0){
                printf("tomar no cu");}
            printf("Removido com sucesso!\n");
        break;
        case(4):
            tamanho= tamanho_Pilha(pi);
            printf("Quantidade de elementos da pilha:%d\n",tamanho);
        break;
        default:
            printf("opicao invalida!\n");
        break;
    }
    }while(opt!=0);
    return 0;
}
