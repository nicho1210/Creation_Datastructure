#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *listPointer;
struct listNode {
	int data;
	listPointer link;
};

struct stack {
	listPointer top;
};

int empty(struct stack *ps) {
	return (ps->top == NULL);
}

void push(struct stack *ps, int data) {
	listPointer p = (listPointer)malloc(sizeof(struct listNode));
	p->data = data;
	if(ps->top == NULL) {
		p->link = p;
	} else {
		p->link = ps->top;	
	}
	ps->top = p;
}

int pop(struct stack *ps) {
	if(empty(ps)) {
		printf("the stack is empty\n");
		exit(2);
	}
	
	int x = ps->top->data;
	
	listPointer temp = ps->top;
	//free(ps->top);
	ps->top = ps->top->link;
	free(temp);
	
	if(ps->top == ps) {
		ps->top = NULL;
	}
	
	return x;
}

int main(void) {
	struct stack DataLink = {0};
	DataLink.top = NULL;
	push(&DataLink, 50);
	int m = pop(&DataLink);
	printf("%d\n", m);
}
