#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[1005];

int main(void) {
	arr[0] = -1; arr[1] = -1;
	for (int i = 2; i < 1001; i++) {
		if (arr[i] == -1) continue;
		for (int j = i + i; j < 1001; j += i) {
			arr[j] = -1;
		}
	}
	int answer = 0, a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (arr[a] != -1) answer++;
	}
	printf("%d\n", answer);
	return 0;
}