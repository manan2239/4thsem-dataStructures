#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};
struct node *head = NULL, *tail = NULL;

void create() {
    struct node *temp;
    int n;
    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        temp = (struct node *) malloc(sizeof(struct node));
        printf("Enter element: "); scanf("%d", &temp->data);
        temp->prev = temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        } 
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
}

void view() {
    struct node *trav;
    trav = head;
    while (trav != NULL)
    {
        printf("%d", trav->data);
        trav = trav->next;
    }
    
}

void delete() {
    printf("Delete");
}

void insert() {
    printf("Insert");
} 
int main() {
    int ch;
    while (1)
    {
        printf("1 for create, 2 for insert, 3 for delete, 4 for view: ");
        scanf("%d", &ch);
        if (ch == 1) create();
        else if (ch == 2) insert();
        else if (ch == 3) delete();
        else if (ch == 4) view();
        break;
    }
    
    return 0;
}
