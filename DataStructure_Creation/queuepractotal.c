#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int front = -1;
int rear = -1;
int front1 = -1;
int rear1 = -1;
int queue[SIZE];
int queue1[SIZE];
int totalinqueue = 0;

int full() {
	return totalinqueue == 100;
}

int empty() {
	return totalinqueue == 0;
}

void addq(int data, int n) {
	if(full()) {
		printf("the queue is full\n");
		exit(1);
	}
	if(n == 0) {
		totalinqueue++;
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
		exit(1);
	}
	if(n == 0) {
		totalinqueue--;
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
	for(i = 0; i < 100; i++) {
		x = rand()%100;
		addq(x, 0);
		printf("%d\n", x);
	}
	printf("------------------------------\n");
	for(i = 0; i < 100 - 5 + 1; i++) {
		m = deleteq(0);
	}
	printf("%d\n", m);
	return 0;
}
