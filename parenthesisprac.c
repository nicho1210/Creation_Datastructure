#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int top = -1;

struct element {
	char type;
	int pos;
};

struct element stack[SIZE];

int full() {
	return top == SIZE - 1;
}

int empty() {
	return top == -1;
}

void push(struct element *ps) {
	if(full()) {
		printf("full\n");
		exit(1);
	}
	stack[++top].type = ps->type;
	stack[top].pos = ps->pos;
}

struct element *pop() {
	if(empty()) {
		printf("empty\n");
		exit(1);
	}
	return &stack[top--];
}

char other_side(char x) {
	if(x == '(') return ')';
	if(x == ')') return '(';
	if(x == '[') return ']';
	if(x == ']') return '[';
	if(x == '{') return '}';
	if(x == '}') return '{';
}

int main(void) {
	char symb;
	int pos = 0;
	struct element data;
	struct element *p;
	while((symb = getchar()) != '\n') {
		if(symb == '(' || symb == '[' || symb == '{') {
			data.type = symb;
			data.pos = pos;
			push(&data);
		} else if(symb == ')' || symb == ']' || symb == '}') {
			if(!empty() && (p = pop())->type == other_side(symb)) {
				printf("%c%d,%d%c\n", p->type, p->pos, pos, symb);
			} else {
				printf("right parenthesis %c at %d has no matching left parenthesis %c\n", symb, pos, other_side(symb));
				if(p->type != other_side(symb)) {
					push(p);
				}
			}
		}
		pos++;
	}
	
	while(!empty()) {
		p = pop();
		printf("left parenthesis %c at %d has no matching right parenthesis %c\n", p->type, p->pos, other_side(p->type));
	}
	return 0;
}
