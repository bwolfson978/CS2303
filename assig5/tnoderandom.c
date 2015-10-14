/**File that populates a binary tree with randomly generated strings, then prints out the strings sorted in-order
 * @author Barrett Wolfson
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tnode.h"

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
 
int main() {

    srand(time(NULL)); //reset random number seed every time program runs

    Tnode* root_node;
    root_node = NULL;
    printf("randomly generated strings inside of tree:\n");
    char* str1 = rand_str_generator(6);
    printf("%s\n", str1);
    char* str2 = rand_str_generator(6);
    printf("%s\n", str2);
    char* str3 = rand_str_generator(6);
    printf("%s\n", str3);
    char* str4 = rand_str_generator(6);
    printf("%s\n", str4);
    char* str5 = rand_str_generator(6);
    printf("%s\n", str5);
    char* str6 = rand_str_generator(6);
    printf("%s\n", str6);

    Tnode* tree; 
    tree = add_tnode(root_node, str1);
    add_tnode(tree, str2);
    add_tnode(tree, str3);
    add_tnode(tree, str4);
    add_tnode(tree, str5);
    add_tnode(tree, str6);
     
    printf("\n");
    printf("Printing in-order traversal of tree:\n");
    print_tree(tree);
    
    //free all the nodes of the tree
    free_tree(tree);    
}
