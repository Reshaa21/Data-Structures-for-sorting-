#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void appendNode(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

struct Node* searchItem(struct Node* head, int target) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == target) {
            return current;
        }
        current = current->next;
    }
	return NULL; 
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* result = NULL;

    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);

    displayList(head);

    int target = 30;
    result = searchItem(head, target);

    if (result != NULL) {
        printf("Item %d found in the list.\n", target);
    } else {
        printf("Item %d not found in the list.\n", target);
    }

    target = 50;
    result = searchItem(head, target);

    if (result != NULL) {
        printf("Item %d found in the list.\n", target);
    } else {
        printf("Item %d not found in the list.\n", target);
    }

    return 0;
}
