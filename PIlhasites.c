
//Criar uma pilha de sites
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct no{
    char* valor;
    struct no *prox;
} No;

typedef struct pilha{
    int cont;
    No *topo;
} Pilha;

Pilha *create(){ //Criando a pilha
        Pilha *p = (Pilha*) malloc(sizeof(Pilha));
        p->topo=NULL;
        p->cont =0;
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
int verifica(Pilha p, char*elemento){
    while(p.topo !=NULL){ 
        if(strcmp(p.topo->valor, elemento)==0){//Compara os valores
            return 0;
        }
        p.topo = p.topo->prox; //Avança o topo
    }
    return 1;//Retorna verdadeiro caso não haja elemento igual
}

void push(Pilha *p, char* elemento){ //Adiciona valores na pilha
    No *NovoNo = (No*) malloc(sizeof(No)); 
    NovoNo->valor = elemento;  
    
    if(vazia(p)){ //Se a pilha estiver vazia o proximo elemento será o topo.
        p->topo =NovoNo;
        p->cont++;
        return;
    }
    if(verifica(*p,elemento)==1){
        NovoNo->prox = p->topo; //O próximo será o antigo topo
        p->topo =NovoNo; //O novo topo será o novo nó
        p->cont++;
    }
}

void imprimir(Pilha p){
    if(p.topo == NULL){
        printf("A pilha está vazia\n");
    }
    else{
        printf("(Topo)-> ");
        while(p.topo !=NULL){ //Enquanto o aux não for nulo o while roda
            printf("%s -> ", p.topo->valor);
            p.topo = p.topo->prox;
        }
        printf("\n");
    }
}
char pop(Pilha *p){ //Remover elementos
    if(!(vazia(p))){
        No *Nodel = p->topo; //O valor a ser removido é o topo, aqui fizemos uma copia do topo em Nodel.
        char dado = Nodel->valor; //guardamos o valor a ser removido
        p->topo = Nodel->prox;//Dizemos que o topo é o proximo valor daquele elemento que foi removido
        p->cont--;
        free(Nodel);//Libera o espaço na memória
        return dado;
    }
    else{
        printf("Pilha Vazia\n");
        return -1;
    }
}
int main(){
    Pilha *p = create();
    push(p,"Duda");
    push(p,"Estrutura");
    push(p,"Duda");
    push(p,"Algoritmos");
    imprimir(*p);
    pop(p);
    imprimir(*p);    
    return 1;
}
