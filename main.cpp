#include <iostream>
using namespace std;

#include "bst.h"

/*************************************************************************
 * PRINT BST
 * Display the BST visually. The root is on the left, with the tree
 * rotated 90 degrees counter-clockwise.
 *   INPUT  bst   The BST to be displayed
 *************************************************************************/
void printBst(BST bst) {
   cout << "BST tree structure:" << endl;
   bst.printTree();
   cout << endl << endl;
}

/*************************************************************************
 * INSERTION TEST
 * Allow the user to input values into the BST.
 *   INPUT  bst   The bst, passed in by reference (so it can be edited)
 *************************************************************************/
void insertionTest(BST& bst) {
   // The BST can hold negative values and zero, but for this demonstration
   // we are only allowing the user to input positive values
   cout << "Enter positive integers.\nWhen finished enter 0" << endl;

   // Set the input to a negative value so we can enter the while-loop
   // IMPORANT: This does NOT do any checking; it assumes the user will
   // only ever input integers
   int input = -1;
   while (input != 0) {
      cout << "> ";
      cin >> input;
      if (input < 0) {
         cout << "Input must be positive" << endl;
         continue;
      }
      // If we have a valid input, we insert it here
      if (input != 0) {
         bst.insert(input);
      }
   }

   cout << endl;
}

/*************************************************************************
 * ORDER TESTS
 * Test the ordering functions provided by the BST class.
 *   INPUT  bst   The BST to be tested
 *************************************************************************/
void orderTests(BST bst) {
   cout << "Tests for ordering the BST:" << endl;
   // inorder(): Prints the values contained in the BST in ascending order
   cout << "BST  in order: ";
   bst.inorder();
   cout << endl;

   // preorder(): Prints the values in preorder (order used for copying)
   cout << "BST  preorder: ";
   bst.preorder();
   cout << endl;

   // postorder(): Prints the values in postorder (order used for clearing)
   cout << "BST postorder: ";
   bst.postorder();
   cout << endl << endl;
}

/*************************************************************************
 * MIN/MAX TESTS
 * Display the minimum and maximum values of the BST.
 *   INPUT  bst   The BST to be tested
 *************************************************************************/
void minMaxTests(BST bst) {
   cout << "Min and max values:" << endl;
   // If the BST is empty, findMin() and findMax() both return 0
   cout << "Min: " << bst.findMin() << endl;
   cout << "Max: " << bst.findMax() << endl;
   cout << endl;
}

/*************************************************************************
 * SIZE AND EMPTY TEST
 * Display whether the BST is empty and its size.
 *   INPUT  bst   The BST to be tested
 *************************************************************************/
void sizeAndEmptyTest(BST bst) {
   cout << "Size and empty tests:" << endl;
   cout << "Is the BST empty? " << (bst.isEmpty() ? "Yes" : "No") << endl;
   cout << "Size: " << bst.size() << endl;
   cout << endl;
}

/*************************************************************************
 * SEARCH TEST
 * Allow the user to search for values in the BST.
 *   INPUT  bst   The BST to be tested
 *************************************************************************/
void searchTest(BST bst) {
   cout << "Enter positive integers to search for in the tree." << endl;
   cout << "When finished enter 0" << endl;

   // Set the input to a negative value so we can enter the while-loop
   // IMPORANT: This does NOT do any checking; it assumes the user will
   // only ever input integers
   int input = -1;
   while (input != 0) {
      cout << "> ";
      cin >> input;
      if (input < 0) {
         cout << "Input must be positive." << endl;
         continue;
      }

      if (input != 0) {
         cout << input << " is" << (bst.contains(input) ? " " : " not ") 
            << "in the BST" << endl << endl;
      }
   }

   cout << endl;
}

/*************************************************************************
 * HEIGHT TEST
 * Print the height of the tree.
 *   INPUT  bst   The BST to be tested
 *************************************************************************/
void heightTest(BST bst) {
   cout << "Height of tree: " << bst.height() << endl << endl;
}

/*************************************************************************
 * CLEAR TEST
 * Test if the BST can be cleared properly. Calls sizeAndEmptyTest().
 *   INPUT  bst   The BST to be cleared, passed by reference
 *************************************************************************/
void clearTest(BST& bst) {
   cout << "Clearing..." << endl;
   bst.clear();
   // If clear() was successful, the BST should be empty and it should
   // have a size of 0
   sizeAndEmptyTest(bst);
}

/*************************************************************************
 * MAIN
 * The entry point of the program.
 *************************************************************************/
int main() {

   BST bst;

   // Now that we've created the BST, let's test it
   insertionTest(bst);
   printBst(bst);

   orderTests(bst);
   minMaxTests(bst);
   sizeAndEmptyTest(bst);

   searchTest(bst);
   heightTest(bst);

   clearTest(bst);

   return 0;

}
