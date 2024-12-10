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

// Ham thay the gia tri trong danh sach
void replaceValue(Node* head, int oldValue, int newValue) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue; // Thay th? giá tr?
            return; // Thoát sau khi thay th?
        }
        temp = temp->next;
    }
    printf("Không tìm th?y ph?n t? thay th?\n");
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
    
    int oldValue, newValue;
    printf("Nhap vi tri can thay the : ");
    scanf("%d", &oldValue);
    printf("Nhap gia tri can thay the : ");
    scanf("%d", &newValue);

    replaceValue(head, oldValue, newValue);
    
    printf("Danh sách sau khi thay th?:\n");
    printList(head);
}

