#include <iostream>
#include <stdlib.h>
#include <locale.h>
//////PILHA//////
using namespace std;

struct valor{
    int num;
    struct valor *prox;
}valor;

typedef struct valor* Pilha;
typedef struct valor Elem;

Pilha* cria_Pilha(){
    Pilha* pi = new Pilha;
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void limpa_Pilha(Pilha* pi){
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

int inserir_Pilha(Pilha* pi, int valor){
    if(pi == NULL)
        return 0;
    Elem* no;
    no = new Elem;
    if(no == NULL)
        return 0;
    no->num = valor;
    no->prox = (*pi);
    *pi = no;
    return 1;
    cout << "\n";
}

int remove_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    cout << "\n";
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
    if(pi == NULL){
        cout << "Vazio Porra";}
    Elem* no = *pi;
    while(no != NULL){
        cout << no->num << endl;
        no = no->prox;
    }
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    int valor,insere,tamanho,remover,op;

    Pilha *pi=cria_Pilha();
    do{
    cout << "1 - Inserir na pilha\n2 - Listar\n3 - Remover\n4 - Sair\n";
    cout <<"Opcao:";
    cin >> op;
    switch(op){

        case(1):
            cout << "Insira o valor:\n";
            cin >> valor;
            insere= inserir_Pilha(pi,valor);
            break;

        case(2):
        cout << "Pilha:\n";
        imprime_Pilha(pi);

        break;

        case(3):
            remover = remove_Pilha(pi);
            if (remover == 0){
                cout << "tomar no cu";}
        break;

        case(4):
            cout << "Obrigado por usar essa merda.";
        break;

        default:
            cout << "Opção inválida seu animal!!!!\n";
        break;
    }
    }while(op!=4);
    return 0;
}
