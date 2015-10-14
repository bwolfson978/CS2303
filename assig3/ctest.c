#include <stdio.h>
#include <string.h>
// string.h covers the C-style string functions.
#include "mystring.h"
#include "account.h"
#include <time.h>

/** ctest.c
 * Program to demonstrate character arrays and
 * dynamically-allocated memory.
 * @author Mike Ciaraldi
 */

const int MAX_CHARS = 20; // Maximum number of characters in array

int main()
{

  srand(time(NULL)); //reset seed for random numbers everytime we run

  char a1[MAX_CHARS + 1]; // Character array--initially empty
  char a2[] = "Hello"; // Character array--unsized but initialized
  char a3[MAX_CHARS + 1]; // Character array--we will underfill it
  char* p1 = "Hello"; // Pointer to constant string
  char* p2;           // Will be a pointer to dynamically-allocated string
  int copy_limit;     // Maximum characters to copy.
  char* test_copy[MAX_CHARS + 1]; //character array initially empty
  char* p3; //pointer to dynamically-allocated string

  strcpy(a3, "Hello, also"); // Initialize uinderfilled character array

  /* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
  */
  printf("Pointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3);
  printf("          p1 = %p p2 = %p\n", p1, p2);

  strcpy(a1, "Hi"); // Initialize character array

  printf("a1 = %s\n", a1);
  printf("a2 = %s\n", a2);
  printf("a3 = %s\n", a3);

  // Be sure there is a terminator character in the last element of the array
  a1[MAX_CHARS] = '\0';

  // Concatenate two character arrays, then print.
  strcat(a1, a2);
  printf("Concatenating a2 to the end of a1\n");
  printf("a1 = %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
  printf("Concatenating a2 to the end of a1, with copy_limit = %d\n",
	 copy_limit);
  if (copy_limit > 0) strncat(a1, a2, copy_limit);
  printf("a1 = %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
  printf("Concatenating a3 to the end of a1, with copy_limit = %d\n",
	 copy_limit);
  if (copy_limit > 0) strncat(a1, a3, copy_limit);
  printf("a1 = %s\n", a1);

  // Duplicate a string, using my function, then print
  printf("Before dup, pointer a2 = %p, contents = %s\n", a2, a2);
  p2 = mystrdup(a2);
  printf("Duplicated string: \n");
  printf("Pointer p2 = %p, contents = %s\n", p2, p2);
  
  char b1[MAX_CHARS + 1]; // Character array--initially empty
  char b2[] = "Hello"; // Character array--unsized but initialized
  char b3[MAX_CHARS + 1]; // Character array--we will underfill it
  char* q1 = "Hello"; // Pointer to constant string
  char* q2;           // Will be a pointer to dynamically-allocated string
  int copy_b_limit;     // Maximum characters to copy.
  char test_b_copy[MAX_CHARS + 1]; //character array initially empty
  char* q3; //pointer to dynamically-allocated string

  mystrcpy(b3, "Hello, also"); // Initialize uinderfilled character array

/////////////////MY VERSIONS//////////////////////////
  printf("\n\n");
  printf("My Versions of the C string library functions\n\n");
  /* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
  */
  printf("Pointers: b1 = %p, b2 = %p, b3 = %p\n", b1, b2, b3);
  printf("          q1 = %p q2 = %p\n", b1, b2);

  mystrcpy(b1, "Hi"); // Initialize character array

  printf("b1 = %s\n", b1);
  printf("b2 = %s\n", b2);
  printf("b3 = %s\n", b3);

  // Be sure there is a terminator character in the last element of the array
  b1[MAX_CHARS] = '\0';

  // Concatenate two character arrays, then print.
  mystrcat(b1, b2);
  printf("Concatenating b2 to the end of b1\n");
  printf("b1 = %s\n", b1);

  // Concatenate two character arrays safely, then print.
  copy_b_limit = MAX_CHARS - mystrlen(b1); // How much space is left?
  printf("Concatenating b2 to the end of b1, with copy_b_limit = %d\n",
	 copy_b_limit);
  if (copy_b_limit > 0) mystrncat(b1, b2, copy_b_limit);
  printf("b1 = %s\n", b1);

  // Concatenate two character arrays safely, then print.
  copy_b_limit = MAX_CHARS - mystrlen(b1); // How much space is left?
  printf("Concatenating b3 to the end of b1, with copy_b_limit = %d\n",
	 copy_b_limit);
  if (copy_b_limit > 0) mystrncat(b1, b3, copy_b_limit);
  printf("b1 = %s\n", b1);

  // Duplicate a string, using my function, then print
  printf("Before dup, pointer b2 = %p, contents = %s\n", b2, b2);
  q2 = mystrdup(b2);
  printf("Duplicated string: \n");
  printf("Pointer q2 = %p, contents = %s\n", q2, q2);
 
  // Duplicate string when length is greater than limit, using my function, then print
  printf("Before dup, pointer b2 = %p, contents = %s\n", b2,b2);
  q2 = mystrndup(b2, 3);
  printf("duplicated string up to 3 chars: \n");
  printf("Pointer q2 = %p, contexts = %s\n", q2,q2);
 
  // Duplicate string when length is equal to limit, using my function, then print
  printf("Before dup, pointer b2 = %p, contents = %s\n", b2,b2);
  q2 = mystrndup(b2, 5);
  printf("duplicated string up to 5 chars: \n");
  printf("Pointer q2 = %p, contexts = %s\n", q2,q2);
 
  // Duplicate string when length is greater than limit, using my function, then print
  printf("Before dup, pointer b2 = %p, contents = %s\n", b2,b2);
  q2 = mystrndup(b2, 7);
  printf("duplicated string up to 7 chars: \n");
  printf("Pointer q2 = %p, contexts = %s\n", q2,q2);
 
  q3 = mystrcpy(test_b_copy, q1);
  printf("length of str 'hello' is: %i\n", mystrlen(q1));
  printf("copy of str 'Hello' is: %s\n", q3);
  char* c1 = "bye";
  //testing when string length is greater than limit
  q3 = mystrncpy(test_b_copy, c1, 2);
  printf("2 char copy of str 'bye' onto string 'Hello' is: %s\n", q3);
  //testing when string length is less than limit
  q3 = mystrncpy(test_b_copy, c1, 5);
  printf("5 char copy of str 'bye' onto string 'byllo' is: %s\n", q3);
  //testing when string length is equal to limit
  q3 = mystrncpy(test_b_copy, q1, 5);
  printf("5 char copy of str 'Hello' is: %s\n", q3);

////////////////////ACCOUNT STRUCT FUNCTIONS////////////////////////////////
  printf("\n\n");
  printf("Struct Function Demonstration: \n\n");
  printf("demonstrate create_account():\n\n");
  ACCOUNT* act;
  char* name;
  int account_number, dollars;
  name = "Barry";
  account_number = 2;
  dollars = 500;
  act = create_account(name,account_number,dollars);
  print_account(act);
  
  printf("demonstrate two random_account()s:\n\n");
  ACCOUNT* b;
  ACCOUNT* c;
  b = random_account();
  print_account(b);
  c = random_account();
  print_account(c);  

  //testing random account array generation
  printf("demonstrating populating an array of 3 pointers to ACCOUNT structs\n\n");  
  ACCOUNT **accounts;
  accounts = make_accounts(3);
  print_accounts(accounts, 3);  
  printf("account shallow copies (copy the pointers, still pointing to same thing in memory): \n\n");
  ACCOUNT **account_copies;
  account_copies = shallow_copy(accounts, 3);
  print_accounts(account_copies, 3);
  printf("account deep copies (duplicate struct held at pointer location,assign to a new pointer and thus new location in memory): \n\n");
  ACCOUNT **deep_copies;
  deep_copies = deep_copy(accounts, 3);
  print_accounts(deep_copies, 3);
  //attempting to free all pointers from structs
  deallocate(accounts, 3); 
  return 0;
}
