#pragma once

// Define the structure for a BST node
typedef struct Node {
    char data;  // Character data stored in the node
    struct Node* left;  // Pointer to the left child node
    struct Node* right; // Pointer to the right child node
} Node;

Node* insert(Node* root, char data);
Node* search(Node* root, char data);
int countNodes(Node* root);
int treeHeight(Node* root);
void inorderTraversal(Node* root);
void freeTree(Node* root);