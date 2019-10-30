#include <iostream>
#define INF 1000020
using namespace std;

int a[105][105], n, b[105][105];

int min(int a, int b) {
	if (a < b) return a;
	else return b;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if(a[i][j] == 0) b[i][j] = INF;
			else b[i][j] = 1;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				b[i][j] = min(b[i][k] + b[k][j], b[i][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i][j] == INF) printf("0 ");
			else printf("1 ");
		}printf("\n");
	}

	return 0;
}