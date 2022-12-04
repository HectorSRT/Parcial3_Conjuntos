#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10000
#define EMPTY 0

typedef int TElemento;

typedef struct conjunto{
    TElemento a[MAX];
    int tam;
}TConjunto;

void clear(TConjunto *c);
bool is_empty(const TConjunto *c);
bool is_full(const TConjunto *c);
bool contains(const TConjunto *c, TElemento x);
void add(TConjunto *c, TElemento x);
void erase(TConjunto *c, TElemento x);
int size(const TConjunto *c);
void leer_conjunto(TConjunto *c, int m, int num);
int erase_p(TConjunto *c);
int erase_f(TConjunto *c);
void union_conjuntos(TConjunto *c, TConjunto *d, TConjunto *r);
void interseccion(TConjunto *c, TConjunto *d, TConjunto *r);
void diferencia(TConjunto *c, TConjunto *d, TConjunto *r);
void suma(TConjunto *c, TConjunto *d);

int main()
{
    TConjunto c;
    TElemento x;
    TConjunto d;
    TConjunto r;
    int n,num;
    clear(&c);
    clear(&d);
    clear(&r);
    scanf("%d", &n);
    leer_conjunto(&c,n,num);
    leer_conjunto(&d,n,num);
    union_conjuntos(&c,&d,&r);
    clear(&r);
    interseccion(&c,&d,&r);
    clear(&r);
    diferencia(&c,&d,&r);
    clear(&r);
    suma(&c,&d);
    int p=erase_p(&c);
    printf("%d ", p);
    printf("\n");
    int z=erase_f(&c);
    printf("%d ", z);
    printf("\n");
    return 0;
}

void leer_conjunto(TConjunto *c, int n, int num){
    for(int i=0;i<n;i++){
        scanf("%d", &num);
        add(c, num);
    }
}

void union_conjuntos(TConjunto *c, TConjunto *d, TConjunto *r){
    printf("Union conjuntos\n");
    for(int i=0;i<c->tam;i++){
        add(r,c->a[i]);
        add(r,d->a[i]);
    }

    for(int i=0;i<r->tam;i++){
        printf("%d ", r->a[i]);
    }
    printf("\n");
}

void interseccion(TConjunto *c, TConjunto *d, TConjunto *r){
    printf("Interseccion conjuntos\n");
    // . pq pasa por valor -> pq pasa por referencia
    for(int i=0;i<c->tam;i++){
        if(contains(d, c->a[i])){
            add(r,c->a[i]);
        }
    }

    for(int i=0;i<r->tam;i++){
        printf("%d ", r->a[i]);
    }
    printf("\n");
}

void diferencia(TConjunto *c, TConjunto *d, TConjunto *r){
    printf("Diferencia conjuntos\n");
    for(int i=0;i<c->tam;i++){
        if(!contains(d,c->a[i])){
            add(r,c->a[i]);
        }
    }
    for(int i=0;i<r->tam;i++){
        printf("%d ", r->a[i]);
    }
    printf("\n");
}

void suma(TConjunto *c, TConjunto *d){
    printf("Suma conjuntos\n");
    for(int i=0;i<c->tam;i++){
        add(c,d->a[i]);
    }

    for(int i=0;i<c->tam;i++){
        printf("%d ", c->a[i]);
    }
    printf("\n");
}

void clear(TConjunto *c){
    c->tam=0;
}

bool is_empty(const TConjunto *c){
    if(c->tam==0){
        return true;
    }else{
        return false;
    }
}

bool is_full(const TConjunto *c){
    if(c->tam==MAX){
        return true;
    }else{
        return false;
    }
}

bool contains(const TConjunto *c, TElemento x){
    for (int i = 0; i < c->tam; i++){
        if (c->a[i]==x){
            return true;
        }
    }
    return false;
}

void add(TConjunto *c, TElemento x){
    if(contains(c,x)){
        return;
    }
    if(is_full(c)){
        printf("set overflow");
        return;
    }
    c->a[c->tam]=x;
    c->tam++;
}

void erase(TConjunto *c, TElemento x){
    if(!contains(c,x)){
        return;
    }
    int k=0;
    for(;k<c->tam;k++){
        if(c->a[k]==x){
            break;
        }
    }
    for(;k<c->tam;k++){
        c->a[k]=c->a[k+1];
    }
    c->tam-=1;
}

int erase_p(TConjunto *c){
    printf("Borrar primer dato\n");
    int x = c->a[0];
    erase(c,c->a[0]);
    return x;
}

int erase_f(TConjunto *c){
    printf("Borrar ultimo dato\n");
    int x = c->a[(c->tam)-1];
    erase(c,c->a[(c->tam)-1]);
    return x;
}

int size(const TConjunto *c){
    return c->tam;
}
