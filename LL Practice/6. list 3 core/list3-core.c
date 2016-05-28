#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list3-core.h"

// print out a list
void showList (list listToPrint) {
   link current = listToPrint->head;
   while (current != NULL){
      printf("[%d] -> ", current->value);
      current = current->next;
   }
   printf("X\n");
}

// inset item at the front of the list
void frontInsert (list l, int item) {
   link current = l->head;
   link newItem = malloc(sizeof(struct _node));
   newItem->value = item;
   newItem->next = current;
   l->head = newItem;
}

// count the number of items in the list
int numItems (list l) {
   int counter = 0;
   link current = l->head;
   while (current != NULL){
      counter++;
      current = current->next;
   }
   return counter;
}

// insert at end of list
void append (list l, int value) {
   link append = malloc(sizeof(struct _node));
   append->value = value;
   append->next = NULL;
   if (l->head == NULL)
   {
      l->head = append;
   } else {
      link current = l->head;
      while (current->next != NULL){
         current = current->next;
      }
      current->next = append;
   }
}

// find the value stored at position i
// i MUST be a valid position in the list
// dont call this on positions outside the list
int lookup (list l, int position) {
   int counter = 0;
   link current = l->head;
   while (counter < position){
      counter++;
      current = current->next;
   }
   return current->value;
}