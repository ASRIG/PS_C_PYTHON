#include <iostream>

using namespace std;

int main(void) {
	int n, a = 1, b = 1, c = 1;
	cin >> n;
	// 직접 경우의 수를 구해볼 경우
	// 1 3 5 11 21 ... 등으로
	// a(n-2) * 2 + a(n-1) = a(n)이 나타나는 걸 볼 수 있다.
	for (int i = 1; i < n; i++) {
		c = (2 * a + b) % 10007;
		a = b; b = c;
	}
	printf("%d\n", c);
	return 0;
}