//
//  linkedLists.c
//  lectureThing
//
//  Created by Steven Strijakov on 19/05/2014.
//  Updated 09/05/2015
//  Copyright (c) 2014 Steven Strijakov. All rights reserved.
//

#include "linkedLists.h"

void test(void);

typedef struct _node {
    int data;
    Node next;
} node;

typedef struct _list {
    Node head;
} list;

int main(int argc, char* argv[]) {
   printf("TESTING\n");
   test();
   printf("ALL TEST PASSED! YOU ARE AWESOME!\n");
   return EXIT_SUCCESS;
}

// Create a new node given some value
Node newNode(int v) {
   Node newNode = malloc(sizeof(node));
   newNode->data = v;
   newNode->next = NULL;
   return newNode;
}

// Creates a new list
List newList() {
   List newList = malloc(sizeof(list));
   newList->head = NULL;
   return newList;
}

// Returns the length of the list
int lengthOfList(List start) {
   int counter = 0;
   Node current = start->head;
   while (current != NULL) {
      counter++;
      current = current->next;
   }
   return counter;
}

// Adds a node at the beginning of the list
void subpend(List list, int value) {
   Node subpend = malloc(sizeof(node));
   subpend->data = value;
   subpend->next = list->head;
   list->head = subpend;
}

// Adds a node at the end of the list
void append(List list, int value) {
   Node append = malloc(sizeof(node));
   append->data = value;
   append->next = NULL;
   if (list->head == NULL) {
      list->head = append;
   } else {
      Node current = list->head;
      while (current->next != NULL) {
         current = current->next;
      }
      current->next = append;
   }
}

// Destrrrryyoooooyyyy
void destroy(List list) {
   Node destroy = NULL;
   Node current = list->head;
   while (current != NULL) {
      destroy = current;
      current = destroy->next;
      free(destroy);
   }
   free(list);
}

// Print out a list in the form
// 1->2->3->NULL
void printList(List l) {
   Node current = l->head;
   while (current != NULL) {
      printf("%d->", current->data);
      current = current->next;
   }
   printf("NULL\n");
}

// Reverses a given list
// Optimal solution only goes through the list once
void reverse(List start) {
   List reverse = malloc (sizeof(list));
   reverse->head = NULL;
   Node current = start->head;
   while (current != NULL) {
      subpend(reverse, current->data);
      current = current->next;
   }
   start->head = reverse->head;
}

// Adds a node at the given position
// If the value is negative, or the pos is greater than the
// size, prints an error message and does not change the list
void insert(List list, int pos, int value) {
   if (pos >= 0 && pos <= lengthOfList(list)) {
   Node insert = malloc (sizeof(node));
      insert->data = value;
      Node current = list->head;
      int counter = 1;
      if (pos == 0) {
         insert->next = list->head;
         list->head = insert;
      } else {
         while (counter < pos) {
            current = current->next;
            counter++;
         }
         insert->next = current->next;
         current->next = insert;
     }
   } else {
      printf("INVALID INPUT!\n");
   }
}

// Given a value, inserts it into the list in sorted
// ascending order  1->2->4->NULL   3  1->2->3->4->NULL
void insort(List list, int value) {
   Node insort = malloc (sizeof(node));
   insort->data = value;
   if (list->head == NULL) {
      list->head = insort;
      insort->next = NULL;
   } else if (list->head->next == NULL){
      if (list->head->data > value) {
         insort->next = list->head;
         list->head = insort;
      } else {
         insort->next = NULL;
         list->head->next = insort;
      }
   } else {
      Node current = list->head;
      while(value > current->next->data && current->next != NULL) {
         current = current->next;
      }
      insort->next = current->next;
      current->next = insort;
   }
}

// Deletes a given node in the list
// Same conditions as insert
void delete(List start, int pos) {
   if (pos >= 0 && pos <lengthOfList(start)) {
      Node current = start->head;
      if (pos == 0) {
        start->head =start->head->next;
      } else {
         int counter = 0;
         while (counter < pos - 1) {
            current = current->next;
            counter++;
         }
         current->next = current->next->next;
      }
   } else {
      printf("INVALID INPUT!\n");
   }
}

void test(void) {

Node myNode = newNode(2);
assert(myNode->data == 2);
assert(myNode->next == NULL);

List myList = newList();
assert(myList->head == NULL);

assert(lengthOfList(myList) == 0);
printList(myList);

//2->NULL
myList->head = myNode;
assert(lengthOfList(myList) == 1);
printList(myList);

//2->4->NULL
myNode = newNode(4);
myList->head->next = myNode;
assert(lengthOfList(myList) == 2);
printList(myList);

//1->2->4->NULL
subpend(myList, 1);
assert(lengthOfList(myList) == 3);
printList(myList);

//1->2->4->6->NULL
append(myList, 6);
assert(lengthOfList(myList) == 4);
printList(myList);

//1->2->4->5->6->NULL
insort(myList, 5);
assert(lengthOfList(myList) == 5);
printList(myList);

//1->2->10->4->5->6->NULL
insert(myList, 2, 10);
assert(lengthOfList(myList) == 6);
printList(myList);

//1->2->10->4->5->6->8->NULL
insert(myList, 6, 8);
assert(lengthOfList(myList) == 7);
printList(myList);

//8->6->5->4->10->2->1->NULL
reverse(myList);
assert(lengthOfList(myList) == 7);
printList(myList);

//8->6->4->10->2->1->NULL
delete(myList, 2);
assert(lengthOfList(myList) == 6);
printList(myList);

//6->4->10->2->1->NULL
delete(myList, 0);
assert(lengthOfList(myList) == 5);
printList(myList);
List MyList = myList;
printList(MyList);
//destroyyyyy
destroy(myList);
}
