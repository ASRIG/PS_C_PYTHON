#include <iostream>

using namespace std;

int n, a[1005], cdf[1005];

void _sort() {
	for (int i = 0; i < n; i++) {
		int num_ = a[i], num_index = i;
		for (int j = i + 1; j < n; j++) {
			if (num_ > a[j]) {
				num_ = a[j]; num_index = j;
			}
		}
		int tmp = a[i]; a[i] = a[num_index]; a[num_index] = tmp;
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	_sort();

	int answer = 0;
	cdf[0] = a[0];

	for (int i = 0; i < n; i++) {
		cdf[i] = cdf[i - 1] + a[i];
		answer += cdf[i];
	}

	printf("%d\n", answer);
	return 0;

}