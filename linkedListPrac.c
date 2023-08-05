#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *listPointer;
struct listNode {
	int data;
	listPointer link;
};

listPointer create2() {
	listPointer first, second;
	first = (listPointer)malloc(sizeof(struct listNode));
	second = (listPointer)malloc(sizeof(struct listNode));
	first->data = 10;
	first->link = second;
	second->data = 20;
	second->link = NULL;
	return first;
}

void insert(listPointer *first, listPointer x) {
	listPointer temp;
	temp = (listPointer)malloc(sizeof(struct listNode));
	temp->data = 50;
	if(*first) {
		temp->link = x->link;
		x->link = temp;
	} else {
		temp->link = NULL;
		*first = temp;
	}
}

int main(void) {
	listPointer first = create2();
	listPointer second = first->link;
	insert(&first, second);
	listPointer third = second->link;
	printf("%d, %d, %d\n",first->data, second->data, third->data);
	return 0;
}
