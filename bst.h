#ifndef BST_H
#define BST_H

struct Node {
public:
   int data;
   Node* parent;
   Node* left;
   Node* right;
   bool isBlack;

   Node();
};

class BST {
private:
   Node* root;

   void fixInsertionViolations(Node* node);
   void rotateLeft(Node* x);
   void rotateRight(Node* x);

   void inorderHelper(Node* node);
   void preorderHelper(Node* node);
   void postorderHelper(Node* node);

   int sizeHelper(Node* node);

   int findMinHelper(Node* node);
   int findMaxHelper(Node* node);

   void printTreeHelper(Node* node, int space);

   void deleteAll(Node* node);

public:
   BST();
   BST(BST& other);
   ~BST();

   Node* copyTree(Node* node);

   bool contains(int data);
   Node* search(int data);

   void insert(int data);
   void remove(int data);

   void inorder();
   void preorder();
   void postorder();

   int size();
   int height();
   bool isEmpty();

   int findMin();
   int findMax();

   void printTree();

   void clear();

   BST& operator=(const BST& other);

};

#endif /* BST_H */
