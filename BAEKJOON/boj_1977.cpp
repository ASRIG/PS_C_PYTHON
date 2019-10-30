#include <iostream>

using namespace std;

int M, N, arr[102], sum_ = 0, min_= 10000000;

int main(void) {
	for (int i = 1; i <= 100; i++) {
		arr[i] = i * i;
	}
	
	cin >> M; cin >> N;
	for (int i = 1; i <= 100; i++) {
		if (arr[i] < M || arr[i] > N) continue;
		sum_ += arr[i];

		if (min_ > arr[i]) min_ = arr[i];
	}
	if (sum_ == 0) printf("-1\n");
	else {
		printf("%d\n", sum_); printf("%d\n", min_);
	}

	return 0;
}