/** file at3.c
 * @author Barrett Wolfson
 *
 * Program to populate an array with random numbers and sort it
 */

#include "print_arrays.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SAMPLE_INT_ARRAY_SIZE (10)

/**
 * @return 0, Indicating success.
 */

int main() {
  int i; // Loop counter
  int a[SAMPLE_INT_ARRAY_SIZE]; // Sample array for demonstration
 
  //change seed of random integers once per run of the program
  srand(time(NULL));
 
  //fill array with random integers
  populate_random_int_array(a, SAMPLE_INT_ARRAY_SIZE);
  
  //print the array of random ints;
  printf("Here is the array of random integers:\n");
  print_int_array(a, SAMPLE_INT_ARRAY_SIZE);

  //sort the array
  bubble_sort(a, SAMPLE_INT_ARRAY_SIZE);

  //print the sorted array
  printf("Here is the sorted array:\n");
  print_int_array(a, SAMPLE_INT_ARRAY_SIZE);

  return 0;
}











