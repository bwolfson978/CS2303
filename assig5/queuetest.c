/**File to demonstrate queue implementation functionality: does things such as trying to dequeue off of an empty queue and add more items to a queue than it is allowed to accept. 
 * @author Barrett Wolfson
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    Queue* queue;
    queue = create_queue(5);
    char *data[] = {"first" , "second", "third", "fourth" , "fifth", "sixth"};
    int i;
    for (i = 0; i < 6; i++) { //try to add on 6 items to a queue with max_cells 5
        printf("enqueue: %s\n", data[i]);
        enqueue(queue, data[i]);
    }
    printf("\n");
    for (i = 0; i < 6; i++) {
        /* need to cast void pointers to char pointers */
        printf("dequeue: %s\n", (char *)dequeue(queue)); //shows the 6th char* didn't make it on, 
							 //shows can't dequeue off an empty queue
    } 
}
