#include <iostream>

using namespace std;

int n, T;

int main(void) {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> n;
		for (int j = 0; j < 20; j++) {
			if (n & 1 << j) printf("%d ", j);
		}printf("\n");
	}
	return 0;
}