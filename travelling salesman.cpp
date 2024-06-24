#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *left, *right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}


struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return search(root->right, key);

    return search(root->left, key);
}


struct Node* findMin(struct Node* node) {
    struct Node* current = node;


    while (current && current->left != NULL)
        current = current->left;

    return current;
}


struct Node* findMax(struct Node* node) {
    struct Node* current = node;


    while (current && current->right != NULL)
        current = current->right;

    return current;
}


int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int key = 40;
    struct Node* searchResult = search(root, key);
    if (searchResult != NULL)
        printf("Element %d found in the tree.\n", key);
    else
        printf("Element %d not found in the tree.\n", key);

    struct Node* minNode = findMin(root);
    printf("Minimum element is %d\n", minNode->data);

    struct Node* maxNode = findMax(root);
    printf("Maximum element is %d\n", maxNode->data);

    return 0;
}

