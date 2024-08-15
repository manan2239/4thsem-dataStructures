#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append(struct node** head, int data){
    struct node* newNode = createNode(data);
    struct node* last = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

void reverseList(struct node** head) {
    struct node* temp = NULL;
    struct node* current = *head;
    while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL){
        *head = temp->prev;
    }
}

void printList(struct node* node) {
    while (node != NULL) {
        printf("%d", node->data);
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);

    printf("Original list: ");
    printList(head);
    reverseList(&head);
    printf("Reversed list: ");
    printList(head);

    return 0;
}