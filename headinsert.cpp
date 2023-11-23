#include<stdio.h>
#include<stdlib.h>

typedef struct Node {

	int data;
	struct Node* pre;
	struct Node* next;

}Node;

Node* initList() {
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->pre = NULL;
	L->next = NULL;
	return L;
}

void headInsert(Node* L, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	if (L->data == 0) {
		//Á´±íÎª¿Õ
		node->next = L->next;
		node->pre = L;
		L->next = node;
	}
	else {
		node->pre = L;
		node->next = L->next;
		L->next->pre = node;
		L->next = node;
	}
}
void printList(Node* L) {
	Node* node = L->next;
	while (node) {
		printf("%d ->", node->data);
		node = node->next;
	}
	printf("NULL\n");
}

int main()
{
	Node* L = initList();
	headInsert(L, 1);
	headInsert(L, 2);
	headInsert(L, 3);
	headInsert(L, 4);
	printList(L);

	return 0;
}