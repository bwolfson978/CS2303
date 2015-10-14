#include "account.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** creates an ACCOUNT struct from data passed in as parameters
 * @param name Pointer to character array expressing name of account owner
 * @param account_number integer account number
 * @param dollars integer number of dollars in the account
 * @return Pointer to created ACCOUNT struct
 */
ACCOUNT* create_account(char* name, int account_number, int dollars){
  ACCOUNT* a;
  a  = (ACCOUNT*)malloc(sizeof(ACCOUNT));
  //ACCOUNT account;
  //account.name = (char*) malloc(NAME_LENGTH);
  a->name = name;
  a->account_number = account_number;
  a->dollars = dollars;
  return a;
}

/** prints an ACCOUNT struct
 * @param a Pointer to the ACCOUNT struct to be printed
 */
void print_account(ACCOUNT* a){
  printf("Pointer: %p\n", a);
  printf("Name: %s\n", (*a).name);
  printf("Account Number: %i\n", (*a).account_number);
  printf("Dollars: %i\n", (*a).dollars);
  printf("\n");
}

/** creates an ACCOUNT struct from random generated data fields
 * @return Pointer to created ACCOUNT struct
 */
ACCOUNT* random_account(){
  char* rand_name;
  int dollars, account_number, length;
  length = 10;
  rand_name = rand_str_generator(NAME_LENGTH);
  dollars = rand() % 500;
  account_number = rand() % 30;
  return create_account(rand_name,account_number,dollars);
}

/** allocates an array of size count pointers to ACCOUNT structs 
 * @param count number of ACCOUNT structs to be created
 * @return Pointer to array of Pointers all pointing to ACCOUNT structs
 */
ACCOUNT **make_accounts(int count){
  ACCOUNT **accounts; //Pointer to array of pointers, each pointing to a random bank account struct
  ACCOUNT *ptr;
  accounts = malloc(sizeof(ptr) * (count+1)); //allocate array to hold pointers
  int i;
  for(i = 0; i < count; i++){
    ptr = random_account();
    accounts[i] = ptr;
  }
  return accounts;
} 

/**duplicates an array of pointers to ACCOUNT structs, but not what they point to
 * @param accounts Pointer to array of pointers to ACCOUNT structs
 * @param size integer size of the array of pointers accounts
 * @return Pointer to the array of pointer copies
 */
ACCOUNT **shallow_copy(ACCOUNT **accounts, int size){
  ACCOUNT **shallow_copies;
  shallow_copies = malloc(sizeof(**accounts) * size);
  int i;
  for(i = 0; i < size; i++){
    shallow_copies[i] = accounts[i];
  }
  return shallow_copies;
} 

/** duplicates an array of pointers, including the structs that they point to
 * @param accounts Pointer to the array of pointers to copy
 * @param size integer size of the accounts array
 * @return Pointer to the duplicate array 
 */
ACCOUNT **deep_copy(ACCOUNT **accounts, int size){
  //dupliacte the structs, then fill the array with pointers to these structs
  ACCOUNT **deep_copies;
  deep_copies = malloc(sizeof(**accounts) * size);
  int i;
  ACCOUNT *a;
  for(i = 0; i < size; i++){
    a = create_account((*accounts[i]).name,(*accounts[i]).account_number,(*accounts[i]).dollars);
    deep_copies[i] = a;
  }
  return deep_copies;
}

/** de-allocates all the structs pointed to by accounts array of pointers
 * @param accounts Pointer to the array of pointers to be freed up
 * @param size the number of accounts
 */
void deallocate(ACCOUNT **accounts, int size){
  int i;
  for(i = 0; i < size; i++){
    free(accounts[i]);//free each pointer in array of pointers
  }
  free(accounts); //free pointer to the array of pointers
}

/** prints an array of pointers to ACCOUNT structs
 * @param accounts Pointer to array of pointers to ACCOUNT structs
 * @param count the number of accounts
 */
void print_accounts(ACCOUNT **accounts, int count){
  int i;
  for(i = 0; i < count; i++){
    print_account(accounts[i]);
  }
}

/**generates a random string of size length
 * @param length the size of the string to be generated
 * @return Pointer to the character array that holds the generated string
 */
char* rand_str_generator(int length){
  const char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *name = NULL;

  if (length){
    name = malloc(sizeof(char) * (length+1));  
    int i;
    for(i = 0; i < length; i++){
      int index = rand() % (int)(sizeof alphabet);
      name[i] = alphabet[index];
    }
    name[length] = '\0';
  }
  return name;
} 
