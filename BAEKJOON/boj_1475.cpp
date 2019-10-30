#include <iostream>
#include <algorithm>

using namespace std;

int n, result_;
int arr[10];

int main(void) {
	cin >> n;
	while (n / 10 != 0) {
		arr[n % 10]++;
		n /= 10;
	}
	if (n >= 0 && n < 10) arr[n]++;
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) continue;
		result_ = max(result_, arr[i]);
	}
	int temp = arr[6] + arr[9];
	if (temp % 2 == 0) {
		temp /= 2;
	}
	else {
		temp /= 2; temp++;
	}
	result_ = max(result_, temp);
	printf("%d\n", result_);
	return 0;
}