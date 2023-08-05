#include <stdio.h>
#include <stdlib.h>

typedef int *happy;

void adjust(happy *ptr) {
	printf("value in func: %d\n", **ptr);
	printf("pos in func: 0x%x\n", *ptr);
	*ptr = (*ptr)+1;
	**ptr = 20;
	printf("adjusted-pos in func: 0x%x\n", *ptr);
}

int main(void) {
	int a = 10;
	happy intp = &a;
	
	adjust(&intp);
	printf("pos in main: 0x%x\n", intp);
	printf("value in main: %d\n", *intp);
	
}
