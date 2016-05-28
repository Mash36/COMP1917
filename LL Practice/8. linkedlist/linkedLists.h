//
//  linkedLists.h
//  lectureThing
//
//  Created by Steven Strijakov on 19/05/2014.
//  Updated 09/05/2015
//  Copyright (c) 2014 Steven Strijakov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _node* Node;
typedef struct _list* List;

// Create a new node given some value
Node newNode(int v);

// Creates a new list
List newList();

// Returns the length of the list
int lengthOfList(List start);

// Adds a node at the beginning of the list
void subpend(List list, int value);

// Adds a node at the end of the list
void append(List list, int value);

// Destrrrryyoooooyyyy
void destroy(List list);

// Print out a list in the form
// 1->2->3->NULL
void printList(List l);

// Reverses a given list
// Optimal solution only goes through the list once
void reverse(List start);

// Adds a node at the given position
// If the value is negative, or the pos is greater than the
// size, prints an error message and does not change the list
void insert(List list, int pos, int value);

// Given a value, inserts it into the list in sorted
// ascending order
void insort(List list, int value);

// Deletes a given node in the list
// Same conditions as insert
void delete(List start, int pos);