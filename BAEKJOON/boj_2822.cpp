#include <iostream>

using namespace std;

struct EXAM {
	int i, score;

	EXAM(int a, int b) {
		i = a; b = score;
	}
	EXAM() {}
};

EXAM a[9];

void _swap(int &a, int &b) {
	int tmp = a; a = b; b = tmp;
}

void _sort(EXAM aa[], int start, int end) {
	for (int i = start; i <= end; i++) {
		int tmp = aa[i].score, tmp_i = i;
		for (int j = i; j <= end; j++) {
			if (tmp < aa[j].score) {
				tmp = aa[j].score; tmp_i = j;
			}
		}
		_swap(aa[i].score, aa[tmp_i].score);
		_swap(aa[i].i, aa[tmp_i].i);
	}
}

void _sort_int(int aa[], int start, int end) {
	for (int i = start; i <= end; i++) {
		int tmp = aa[i], tmp_i = i;
		for (int j = i; j <= end; j++) {
			if (tmp > aa[j]) {
				tmp = aa[j]; tmp_i = j;
			}
		}
		_swap(aa[i], aa[tmp_i]);
	}
}

int main(void) {
	for (int i = 1; i <= 8; i++) {
		cin >> a[i].score; a[i].i = i;
	}
	_sort(a, 1, 8);
	int answer = 0;
	for (int i = 1; i <= 5; i++) answer += a[i].score;
	printf("%d\n", answer);
	int aa[6];
	for (int i = 1; i <= 5; i++) aa[i] = a[i].i;
	_sort_int(aa, 1, 5);
	for (int i = 1; i <= 5; i++) printf("%d ", aa[i]);

	return 0;
}