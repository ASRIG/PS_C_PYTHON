#include <iostream>

using namespace std;

int a[10000];

int main(void) {
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a[tmp - 1]++;
	}

	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j < a[i - 1]; j++) {
			printf("%d\n", i);
		}
	}

	return 0;
}