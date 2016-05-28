/*
 *  backToFront.c
 *  2013 s1 Prac Exam
 *  UNSW comp1917
 *
 *  Unleashed by Richard Buckland and Devid Collien
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "backToFront.h"

nodePtr backToFront (nodePtr oldList) {
      nodePtr newList = malloc(sizeof(struct _node));
      if (oldList == NULL)
      {
            newList = NULL;
      } else if (oldList->next == NULL)
      {
            newList = oldList;
      } else {
            nodePtr current = oldList;
        while (current->next->next != NULL){
            current = current->next;
        }
        newList = current->next;
        current->next->next = oldList;
        current->next = NULL;
    }
    return newList;
}