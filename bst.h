#ifndef BST_H
#define BST_H

struct Node {
public:
   int data;
   Node* parent;
   Node* left;
   Node* right;
   bool isBlack;

   /*************************************************************************
    * NODE CONSTRUCTOR
    * Set values to default; all pointers are set to null.
    *************************************************************************/
   Node();
};

class BST {
private:
   Node* root;

   /*************************************************************************
    * FIX INSERTION VIOLATIONS
    * Rebalance the tree according to the properties of a Red-Black tree.
    *   INPUT  node  The node to be checked for violations
    *************************************************************************/
   void fixInsertionViolations(Node* node);

   /*************************************************************************
    * ROTATE LEFT
    * Rotate the tree to the left (x becomes left child of y).
    *   INPUT  x  The node to rotate
    *************************************************************************/
   void rotateLeft(Node* x);

   /*************************************************************************
    * ROTATE RIGHT
    * Rotate the tree to the right (x becomes right child of y).
    *   INPUT  x  The node to rotate
    *************************************************************************/
   void rotateRight(Node* x);

   /*************************************************************************
    * IN ORDER HELPER
    * Helper function to print BST in sequential order. A helper is used to 
    * protect the root node from being exposed to the user.
    *   INPUT  node  The node to begin printing from (usually the root)
    *************************************************************************/
   void inorderHelper(Node* node);

   /*************************************************************************
    * PREORDER HELPER
    * Helper function to print BST in preorder. A helper is used to protect 
    * the root node from being exposed to the user. 
    * While this function simply prints the data, this is the same logic that 
    * is used when copying the tree.
    *   INPUT  node  The node to begin printing from (usually the root)
    *************************************************************************/
   void preorderHelper(Node* node);

   /*************************************************************************
    * POSTORDER HELPER
    * Helper function to print BST in postorder. A helper is used to protect 
    * the root node from being exposed to the user. 
    * While this function simply prints the data, this is the same logic that 
    * is used when deleting the tree.
    *   INPUT  node  The node to begin printing from (usually the root)
    *************************************************************************/
   void postorderHelper(Node* node);

   /*************************************************************************
    * SIZE HELPER
    * Helper function to get the size of the BST. A helper is used to protect
    * the root node from being exposed to the user.
    *   INPUT  node  The node to begin counting size from (usually the root)
    *************************************************************************/
   int sizeHelper(Node* node);

   /*************************************************************************
    * FIND MIN HELPER
    * Helper function to get the smallest value in the BST. A helper is used
    * to protect the root node from being exposed to the user.
    *   INPUT  node  The node under which to find the smallest value (usually
    *                the root)
    *************************************************************************/
   int findMinHelper(Node* node);

   /*************************************************************************
    * FIND MAX HELPER
    * Helper function to get the largest value in the BST. A helper is used
    * to protect the root node from being exposed to the user.
    *   INPUT  node  The node under which to find the largest value (usually
    *                the root)
    *************************************************************************/
   int findMaxHelper(Node* node);

   /*************************************************************************
    * PRINT TREE HELPER
    * Helper function to print the BST as a visual representation. A helper 
    * is used to protect the root node from being exposed to the user.
    *   INPUT  node  The node under which to print the tree (usually the 
    *                root)
    *************************************************************************/
   void printTreeHelper(Node* node, int space);

   /*************************************************************************
    * DELETE ALL
    * Deletes all nodes from the tree (freeing memory). Called by clear().
    *   INPUT  node  The node under which to delete all nodes (usually the 
    *                root)
    *************************************************************************/
   void deleteAll(Node* node);

public:
   /*************************************************************************
    * BST CONSTRUCTOR
    * Initialize the BST with a null root node.
    *************************************************************************/
   BST();

   /*************************************************************************
    * COPY CONSTRUCTOR
    * Copy one BST to another
    *   INPUT  bst   The BST to be copied into the new object.
    *************************************************************************/
   BST(BST& other);

   /*************************************************************************
    * BST DESTRUCTOR
    * Delete all nodes (clearing memory) in preparation for BST to exit scope
    *************************************************************************/
   ~BST();

   /*************************************************************************
    * COPY TREE
    * Copy a tree to a new object.
    *   INPUT  node     The node (and, by extension, its parent and children) 
    *                   to be copied
    *          newNode  The root node of the new tree
    *************************************************************************/
   Node* copyTree(Node* node);

   /*************************************************************************
    * CONTAINS
    * Returns true if the value is contained within the tree.
    *   INPUT   data      The value to attempt to find in the tree.
    *   OUTPUT  contains  A boolean value that represents whether the value
    *                     exists in the tree
    *************************************************************************/
   bool contains(int data);

   /*************************************************************************
    * SEARCH
    * With great power comes great responsibility. Returns the node object
    * containing the specified value.
    *   INPUT  data  The data to get the node of
    *************************************************************************/
   Node* search(int data);

   /*************************************************************************
    * INSERT
    * Insert a value into the tree. The tree automatically rebalances itself
    * after inserting values.
    *   INPUT  data  The data to insert into the tree
    *************************************************************************/
   void insert(int data);

   /*************************************************************************
    * REMOVE
    * Removes the data from the tree if it exists.
    *   INPUT  data  The value to be removed from the tree
    *************************************************************************/
   void remove(int data);

   /*************************************************************************
    * IN ORDER
    * Print the data in the tree in order.
    *************************************************************************/
   void inorder();

   /*************************************************************************
    * PREORDER
    * Print the data in the tree in preorder (order used for copying).
    *************************************************************************/
   void preorder();

   /*************************************************************************
    * POSTORDER
    * Print the data in the tree in postorder (order used for clearing).
    *************************************************************************/
   void postorder();

   /*************************************************************************
    * SIZE
    * Return the number of nodes in the tree.
    *   OUTPUT  size  The size, or number of nodes, in the tree
    *************************************************************************/
   int size();

   /*************************************************************************
    * HEIGHT
    * Return the number of nodes from the root to the furthest leaf.
    *   OUTPUT  height  The height of the tree
    *************************************************************************/
   int height();

   /*************************************************************************
    * IS EMPTY
    * Return true if the tree is empty and false if it is not.
    *   OUTPUT  isEmpty  True if the tree is empty and false otherwise
    *************************************************************************/
   bool isEmpty();

   /*************************************************************************
    * FIND MIN
    * Get the smallest value in the tree.
    *   OUTPUT  min  The smallest value (furthest left) in the tree
    *************************************************************************/
   int findMin();

   /*************************************************************************
    * FIND MAX
    * Get the largest value in the tree.
    *   OUTPUT  max  The largest value (furthest right) in the tree
    *************************************************************************/
   int findMax();

   /*************************************************************************
    * PRINT TREE
    * Print the tree an a visual format, with the root on the left. Tree is
    * rotated 90 degrees counter-clockwise.
    *************************************************************************/
   void printTree();

   /*************************************************************************
    * CLEAR
    * Delete all nodes from the tree and memory.
    *************************************************************************/
   void clear();

   /*************************************************************************
    * EQUAL OPERATOR
    * Override the operator for copying BST.
    *   INPUT  rhs  The BST on the right-hand side of the operator
    *************************************************************************/
   BST& operator=(const BST& rhs);

};

#endif /* BST_H */
