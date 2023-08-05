#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int queue[SIZE];
int front = -1;
int rear = -1;
//int lastOperationIsAddq = 0;
//int totalInQueue = 0;

int empty() {
	//return (rear == front) && (lastOperationIsAddq == 0);
	//return totalInQueue == 0;
	return front == rear;
}

int full() {
	//return (rear == front) && (lastOperationIsAddq == 1);
	//return totalInQueue == 100;
	return front == (rear+1) % 100;
}

void addq(int data) {
	if(full()) {
		printf("full\n");
		exit(1);
	}
	//lastOperationIsAddq = 1;
	//totalInQueue++;
	rear = (rear+1)%100;
	queue[rear] = data;
}

int deleteq() {
	if(empty()) {
		printf("empty\n");
		exit(1);
	}
	//lastOperationIsAddq = 0;
	//totalInQueue--;
	front = (front + 1)%100;
	return queue[front];
}

int main(void) {
	int i, x, m;
	for(i = 0; i < 30; i++) {
		x = rand()%100;
		addq(x);
	}
	
	for(i = 0; i < 30; i++) {
		printf("%d\n", queue[i]);
	}
	return 0;
}
