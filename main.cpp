#include <iostream>
using namespace std;

#include "bst.h"

void insertionTest(BST& bst) {
   cout << "Enter positive integers.\nWhen finished enter 0" << endl;

   int input = -1;
   while (input != 0) {
      cout << "> ";
      cin >> input;
      if (input < 0) {
         cout << "Input must be positive" << endl;
         continue;
      }
      if (input != 0) {
         bst.insert(input);
      }
   }
}

void printBST(BST bst) {
   cout << "BST tree structure:" << endl;
   bst.printTree();
   cout << endl << endl;
}

void orderTests(BST bst) {
   cout << "Tests for ordering the BST:" << endl;
   cout << "BST  in order: ";
   bst.inorder();
   cout << endl;

   cout << "BST  preorder: ";
   bst.preorder();
   cout << endl;

   cout << "BST postorder: ";
   bst.postorder();
   cout << endl << endl;
}

void minMaxTests(BST bst) {
   cout << "Min and max values:" << endl;
   cout << "Min: " << bst.findMin() << endl;
   cout << "Max: " << bst.findMax() << endl;
   cout << endl;
}

void sizeAndEmptyTest(BST bst) {
   cout << "Size and empty tests:" << endl;
   cout << "Is the BST empty? " << (bst.isEmpty() ? "Yes" : "No") << endl;
   cout << "Size: " << bst.size() << endl;
   cout << endl;
}

void clearTest(BST& bst) {
   cout << "Clearing..." << endl;
   bst.clear();
}

int main() {

   BST bst;

   insertionTest(bst);
   bst.printTree();

   orderTests(bst);
   minMaxTests(bst);
   sizeAndEmptyTest(bst);
   
   clearTest(bst);
   sizeAndEmptyTest(bst);

   return 0;

}
