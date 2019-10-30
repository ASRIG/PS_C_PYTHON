#include <iostream>

using namespace std;

int L, P, a[5];

int main(void) {
	cin >> L >> P;
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 5; i++) {
		printf("%d ", a[i] - L * P);
	}printf("\n");
	return 0;
}