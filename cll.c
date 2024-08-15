#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

void insert(int data) {
    struct node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Node inserted with data %d\n", data);
}

void delete(int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head, *prev = NULL;
    if (temp->data == data) {
        if(temp->next == head) {
            free(head);
            head = NULL;
            printf("Node with data %d deleted.\n", data);
            return;
        } else {
            struct node* last = head;
            while(last->next != head) {
                last = last->next;
            }
            last->next = head->next;
            head = head->next;
            free(temp);
            printf("Node with data %d deleted.\n", data);
            return;
        }
    }
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != head && temp->data != data);
    if (temp == head) {
        printf("Node with data %d not found.\n", data);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node with data %d deleted.\n", data);
}

void view() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    printf("Circular linked list: ");
    do {
        printf("%d", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void create(int data) {
    head = createNode(data);
    printf("List created with first node having data %d\n", data);
}

int main() {
    int ch, data;
    while (1) {
        printf("Enter your choice: 1 for create, 2 for insert, 3 for delete, 4 for view, 0 to exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (head != NULL) {
                printf("List already existing. Insert more nodes.\n");
            } else {
                printf("Enter data for the first node: ");
                scanf("%d", &data);
                create(data);
            }
            break;
        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insert(data);
            break;
        case 3:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            delete(data);
            break;
        case 4:
            view();
            break;
        case 0:
            exit(0);        
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
    return 0;
}