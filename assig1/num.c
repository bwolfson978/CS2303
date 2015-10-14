#include <stdio.h>
#include <stdlib.h>
#include "grade_info.h"

/* Very simple program to demonstrate reading an arbitrary amount of numbers from the command line.
 * Usage;
 *	./num some_number another_number 
 * Example:
 *	./num 2014 45 78 99
 *
 */
#define MAX_GRADES (20) //max amount of inputs for grades


int main (int argc, const char* argv[]) {

  if (argc < 2) { // Check that there was an entry
    printf("must enter a number on the command line!\n");
    return 1; // Indicate Failure
  }
  
  int grades[MAX_GRADES]; // declare array of grades

  if ((argc - 1) > MAX_GRADES)
  {
    printf("The max amount of grades allowed is %d, only the first %d inputs have been processed.\n", MAX_GRADES, MAX_GRADES);
  }

  for (int i = 0; i < MAX_GRADES; i++)
  {
    if ((i + 1) > (argc - 1)) // stop if all cmd line args have been processed
    {
      break;
    }
    grades[i] = atoi(argv[i+1]); // populate array with cmd line values
  }

  //print all the elements of the array
  for (int j = 0; j < MAX_GRADES; j++)
  {
    if ((j + 1) > (argc -1))
    {
      break;
    }
    printf("%d\n", grades[j]);
  }

  if ((argc - 1) < MAX_GRADES)
  {
    grade_info(grades,(argc -1));
  }
  else
  {
    grade_info(grades, MAX_GRADES);
  }

  return 0; // Indicate success!
  
}
