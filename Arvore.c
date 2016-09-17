#include <stdlib.h>
#include <stdio.h>
#include "Arvore.h"

Arvore *alocaNo()
{
    return (Arvore*)malloc(sizeof(Arvore));
}

Arvore *inserirRaiz(int chave)
{
    Arvore *raiz = alocaNo();
    raiz->chave = chave;
    raiz->pai = NULL;
    raiz->esquerda = NULL;
    raiz->direita = NULL;
    
    return raiz;
}

void excluir(Arvore *ptr,int chave)
{
    Arvore *tmp,*z,*noAux;
    
    if(ptr){
        
        if(tmp = buscar(ptr,chave)){
            
            if(tmp == ptr){ //RAIZ
                
                z = ptr->direita;
                z->pai = NULL;
                
                while(z->esquerda)
                    z = z->esquerda;
                
                z->esquerda = ptr->esquerda;
                raiz = ptr->direita;
                free(ptr);
            }
            else if((ptr->esquerda) && (ptr->direita)){ //Se o nó possuir os 2 filhos
                
                tmp = ptr->pai;
                tmp->direita = ptr->direita;
                noAux = ptr->direita;
                noAux ->pai = tmp;
                
                z = tmp->direita;
                
                while(z->esquerda)
                    z = z->esquerda;
                
                z->esquerda = ptr->esquerda;
                
                free(ptr);
            }
            else if((ptr->esquerda) && (!ptr->direita)){//Se o nó possuir apenas o filho a esquerda
             tmp = ptr->pai;
             tmp->esquerda = ptr->esquerda;
             noAux = ptr->esquerda;
             noAux->pai = tmp;
             
             free(ptr);
            }
            
        }
        else
            printf("Nao encontrado !\n");
    }
}

int contaPares(Arvore *ptr,int cont)
{  
   if(ptr){
       if(ptr->chave %2 == 0)
           contaPares(ptr->esquerda,cont+1);
       else{
           contaPares(ptr->esquerda);
           contaPares(ptr->direita);
       }
           
   }
   
   return cont;
}

void inserir(Arvore *ptrArvore,int chave)
{
    Arvore *novoNo;
    
    if(chave > ptrArvore->chave){
        
        if(ptrArvore->direita)
            inserir(ptrArvore->direita,chave);
        else{
            novoNo = alocaNo();
            novoNo->chave = chave;
            novoNo->pai = ptrArvore;
            novoNo->direita = NULL;
            novoNo->esquerda = NULL;
            
            ptrArvore->direita = novoNo;
        }
    }
    else{
        if(ptrArvore->esquerda)
            inserir(ptrArvore->esquerda,chave);
        else{
            novoNo = alocaNo();
            novoNo->chave = chave;
            novoNo->pai = ptrArvore;
            novoNo->direita = NULL;
            novoNo->esquerda = NULL;
            
            ptrArvore->esquerda = novoNo;
        }
    }
}

Arvore *buscar(Arvore *ptrArvore,int chave)
{
    if(ptrArvore){
        if(ptrArvore->chave == chave){
            printf("Chave '%d' encontrada !\n",chave);
            return ptrArvore;
        }
        else if(chave > ptrArvore->chave)
           return buscar(ptrArvore->direita,chave);
        else
           return buscar(ptrArvore->esquerda,chave);
    }
    else
        return NULL;
}

void preOrdem(Arvore *ptr)
{
    if(ptr){
        printf("%d ",ptr->chave);
        preOrdem(ptr->esquerda);
        preOrdem(ptr->direita);
    }
}

void posOrdem(Arvore *ptr)
{
    if(ptr){
        posOrdem(ptr->esquerda);
        posOrdem(ptr->direita);
        printf("%d ",ptr->chave);
    }
}

void ordem(Arvore *ptr)
{
    if(ptr){
        ordem(ptr->esquerda);
        printf("%d ",ptr->chave);
        ordem(ptr->direita);
    }
}

void menu()
{
    Arvore *aux;
    int i,opc = 1,chave,nChaves;
    
    while(opc != 0){
        printf("1- Inserir | 2- Procurar | 3- Pre-Ordem | 4- Pos-Ordem | 5- Ordem | 6- Excluir | 7- Conta Pares | 0- Sair\n");
        scanf("%d",&opc);
        
        switch(opc){
            case 1:
                
                printf("Numero de chaves que voce deseja inserir\n");
                scanf("%d",&nChaves);
                
                for(i=0;i<nChaves;i++){
                    printf("Chave: ");
                    scanf("%d",&chave);   
                    
                    if(!raiz)
                        raiz = inserirRaiz(chave);
                    else
                        inserir(raiz,chave);
                }
                
                break;
            case 2:
                printf("Chave que voce deseja buscar: ");
                scanf("%d",&chave);
                
                if(aux = buscar(raiz,chave))
                    printf("%d ",buscar(raiz,chave)->chave);
                else
                    printf("Chave nao encontrada !\n");
               break; 
            case 3:
                printf("\n");
                preOrdem(raiz);
                printf("\n");
                break;
            case 4:
                printf("\n");
                posOrdem(raiz);
                printf("\n");
                break;
            case 5:
                printf("\n");
                ordem(raiz);
                printf("\n");
                break;
            case 6:
                printf("Chave que voce deseja excluir: ");
                scanf("%d",&chave);
                
                excluir(raiz,chave);
                break;
            case 7:
                printf("\n");
                printf("A arvore possui %d numeros pares\n",contaPares(raiz));
                break;
        }
    }
}