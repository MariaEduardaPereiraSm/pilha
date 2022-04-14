#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int dado;
    struct no *prox;
} No;
//
typedef struct pilha{
    int cont;
    No *topo;
} Pilha;

Pilha *create () { //Criação da Pilha
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    p->cont=0;
    return p;
}
int vazia(Pilha *p){ //Verifica se a pilha está vazia
     if(p->topo==NULL){
         return 1;
     }
     else{
         return 0;
     }
}

void push(Pilha*p, int elemento){ //Adiciona valores na pilha
    No *NovoNo = (No*) malloc(sizeof(No)); 
    NovoNo->dado = elemento;
    if(!(vazia(p))){ //Se a pilha estiver vazia o proximo elemento será o topo.
        NovoNo->prox = p->topo;
    }
    p->topo =NovoNo; //O topo da pilha será o novo nó
    p->cont++;
}

int pop(Pilha *p){ //Remover elementos
    if(!(vazia(p))){
        No *Nodel = p->topo; //O valor a ser removido é o topo, aqui fizemos uma copia do topo em Nodel.
        int dado = Nodel->dado; //guardamos o valor a ser removido
        p->topo = Nodel->prox;//Dizemos que o topo é o proximo valor daquele elemento que foi removido
        p->cont--;
        free(Nodel);//Libera o espaço na memória
        printf("\nDado %d removido com sucesso", dado);
        
    }
    else{
        printf("\nPilha Vazia");
        return -1;
    }
}
void imprimir(Pilha *p){
    No *aux = p->topo;
    if(aux==NULL){
            printf("\nA pilha está vazia");
    }
    else{
        printf("\nElementos da pilha a partir do Topo ");
        while(aux!=NULL){ //Enquanto o aux não for nulo o while roda
            printf("->%d ", aux->dado);
            aux = aux->prox;
        }
    }}
void pilhatopo(Pilha *p){
     No *aux = p->topo;
    printf("\nTopo da pilha -> %d",aux->dado);
}
void multiplospop(Pilha *p, int N){
    if(vazia(p)){
        printf("\nA pilha está vazia");
    }
    else if(N<=p->cont){
       for (size_t i = 0; i < N; i++)
       {
         if(!(vazia(p))){
        No *Nodel = p->topo; //O valor a ser removido é o topo, aqui fizemos uma copia do topo em Nodel.
        int dado = Nodel->dado; //guardamos o valor a ser removido
        p->topo = Nodel->prox;//Dizemos que o topo é o proximo valor daquele elemento que foi removido
        p->cont--;
        free(Nodel);//Libera o espaço na memória
        printf("\nDado %d removido com sucesso", dado);       
    }
       }
       
    }
    else{
        printf("\nO numero de elementos que se deseja desempilhar é maior que o número de elementos da pilha");
    }
}
int main(){
    Pilha *p = create();
    multiplospop(p,2);// Não há remoção pois a Pilha está Vazia
    push(p,1);
    push(p,10);
    push(p,18);
    push(p,100);
    pilhatopo(p);//100 é o topo da pilha
    imprimir(p);
    multiplospop(p,10); // N é maior que o número de elementos da pilha
    multiplospop(p,2); // Remove 100 e 18
    imprimir(p);
}