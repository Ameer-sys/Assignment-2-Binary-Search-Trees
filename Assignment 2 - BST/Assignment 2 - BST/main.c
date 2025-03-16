#include <stdio.h>
#include "bstrees.h"
#include <time.h>

// Generate a random lowercase character between 'a' and 'z'
char getRandomChar() {
    return 'a' + rand() % 26;
}

int main(void) {

    srand(time(NULL)); // Seed the random number generator
    Node* root = NULL; // Initialize the BST root as empty
    int numChars = 11 + rand() % 10; // Generate a random number of characters (between 11 and 20)

    //out put 
   

    // Insert random characters into the BST
    printf("Inserting %d characters: ", numChars);
    for (int i = 0; i < numChars; i++) {
        char ch = getRandomChar();
        printf("%c ", ch);
        root = insert(root, ch);
    }
    printf("\n");
    printf("\n");

    printf("Output after insertion: \n");


    // Print the BST in sorted order using inorder traversal
    printf("Sorted order: ");
    inorderTraversal(root);
    printf("\n");

    // Display the total number of nodes in the BST
    printf("Number of nodes: %d\n", countNodes(root));

    // Display the height of the BST
    printf("Tree height: %d\n", treeHeight(root));

    // Free allocated memory to prevent memory leaks
    freeTree(root);
	return 0;
}