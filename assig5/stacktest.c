/**File to test the stack functions
 * @author Barrett Wolfson
 */

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

typedef struct {
  int x;
  double y;
} Foo; // Just some arbitrary struct


int main() {
  const int max_entries = 5; // size of stack
  Foo* new_foo1;
  Foo* new_foo2;
  Foo* new_foo3;
  Foo* new_foo4; 
  Foo* new_foo5;
  Foo* new_foo6;
  Foo* returned_foo;

  // First, create a stack
  Stack *new_stackA = create_stack(max_entries);
  ///////////////////////TEST A/////////////////////
  /* push 3 elements onto the stack, pop 2 off, and push on one  more */
  printf("TEST A: push 3 elements onto stack, pop two off, and push on one more.\n\n");

  // Allocate a Foo and push it onto the stack.
  new_foo1 = (Foo *) malloc(sizeof(Foo));
  new_foo1->x = 6;
  new_foo1->y = 14.79;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo1->x, new_foo1->y);
  push(new_stackA, (void *) new_foo1);

  // Allocate another Foo and push it onto the stack.
  new_foo2 = (Foo *) malloc(sizeof(Foo));
  new_foo2->x = 217;
  new_foo2->y = 3.14159;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo2->x, new_foo2->y);
  push(new_stackA, (void *) new_foo2);
  
  // Allocate a 3rd Foo and push it onto the stack.
  new_foo3 = (Foo *) malloc(sizeof(Foo));
  new_foo3->x = 188;
  new_foo3->y = 2.54589;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo3->x, new_foo3->y);
  push(new_stackA, (void *) new_foo3);
 
  // Peek at the top of the stack
  returned_foo = (Foo *) peek(new_stackA);
  printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

  // Retrieve two Foos and print them.
  returned_foo = (Foo *) pop(new_stackA);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  returned_foo = (Foo *) pop(new_stackA);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  
  // Push a new Foo onto the stack
  new_foo4 = (Foo *) malloc(sizeof(Foo));
  new_foo4->x = 97;
  new_foo4->y = 5.123;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo4->x, new_foo4->y);
  push(new_stackA, (void *) new_foo4);

  // Peek at the top of the stack
  returned_foo = (Foo *) peek(new_stackA);
  printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

   // Retrieve two Foos and print them.
  returned_foo = (Foo *) pop(new_stackA);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  returned_foo = (Foo *) pop(new_stackA);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
 
  // Clean up
  delete_stack(new_stackA);
  free(new_foo1);
  free(new_foo2);
  free(new_foo3);
  free(new_foo4);
  
  //////////////////TEST B////////////////////////
  /* push more than five elements, confirm theat function correctly handles */
  // First, create a stack
  Stack *new_stackB = create_stack(max_entries);
  printf("\nTESTB: push more than 5 elements, confirm correct functionality\n\n");

  // Allocate a Foo and push it onto the stack.
  new_foo1 = (Foo *) malloc(sizeof(Foo));
  new_foo1->x = 6;
  new_foo1->y = 14.79;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo1->x, new_foo1->y);
  push(new_stackB, (void *) new_foo1);

  // Allocate another Foo and push it onto the stack.
  new_foo2 = (Foo *) malloc(sizeof(Foo));
  new_foo2->x = 217;
  new_foo2->y = 3.14159;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo2->x, new_foo2->y);
  push(new_stackB, (void *) new_foo2);
  
  // Allocate a 3rd Foo and push it onto the stack.
  new_foo3 = (Foo *) malloc(sizeof(Foo));
  new_foo3->x = 188;
  new_foo3->y = 2.54589;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo3->x, new_foo3->y);
  push(new_stackB, (void *) new_foo3);
 
  // Allocate a 4th Foo and push it onto the stack.
  new_foo4 = (Foo *) malloc(sizeof(Foo));
  new_foo4->x = 9;
  new_foo4->y = 12.2;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo4->x, new_foo4->y);
  push(new_stackB, (void *) new_foo4);

  // Allocate a 5th Foo and push it onto the stack.
  new_foo5 = (Foo *) malloc(sizeof(Foo));
  new_foo5->x = 145;
  new_foo5->y = 1.234;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo5->x, new_foo5->y);
  push(new_stackB, (void *) new_foo5);
 
  // Allocate a 6th Foo and push it onto the stack.
  new_foo6 = (Foo *) malloc(sizeof(Foo));
  new_foo6->x = 6;
  new_foo6->y = 14.79;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo6->x, new_foo6->y);
  push(new_stackB, (void *) new_foo6);
 
  //make sure that the 6th foo didn't make it onto the stack b/c max size 5
   // Peek at the top of the stack
  returned_foo = (Foo *) peek(new_stackB);
  printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

  // Clean up
  delete_stack(new_stackB);
  free(new_foo1);
  free(new_foo2);
  free(new_foo3);
  free(new_foo4);
  free(new_foo5);
  free(new_foo6);

  //////////////////TEST C////////////////////////
  /* POP more than five elements, confirm that function correctly handles */
  // First, create a stack
  Stack *new_stackC = create_stack(max_entries);
  printf("\nTESTC: POP more than 5 elements, confirm correct functionality\n\n");

  // Allocate a Foo and push it onto the stack.
  new_foo1 = (Foo *) malloc(sizeof(Foo));
  new_foo1->x = 6;
  new_foo1->y = 14.79;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo1->x, new_foo1->y);
  push(new_stackC, (void *) new_foo1);

  // Allocate another Foo and push it onto the stack.
  new_foo2 = (Foo *) malloc(sizeof(Foo));
  new_foo2->x = 217;
  new_foo2->y = 3.14159;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo2->x, new_foo2->y);
  push(new_stackC, (void *) new_foo2);
  
  // Allocate a 3rd Foo and push it onto the stack.
  new_foo3 = (Foo *) malloc(sizeof(Foo));
  new_foo3->x = 188;
  new_foo3->y = 2.54589;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo3->x, new_foo3->y);
  push(new_stackC, (void *) new_foo3);
 
  // Allocate a 4th Foo and push it onto the stack.
  new_foo4 = (Foo *) malloc(sizeof(Foo));
  new_foo4->x = 9;
  new_foo4->y = 12.2;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo4->x, new_foo4->y);
  push(new_stackC, (void *) new_foo4);

  // Allocate a 5th Foo and push it onto the stack.
  new_foo5 = (Foo *) malloc(sizeof(Foo));
  new_foo5->x = 145;
  new_foo5->y = 1.234;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo5->x, new_foo5->y);
  push(new_stackC, (void *) new_foo5);
 
 // Peek at the top of the stack
  returned_foo = (Foo *) peek(new_stackC);
  printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  
  //try to pop more than five Foos off of the top of the stack
  returned_foo = (Foo *) pop(new_stackC);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  returned_foo = (Foo *) pop(new_stackC);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  returned_foo = (Foo *) pop(new_stackC);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  returned_foo = (Foo *) pop(new_stackC);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  returned_foo = (Foo *) pop(new_stackC);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  printf("Size of stack after fifth pop= %d\n", new_stackC->cells_used);

  returned_foo = (Foo *) pop(new_stackC);
    // Clean up
  delete_stack(new_stackC);
  free(new_foo1);
  free(new_foo2);
  free(new_foo3);
  free(new_foo4);
  free(new_foo5);


  return 0;
}
