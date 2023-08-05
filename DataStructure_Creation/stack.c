#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int array[SIZE] = {0};
int top = -1;
char character;
int num = 0;

int empty() {
    if(top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int full() {
    if(top == 99) {
        return 1;
    } else {
        return 0;
    }
}

void push(int n) {
    array[++top] = n;
}

int pop() {
    return array[top--];
}

int main(void) {
    char last;
    while((character = getchar()) != '\n') {
        if(character == '(') {
            push(num);
        } 
        if(character == ')') {
            if(!empty()) {
                printf("(%d,%d)\n", pop(), num);
            } else {
                printf("No.%d ) has no ( to pair with\n", num);
            }
        }
        num++;
    }
    if(!empty()) {
        printf("No.%d ( has no ) to pair with\n", pop());
    }
    return 0;
}