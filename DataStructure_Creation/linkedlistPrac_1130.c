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

void insert(listPointer *first, listPointer x, int data) {
	listPointer p = (listPointer)malloc(sizeof(struct listNode));
	p->data = data;
	if(*first) {
		p->link = x->link;
		x->link = p;
	} else {
		*first = p;
	}
}

int main(void) {
	listPointer first, second, third;
	first = create2();
	second = first->link;
	insert(&first, second, 100);
	third = second->link;
	printf("%d\n", third->data);
	return 0;
}
