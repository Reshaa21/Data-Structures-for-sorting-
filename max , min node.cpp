#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to search for an element in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// Function to find the minimum element in the BST
struct Node* findMin(struct Node* root) {
    struct Node* current = root;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Function to find the maximum element in the BST
struct Node* findMax(struct Node* root) {
    struct Node* current = root;

    while (current && current->right != NULL) {
        current = current->right;
    }

    return current;
}

// Function to print the tree in-order
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("In-order traversal of the BST: ");
    inorder(root);
    printf("\n");

    int key = 40;
    struct Node* searchResult = search(root, key);
    if (searchResult != NULL) {
        printf("Element %d found in the BST.\n", key);
    } else {
        printf("Element %d not found in the BST.\n", key);
    }

    struct Node* minNode = findMin(root);
    if (minNode != NULL) {
        printf("Minimum element in the BST is: %d\n", minNode->data);
    }

    struct Node* maxNode = findMax(root);
    if (maxNode != NULL) {
        printf("Maximum element in the BST is: %d\n", maxNode->data);
    }

    return 0;
}

