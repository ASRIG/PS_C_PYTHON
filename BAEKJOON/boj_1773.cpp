#include <iostream>

using namespace std;

int n, c, a[101], b[2000001], answer;

int main(void) {
	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = a[i]; j <= c; j+= a[i]) {
			b[j]++;
		}
	}
	for (int i = 0; i <= c; i++) {
		if (b[i] != 0) { answer++; }
	}
	printf("%d\n", answer);
	return 0;
}