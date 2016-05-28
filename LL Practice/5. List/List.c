
//Written by Michael Simarta
//With the help of Bernice Chen
//list.c file that implements all functions declared in list.h
//implement the median() function here
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"
 
typedef struct _node {
    int value;
    Node next;
} node;
 
typedef struct _list {
    Node head;
} list;

//int numItems (List l); 
//when the median() function is complete,
//compile with testList.c, type
//"gcc -Wall -Werror -O -o test testList.c List.c"
//to run program, type
//"./test"
 
//TODO
//Read List.h to help you look at the hints
//find the median value
//given a list X
//(Empty List)
//then median (list);
//it will return 0 
 //
//given a list 1->X
//then median (list);
//it will return 1  
//
//given a list 0->1->2->X
//then median (list);
//it will return 1
//
//given a list 2->3->5->6->X
//then median (list);    
//it will return 4
//because the middle is the average of the 2 middle numbers
//(3+5)/2 = 4.
//We will not test where the average will lead to decimal places
//
//given a list 2->3->5->6->1000->X
//then median (list);
//it will return 5
int median(List l) {
  int median = 0;
  if (numItems (l) == 0)
  {
    median = 0;
  } else if (numItems(l) == 1)
  {
    median = getValue (l,0);
  } else if (numItems(l) % 2 == 1)
  {
    median = getValue (l, (numItems(l)-1)/2);
  } else if (numItems(l) % 2 == 0)
  {
    median = (getValue (l, (numItems(l)/2)) + getValue (l, numItems(l)/2 -1)) /2;
  }
  return median;
}
 
//returns a new list of length 0
List newList() {
  List newList = malloc(sizeof(struct _node));
  newList->head = NULL;
  return newList;
}
 
//frees everything malloced for the list
void destroy(List l) {
  Node current = l->head;
  Node previous = NULL;
  while (current != NULL){
    previous = current;
    current = previous->next;
    free(previous);
  }
  free (l);
}
 
//appends a node of value to the end of the list
void append(List l, int value) {
  Node append = malloc(sizeof(struct _node));
  append->value = value;
  append->next = NULL;
  if (l->head == NULL)
  {
    l->head = append;
  } else {
    Node current = l->head;
    while (current->next != NULL){
      current = current->next;
    }
    current->next = append;
  }
}
//returns the int value of the node at index
//assumes input index is within range of the list's length
//starts from 000000000000!!!!!!!!!!!!!!!!!!!!
int getValue(List l, int index) {
  int counter = 0;
  Node current = l->head;
  while (counter < index){
    counter++;
    current = current->next;
  }
  return current->value;
}

// count the number of items in the list
int numItems (List l) {
  int counter = 0;
  Node current = l->head;
  while (current != NULL){
    counter++;
    current = current->next;
  }
  return counter;
}