// testClone.c
// testing clone() in hs-ppexam
// richard buckland 27 may 2014

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list-ppexam.h"

// simple unit tests on the list
void testList (void);
void showList (list l);


int main (int argc, char *argv[])  {

    testList();
    printf ("All tests passed.  You are awesome!\n");
    return EXIT_SUCCESS;
}


void testList (void) {

    // test a list with no nodes in it
    printf ("test cloning an empty list\n");
    list originalList = malloc (sizeof (*originalList));
    list cloned;
    assert (originalList !=NULL);
    originalList->head = NULL;  
    
    printf ("before cloning..\n");
    showList (originalList);
    cloned = clone (originalList);
    assert (cloned != NULL);
    printf ("after cloning: original list:\n");
    showList (originalList);
    printf ("after cloning: clone list:\n");
    showList (cloned);

    assert (originalList->head == NULL);  
    assert (cloned->head    == NULL);  

    // create 10 nodes on the stack 
    node nodes[10];

    // test a list with one node in it
    printf ("test cloning a list containing one node\n");
    originalList->head = &nodes[0];
    originalList->head->value = 42;
    originalList->head->next = NULL;  
    
    printf ("before cloning..\n");
    showList (originalList);
    cloned = clone (originalList);
    assert (cloned != NULL);
    printf ("after cloning: original list:\n");
    showList (originalList);
    printf ("after cloning: clone list:\n");
    showList (cloned);

    assert (originalList->head == &nodes[0]);  
    assert (originalList->head->value == 42);
    assert (originalList->head->next == NULL);

    assert (cloned->head != &nodes[0]);  
    assert (cloned->head->value == 42);
    assert (cloned->head->next == NULL);



    printf ("test cloning a list containing two nodes\n");
    originalList->head = &nodes[0];
    nodes[0].value = 7;
    nodes[1].value = 8; 
    nodes[0].next  = &nodes[1];
    nodes[1].next  = NULL;  
    
    printf ("before cloning..\n");
    showList (originalList);
    cloned = clone (originalList);
    assert (cloned != NULL);
    printf ("after cloning: original list:\n");
    showList (originalList);
    printf ("after cloning: clone list:\n");
    showList (cloned);

    assert (nodes[0].value == 7);
    assert (nodes[1].value == 8); 
    assert (nodes[0].next  == &nodes[1]);
    assert (nodes[1].next  == NULL);  

    assert (cloned->head != &nodes[0]);  
    assert (cloned->head->next != &nodes[1]);    
    assert (cloned->head->value == nodes[0].value);
    assert (cloned->head->next->value == nodes[1].value);
   

    printf ("test cloning a list containing three nodes\n");
    originalList->head = &nodes[0];
    nodes[0].value = 1;
    nodes[1].value = 2;
    nodes[2].value = 7;  
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = NULL;  
    
    printf ("before cloning..\n");
    showList (originalList);
    cloned = clone (originalList);
    assert (cloned != NULL);
    printf ("after cloning: original list:\n");
    showList (originalList);
    printf ("after cloning: clone list:\n");
    showList (cloned);

    assert (nodes[0].value == 1);
    assert (nodes[1].value == 2);
    assert (nodes[2].value == 7);  
    assert (nodes[0].next  == &nodes[1]);
    assert (nodes[1].next  == &nodes[2]);
    assert (nodes[2].next  == NULL);  


    assert (cloned->head != &nodes[0]);  
    assert (cloned->head->next != &nodes[1]);  
    assert (cloned->head->next->next != &nodes[2]);  
    assert (cloned->head->value == nodes[0].value);
    assert (cloned->head->next->value == nodes[1].value);
    assert (cloned->head->next->next->value == nodes[2].value);


    printf ("test cloning a list containing four nodes\n");
    originalList->head = &nodes[0];
    nodes[0].value = 1;
    nodes[1].value = 2;
    nodes[2].value = 7;  
    nodes[3].value = 3;  
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = &nodes[3];
    nodes[3].next  = NULL;  
    
    printf ("before clone..\n");
    showList (originalList);
    cloned = clone (originalList);
    assert (cloned != NULL);
    printf ("after cloning: original list:\n");
    showList (originalList);
    printf ("after cloning: clone list:\n");
    showList (cloned);

    assert (nodes[0].value == 1);
    assert (nodes[1].value == 2);
    assert (nodes[2].value == 7);  
    assert (nodes[3].value == 3);  
    assert (nodes[0].next  == &nodes[1]);
    assert (nodes[1].next  == &nodes[2]);
    assert (nodes[2].next  == &nodes[3]);
    assert (nodes[3].next  == NULL);  

    assert (cloned->head != &nodes[0]);  
    assert (cloned->head->next != &nodes[1]);  
    assert (cloned->head->next->next != &nodes[2]);  
    assert (cloned->head->next->next->next != &nodes[3]);  
    assert (cloned->head->value == nodes[0].value);
    assert (cloned->head->next->value == nodes[1].value);
    assert (cloned->head->next->next->value == nodes[2].value);
    assert (cloned->head->next->next->next->value == nodes[3].value);
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
