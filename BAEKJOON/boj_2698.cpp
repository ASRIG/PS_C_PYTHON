#include <iostream>
#include <algorithm>

using namespace std;

// 다시하기

int n, k, result_, t;
int dp0[100][100], dp1[100][100];

int main() {
	cin >> t;
	for (int i = 1; i <= 100; i++) {
		for (int j = 0; j <= i - 1; j++) {
			if (i == 1 && j == 0) {
				dp1[i][j] = 1; dp0[i][j] = 1;
			}
			else {
				dp0[i][j] = dp0[i - 1][j] + dp1[i - 1][j];
				dp1[i][j] = dp0[i - 1][j] + dp1[i - 1][j - 1];
			}
		}
	}

	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		result_ = dp0[n][k] + dp1[n][k];
		printf("%d\n", result_);
	}
	
	return 0;
}
