#include <stdio.h>
#include <stdlib.h>

/* Very simple program to demonstrate reading a number from the command line and * testing whether or not that number is a leap year.
 *
 * Usage;
 *	./leap some_year_number_over_1751
 * Example:
 *	./leap 2014
 *
 */

int main (int argc, const char* argv[]) {

  if (argc < 2) { // Check that there was an entry 
    printf("must enter a year number on the command line!\n");
    return 1; //indicate failure
  }

  int n; // the integer read from the command line
  n = atoi(argv[1]); // Get string from command line; convert to int
  
  // Check if the entered year is within the range this program can handle
  if (n < 1752) 
  {
    printf("This program cannot test the year %d. It only handles the year 1752 and after.\n", n);
  }
  
  /* Check if the entered year is a leap year (evenly divisible by 4)
   * with the following exception: if the year is evenly divisible by 100,
   * it must also be evenly divisible by 400 to be considered a leap year.
   */
  else if (n % 4 == 0)
  {
    if (n % 100 == 0)
    {
      if  (n % 400 == 0)
      {
        printf("The year %d is a leap year\n", n);
      }
      else
      {
        printf("The year %d is not a leap year\n", n);
      }
    }
    else
    {
      printf("The year %d is a leap year\n", n);
    }
  }
 
  // otherwise the year is not a leap year.
  else
  {
    printf("The year %d is not a leap year\n", n);
  }

  return 0; // Indicate success!
}
