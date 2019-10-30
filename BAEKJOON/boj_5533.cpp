#include <iostream>

using namespace std;

int card_[101], n, answer[201], tmp[201][3];

void _fill(int a[], int b, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = b;
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> tmp[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		_fill(card_, 0, 101);
		for (int j = 0; j < n; j++) {
			card_[tmp[j][i]]++;
		}
		for (int j = 0; j < n; j++) {
			if (card_[tmp[j][i]] == 1) answer[j] += tmp[j][i];
		}
	}

	for (int j = 0; j < n; j++) {
		printf("%d\n", answer[j]);
	}
	return 0;
}