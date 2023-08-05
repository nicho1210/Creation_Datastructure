#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct stack {
	int A[SIZE];
	int top;
};

int full(struct stack *ps) {
	return ps->top == (SIZE-1);
}

int empty(struct stack *ps) {
	return ps->top == -1;
}

void push(int data, struct stack *ps) {
	if(full(ps)) {
		printf("the stack is full\n");
		exit(1);
	}
	ps->A[++(ps->top)] = data;
}

int pop(struct stack *ps) {
	if(empty(ps)) {
		printf("the stack is empty\n");
		exit(1);
	}
	return ps->A[(ps->top)--];
}

int main(void) {
	char symb;
	int pos = 0;
	struct stack parenthesis[3] ={{0,-1},{0,-1},{0,-1}};
	while((symb = getchar()) != '\n') {
		
		if(symb == '(') {
			push(pos, &parenthesis[0]);
		} else if(symb == ')') {
			if(empty(&parenthesis[0])) {
				printf("right parenthesis ) at %d has no matching left parenthesis (\n", pos);
			} else {
				printf("(%d,%d)\n", pop(&parenthesis[0]), pos);
			}
		}
		/*
		if(symb == '[') {
			push(pos, &parenthesis[1]);
		} else if(symb == ')') {
			if(empty(&parenthesis[1])) {
				printf("right parenthesis ] at %d has no matching left parenthesis [\n", pos);
			} else {
				printf("[%d,%d]\n", pop(&parenthesis[1]), pos);
			}
		}
		*/
		/*
		if(symb == '{') {
			push(pos, &parenthesis[2]);
		} else if(symb == '}') {
			if(empty(&parenthesis[2])) {
				printf("right parenthesis } at %d has no matching left parenthesis [n", pos);
			} else {
				printf("(%d,%d)\n", pop(&parenthesis[2]), pos);
			}
		}
		*/
		pos++;
	}
	/*
	while(!empty(&parenthesis[0])) {
		printf("left parenthesis ( at %d has no matching right parenthesis )\n", pop(&parenthesis[0]));
	}
	while(!empty(&parenthesis[1])) {
		printf("left parenthesis [ at %d has no matching right parenthesis ]\n", pop(&parenthesis[1]));
	}
	while(!empty(&parenthesis[2])) {
		printf("left parenthesis { at %d has no matching right parenthesis }\n", pop(&parenthesis[2]));
	}
	*/
	return 0;
}
