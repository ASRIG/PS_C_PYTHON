#include <stdio.h>

int n, bag_ = -1;

int main(void) {
	scanf("%d", &n);
	int temp_ = n / 5;
	for (int i = 0; i <= n / 5; i++) {
		int cur_temp = n - 5 * i;
		if (cur_temp % 3 == 0) {
			bag_ = i + cur_temp / 3;
		}
	}
	printf("%d\n", bag_);
	return 0;
}