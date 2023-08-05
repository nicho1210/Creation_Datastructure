#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct takem {
	int stack[SIZE];
	int top;
};

int empty(struct takem *pt) {
	return pt->top == -1;
}

int full(struct takem *pt) {
	return pt->top == 99;
}

void push(int data, struct takem *pt) {
	if(full(pt)) {
		printf("full\n");
		exit(1);
	}
	pt->stack[++(pt->top)] = data;
}

int pop(struct takem *pt) {
	if(empty(pt)) {
		printf("empty\n");
		exit(1);
	}
	return pt->stack[(pt->top)--];
}

int print(struct takem *pt) {
	while(!empty(pt)) {
		printf("%d\n", pop(pt));
	}
}

int main(void) {
	int i, x, m;
	struct takem three[2] = {{{0},-1},{{0},-1}};
	
	printf("%d %d\n", three[0].top, three[1].top);
	
	for(i = 0; i < 30; i++) {
		x = rand()%100;
		push(x, &three[0]);
		//printf("%d\n", x);
	}
	
	printf("------------------------------\n");
	
	for(i = 29; i >= 0; i--) {
		printf("%d\n", three[0].stack[i]);
	}
	
	for(i = 0; i < 3; i++) {
		m = pop(&three[0]);
		push(m, &three[1]);
	}
	
	for(i = 0; i < 3; i++) {
		push(pop(&three[1]), &three[0]);
	}
	
	printf("the answer is: %d\n", m);
	print(&three[0]);
	return 0;
}
