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

   void inOrderHelper(Node* node);
   void deleteAll(Node* node);
   void fixViolations(Node* node);
   void rotateLeft(Node* x);
   void rotateRight(Node* x);
   void printTreeHelper(Node* node, int space);

public:
   BST();
   ~BST();

   void insert(int data);
   void inOrder();
   void printTree();
};

#endif /* BST_H */
