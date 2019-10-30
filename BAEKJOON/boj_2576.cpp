#include <iostream>
#define min(a, b) a < b ? a : b
using namespace std;

int cnt, min_ = 990, sum_ = 0;

int main(void) {
	int tmp;
	for (int i = 0; i < 7; i++) {
		cin >> tmp;
		if (tmp & 1 << 0) {
			sum_ += tmp;
			min_ = min(min_, tmp);
		}
	}
	if (sum_) {
		printf("%d\n%d\n", sum_, min_);
	}
	else {
		printf("-1\n");
	}
	return 0;
}