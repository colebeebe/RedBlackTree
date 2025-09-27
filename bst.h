#ifndef BST_H
#define BST_H

struct Node {
public:
   int data;
   Node* parent = nullptr;
   Node* left   = nullptr;
   Node* right  = nullptr;

};

class BST {
private:
   Node* root;

   void inOrderHelper(Node* node);
   void deleteAll(Node* node);

public:
   BST();
   ~BST();

   void insert(int data);
   void inOrder();

};

#endif /* BST_H */
