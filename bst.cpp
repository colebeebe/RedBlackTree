#include <iostream>
#include "bst.h"

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

void BST::insert(int data) {
   Node* parent = nullptr;
   Node* current = root;

   while (current != nullptr) {
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

   if (parent == nullptr) {
      // If the parent is null we're at the root
      root = newNode;
   }
   else if (data < parent->data) {
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
