/** File print_arrays.c
 * @author Mike Ciaraldi
 *
 * Header file for functions that print arrays.
 */

#ifndef PRINT_ARRAYS_H
#define PRINT_ARRAYS_H

// function prototypes:

void print_int_array(int a[], int size);
void print_double_array(double a[], int size);
int populate_int_array_from_cmdline(int argc, const char* argv[], int a[], int size);
void print_double_array_from_cmdline(int argc, const char* argv[], double b[], int size);

#endif
