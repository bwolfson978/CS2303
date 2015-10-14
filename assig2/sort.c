/** File
 * @author Barrett Wolfson
 * Source file for array sorting functions
 */
#define MAX_RAND_INT (10)
#include <stdlib.h>

/**
 * sorts the given array of integers into ascending order using bubble sort
 * @param a Array of integers to be sorted
 * @param size number of elements in the array
 */
void bubble_sort(int a[], int size) {
  int i,j,temp;
  for(i = 0; i < size; i++){
    for(j = 0; j < size; j++){
      if(a[i] < a[j]){
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
}

/**
 * generates a random integer from 0 to max inclusive
 * @param max the largest possible number returned 
 * @return the generated random integer
 */
int gen_random_integer(int max){ 
  int r; //the random integer to be generated
  r = rand() % (max + 1); //generate random int between 0 and max inclusive
  return r;
}

/**
 * populates an array with random integers
 * @param a the Array to be filled
 * @param size the length of the array
 */
void populate_random_int_array(int a[], int size){
  int i;
  for(i = 0; i < size; i++){
    a[i] = gen_random_integer(MAX_RAND_INT);
  }
}


