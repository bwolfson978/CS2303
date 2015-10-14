This assignment implements stacks, queues, and binary trees in C.

### Part1: Stack and Queue Implementation
------
Function prototypes for the stack/queue data structure implementation are found in stack.h/queue.h, function implementations are found in stack.c/queue.c. The program stacktest.c tests the stack data structure by pushing and popping items elements, including attempting to push more elements than the stack can hold, popping more elements than are on the stack, and confirming correct functionality. The program queuetest.c tests the queue data structure implementation by adding 6 strings to a queue that is set to only hold maximum five, then attempts to remove more than five. The program shows that the 6th attempt to add a cell is not registered by the queue, and the attempt to remove a cell from an empty queue results in a queue underflow and reception of a null pointer. This test program can be run by typing "make clean", "make", then "./queuetest" into the command line.

### Part2: Binary Tree Implementation
------
Function prototypes for the binary tree data structure implementation are found in tnode.h, and function implementations are found in tnode.c The program tnodetest.c populates a binary tree with 6 pre-set strings and then in-order traverses the tree and prints the strings in ascending order. The program tnoderandom.c does the same thing except with randomly generated strings using the function from assignment 3. These test programs can be run by typing "make clean","make", then either "./tnodetest" or "./tnoderandom" into the command line.
