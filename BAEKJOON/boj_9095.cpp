#include <iostream>
#include <algorithm>

using namespace std;

int T, n, arr[15][4], answer;

int main() {
	arr[1][1] = 1; arr[2][2] = 1; arr[3][3] = 1;
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 3; j++) {
			if (arr[i][j] > 0) {
				for (int k = 1; k <= 3; k++) {
					arr[i + k][k] = arr[i + k][k] + arr[i][j];
				}
			}
		}
	}

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n;
		answer = 0;
		for (int i = 1; i <= 3; i++) answer += arr[n][i];
		printf("%d\n", answer);
	}
}