/**File which holds implementations of queue functions
 * @author Barrett Wolfson
 */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
 
/** creates a circular buffer implementation of a queue in memory
 * @param max_cells the number of cells in the queue
 * @return Pointer to the queue
 */
Queue *create_queue(int max_cells){
  Queue* queue;
  queue = (Queue*)malloc(sizeof(Queue)); //allocate memory for the Queue pointer

  if(queue == NULL) return NULL; //Error--unable to allocate

  // Fill in the struct
  queue->max_cells = max_cells;
  queue->cells_used = 0;

  // Now allocate space for the queue entries
  queue->buffer = malloc(sizeof(void*)* max_cells); //allocates an array of size max_cells of void pointers
  if(queue->buffer == NULL){
    free(queue); //Unable to allocate queue entries, so free the struct
    return NULL;
  }
  queue->head_ptr = 0; //both start at first space of allocated array
  queue->tail_ptr = 0;

  return queue;
}

/** add an element to the queue
 * @param which_queue Pointer to target queue struct
 * @param ptr Pointer to be added to the queue
 * @return int -1 for failed add, 0 for successful enqueueing
 */
int enqueue(Queue *which_queue, void* ptr){
  if(which_queue->cells_used >= which_queue->max_cells){
    which_queue->cells_used = which_queue->max_cells;
    return -1; //Queue overflow
  }
  else{
    if(which_queue->head_ptr >= which_queue->max_cells){
      which_queue->head_ptr = 0;
    }
    // enqueue the ptr
    which_queue->buffer[which_queue->head_ptr] = ptr; //store the pointer on the queue
    which_queue->head_ptr++; //point to the next free cell
    which_queue->cells_used++;
    return 0; //success
  }
}

/** remove an element from the queue
 * @param which_queue the target queue which we are taking an element from
 * @return pointer to the removed element
 */
void* dequeue(Queue *which_queue) {
  void * element;
  if (which_queue->cells_used <= 0) {
    which_queue->cells_used = 0;
    printf("Queue underflow\n");
    return NULL;
  } 
    
  element = which_queue->buffer[which_queue->tail_ptr];
  which_queue->tail_ptr++;
  which_queue->cells_used--;
  if (which_queue->tail_ptr == which_queue->max_cells) {
    which_queue->tail_ptr = 0;
  }
        
  return element;
}

 

