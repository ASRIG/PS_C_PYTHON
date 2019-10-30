#include <iostream>

using namespace std;

int a[3];

void _swap(int &a, int &b) {
	int tmp = a; a = b; b = tmp;
}

void _sort(int aa[], int start_, int end_) {
	for (int i = start_; i < end_; i++) {
		int tmp = aa[i], tmp_i = i;
		for (int j = i; j < end_; j++) {
			if (tmp > aa[j]) {
				tmp = aa[j]; tmp_i = j;
			}
		}
		_swap(aa[i], aa[tmp_i]);
	}
}

int main(void) {
	while (1) {
		for (int i = 0; i < 3; i++) cin >> a[i];
		if (a[0] == 0 && a[1] == 0 && a[2] == 0) break;
		_sort(a, 0, 3);
		if (a[2] * a[2] == a[0] * a[0] + a[1] * a[1]) printf("right\n");
		else printf("wrong\n");
	}
	return 0;
}