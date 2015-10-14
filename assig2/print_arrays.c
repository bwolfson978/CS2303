/** file print_arrays.c
 * @author Mike Ciaraldi
 * @author Barrett Wolfson
 * Functions for printing arrays.
 */

#include <stdlib.h>
#include <stdio.h>
#include "print_arrays.h"

/** Print an array of ints, one per line
    @param a Array to print
    @param num_elements Number of elements in the array
*/

void print_int_array(int a[], int num_elements) {
  int i; // Loop counter

  for (i = 0; i < num_elements; i++) {
    printf("%d\n", a[i]);
  }
}

/** Print an array of doubles, one per line
  * @param a Array to print
  * @param num_elements Number of elements in the array
  */
void print_double_array(double b[], int num_elements) {
  int i; // Loop counter

  for(i = 0; i < num_elements; i++) {
    printf("%lf\n", b[i]);
  }
}

/** Populate an array of ints, one per line, from the command line.
    @param argc number of command line args
    @param argv Array of command line inputs
    @param a Array to print
    @param num_elements Number of elements in the array
    @return the number of entries that were processed
*/

int populate_int_array_from_cmdline(int argc, const char* argv[], int a[], int num_elements) {
  // Fill the array with integers entered on the command line
  int num_entries = 0;
  for (int i = 0; i < num_elements; i++)
  {
    if((i+1)>(argc-1))
    {
      num_entries = argc - 1;
      break;
    }
    a[i] = atoi(argv[i+1]);
    num_entries += 1;
  }
  return num_entries;
}


