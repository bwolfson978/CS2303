#include <stdlib.h>
#include <stdio.h>
#include "grade_info.h"
/**
 * @param grades[] array of grades 
 * @param size the number of grade values in the array
 * @return void returns nothing
 */
void grade_info(int grades[], int size)
{
  int average, smallest, largest, count, sum;

  smallest = grades[0];
  largest = grades[0];
  count = 0;
  sum = 0;
  for (int i = 0; i < size; i++)
  {
    if(grades[i]>largest)
    {
      largest = grades[i];
    }
    if(grades[i]<smallest)
    {
      smallest = grades[i];
    }
    
    sum += grades[i];
    count++;
  }

  average =sum/count;
  printf("The smallest grade in the array is %d\n", smallest);
  printf("The largest grade in the array is %d\n", largest);
  printf("The average grade is %d\n", average);    
}
