#include <iostream>

using namespace std;

int pow(int a, int b) {
	int ret = 1;
	for (int i = 1; i <= b; i++) {
		ret *= a;
	}
	return ret;
}

int arr[6];

int main(void) {
	int answer = 0;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		answer += pow(arr[i], 2);
	}

	printf("%d\n", answer % 10);
	return 0;
}