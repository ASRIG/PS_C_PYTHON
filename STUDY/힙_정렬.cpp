#include <iostream>
#include <algorithm>
using namespace std;

const int number = 9;
int heap[9] = { 7, 6,5,8,3,5,9,1,6 };

void swap(int &a, int &b) {
	int tmp = a; a = b; b = tmp;
}

int main(void) {
	// 힙을 구성
	for (int i = 1; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) {
				swap(heap[root], heap[c]);
			}
			c = root;
		} while (c != 0);
	}

	// 크기를 줄여가며 반복적으로 힙을 구성
	for (int i = number - 1; i >= 0; i--) {
		swap(heap[0], heap[i]);
		int root = 0, c = 1;
		do {
			c = 2 * root + 1;
			// 자식 중에 더 큰값 찾기
			if (c < i - 1 && heap[c] < heap[c + 1]) {
				c++;
			}
			// 루트보다 자식이 더 크다면 교환
			if (c < i && heap[root] < heap[c]) {
				swap(heap[root], heap[c]);
			}
			root = c;
		} while (c < i);
	}

	for (int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	}



	return 0;
}