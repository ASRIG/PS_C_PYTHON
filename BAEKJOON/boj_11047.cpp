#include <iostream>

using namespace std;

int N, K, a[15], b[15];

void mergeSort(int start, int end) {
	if (start < end) {
		int mid = (start + end) >> 1;

		mergeSort(start, mid);
		mergeSort(mid + 1, end);

		int left = start, right = mid + 1;
		int idx = start;

		while (left <= mid || right <= end) {
			if (right > end || (left <= mid && a[left] > a[right]))
				b[idx++] = a[left++];
			else
				b[idx++] = a[right++];
		}
		for (int i = start; i <= end; i++) a[i] = b[i];
	}
}

int main(void) {
	cin >> N >> K;
	for (int i = 0; i < N;i++) {
		cin >> a[i];
	}
	mergeSort(0, N - 1);
	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer += K / a[i];
		K %= a[i];
	}
	printf("%d\n", answer);

	return 0;
}