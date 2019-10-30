#include <iostream>

int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
int tmp[10];

void mergeSort(int start, int end) {
	if (start < end) {
		int mid = (start + end) >> 1;

		mergeSort(start, mid);
		mergeSort(mid + 1, end);

		int left = start, right = mid + 1;
		int idx = start;

		while (left <= mid || right <= end) {
			if (start == 0 && end == 1) printf("left : %d, right : %d, idx : %d\n", left, right, idx);
			if (right > end || (left <= mid && arr[left] < arr[right]))
				tmp[idx++] = arr[left++];
			else
				tmp[idx++] = arr[right++];
		}
		for (int i = start; i <= end; i++) arr[i] = tmp[i];
	}
}

void print(int a) {
	printf("%s\n", !a ? "Àü" : "ÈÄ");
	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
	printf("\n");
}

int main() {
	print(0);
	mergeSort(0, 10 - 1);
	print(1);
	return 0;
}