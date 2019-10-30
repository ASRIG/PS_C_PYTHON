#include <iostream>
#include <algorithm>

using namespace std;

int ax, ay, ai, aj;
int n, m, k;
int arr[305][305];

int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> ai >> aj >> ax >> ay;
		int sum = 0;
		for (int ia = ai; ia <= ax; ia++) {
			for (int ib = aj; ib <= ay; ib++) {
				sum += arr[ia][ib];
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}