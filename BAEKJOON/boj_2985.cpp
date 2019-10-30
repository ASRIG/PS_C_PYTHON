#include <iostream>

using namespace std;

int a, b, c;

int main(void) {
	cin >> a >> b >> c;
	if (a + b == c) {
		printf("%d+%d=%d\n", a, b, c);
	}
	else if (a - b == c) {
		printf("%d-%d=%d\n", a, b, c);
	}
	else if (a * b == c) {
		printf("%d*%d=%d\n", a, b, c);
	}
	else if (a == b + c) printf("%d=%d+%d\n", a, b, c);
	else if (a == b - c) printf("%d=%d-%d\n", a, b, c);
	else if (a == b * c) printf("%d=%d*%d\n", a, b, c);
	else if (a == b / c) printf("%d=%d/%d\n", a, b, c);
	
	
	return 0;
}