#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Display list from beginning to end
void displayForward(struct Node* head) {
    printf("Forward: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        if (head->next == NULL) break;  // Stop at the end
        head = head->next;
    }
    printf("NULL\n");
}

// Display list from end to beginning
void displayBackward(struct Node* tail) {
    printf("Backward: ");
    while (tail != NULL) {
        printf("%d <-> ", tail->data);
        tail = tail->prev;
    }
    printf("NULL\n");
}

// Delete a node by value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Element %d not found.\n", key);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;  // If head node is to be deleted

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// Main function
int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    displayForward(head);

    // Get tail to display backward
    struct Node* tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    displayBackward(tail);

    deleteNode(&head, 20);
    displayForward(head);

    return 0;
}
