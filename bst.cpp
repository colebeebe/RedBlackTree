#include <iostream>
#include "bst.h"

Node::Node() {
   data   = 0;
   parent = nullptr;
   left   = nullptr;
   right  = nullptr;
   isRed  = true;
}

BST::BST() {
   root = nullptr;
}

BST::~BST() {
   deleteAll(root);
   root = nullptr;
}

void BST::inOrderHelper(Node* node) {
   if (node == nullptr) return;

   inOrderHelper(node->left);
   std::cout << node->data << " ";
   inOrderHelper(node->right);
}

void BST::deleteAll(Node* node) {
   if (node == nullptr) return;

   deleteAll(node->left);
   deleteAll(node->right);

   delete node;
}

void BST::rotateLeft(Node* x) {
   Node* y = x->right;
   x->right = y->left;
   if (x->right) {
      x->right->parent = x;
   }

   y->parent = x->parent;
   if (x == root) {
      root = y;
   }
   else if (x == x->parent->left) {
      x->parent->left = y;
   }
   else {
      x->parent->right = y;
   }

   y->left = x;
   x->parent = y;
}

void BST::rotateRight(Node* x) {
   Node* y = x->left;
   x->left = y->right;
   if (x->left) {
      x->left->parent = x;
   }

   y->parent = x->parent;
   if (x == root) {
      root = y;
   }
   else if (x == x->parent->left) {
      x->parent->left = y;
   }
   else {
      x->parent->right = y;
   }

   y->right = x;
   x->parent = y;
}

void BST::insert(int data) {
   Node* parent = nullptr;
   Node* current = root;

   while (current) {
      if (data == current->data) return;

      parent = current;
      if (data < current->data) {
         current = current->left;
      }
      else {
         current = current->right;
      }
   }

   // Create a new node
   Node* newNode = new Node;
   newNode->data = data;

   if (!parent) {
      // If the parent is null we're at the root
      root = newNode;
      return;
   }

   // Insert the node by setting its pointers
   newNode->parent = parent;
   if (data < parent->data) {
      parent->left = newNode;
   }
   else {
      parent->right = newNode;
   }

}

void BST::inOrder() {
   std::cout << "[ ";
   inOrderHelper(root);
   std::cout << "]" << std::endl;
}
