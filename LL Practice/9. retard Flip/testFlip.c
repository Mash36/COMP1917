/*
 *  testFlip.c
 *  perth practice-prac-exam
 *
 *  Richard Buckland: 3 june 2014
 *  
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

static void testFlip (void);

static node *newNode (int item);

int main (int argc, const char * argv[]) {
   
   printf ("About to test the flip function\n");
   testFlip();   
   printf ("All FLIP tests passed!  You are awesome!\n");
   
   return EXIT_SUCCESS;
}

void testFlip (void) {
   
   // create 10 nodes, names indicate their value, next=NULL
   node *node5 = newNode (5);
   node *node6 = newNode (6);
   node *node7 = newNode (7);
   node *node8 = newNode (8);
   node *node9 = newNode (9);
   node *node0 = newNode (0);
   node *node1 = newNode (1);
   node *node2 = newNode (2);
   node *node3 = newNode (3);
   node *node4 = newNode (4);
   
   printf ("Test [1] \nTesting flip [] == []\n");
   list listEmpty  = malloc (sizeof (list*));
   assert (listEmpty != NULL);
   listEmpty->head = NULL;
   
   flip (listEmpty);  // == NULL
   assert (listEmpty->head == NULL);
   printf ("Test passed!\n");
     
   printf ("Test [2] \nTesting flip 1 == 1\n");
   list list1  = malloc (sizeof (list*));
   assert (list1 != NULL);
   list1->head = node1;

   node1->next = NULL;
   
   flip (list1);  // == 1
   assert (list1->head == node1);
   assert (node1->next == NULL);
   printf ("Test passed!\n");

   printf ("Test [3] \nTesting flip 12 == 21\n");
   list list12  = malloc (sizeof (list*));
   assert (list12 != NULL);
   list12->head = node1;

   node1->next = node2;
   node2->next = NULL;
   
   flip (list12);  // == 21
   assert (list12->head == node2);
   assert (node2->next == node1);
   assert (node1->next == NULL);
   printf ("test passed!\n");

   printf ("Test [4] \nTesting flip 01467 == 10647\n");
   list list01467  = malloc (sizeof (list*));
   assert (list01467 != NULL);
   list01467->head = node0;

   node0->next = node1;
   node1->next = node4;
   node4->next = node6;
   node6->next = node7;
   node7->next = NULL;
   
   flip (list01467);  // == 10647
   assert (list01467->head == node1);
   assert (node1->next == node0);
   assert (node0->next == node6);
   assert (node6->next == node4);
   assert (node4->next == node7);
   assert (node7->next == NULL);
 
   // values should be unchanged
   assert (node0->value == 0);
   assert (node1->value == 1);
   assert (node2->value == 2);
   assert (node3->value == 3);
   assert (node4->value == 4);
   assert (node5->value == 5);
   assert (node6->value == 6);
   assert (node7->value == 7);
   assert (node8->value == 8);
   assert (node9->value == 9);
   printf ("Test passed!\n");

   printf ("Test [5]\nTesting flip 2358 == 3285\n");
   list list2358  = malloc (sizeof (list*));
   assert (list2358 != NULL);
   
   list2358->head = node2;
   node2->next = node3;
   node3->next = node5;
   node5->next = node8;
   node8->next = NULL;
   
   flip (list2358);  // == 3285
   assert (list2358->head == node3);
   assert (node3->next == node2);
   assert (node2->next == node8);
   assert (node8->next == node5);
   assert (node5->next == NULL);
   
   // values should be unchanged
   assert (node0->value == 0);
   assert (node1->value == 1);
   assert (node2->value == 2);
   assert (node3->value == 3);
   assert (node4->value == 4);
   assert (node5->value == 5);
   assert (node6->value == 6);
   assert (node7->value == 7);
   assert (node8->value == 8);
   assert (node9->value == 9);
   printf ("test passed!\n");



   printf ("Testing flip 0123456789 == 1032547698\n");
   list list0123456789  = malloc (sizeof (list*));
   assert (list0123456789 != NULL);

   list0123456789->head = node0;
   node0->next = node1;
   node1->next = node2;
   node2->next = node3;
   node3->next = node4;
   node4->next = node5;
   node5->next = node6;
   node6->next = node7;
   node7->next = node8;
   node8->next = node9;
   node9->next = NULL;

   flip (list0123456789); // == 1032547698
   
   assert (list0123456789->head == node1);
   assert (node1->next == node0);
   assert (node0->next == node3);
   assert (node3->next == node2);
   assert (node2->next == node5);
   assert (node5->next == node4);
   assert (node4->next == node7);
   assert (node7->next == node6);
   assert (node6->next == node9);
   assert (node9->next == node8);
   assert (node8->next == NULL);
   
   assert (node0->value == 0);
   assert (node1->value == 1);
   assert (node2->value == 2);
   assert (node3->value == 3);
   assert (node4->value == 4);
   assert (node5->value == 5);
   assert (node6->value == 6);
   assert (node7->value == 7);
   assert (node8->value == 8);
   assert (node9->value == 9);
   printf ("Test passed!\n");


   
   // free the nodes - not needed in subsequent tests
   free (node0);
   free (node1);
   free (node2);
   free (node3);
   free (node4);
   free (node5);
   free (node6);
   free (node7);
   free (node8);
   free (node9);
   
   printf ("Test passed!\n");
}   



static node *newNode (int item) {
   node *new = malloc (sizeof (node));
   assert (new != NULL);
   new->value = item;
   new->next  = NULL;
   
   return new;
}


void show (list items) {
   link current = items->head; 
   while (current != NULL) {
      printf ("%d -> ",current->value);
      fflush (stdout);
      current = current->next;
   }
   printf ("X\n");
}
