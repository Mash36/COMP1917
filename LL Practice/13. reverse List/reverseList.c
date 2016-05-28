/*
 *  reverseList.c
 *  2013s1 Practice Prac Exam #1
 *  UNSW comp1917
 *
 *  Created by INSERT YOUR NAME HERE
 *  Share freely CC-BY-3.0
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "reverseList.h"

list reverse (list inputList) {
   list current = inputList;
   list previous = NULL;
   list temp = NULL;

   while (current != NULL){
      temp = current->rest;
      current->rest = previous;
      previous = current;
      current = temp;
   }
   return previous;
}