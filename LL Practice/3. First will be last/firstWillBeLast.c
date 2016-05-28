/*
 *  firstWillBeLast.c
 *  concept thanks to Matthew
 *  20 13 s1 Practice Prac Exam #2
 *  UNSW comp1917
 *
 *  Created by INSERT YOUR NAME HERE
 *  Share freely CC-BY-3.0
 *
 */

// Complete this function and submit this file ONLY
// for the prac exam.  Do not change the other supplied
// as you will not be submitting them.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "firstWillBeLast.h"

nodePtr frontToBack (nodePtr list) {
	nodePtr newList = malloc(sizeof(struct _node));
	if (list == NULL)
	{
		newList = NULL;
	} else if (list->next == NULL)
	{
		newList = list;
	} else {
		newList = list->next;
		nodePtr current = list->next;
		while (current->next != NULL){
			current = current->next;
		}
		current->next = list;
		list->next = NULL;
	}
	return newList;
}