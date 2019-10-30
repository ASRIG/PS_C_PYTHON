#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int number = 10;
int data_[] = { 1,10,5,8,7,6,4,3,2,9 };

void show() {
	for (int i = 0; i < number; i++) {
		printf("%d ", data_[i]);
	}printf("\n");
}

void _swap(int &a, int &b) {
	int t = a; a = b; b = t;
}

void quickSort(int start, int end) {
	if (start == end) return;
	
	_swap(data_[start], data_[((end - start) / 2 + start)]);
	
	int pivot = start;
	int left = start + 1, right = end - 1;
	
	while (left <= right) {
		while (left <= right && data_[left] <= data_[pivot]) left++;
		while (left <= right && data_[right] >= data_[pivot]) right--;
		if (left <= right) {
			_swap(data_[left], data_[right]);
		}
	}

	swap(data_[pivot], data_[right]);
	quickSort(start, right);
	quickSort(right + 1, end);
}

void my_quickSort(int start, int end) {
	if (start == end) return;

	_swap(data_[start], data_[((end - start) / 2 + start)]);
	int pivot = start;
	int left = start + 1, right = end - 1;

	while (left <= right) {
		while (left <= right && data_[left] >= data_[pivot]) left++;
		while (left <= right && data_[right] <= data_[pivot]) right--;
		if (left <= right) _swap(data_[left], data_[right]);
	}

	_swap(data_[right], data_[pivot]);
	my_quickSort(start, right);
	my_quickSort(right + 1, end);
}


int main(void) {
	show();
	quickSort(0, number);
	show();
	my_quickSort(0, number);
	show();
	return 0;
}