// testOrderedInsert.c
// testing orderedInsert() in exam.c
// richard buckland 19 may 2014

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list.h"


// simple unit tests on the list
void testList (void);
void showList (list l);


int main (int argc, char *argv[])  {

    testList();
    printf ("All tests passed.  You are awesome!\n");
    return EXIT_SUCCESS;
}


void testList (void) {

	// create a list with no nodes in it
    list myList = malloc (sizeof (*myList));
    assert (myList !=NULL);
    myList->head = NULL;  

    // insert 3
    orderedInsert (myList,3);

    assert (myList->head != NULL);
    assert (myList->head->value == 3);
    assert (myList->head->next  == NULL);
    showList (myList);
    link threePtr = myList->head;    

    // insert 1
    orderedInsert (myList,1);

    assert (myList->head != NULL);
    assert (myList->head->value == 1);
    assert (myList->head->next  == threePtr);
    assert (threePtr->value == 3);
    assert (threePtr->next  == NULL);
    showList (myList);

    // insert 4
    orderedInsert (myList,4);

    assert (myList->head != NULL);
    assert (myList->head->value == 1);
    assert (myList->head->next  == threePtr);
    assert (myList->head->next->value == 3);
    assert (myList->head->next->next  != NULL);
    assert (myList->head->next->next->value == 4);
    assert (myList->head->next->next->next  == NULL);
    showList (myList);


    // insert 1
    orderedInsert (myList,1);

    link current = myList->head;
    assert (current != NULL);
    assert (current->value == 1);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 1);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 3);
    assert (current == threePtr);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 4);

    current = current->next;
    assert (current == NULL);

    showList (myList);


    // insert 5
    orderedInsert (myList,5);

    current = myList->head;
    assert (current != NULL);
    assert (current->value == 1);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 1);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 3);
    assert (current == threePtr);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 4);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 5);

    current = current->next;
    assert (current == NULL);

    showList (myList);


    // insert 9
    orderedInsert (myList,9);

    current = myList->head;
    assert (current != NULL);
    assert (current->value == 1);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 1);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 3);
    assert (current == threePtr);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 4);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 5);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 9);

    current = current->next;
    assert (current == NULL);

    showList (myList);

    // insert 2
    orderedInsert (myList,2);

    current = myList->head;
    assert (current != NULL);
    assert (current->value == 1);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 1);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 2);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 3);
    assert (current == threePtr);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 4);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 5);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 9);

    current = current->next;
    assert (current == NULL);

    showList (myList);

    // insert 6
    orderedInsert (myList,6);

    current = myList->head;
    assert (current != NULL);
    assert (current->value == 1);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 1);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 2);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 3);
    assert (current == threePtr);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 4);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 5);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 6);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 9);

    current = current->next;
    assert (current == NULL);

    showList (myList);

    // insert 0
    orderedInsert (myList,0);

    current = myList->head;
    assert (current != NULL);
    assert (current->value == 0);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 1);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 1);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 2);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 3);
    assert (current == threePtr);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 4);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 5);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 6);

    current = current->next;
    assert (current != NULL);
    assert (current->value == 9);

    current = current->next;
    assert (current == NULL);

    showList (myList);


    // check that the values of the nodes have not been changed
    assert (threePtr->value == 3);

 
}


void showList (list l) {

    assert (l !=NULL);

    // start at the first node
    link current = l->head;
    while (current != NULL) {
        printf ("[%d] -> ", current->value);
        current = current->next;
    }
    printf ("X\n");
}


