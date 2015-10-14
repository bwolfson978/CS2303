/** Struct to define a queue; each entry can hold a pointer to anything
 * @author Barrett Wolfson
 */

struct queue{
  void **buffer; //array of void pointers in memory
  int tail_ptr; //index number of tail of queue
  int head_ptr; //index number of next available cell in queue
  int max_cells; //Maximum number of entries in the queue
  int cells_used; //Currently used number of cells 
};

typedef struct queue Queue; //for convenience

// Function Prototypes

Queue *create_queue(int max_cells);

int enqueue(Queue *which_queue, void* ptr);

void *dequeue(Queue *which_queue);

