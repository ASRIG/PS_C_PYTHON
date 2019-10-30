#include <iostream>

using namespace std;

int n, m, arr[500005], a, input;

void swap(int &a, int &b) {
	int tmp = a; a = b; b = tmp;
}

void heapify() {
	for (int i = 1; i < n; i++) {
		int root = 0, c = i;
		do {
			root = (c - 1) / 2;
			if (arr[root] < arr[c])swap(arr[root], arr[c]);
			c = root;
		} while (c != 0);
	}
}

void heap_sort() {
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		int root = 0, c = 1;
		do {
			c = root * 2 + 1;
			if (c < i - 1 && arr[c] < arr[c + 1]) c++;
			if (c < i && arr[c] > arr[root]) swap(arr[c], arr[root]);
			root = c;
		} while (c < i);
	}
}

void find_num(int a) {
	int ans = 0;
	int start_ = 0, end_ = n - 1;
	while (end_ - start_ >= 0) {
		int mid_ = (start_ + end_) / 2;
		if (arr[mid_] == a) {
			ans = 1; break;
		}
		if (arr[mid_] < a) start_ = mid_ + 1;
		else end_ = mid_ - 1;
	}
	printf("%d", ans);
}


int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	heapify(); heap_sort();

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &input);
		find_num(input);
		if (i == m - 1)printf("\n");
		else printf(" ");
	}

	return 0;
}