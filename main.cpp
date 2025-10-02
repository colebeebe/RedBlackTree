#include <iostream>
#include "bst.h"

int main() {

   BST bst;

   int input = -1;
   while (input != 0) {
      std::cout << "> ";
      std::cin >> input;
      if (input < 0) {
         std::cout << "Input must be positive" << std::endl;
         continue;
      }
      if (input != 0) {
         bst.insert(input);
      }
   }

   bst.inOrder();
   
   std::cout << std::endl;
   bst.printTree();

   return 0;

}
