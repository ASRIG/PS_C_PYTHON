#include <iostream>

using namespace std;

int cnt = 1, n, k, arr[1001];

int main(void) {
	cin >> n >> k;

	for (int i = 2; i <= n; i++) {
		if (arr[i] == -1) continue;
		arr[i] = 2; 
		if (cnt++ == k) {
			printf("%d\n", i);
			return 0;
		}
		for (int j = i + i; j <= n; j += i) {
			if (arr[j] == -1) continue;
			arr[j] = -1; //printf("¼ø¼­ %d : %d\n", cnt, j);
			if (cnt++ == k) {
				printf("%d\n", j);
				return 0;
			}
		}
	}
	return 0;
}