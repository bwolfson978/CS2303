/** Struct to define a Tnode, each holds a c-style string, and pointers to left and right child Tnodes
 * @author Barrett Wolfson
 */

struct tnode{
  char* data;
  struct tnode* left;
  struct tnode* right;
};

typedef struct tnode Tnode;

// Function Prototypes

Tnode* create_tnode(Tnode* node, char* value);

Tnode* add_tnode(Tnode* current_tnode, char* value);

void print_tree(Tnode* root_node);

void free_tree(Tnode* root_node);
