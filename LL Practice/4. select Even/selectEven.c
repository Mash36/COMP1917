	// selectEven.c
//

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list-selectEven.h"

// given a list of integers, write a function which
// finds all even integers and constructs
// a new list containing these even integers
// The original list should remain unmodified.
// The new list should be returned by the function.
// So if the original list is 1->55->66->4->X, the function
// should return a list 66->4->X.
// And if the original list is 1->3->7->X, the function
// should return an empty list.
//
// Constraints:
// don't delete any nodes (i.e. do not call free())
// the order of integers in the new list should be the same as the original
// the original list should remain unmodified
//
// A function to determine the length of a list called numItems()
// is provided. Fell free to use it but do not modify the function.
void append(list list, int value);

list selectEven (list sourceList) {
	list newList = malloc(sizeof(struct _node));
	newList->head = NULL;
	link current = sourceList->head;
	while (current!= NULL){
		if (current->value %2 == 0)
		{
			append (newList, current->value);
		}
		current = current->next;
	}
	return newList;
}

void append(list list, int value) {
	link append = malloc(sizeof(struct _node));
	append->value = value;
	append->next = NULL;
	if (list->head == NULL)
	{
		list->head = append;
	} else {
		link current = list->head;
		while (current->next != NULL){
			current = current->next;
		}
		current->next = append;
	}
}