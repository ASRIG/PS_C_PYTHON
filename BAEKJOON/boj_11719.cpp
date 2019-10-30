#include<stdio.h>

int main(void) {
	char c;
	c = getchar();
	while (c != -1) {
		putchar(c);
		c = getchar();
	}
	/*
	char c;
	while ((c = getchar()) && c != EOF){
		printf("%c", c);
	}
	*/
}