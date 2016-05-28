/*

Tried by Mash 
on 21/05/2016
Had some compile error
Too lazy to debug atm
Have to look at it later.
K. Bye.

*/


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list3-extraFns.h"


list newList (void) {
   list newList = malloc(sizeof(struct _node));
   newList->head = NULL;
   return newList;
}

void deleteHead (list l) {
   link current = l->head;
   current = current->next;
}

void deleteLast (list l) {
   link current = l->head;
   if (l->head->next == NULL)
   {
      l->head = NULL;
   } else {
      while (current != NULL){
         current = current->next;
      }
      current->next = NULL;
   }
}

void concatenate (list to, list from) {
   link current = to->head;

   if (to->head == NULL)
   {
      to->head = from->head;
   } else {
      
      while (current->next != NULL){
         current = current->next;
      }
      current->next = from->head;
   }
   from->head = NULL;
}

int count42s (list l) {
   int counter = 0;
   link current = malloc(sizeof(struct _node));
   while (current->value == 42){
      counter++;
      current = current->next;
   }
   return counter;
}