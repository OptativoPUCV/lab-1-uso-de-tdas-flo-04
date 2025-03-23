#include "arraylist.h"
#include "stack.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "exercises.h"

// Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
// NO MODIFICAR
void imprime_lista(List *L) {
  int *dato;
  dato = (int *)first(L);
  printf("[");
  while (dato != NULL) {
    printf("%d ", *dato);
    dato = (int *)next(L);
  }
  printf("]\n");
}

// Ojo que la pila se vacía al imprimir y se imprime en orden inverso
// NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
  void *dato;
  printf("[");
  while ((dato = pop(P)) != NULL) {
    printf("%d ", *(int *)dato);
  }
  printf("]\n");
}

/*
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List *crea_lista() {
  List *L = create_list();

  for(int aux = 1; aux <= 10; aux++){
    int* num = (int*)malloc(sizeof(int));
    *num = aux;
    pushBack(L, num);
  }
  return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
  int sum = 0;
  void* elemento = first(L);
  while(elemento != NULL){
    int num = *((int*)elemento);
    sum += num;
    elemento = next(L);
  }
  return 0;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List *L, int elem) {
  void* aux = first(L);
  while (aux != NULL){
      int num = *((int*)aux);
      if(elem == num){
        popCurrent(L);
      }
      else{
        aux = next(L);
      }
  }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack *P1, Stack *P2) {
  Stack* PAux = create_stack();

  while(top(P1) != NULL){
      push(PAux, top(P1));
      pop(P1);
  }

  while(top(PAux) != NULL){
      push(P2, top(PAux));
      pop(PAux);
  }
  
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) { 
  Stack* PAper = create_stack();
  int cont = 0;
  while (cadena[cont] != '\0'){
    if(cadena[cont] == '(' || cadena[cont] == '[' || cadena[cont] == '{'){
      push(PAper, &cadena[cont] );
      cont++;
      
    }
    else{
      if((cadena[cont] == '('&& *(char*)top(PAper) == ')' ) ||  
        (cadena[cont] == '{'&& *(char*)top(PAper) == '}' ) || 
        (cadena[cont] == '['&& *(char*)top(PAper) == ']' )){
        
      }
  
    
  }
  
}
