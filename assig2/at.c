/** file at.c
 * @author Mike Ciaraldi
 *
 * Program to demonstrate arrays in C.
 */

#include "print_arrays.h"
#include <stdio.h>

#define SAMPLE_INT_ARRAY_SIZE (10)
#define SAMPLE_DOUBLE_ARRAY_SIZE (5)

/** Main program for demonstrating arrays. It fills them and prints them.
 * @return 0, Indicating success.
 */

int main() {
  int i; // Loop counter
  int j; // loop counter for populating the array of doubles

  int a[SAMPLE_INT_ARRAY_SIZE]; // Sample array for demonstration

  double b[SAMPLE_DOUBLE_ARRAY_SIZE]; //sample array of doubles
 
  // Fill the array with consecutive integers
  for (i = 0; i < SAMPLE_INT_ARRAY_SIZE; i++) a[i] = i;

  // fill the double array with consecutive doubles
  double d = 0.0;
  for (j = 0; j < SAMPLE_DOUBLE_ARRAY_SIZE; j++) {
    b[j] = d;
    d += 1.0;
  }  

  // Now print out the int array
  printf("here is an array of integers:\n");
  print_int_array(a, SAMPLE_INT_ARRAY_SIZE);
  
  // Now print out the double array
  printf("here is an array of doubles:\n");
  print_double_array(b, SAMPLE_DOUBLE_ARRAY_SIZE);

  return 0; // Success!
}
