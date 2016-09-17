
typedef struct{
    int chave;
    struct Arvore *pai;
    struct Arvore *esquerda;
    struct Arvore *direita;
}Arvore;

Arvore *raiz;

Arvore *alocaNo();
Arvore *inserirRaiz(int chave);

Arvore *buscar(Arvore  *ptr,int chave);
void inserir(Arvore *ptr,int chave);
void excluir(Arvore *ptr,int chave);
int altura(Arvore *ptr,int count);

int contaPares(Arvore *ptr);
void primo(Arvore *ptr);

void preOrdem(Arvore *ptr);
void posOrdem(Arvore *ptr);
void ordem(Arvore *ptr);

void menu();