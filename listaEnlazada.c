#include <stdio.h>
#include <stdlib.h>
typedef struct nodo {
  char *name;
  char *last;
  float note1;
  float note2;
  float note3;
  float resultado;
  struct nodo *next;
} Nodo;
typedef struct listaEnlazada {
  Nodo *head;
  Nodo *tail;
  int tam;
} ListaLigada;
Nodo *getNodo(char *nombre, char *last, float note1, float note2, float note3);
ListaLigada *getListLigada();
void add(ListaLigada *ll, Nodo *nodo);
void imprimir(ListaLigada *ll);
void freeMemory(ListaLigada *ll);
Nodo* findNodo(ListaLigada* ll,int indice);
int main() {
  printf("********************\n");
  printf("ESTAMOS EN LA RAMA MASTER modifico para evaluar conflicto merge\n");
  printf("********************\n");
  ListaLigada *ll = getListLigada();
  Nodo *nodo1 = getNodo("oscar", "Reyes", 9.9, 9.9, 9.9);
  Nodo *nodo2 = getNodo("Veronica", "Velasco", 9.9, 8.9, 8.9);
  Nodo *nodo3 = getNodo("Aleyda", "Velasco", 9.9, 8.9, 8.9);
  add(ll, nodo1);
  add(ll, nodo2);
  add(ll, nodo3);
  imprimir(ll);
  printf("El nodo buscado en posicion 0: %s\n",findNodo(ll,0)->name);
  printf("El nodo buscado en posicion 1: %s\n",findNodo(ll,1)->name);
  freeMemory(ll);

  return 0;
}
Nodo *getNodo(char *nombre, char *last, float note1, float note2, float note3) {
  Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
  nodo->name = nombre;
  nodo->last = last;
  nodo->note1 = note1;
  nodo->note2 = note2;
  nodo->note3 = note3;
  nodo->resultado = (note1 + note2 + note3) / 3;
  nodo->next = NULL;
  return nodo;
}
ListaLigada *getListLigada() {
  ListaLigada *ll = (ListaLigada *)malloc(sizeof(ListaLigada));
  ll->head = NULL;
  ll->tail = NULL;
  ll->tam = 0;
  return ll;
}
void imprimir(ListaLigada *ll) {
  Nodo *current = ll->head;
  while (current != NULL) {
    printf(" Nombre: %s\n Apellido: %s\n Calificacion1: %f\n Calificacion2: "
           "%f\n Calificacion3: %f\n Promedio: %f\n",
           current->name, current->last, current->note1, current->note2,
           current->note3, current->resultado);
    current = current->next;
    printf("\n");
  }
}
void add(ListaLigada *ll, Nodo *nodo) {
  if (ll->head == NULL)
    ll->head = nodo;
  else
    ll->tail->next = nodo;
  ll->tail = nodo;
  ll->tam++;
}
void freeMemory(ListaLigada *ll) {
  Nodo *current = ll->head;
  while (current != NULL) {
    Nodo *next = current->next;
    free(current);
    current = next;
  }
  free(ll);
}
Nodo* findNodo(ListaLigada* ll,int indice){
  if(ll->tam && indice < ll->tam)
  {
    Nodo* current=ll->head;
    int i=0;
    while(i++<indice)
      current=current->next;
    return current;
  }
  return NULL;
}
