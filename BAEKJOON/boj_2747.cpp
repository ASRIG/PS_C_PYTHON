#include <iostream>

using namespace std;

long long arr[100];

long long fibo(int n) {
	if (arr[n] != -1) {
		return arr[n];
	}
	else {
		arr[n] = fibo(n - 1) + fibo(n - 2);
		return arr[n];
	}
}

int main(void) {
	for (int i = 0; i < 100; i++) {
		arr[i] = -1;
	}
	int num;
	arr[0] = 0; arr[1] = 1;
	cin >> num;
	fibo(num);
	printf("%lld\n", arr[num]);
	return 0;
}