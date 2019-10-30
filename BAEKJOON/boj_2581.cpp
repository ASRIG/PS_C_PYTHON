#include <iostream>

using namespace std;

int arr[10001], N, M;

int main(void) {
	cin >> M >> N;

	for (int i = 2; i <= 10000; i++) {
		if (arr[i] == -1) continue;
		arr[i] = 1;	// ¼Ò¼ö
		for (int j = i + i; j <= 10000; j += i) {
			arr[j] = -1;
		}
	}
	int first_num = 0, sum_ = 0;
	for (int i = M; i <= N; i++) {
		if (arr[i] == 1) {
			if (first_num == 0) first_num = i;
			sum_ += i;
		}
	}
	if (first_num == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n%d\n", sum_, first_num);
	}
	return 0;
}