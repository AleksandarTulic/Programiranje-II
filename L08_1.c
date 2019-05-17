#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    void *data;
    struct node *left, *right;
}NODE;

int cmp(const void *a, const void *b)
{
    return strcmp((char*)a, (char*)(b));
}

void write_one(const char *a)
{
    printf("%s\n", (char*)a);
}

NODE* search(NODE *head, NODE *tail, const void *data, int (*cmp)(const void *, const void *))
{
    while(head){
        if((*cmp)(head->data,data)==0){
            return head;
        }
        head=head->right;
    }
    return head;
}

void add(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *))
{
    if ( search(*phead, *ptail, data, cmp) ) return;

    NODE *p, *q, *novi = (NODE*)malloc(sizeof(NODE));

    novi->data = data;novi->left = 0;novi->right = 0;

    if ( *phead == 0 ) *phead = *ptail = novi;
    else if ( (*cmp)( (*phead)->data, data ) > 0 )
    {
        novi->right = *phead;
        (*phead)->left = novi;
        *phead = novi;
    }
    else if ( (*cmp)( (*phead)->data, data ) < 0 )
    {
        novi->left = *ptail;
        (*ptail)->right = novi;
        *ptail = novi;
    }
    else
    {
        for (p = *phead, q = (*ptail)->left; (*cmp)( p->right->data, data ) < 0 && (*cmp)( q->data, data ) > 0; p = p->right, q = q->left )
            if ( (*cmp)( q->data, data ) < 0 ) p = q;

        novi->right = p->right;
        novi->left = q;
        p->right->left = novi;
        p->right = novi;
    }
}

void deletef(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *))
{
    NODE *p = search(*phead, *ptail, data, cmp);

    if ( p == 0 ) return;
    else if ( p == *phead && p == *ptail ) *phead = *ptail = 0;
    else if ( p == *phead )
    {
        *phead = (*phead)->right;
        (*phead)->left = 0;
    }
    else if ( p == *ptail )
    {
        *ptail = (*ptail)->left;
        (*ptail)->right = 0;
    }
    else
    {
        p->left->right = p->right;
        p->right->left = p->left;
    }

    free(p);
}

void write(NODE *head, void (*write_one)(const void *))
{
    while ( head )
    {
        (*write_one)(head->data);
        head = head->right;
    }
}

void delete_list(NODE **phead, NODE **ptail)
{
    while ( *phead )
    {
        NODE *p = (*phead)->right;
        free(*phead);
        *phead = p;
        *ptail = 0;
    }
}

int main()
{
    NODE *head = 0, *tail = 0;

    char niz1[] = "Ponedeljak";
    char niz2[] = "Utorak";
    char niz3[] = "Srijeda";
    char niz4[] = "Cetvrtak";
    char niz5[] = "Petak";
    char niz6[] = "Subota";
    char niz7[] = "Nedelja";

    add(&head, &tail, niz1, &cmp);
    add(&head, &tail, niz2, &cmp);
    add(&head, &tail, niz3, &cmp);
    add(&head, &tail, niz4, &cmp);
    add(&head, &tail, niz5, &cmp);
    add(&head, &tail, niz6, &cmp);
    add(&head, &tail, niz7, &cmp);

    write(head, &write_one);

    deletef(&head, &tail, niz5, &cmp);
    deletef(&head, &tail, niz1, &cmp);
    deletef(&head, &tail, niz7, &cmp);
    printf("\n");

    write(head, &write_one);

    delete_list(&head, &tail);

    printf("\n");

    write(head, &write_one);
    return 0;
}

/*

CVOR* dodaj_pocetak(CVOR **plista, int podatak) {
  CVOR *novi = (CVOR *)malloc(sizeof(CVOR));
  novi->podatak = podatak;
  if (*plista == 0) *plista = novi;
  else novi->sljedeci = (*plista)->sljedeci;
  (*plista)->sljedeci = novi;
  return novi;
}


CVOR* dodaj_kraj(CVOR **plista, int podatak) {
  CVOR *novi = (CVOR *)malloc(sizeof(CVOR));
  novi->podatak = podatak;
  if (*plista == 0) novi->sljedeci = novi;
  else {
    novi->sljedeci = (*plista)->sljedeci;
    (*plista)->sljedeci = novi;
  }
  *plista = novi;
  return novi;
}


CVOR* dodaj_iza(CVOR **plista, CVOR *cvor, int podatak) {
  CVOR *novi = (CVOR *)malloc(sizeof(CVOR));
  novi->podatak = podatak;

  novi->sljedeci = cvor->sljedeci;
  cvor->sljedeci = novi;

  if (*plista == cvor) *plista = novi;

  return novi;
}

CVOR* dodaj_ispred(CVOR **plista, CVOR *cvor, int podatak) {
  CVOR *novi = (CVOR *)malloc(sizeof(CVOR));

  novi->podatak = cvor->podatak;
  novi->sljedeci = cvor->sljedeci;

  cvor->podatak = podatak;
  cvor->sljedeci = novi;

  if (*plista == cvor) *plista = novi;

  return cvor;
}

int brisi_iza(CVOR **plista, CVOR *cvor) {
  CVOR *p = cvor->sljedeci;
  if (cvor == p) return 0;
  cvor->sljedeci = p->sljedeci;
  if (*plista == p) *plista = cvor;
  free(p);
  return 1;
}

void brisi_listu(CVOR **plista) {
  if (*plista == 0) return;
  CVOR *p = *plista;
  do {
    CVOR *q = p->sljedeci;
    free(p); p = q;
  } while (p != *plista);
  *plista = 0;
}

CVOR* trazi(CVOR *lista, int podatak) {
  if (lista == 0) return 0;
  CVOR *p;
  for (p = lista; p->podatak != podatak && p->sljedeci != lista; p = p->sljedeci);
  return p->podatak == podatak ? p : 0;
}

void pisi(CVOR *lista) {
  if (lista == 0) return;
  CVOR *p = lista;
  do {
    p = p->sljedeci;
    printf(" %d", p->podatak);
  } while (p != lista);
}

void spoji(CVOR **plista1, CVOR *lista2) {
  if (*plista1 == 0) *plista1 = lista2;
  else if (lista2 == 0) return;
  CVOR *p = (*plista1)->sljedeci;
  (*plista1)->sljedeci = lista2->sljedeci;
  lista2->sljedeci = p;
  *plista1 = lista2;
}


*/
