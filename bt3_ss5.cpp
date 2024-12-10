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

// Xoa phan tu cuoi cung
void deleteLast(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong\n");
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

   
    if (temp->prev == NULL) {
        free(temp);
        *head = NULL;
    } else {
        temp->prev->next = NULL;
        free(temp);
    }
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
    
    //xoa phan tu cuoi cung
    deleteLast(&head);
    printf("Danh sach sau khi xoa : \n");
    printList(head);
    return 0;
}

