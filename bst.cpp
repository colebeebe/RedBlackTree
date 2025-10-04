#include <iostream>
#include "bst.h"

//////////////////////
// NODE CONSTRUCTOR //
//////////////////////

Node::Node() {
   data     = 0;
   parent   = nullptr;
   left     = nullptr;
   right    = nullptr;
   isBlack  = true;
}


//////////////////////////////////
// BST CONSTRUCTOR & DESTRUCTOR //
//////////////////////////////////

BST::BST() {
   root = nullptr;
}

BST::BST(BST& bst) {
   root = copyTree(bst.root);
}

BST::~BST() {
   clear();
}

////////////////////////////
// PRIVATE MEMBER METHODS //
////////////////////////////

Node* BST::copyTree(Node* node) {
   if (!node) return nullptr;

   Node* newNode = new Node;
   newNode->data = node->data;

   newNode->left = copyTree(node->left);
   newNode->right = copyTree(node->right);

   return newNode;
}

void BST::fixInsertionViolations(Node* node) {
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
      fixInsertionViolations(grandparent);
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

void BST::inorderHelper(Node* node) {
   if (!node) return;

   inorderHelper(node->left);
   std::cout << node->data << " ";
   inorderHelper(node->right);
}

void BST::preorderHelper(Node* node) {
   if (!node) return;

   std::cout << node->data << " ";
   preorderHelper(node->left);
   preorderHelper(node->right);
}

void BST::postorderHelper(Node* node) {
   if (!node) return;

   postorderHelper(node->left);
   postorderHelper(node->right);
   std::cout << node->data << " ";
}

int BST::sizeHelper(Node* node) {
   if (!node) return 0;

   int size = 0;
   size += sizeHelper(node->left);
   size += 1;
   size += sizeHelper(node->right);
   return size;
}

int BST::findMinHelper(Node* node) {
   if (!node) return 0;

   if (!node->left) return node->data;

   return findMinHelper(node->left);
}

int BST::findMaxHelper(Node* node) {
   if (!node) return 0;

   if (!node->right) return node->data;
   
   return findMaxHelper(node->right);
}

void BST::printTreeHelper(Node* node, int space) {
   if (!node) return;

   // Increase distance between levels
   space += 6;

   // Print right child first (so it shows on top)
   printTreeHelper(node->right, space);

   // Print current node after spacing
   std::cout << std::endl;
   for (int i = 6; i < space; i++)
      std::cout << " ";

   // Print node value and color
   std::cout << node->data << (node->isBlack ? "(B)" : "(R)") << std::endl;

   // Print left child
   printTreeHelper(node->left, space);
}

void BST::deleteAll(Node* node) {
   if (!node) return;

   deleteAll(node->left);
   deleteAll(node->right);

   delete node;
}


///////////////////////////
// PUBLIC MEMBER METHODS //
///////////////////////////

bool BST::contains(int data) {
   return false;
}

Node* BST::search(int data) {
   return nullptr;
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
   fixInsertionViolations(newNode);
   root->isBlack = true;

}

void BST::remove(int data) {

}

void BST::inorder() {
   std::cout << "[ ";
   inorderHelper(root);
   std::cout << "]";
}

void BST::preorder() {
   std::cout << "[ ";
   preorderHelper(root);
   std::cout << "]";
}

void BST::postorder() {
   std::cout << "[ ";
   postorderHelper(root);
   std::cout << "]";
}

int BST::size() {
   return sizeHelper(root);
}

int BST::height() {
   return 0;
}

bool BST::isEmpty() {
   return size() == 0;
}

int BST::findMin() {
   return findMinHelper(root);
}

int BST::findMax() {
   return findMaxHelper(root);
}

void BST::printTree() {
   printTreeHelper(root, 0);
   std::cout << std::endl;
}

void BST::clear() {
   deleteAll(root);
   root = nullptr;
}

BST& BST::operator=(const BST& rhs) {
   if (this != &rhs) {
      clear();
      root = copyTree(rhs.root);
   }
   return *this;
}
