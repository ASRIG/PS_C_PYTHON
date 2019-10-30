#include <iostream>
#include <algorithm>

using namespace std;

int size, sorted[8], count(0);

void merge(int a[], int m, int middle, int n) {
	int i = m, j = middle + 1, k = m;
	// 작은 순서대로 배열에 삽임
	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k++] = a[i++];
		}
		else {
			sorted[k++] = a[j++];
		}
	}

	// 남은 데이터도 삽입
	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sorted[k++] = a[t];
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k++] = a[t];
		}
	}
	for (int t = m; t <= n; t++) a[t] = sorted[t];
}

void mergeSort(int a[], int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main(void) {
	const int number = 8;
	int array_[number] = { 7,6,5,8,3,5,9,1 };
	mergeSort(array_, 0, number - 1);
	for (int i = 0; i < number; i++) {
		printf("%d ", array_[i]);
	}
	printf("\n");
	return 0;
}