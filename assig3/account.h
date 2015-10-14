/** file account.h with functions on account structs
 * @author Barrett Wolfson
 */


#ifndef ACCOUNT_H
#define ACCOUNT_H
#define NAME_LENGTH (10) //the length of the random strings to be generated

//ACCOUNT structure with string name, int account_number and dollars
struct _ACCOUNT
{
  char* name; //name of account owner
  int account_number; //account number
  int dollars; //dollar amount in the account
};

typedef struct _ACCOUNT ACCOUNT; //readability

//function prototypes
ACCOUNT* create_account(char* name, int account_number, int dollars);
void print_account(ACCOUNT* a);
ACCOUNT* random_account();
char* rand_str_generator(int length);
ACCOUNT **make_accounts(int count);
void print_accounts(ACCOUNT **accounts, int count);
ACCOUNT** shallow_copy(ACCOUNT **accounts, int size);
ACCOUNT** deep_copy(ACCOUNT **accounts, int size);
void deallocate(ACCOUNT **accounts, int size);
#endif
