#include <iostream>

int arr[10] = { 1,9,2,7,3,8,4,6,10, 2 };
int arr2[10] = { 1,9,2,7,3,8,4,6,10, 2 };

using namespace std;

void swap(int &a, int &b) {
	int tmp = a; a = b; b = tmp;
}

void qsort(int start, int end) {
	if (start == end) return;
	swap(arr[start], arr[(start + end) / 2]);
	int pivot = start;
	int left = start + 1, right = end - 1;

	while (left <= right) {
		while (left <= right && arr[pivot] >= arr[left]) left++;
		while (left <= right && arr[pivot] <= arr[right]) right--;
		if (left <= right) swap(arr[left], arr[right]);
	}

	swap(arr[pivot], arr[right]);
	qsort(start, right);
	qsort(right + 1, end);
}

int sorted[10];

void merge(int m, int mid, int n) {
	int i = m, j = mid + 1, k = m;

	while (i <= mid && j <= n)
		sorted[k++] = (arr2[i] <= arr2[j]) ? arr2[i++] : arr2[j++];
	while (i <= mid) sorted[k++] = arr2[i++];
	while (j <= n) sorted[k++] = arr2[j++];
	for (int ia = 0; ia <= n; ia++) {
		arr2[ia] = sorted[ia];
	}
}

void msort(int start, int end) {
	if (start < end) {
		int mid = (end + start) / 2;
		msort(start, mid);
		msort(mid + 1, end);
		merge(start, mid, end);
	}
}


int main(void) {
	qsort(0, 10);
	msort(0, 9);

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr2[i]);
	}printf("\n");
	return 0;
}

