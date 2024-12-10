#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
}Node; 

Node* createNode(int data){
	//cap phat bo nho
	Node* newNode = (Node*)malloc(sizeof(Node));
	//gan data
	newNode->data = data;
	
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}


//them phan tu vao dau danh sach
void inserHead(Node** head,int data){
	//tao node moi
	Node* newNode = createNode(data);
	newNode->next = *head; 
	if(*head != NULL){
		(*head)->prev = newNode;
	} 
	*head = newNode;
}

//Them phan tu vao cuoi danh sach
void inserEnd(Node** head,int data){
	Node* newNode = createNode(data);
	if(*head == NULL){
		*head = newNode;
		return;
	}
	//tim phan tu cuoi
	Node* temp = *head;
	while(temp->prev != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

//Duyet danh sach
void printList(Node* head){
	Node* temp = head;
	printf("NULL");
	while(temp != NULL){
		printf("<--->%d",temp->data);
		temp = temp->next;
	}
	printf("<--->NULL\n");
}

// them 1 phan tu vao vi tri bat ki 
void insertElement(Node** head, int data, int position){
	Node* newNode = createNode(data);
	
	if(position == 0){
		newNode->next = *head;
		*head = newNode;
		return;
	}
	Node* temp = *head;
	for(int i; i < position - 1 && temp != NULL;i++){
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	temp->prev = newNode;
	newNode->prev = temp;

}

// Xoa mot phan tu o vi tri bat ki 
void deleteElement(Node** head, int position) {
    if (*head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }

    Node* temp = *head;

    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    // Cap nhat cac con tro da xoa nut
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}
int main() {
	Node* head = NULL;
	int value,position;
	do{
		printf(	"**************MENU****************\n");
		printf("1. Them mot phan tu vao dau danh sach\n");
		printf("2. Hien thi\n");
		printf("3. Them mot phan tu vao cuoi danh sach\n");
		printf("4. Them mot phan tu vao vi tri bat ki\n");
		printf("5. Xoa mot phan tu vao vi tri bat ki\n");
		printf("6. Thoat\n");
		printf("Moi ban chon tu 1 - 4 : ");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1 :
				printf("Noi ban nhap vao gia tri cho phan tu : ");
				scanf("%d",&value);
				inserHead(&head,value);
				break;
			case 2 :
				printList(head);
				break;
			case 3 :
				printf("Moi ban nhap vao gia tri phan tu can chen vao cuoi : ");
				scanf("%d",&value);
				inserEnd(&head,value);
				break;
			case 4 :
				printf("Moi ban nhap vao vi tri can chen : ");
				scanf("%d",&position);
				printf("Moi ban nhap gia tri can chen : ");
				scanf("%d",&value);
				insertElement(&head,value,position);
				break;
			case 5 :
				printf("Moi ban nhap vao vi tri can chen : ");
				scanf("%d",&position);
				deleteElement(&head,position);
				break;
			case 6 :
				exit(0);
			default : 
				printf("Vui long nhap lai");
		}
	}while(1==1);
	return 0;
}

