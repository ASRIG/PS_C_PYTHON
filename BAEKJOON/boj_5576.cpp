#include <iostream>
#include <algorithm>

using namespace std;

int a[10], b[10];

bool comp(int a, int b) {
	return a > b;
}

void test_sort(int c[]) {
	for (int i = 0; i < 10; i++) {
		int max_num = c[i], index_ = i;
		for (int j = i + 1; j < 10; j++) {
			if (max_num < c[j]) {
				max_num = c[j]; index_ = j;
			}
		}
		int temp_ = c[i]; c[i] = c[index_];
		c[index_] = temp_;
	}
}

int main(void) {
	for (int i = 0; i < 10; i++) cin >> a[i];
	for (int i = 0; i < 10; i++) cin >> b[i];
	//sort(a, a + 10, comp); sort(b, b + 10, comp);
	test_sort(a); test_sort(b);

	printf("%d %d\n", a[0] + a[1] + a[2], b[0] + b[1] + b[2]);
	return 0;
}