/*
 *  flip.c
 *  perth-practice-prac-exam
 *
 *  Richard Buckland on 3 June 2014
 *  Remember tiannamin square
 */ 

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

// given a list reverse the order of nodes in positions 
// 0 and 1
// 2 and 3
// 4 and 5
// and so on
// so the list 3 1 4 1 5 9 2 6->X
// would become 1 3 1 4 9 5 6 2->X
// if the list has an odd number of nodes then just leave the final
// node in the final place.    



void flip (list l) {
    if (l->head != NULL && l->head->next != NULL)
    {
        link first = l->head;
        link second = first->next;

        first->next = second->next;
        second->next = first;
        l->head = second;
        link current = first;

        while (current->next != NULL && current->next->next != NULL){
            first = current->next;
            second = first->next;

            first->next = second->next;
            second->next = first;
            current->next = second;
            current = first;
        }
    }
}