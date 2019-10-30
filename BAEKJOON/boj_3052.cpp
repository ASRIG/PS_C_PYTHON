#include <iostream>

using namespace std;

int a, b, c[42];

int main(void) {
	for (int i = 0; i < 10; i++) {
		cin >> a;
		c[a % 42]++;
	}

	int answer = 0;
	for (int i = 0; i < 42; i++) {
		if (c[i] != 0) answer++;
	}
	printf("%d\n", answer);
	return 0;
}