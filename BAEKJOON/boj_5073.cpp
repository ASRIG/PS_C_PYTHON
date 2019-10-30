#include <iostream>
#define max(a, b) a < b ? b : a
using namespace std;

int a, b, c;

int main(void) {
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0) break;
		if (a + b <= c || a + c <= b || b + c <= a) {
			printf("Invalid\n");
		}
		else if (a == 0 || b == 0 || c == 0) printf("Invalid\n");
		else {
			if (a == b && b == c && c == a) printf("Equilateral\n");
			else if (a == b || b == c || c == a) printf("Isosceles\n");
			else printf("Scalene\n");
		}
		
	}
	return 0;
}