/*
 *  backToFront.h
 *  2013 s1 Prac Exam
 *  UNSW comp1917
 *
 *  Unleashed by Richard Buckland and Devid Collien
 *  Share freely CC-BY-3.0
 *
 */

typedef struct _node *nodePtr;

typedef struct _node {
   int      value;
   nodePtr  next;
} node;

// given a list of nodes this function takes the node
// at the end of the list and moves it to the front
// of the list  by changing pointers, leaving the relative
// order of the other nodes unchanged.
// note: this function must not create new nodes
// or change the value field of existing nodes.
nodePtr backToFront (nodePtr items);
