#include <stdio.h>
#include <stdlib.h>

int stack[100];
int top = -1;

void push(int n) {
	stack[++top] = n;
}

int pop() {
	return stack[top--];
}

struct stint {
    int f3, f4;
};

struct stfloat {
    float f5, f6;
};

struct name{
    int f1;    //0x40
	double f2;   //0x48
	int f3;          
             
    int utype;      
	union {
		struct stint x;
		struct stfloat y;
	};   
};

int main() {
	int i;
	int n = 4;
	int NumOfVar = 4;
	int temp1, temp2;
	
	struct name nicholas;
	struct name *pointer = &nicholas;
	printf("0x%x\n", &(nicholas.f1));
	printf("0x%x\n", &(nicholas.f2));
	printf("0x%x\n", &(nicholas.utype));
	
	return 0;
} 
