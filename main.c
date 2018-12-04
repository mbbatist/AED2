#include <stdio.h>
#include <stdlib.h>
struct NO
{
    int info;
    struct NO *esq;
    struct NO *dir;
};
typedef struct NO ArvBin;
ArvBin* cria_ArvBin();
int insere_ArvBin(ArvBin *T, int valor);
void libera_ArvBin(ArvBin *T);
int altura_ArvBin(ArvBin *T);
int totalnos_Arv(ArvBin *T);
void preOrdem_ArvBin(ArvBin *T);
void emOrdem_ArvBin(ArvBin *T);
void posOrdem_ArvBin(ArvBin *T);
int remove_ArvBin(ArvBin *T,int valor);
int main(int argc, char** argv) {
    ArvBin* raiz;
    raiz=cria_ArvBin();
    int x=insere_ArvBin(raiz,3);
    libera_ArvBin(raiz);
    x=altura_ArvBin(raiz);
    printf("Altura da árvore Binária: %d",x);
    totalnos_ArvBin(raiz);
    preOrdem_ArvBin(raiz);
    emOrdem_ArvBin(raiz);
    posOrdem_ArvBin(raiz);
    x=remove_ArvBin(raiz,valor);
    return (EXIT_SUCCESS);
}

ArvBin* cria_ArvBin()
{
    ArvBin* raiz=(ArvBin*)malloc(sizeof(ArvBin));
    if(raiz!=NULL)
        *raiz=NULL;
    return raiz;
}

int insere_ArvBin(ArvBin *T, int valor)
{
    if(T==NULL)
        return 0;
    struct NO*novo;
    novo=(struct NO*)malloc(sizeof(struct NO));
    if(novo==NULL)
        return 0;
    novo->info=valor;
    novo->dir=NULL;
    novo->esq=NULL;
    if((*T)==NULL)
        (*T)=novo;
    else
    {
        ArvBin* atual=(*T);
        ArvBin* ant=NULL;
        while(atual!=NULL)
        {
            ant = atual;
            if(valor==atual->info)
                free(novo);
            if(valor>atual->info)
                atual=atual->dir;
            else
                atual=atual->esq;
        }
        if(valor>ant->info)
            ant->dir=novo;
        else
            ant->esq=novo;
    }
    return 1;
}

void libera_NO(struct NO* no)
{
    if(no==NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no=NULL;
}

void libera_ArvBin(ArvBin* T)
{
    if(T == NULL)
        return;
    libera_NO(*T);//libera cada nó
    free(T);//libera a raiz
}
 
int altura_ArvBin(ArvBin* T)
{
    if(T==NULL)
        return 0;
    if(*T==NULL)
        return 0;
    int alt_esq=altura_ArvBin(&(*T->esq));
    int alt_dir=altura_ArvBin(&(*T->dir));
    if(alt_esq>alt_dir)
        return(alt_esq+1);
    else
        return(alt_dir+1);
}

int totalnos_ArvBin(ArvBin* T)
{
    if(T==NULL)
        return 0;
    if(*T==NULL)
        return 0;
    int alt_esq=altura_ArvBin(&(*T->esq));
    int alt_dir=altura_ArvBin(&(*T->dir));
    return(alt_dir+alt_esq+1);
}

void preOrdem_ArvBin(ArvBin* T)
{
    if(T==NULL)
        return;
    if(*T==NULL)
    {
        printf("%d\n",(*T)->info);
        preOrdem_ArvBin(&((*T)->esq));
        preOrdem_ArvBin(&((*T)->dir));
    }
}

void emOrdem_ArvBin(ArvBin* T)
{
    if(T==NULL)
        return;
    if(*T==NULL)
    {
        preOrdem_ArvBin(&((*T)->esq));
        printf("%d\n",(*T)->info);
        preOrdem_ArvBin(&((*T)->dir));
    }
}

void posOrdem_ArvBin(ArvBin* T)
{
    if(T==NULL)
        return;
    if(*T==NULL)
    {
        preOrdem_ArvBin(&((*T)->esq));
        preOrdem_ArvBin(&((*T)->dir));
        printf("%d\n",(*T)->info);
    }
}

int remove_ArvBin(ArvBin* T,int valor)
{
    if()
}

ArvBin* remove_atual(struct NO* atual)
{
    if(T==NULL) return 0;
}