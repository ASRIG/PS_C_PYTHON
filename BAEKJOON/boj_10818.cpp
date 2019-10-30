#include <iostream>
#define _max(a, b) a < b ? b : a
#define _min(a, b) a < b ? a : b
using namespace std;

int n, tmp, min_num = 5000000, max_num = -5000000;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		max_num = _max(max_num, tmp);
		min_num = _min(min_num, tmp);
	}
	printf("%d %d\n", min_num, max_num);
	return 0;
}