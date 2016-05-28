// clone.c
// 
 
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
 
#include "list-ppexam.h"
 
// given a list of nodes 
// leaves it untouched and returns a new list
// made of new nodes of the same length as the 
// input list and the having the same content values
// in the same order
// eg cloning a list 4->5->3->6->X would return 
// another list 4->5->3->6->X made up of new nodes and
// it would also leave the old list altered.
 
list clone (list old) {
    list new = malloc(sizeof(struct _node));

    if (old->head == NULL)
    {
        new->head = NULL;
    } else {
        new->head = malloc(sizeof(struct _node));
        link oldCurrent = old->head;
        link newCurrent = new->head;

        while (oldCurrent != NULL)
        {
            newCurrent->value = oldCurrent->value;
            if (oldCurrent->next == NULL)
            {
                newCurrent->next = NULL;
            }
            else {
                newCurrent->next = malloc(sizeof(struct _node));
            }
            oldCurrent = oldCurrent->next;
            newCurrent = newCurrent->next;
        }
    }
    return new;
}