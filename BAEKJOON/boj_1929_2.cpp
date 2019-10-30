#include <iostream>

using namespace std;

int m, n;
int arr[1000006];

int main(void) {
	for (int i = 2; i <= 1000000; i++) {
		if (arr[i] == 1) continue;
		arr[i] = 2;
		for (int j = i + i; j <= 1000000; j+=i) {
			arr[j] = 1;
		}
	}

	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		if (arr[i] == 2) printf("%d\n", i);
	}
	return 0;
}