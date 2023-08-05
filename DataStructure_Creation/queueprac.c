#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int front = -1;
int rear = -1;
int front1 = -1;
int rear1 = -1;
int lastOperationAddq = 0;
int queue[SIZE];
int queue1[SIZE];

int full() {
	return (front == rear) && (lastOperationAddq == 1);
}

int empty() {
	return (front == rear) && (lastOperationAddq == 0);
}

void addq(int data, int n) {
	if(full()) {
		printf("the queue is full\n");
		exit(1);
	}
	if(n == 0) {
		rear = (rear+1) % 100;
		queue[rear] = data;
	}
	if(n == 1) {
		rear1 = (rear1+1) % 100;
		queue1[rear1] = data;
	}
}

int deleteq(int n) {
	if(empty()) {
		printf("the queue is empty\n");
		//exit(1);
	}
	if(n == 0) {
		front = (front+1) % 100;
		return queue[front];	
	}
	if(n == 1) {
		front1 = (front1+1) % 100;
		return queue1[front1];
	}
}

int main() {
	int i, x, m;
	int take = 2;
	for(i = 0; i < 30; i++) {
		x = rand() % 100;
		printf("%d\n", x);
		addq(x, 0);
	}

	for(i = 0; i < take; i++) {
		m = deleteq(0);
		addq(m, 1);
	}
	
	for(i = 0; i < 28; i++) {
		addq(deleteq(0), 1);
	}
	
	printf("----------------queue1----------------\n");
	for(i = 0; i < 30; i++) {
		printf("%d\n", queue1[i]);
	}
	
	for(i = 0; i < 30; i++) {
		addq(deleteq(1), 0);
	}	
	printf("-----------------------------------------\n");
	for(i = 30; i < 60; i++) {
		printf("%d\n", queue[i]);
	}
}
