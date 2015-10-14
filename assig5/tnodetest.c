/**File which tests adding strings to a binary tree, which sorts them into ascending order, then traverses the tree and prints the strings in-order 
 * @author Barrett Wolfson
 */

#include <stdio.h>
#include <stdlib.h>
#include "tnode.h"


int main() {
    Tnode* root_node;
    root_node = NULL;
    char *data[] = {"first" , "second", "third", "fourth" , "fifth", "sixth"};
    
    Tnode* tree; 
    tree = add_tnode(root_node, data[0]);
    add_tnode(tree, data[1]);
    add_tnode(tree, data[2]);
    add_tnode(tree, data[3]);
    add_tnode(tree, data[4]);
    add_tnode(tree, data[5]);
     
    print_tree(tree);
    
}
