#include <iostream>

using namespace std;

struct TOB {
	char a[8];

	void rotate() {
		int tmp = a[0];
		a[0] = a[7];
		for (int i = 7; i > 1; i--) {
			a[i] = a[i - 1];
		} a[1] = tmp;
	}

	void inv_rotate() {
		int tmp = a[0]; a[0] = a[1];
		for (int i = 1; i < 7; i++) {
			a[i] = a[i + 1];
		} a[7] = tmp;
	}

	void print() {
		for (int i = 0; i < 8; i++) {
			printf("%c ", a[i]);
		} printf("\n");
	}
};

int k, a, b;
TOB t[4];

int pow(int a, int b) {
	int ret = 1;
	for (int i = 0; i < b; i++) {
		ret *= a;
	}
	return ret;
}

int main(void) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> t[i].a[j];
			// N : 0, S : 1
		}
	}

	cin >> k;
	int d[4];
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 4; j++) {
			d[j] = 0;
		}

		scanf("%d %d", &a, &b);
		a -= 1; d[a] = b;
		

		// 1 시계, -1 반시계
		for (int j = a; j < 3; j++) {
			if (t[j].a[2] != t[j + 1].a[6]) {
				d[j + 1] = d[j] * -1;
			}
		}

		for (int j = a; j > 0; j--) {
			if (t[j].a[6] != t[j - 1].a[2]) {
				d[j - 1] = d[j] * -1;
			}
		}
		
		for (int j = 0; j < 4; j++) {
			if (d[j] == 1) t[j].rotate();
			else if (d[j] == -1) t[j].inv_rotate();
		}
	}

	int answer = 0;
	for (int i = 0; i < 4; i++) {
		if (t[i].a[0] == '1') {
			answer += pow(2, i);
		}
	}
	printf("%d\n", answer);

	return 0;
}