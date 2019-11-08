#include <iostream>

using namespace std;

int n;

int main(void) {
	cin >> n;
	int a = 1, b = 1, c = 1;
	// 직사각형을 어떻게 채우느냐에 따라 나오는 결과
	// 나오는 경우의 수를 보면 피보나치를 따름.
	for (int i = 1; i < n; i++) {
		c = (a + b) % 10007;
		a = b; b = c;
	}
	printf("%d\n", c);
	return 0;
}