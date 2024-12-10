#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Duyet danh sach
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("<->%d", temp->data);
        temp = temp->next;
    }
    printf("<->NULL\n");
}

// Them 1 phan tu vao vi tri bat ki
void insertElement(Node** head, int data, int position) {
    Node* newNode = createNode(data);

    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Loi vi tri ko hop le\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Them phan tu vao cuoi danh sach
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

int main() {
    Node* head = NULL;
    int n;

    printf("Nhap so luong phan tu : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        printf("Nhap gia tri cho phan tu %d : ", i + 1);
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Danh sach hien tai : \n");
    printList(head);

    int insertValue, position;
	printf("Nhap vi tri can chen: ");
    scanf("%d", &position);
    printf("Nhap gia tri can chen: ");
    scanf("%d", &insertValue);
    
    insertElement(&head, insertValue, position);

    printf("Danh sach sau khi chen: \n");
    printList(head);


    return 0;
}
