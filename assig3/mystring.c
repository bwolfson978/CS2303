/** mystring.c
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  mystrcpy(newstr, src);
  return newstr;
}

/** Duplicates a C-style string up to n characters. If s is longer than n, only n characters are copied, and a '/0' is added. malloc() and free() are used to obtain memory for the new string.
 * @param s Pointer to the string to be duplicated
 * @param n the number of characters to be duplicated from s
 * @return Pointer to the string duplicate
 */
char *mystrndup(const char *s, size_t n){
  int length; //length of the source string
  char* newstr; //Pointer to memory which will hold new string

  length = mystrlen(s) + 1; //leave space for terminator
  newstr = (char*) malloc(length); //allocate memory for newstr

  //if no memory was available, return null pointer
  if (newstr == 0) return (char *) 0;

  //otherwise, copy string up through n chars and return pointer to new string
  mystrncpy(newstr, s, n);
  *(newstr+length) = '\0';
  return newstr; 
}

/** Calculates the length of a string
 * @param src pointer to the target string
 * @return the length of the string (int)
 */
size_t mystrlen(const char *src){
  int size; //size of the source str
  char currChar; //current char within the array of characters
  size = 0; 
  currChar = *src;
  while(currChar != '\0'){
    size++;
    currChar = *(++src); //move to next character in array
  }
  return size;
}

/** Copies the array pointed by src into the array pointed by destination (including the null ending character
 * @param src Pointer to the string to be copied
 * @param dest Pointer to the new copy of the string
 * @return start_of_dest Pointer to the string copy
 */
char* mystrcpy(char *dest, const char *src){  
  char* start_of_dest; 
  start_of_dest = dest; //hold the first memory location
  while(*src != '\0'){
      *dest = *src; //copy chars from src to dest
      src++;
      dest++;
  }
  *dest = *src; //run one more time to include the null character
  return start_of_dest; //return pointer to first char of dest
}

/** Copies the first n bytes of src. If there is no null bytes among the first n bytes of src, result will not be null-terminated. If length of src is less than n, remainder of dest will be null-padded.
 * @param dest Pointer to the string copy
 * @param src Pointer to the string to be copied
 * @param n number of bytes to be copied
 * @return start_of_dest Pointer to the string copy
 */
char* mystrncpy(char *dest, const char *src, size_t n){
  char* start_of_dest;
  int i, length;
  start_of_dest = dest; //hold first memory location of dest
  length = mystrlen(src); //length of src string

  for(i = 0; i < n; i++){
    if(i > length){ //null pad
      *dest = '\0';
      dest++;
    }
    else{
      *dest = *src; //copy chars from src to dest
      dest++;
      src++;
    }
  }
  return start_of_dest; //return pointer to first char of dest
}


/** Appends the src string to the dest string over-writing the '/0' character at the end of dest, then adds a '/0' back on to the end of the resulting string. dest string must have ebough space for result.
* @param dest Pointer to the first string of the concatenation, which becomes the result afterwards
* @param src Pointer to the string to be added onto the end of dest
* @return dest Pointer to the concatenated string
*/
char* mystrcat(char *dest, const char *src){
  int length; 
  char* start_of_dest;
  start_of_dest = dest; //store memory location of first position of the first string
  char* insert; //pointer to position of string we're inserting at
  length = mystrlen(dest); //length of the destination string
  insert = dest + length; //set insert position to end of first string

  while(*src != '\0'){
    *insert = *src; //copy chars from src onto end of dest string
    insert++; 
    src++;
  }
  *insert = *src; //run one more time to tack on the null-terminating character
  return start_of_dest; //return pointer to the start of the resulting string
}

/** Appends the first n characters, plus a '/0' character from src onto the end of dest, overwriting the '/0' of dest.
 * @param dest Pointer to the first string of concatenation, which becomes the result afterwards
 * @param src Pointer to the string to be added onto the end of dest
 * @param n the amount of characters from src to concatenate onto dest
 * @return dest Pointer to the concatenated string
 */
char* mystrncat(char *dest, const char *src, size_t n){ 
  int i, length;
  char* start_of_dest;
  start_of_dest = dest; //store memory location of first position  of the first string
  char* insert; //pointer to position of string we're inserting at
  length = mystrlen(dest); //length of the destination string
  insert = dest + length; //set insert position to end of first string

  for(i = 0; i < n; i++){
    if(i > length){ //stop adding on if we reach end of string
      break;
    }
    *insert = *src; //copy chars from src onto back of destination string
    insert++; 
    src++;
  }
  return start_of_dest; //return pointer to first position of resulting string 
}
