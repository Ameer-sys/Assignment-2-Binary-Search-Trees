#include <stdio.h>
#include <stdlib.h>
#include "bstrees.h"


// Insert a node into the BST
// If the tree is empty, create a new node.
// Otherwise, insert the node in the correct position based on BST properties.
Node* insert(Node* root, char data) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) { // Check if memory allocation failed
            fprintf(stderr, "Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}


// Search for a node in the BST
// Returns a pointer to the node if found, otherwise returns NULL.
Node* search(Node* root, char data) {
    if (root == NULL || root->data == data)
        return root; // Node found or reached a NULL pointer
    if (data < root->data)
        return search(root->left, data); // Search in the left subtree
    return search(root->right, data); // Search in the right subtree
}

// Count the number of nodes in the BST
// Uses a recursive approach to count nodes in both subtrees.
int countNodes(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Determine the height of the BST
// The height is the longest path from the root to a leaf node.
int treeHeight(Node* root) {
    if (root == NULL)
        return -1; // Return -1 to indicate no nodes exist
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight); // Return the maximum depth
}

// Perform inorder traversal of the BST
// Inorder traversal prints elements in sorted order.
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left); // Visit left subtree
        printf("%c ", root->data); // Print current node
        inorderTraversal(root->right); // Visit right subtree
    }
}

// Free the memory allocated for the BST
// Uses postorder traversal to free all nodes.
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left); // Free left subtree
        freeTree(root->right); // Free right subtree
        free(root); // Free current node
    }
}
