#include <iostream>

using namespace std;

int n;

int main(void) {
	cin >> n;
	int a = 1, b = 1, c = 1;
	// ������ �Ǻ���ġ ������ ���󰣴�.
	for (int i = 1; i < n; i++) {
		c = (a + b) % 15746;
		a = b; b = c;
	}

	printf("%d\n", c);

	return 0;
}