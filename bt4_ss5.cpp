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

// Ham dem so luong phan tu trong danh sach
int countElements(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
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
    
    // Dem so luong phan tu
    int count = countElements(head);
    if (count > 0) {
        printf("So luong phan tu trong danh sach: %d\n", count);
    } else {
        printf("Danh sach rong\n");
    }
    return 0;

}

