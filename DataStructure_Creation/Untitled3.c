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
	return top == 99;
}

int empty() {
	return top == -1;
}

void push(struct element *p) {
	if(full()) {
		printf("the stack is full\n");
		exit(1);
	}
	stack[++top].type = p->type;
	stack[top].pos = p->pos;
}

struct element *pop() {
	if(empty()) {
		printf("the stack is empty\n");
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
	while((symb = getchar())!='\n') {
		if(symb == '(' || symb == '[' || symb == '{') {
			data.type = symb;
			data.pos = pos;
			push(&data);
		} else if(symb == ')' || symb == ']' || symb == '}') {
			if(!empty() && (p = pop())->type == other_side(symb)) {
				printf("%c%d%,%d%c\n", p->type, p->pos, pos, symb);
			} else {
				printf("right parenthesis %c has no matching left parenthesis %c at %d\n", symb, other_side(symb), pos);
				if(p->type!=other_side(symb)) {
					push(p);
				}
			}
		}
		pos++;
	}
	
	while(!empty()) {
		p = pop();
		printf("left parenthesis %c has no matching right parenthesis %c at %d\n", p->type, other_side(p->type), p->pos);
	}
	return 0;
}
