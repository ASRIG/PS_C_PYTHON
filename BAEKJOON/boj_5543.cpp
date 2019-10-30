#include <iostream>
#include <algorithm>
#define min(a, b) a < b ? a : b
using namespace std;

int a[3], b[2], answer = 99999999;

int main(void) {
	for (int i = 0; i < 3; i++) cin >> a[i];
	for (int i = 0; i < 2; i++) cin >> b[i];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			answer = min(answer, a[i] + b[j] - 50);
		}
	}

	printf("%d\n", answer);
	return 0;
}