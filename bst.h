#ifndef BST_H
#define BST_H

struct Node {
public:
   int data;
   Node* parent;
   Node* left;
   Node* right;
   bool isRed;

   Node();
};

class BST {
private:
   Node* root;

   void inOrderHelper(Node* node);
   void deleteAll(Node* node);
   void rotateLeft(Node* x);
   void rotateRight(Node* x);

public:
   BST();
   ~BST();

   void insert(int data);
   void inOrder();
};

#endif /* BST_H */
