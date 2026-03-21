#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
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
List* crea_lista() {
   List* L = create_list();
   /*
   Esto funciona pero es técnicamente incorrecto. Cuando el arreglo valores se libere del stack, las direcciones de memoria guardadas en L
   tendrán comportamiento indefinido puesto que el arreglo valores se liberará tras finalizar la función crea_lista.
   int valores[10];
   for(int i=0; i<10; i++) {
      valores[i]=i+1;
      pushBack(L, &valores[i]);  
   }
   */

   for(int i=1; i<=10; i++) {
      int* dato = (int*) malloc(sizeof(int));
      if(dato) {
         *dato = i;
         pushBack(L, dato);
      }
   }   
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/

int sumaLista(List *L) {
   int sumaTotal = 0;
   int* valor = first(L);
   
   while(valor!=NULL) {
      sumaTotal+=(*valor);
      valor = next(L);
   }
   return sumaTotal;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   int* dato = first(L);
   while(dato!=NULL) {
      if((*dato)==elem) {
         popCurrent(L);
      }
      dato = next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* auxiliar = create_stack(); // <- Pila auxiliar
   void* dato;

   while((dato=pop(P1)) != NULL) { // Vaciar P1 en auxiliar (invertido) mientras P1 siga lleno
      push(auxiliar, dato);
   }
   while((dato=pop(auxiliar)) != NULL) { // Vaciar auxiliar y comenzar a llenar ambas P1 y P2 al mismo tiempo (orden original)
      push(P1, dato);
      push(P2, dato);
   }
}


/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   Stack *pila = create_stack(); // Crear una pila donde almacenar los paréntesis

   for(int i=0; cadena[i]!='\0'; i++) {
      char caracter = cadena[i];

      if(caracter=='(' || caracter=='[' || caracter=='{') { // _______________________
         char *pChar = (char*) malloc(sizeof(char)); //_______|
         *pChar = caracter;                         // | -> Guardar tipo de paréntesis abierto en la pila para verificar si se cierra después
         push(pila, pChar);                        //  _______________________________
      }
      else if(caracter==')' || caracter==']' || caracter=='}') { // En caso de encontrar un paréntesis que cierra:
         char *topCaracter = (char*) pop(pila); // Retirar el primer elemento de la pila
         if(topCaracter==NULL) return 0;   // En caso de que la pila esté vacía, significa que falta un paréntesis abierto, por ende están desbalanceados

         if((caracter==')' && *topCaracter != '(') ||   //_______________________
            (caracter==']' && *topCaracter != '[') ||   //| Casos donde el paréntesis de cierre encontrado no coincide con el de apertura
            (caracter=='}' && *topCaracter != '{')) {   //_______________________
            free(topCaracter);   // Liberar la memoria reservada del paréntesis de cierre actual
            return 0;   // Retornar -> paréntesis desbalanceados
         }
         free(topCaracter);
      }
   }
   void *sobrante = pop(pila);
   if(sobrante==NULL) return 1;// Pila de paréntesis abiertos vacía
   // En caso contrario, quiere decir que aún hay paréntesis abiertos remanentes en la pila, ej: "((())"
   while(sobrante!=NULL) {
      free(sobrante);
      sobrante= pop(pila);
   }
   return 0;
}
