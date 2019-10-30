#include <iostream>

using namespace std;

int m1, m2, n, tmp;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		m1 += (tmp / 30 + 1) * 10;
		m2 += (tmp / 60 + 1) * 15;
	}

	if (m1 > m2) {
		printf("M %d\n", m2);
	}
	else if (m1 < m2) {
		printf("Y %d\n", m1);
	}
	else {
		printf("Y M %d\n", m1);
	}

	return 0;
}