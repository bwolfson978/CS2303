/**File which holds implementation of tnode functions for a binary tree data structure implementation
 * @author Barrett Wolfson
 */

#include "tnode.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** creates a new node on the tree 
 * @param value the string value held at the node to be added
 * @return Pointer to the added Tnode
 */
Tnode* create_tnode(Tnode* node, char* value){
  node = (Tnode*)malloc(sizeof(Tnode));
  node->data = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

/** adds a tnode to a tree
 * @param current_tnode pointer to the Tnode which we are adding below (initially root node)
 */
Tnode* add_tnode(Tnode* current_tnode, char* value){
  if(current_tnode == NULL){ //if the pointer is null, allocate a new node
    create_tnode(current_tnode, value); 
  }
  else if(strcmp(current_tnode->data, value)<0){ //the string at current node comes before value
    current_tnode->right = add_tnode(current_tnode->right, value); //add node to the right subtree
  }
  else { //string at current node either matches or comes after value
    current_tnode->left = add_tnode(current_tnode->left, value); //add node to the left subtree
  }
}

/** print all the values of the tree in-order
 * @param root_node the root node of the tree to be printed
 */
void print_tree(Tnode* root_node){
  //print left node value
  //print current node value
  //print right node value
  
  if(root_node != NULL){
    print_tree(root_node->left);
    printf("%s\n", root_node->data);
    print_tree(root_node->right);
  }
}

/** frees all the nodes of a tree
 * @param root_node Pointer to the root node of the tree
 */
void free_tree(Tnode* root_node){
  if(root_node != NULL){
    if(root_node->left != NULL){ //free the left subtree
      free_tree(root_node->left);
    }
    
    if(root_node->right != NULL){ //free the right subtree
      free_tree(root_node->right);
    }
    
    free(root_node); //free the current node pointer
  }
}
