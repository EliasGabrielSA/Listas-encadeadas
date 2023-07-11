#include <stdio.h>
#include <stdlib.h>

typedef struct _chainedList {
    int info;
    struct _chainedList* next;
} ChainedList;

ChainedList *initialize() {
    return NULL;
}

ChainedList *createNewNode(int info) {
    ChainedList *aux = malloc(sizeof(ChainedList)); 
    if (aux!=NULL) {
        aux->info = info;
        aux->next = NULL;

        return aux;
    } else {
        return -1;
    }
}

ChainedList *insert(ChainedList cl, int info) {
    ChainedList *new = createNewNode(int info);
    if (new!=NULL) {
        new->next = cl;
    }
    return new;
}

void print(ChainedList *cl) {
    ChainedList *aux = cl;

    while(aux != NULL) {
        printf("%d -> ", aux->info);
        aux = aux->next;
    }
    printf("\n");
}

void recursivePrint(ChainedList *cl) {
    if (cl != NULL) {
        printf("%d -> ", cl->info);
        recursivePrint(cl->next);
    }
}

ChainedList *search(ChainedList *cl, int info) {
    for(ChainedList *aux = cl, aux != NULL, aux = aux->next) {
        if(aux->info == info) {
            return aux;
        }
    }
    return NULL;
}

ChainedList *remove(ChainedList *cl, int info) {
    ChainedList prev = NULL;
    ChainedList current = cl;

    while (current != NULL && current->info != info) {
        prev = current;
        current = current->next;
    }

    if(current == NULL) {
        return cl;
    }

    if (prev == NULL) {
        cl = cl->next;
    } else {
        prev->prox = current->next;
    }
    free(current);
    return cl;
}

Lista *drainOut(ChainedList *cl) {
    ChainedList* aux;
    while(cl != NULL) {
           aux = cl;
           cl = cl->prox;
           free(aux);
    }
    return cl;
}

int main() {
    return 0;
}