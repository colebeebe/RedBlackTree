#include <iostream>
#include "bst.h"

Node::Node() {
   data     = 0;
   parent   = nullptr;
   left     = nullptr;
   right    = nullptr;
   isBlack  = true;
}

BST::BST() {
   root = nullptr;
}

BST::~BST() {
   deleteAll(root);
   root = nullptr;
}

void BST::inOrderHelper(Node* node) {
   if (!node) return;

   inOrderHelper(node->left);
   std::cout << node->data << " ";
   inOrderHelper(node->right);
}

void BST::deleteAll(Node* node) {
   if (!node) return;

   deleteAll(node->left);
   deleteAll(node->right);

   delete node;
}

void BST::fixViolations(Node* node) {
   // Recursion return case
   if (!node) return;

   // Case 1: Node is the root
   if (!node->parent) return;

   // Case 2: Parent is black
   if (node->parent->isBlack) return;

   // Case 3: Parent is red
   if (!node->parent->parent) return;

   Node* grandparent = node->parent->parent;
   Node* uncle = nullptr;

   if (grandparent->left == node->parent) {
      uncle = grandparent->right;
   }
   else {
      uncle = grandparent->left;
   }

   // Case 3a: Uncle is red
   if (uncle && !uncle->isBlack) {
      node->parent->isBlack = true;
      uncle->isBlack = true;
      grandparent->isBlack = false;
      fixViolations(grandparent);
   }
   // Case 3b: Uncle is black (or null)
   else {
      if (node == node->parent->left) {
         // Left-Left Case
         if (node->parent == grandparent->left) {
            rotateRight(grandparent);
            node->parent->isBlack = true;
         }
         // Right-Left Case
         else {
            rotateRight(node->parent);
            rotateLeft(grandparent);
            node->isBlack = true;
         }
      }
      else {
         // Right-Right Case
         if (node->parent == grandparent->right) {
            rotateLeft(grandparent);
            node->parent->isBlack = true;
         }
         // Left-Right Case
         else {
            rotateLeft(node->parent);
            rotateRight(grandparent);
            node->isBlack = true;
         }
      }
      // No matter what, the grandparent always turns red
      grandparent->isBlack = false;
   }
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
   newNode->isBlack = false;
   newNode->parent = parent;
   if (data < parent->data) {
      parent->left = newNode;
   }
   else {
      parent->right = newNode;
   }

   // Once Red-Black violations have been fixed, the root is always set to black
   fixViolations(newNode);
   root->isBlack = true;

}

void BST::inOrder() {
   std::cout << "[ ";
   inOrderHelper(root);
   std::cout << "]" << std::endl;
}
