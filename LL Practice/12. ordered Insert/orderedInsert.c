// orderedInsert.c
// 
 
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
 
#include "list.h"
 
// given a list of nodes which is arranged in non-decreaing order
// eg 1->4->6->10->X
// and a number, create a new node containing the number and 
// insert it in the correct place in the list so that the the
// resultant one-element-longer list is still in non decreasing
// order.  
// insert the new node by rearranging pointers, don't change the 
// value field for nodes already in the list.
// (if the number being inserted is already in the list 
// you may place the new node before or after the existing nodes
// however you wish just so long as the resulting list is in order.)
 
// eg inserting 3 in the list above would produce the list
// 1->3->4->6->10->X
 
void orderedInsert (list l, int number) {
	link current = l->head;
	link previous = NULL;
	link new = malloc(sizeof(struct _node));
	new->value = number;
	
	if (current == NULL || current->value >= new->value){
		l->head = new;
		new->next = current;
		return;
	}
	while (current != NULL && current->next != NULL 
		   && current->value < new->value) {
		previous = current;
		current = current->next;
	}
	if (current != NULL && current->value <= new->value )
	{
		new->next = NULL;
		current->next = new;
	} else if (current != NULL) {
		previous->next = new;
		new->next = current;
	} 
}
