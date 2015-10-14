/** file at2.c
 * @author Barrett Wolfson
 *
 * Program to demonstrate arrays in C by populating an array from cmd line inputs then printing out it's values
 */

#include "print_arrays.h"
#include "sort.h"
#include <stdio.h>

#define SAMPLE_INT_ARRAY_SIZE (10)

/** Modified program for demonstrating arrays. It fills them from the command line and then and prints them.
 * @return 0, Indicating success.
 */

int main(int argc, const char* argv[]) {
  int i; // Loop counter
  int a[SAMPLE_INT_ARRAY_SIZE]; // Sample array for demonstration

  int num_entries;
  num_entries = populate_int_array_from_cmdline(argc, argv, a, SAMPLE_INT_ARRAY_SIZE);
  if (num_entries < SAMPLE_INT_ARRAY_SIZE){ //if less inputs then size of array
    // print only the supplied values (avoid weird numbers for empty spaces)
    printf("Here is the array of integers you entered:\n");
    print_int_array(a, num_entries);
  }
  else {
    //print every value stored into the array
    printf("Here is the array of integers you entered:\n");
    print_int_array(a, SAMPLE_INT_ARRAY_SIZE);
  }
    
  // now sort the array
  bubble_sort(a, SAMPLE_INT_ARRAY_SIZE);

  // now print the entire array
  printf("Here is the array sorted in ascending order:\n");
   print_int_array(a, SAMPLE_INT_ARRAY_SIZE); //this function
  // will print 0's and random big numbers if less cmd line inputs then size
    
  return 0; // Success!
}
