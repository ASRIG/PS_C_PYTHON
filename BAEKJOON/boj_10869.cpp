#include <stdio.h>

int a, b;

int main(void) {
	scanf("%d %d", &a, &b);
	printf("%d\n", a + b);
	printf("%d\n", a - b);
	printf("%d\n", a * b);
	printf("%d\n", a / b);
	printf("%d\n", a % b);
	return 0;
}