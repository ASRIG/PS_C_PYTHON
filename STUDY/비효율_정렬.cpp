#include <iostream>

using namespace std;

int arr1[] = { 5, 1, 2, 3, 2, 1 };
int arr2[] = { 5, 1, 2, 3, 2, 1 };
int arr3[] = { 5, 1, 2, 3, 2, 1 };
int n = 6, cnt;

void print() {
	printf("[[ round :: %d ]]\n", ++cnt);
	for (int i = 0; i < n; i++)printf("%d ", arr1[i]);
	printf("\n");
}

void insert_sort() {
	for (int i = 1; i < n; i++) {
		print();
		int key = arr1[i];
		for (int j = i - 1; j >= 0; j--) {
			print();
			if (arr1[j] > key) {
				arr1[j + 1] = arr1[j];
				arr1[j] = key;
			}
			else break;
		}
	}
	print();
}

int main(void) {
	insert_sort();
	return 0;
}