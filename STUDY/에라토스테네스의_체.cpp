#include <iostream>
#include <cstdio>

#define MAX 1001
using namespace std;

int arr[1002];

void Eratosthenes(int num) {
	int i;
	for (i = 2; i <= num; i++) {
		if (arr[i] != 0 && arr[i] != -1) {
			break;
		}
		else if (i == num) return;
	}

	arr[i] = 0;
	// 0은 소수 -1은 소수가 아닌 것
	for (int j = i + i; j <= num; j += i) {
		arr[j] = -1;
	}

	Eratosthenes(num);
	return;
}


int main() {
	int n, cnt = 0;
	scanf("%d", &n);

	for (int i = 2; i <= MAX; i++) {
		arr[i] = i;
	}

	Eratosthenes(MAX);

	arr[1] = -1;

	for (int i = 0; i < n; i++) {
		int val;
		scanf("%d", &val);

		arr[val] == 0 ? cnt++ : 0;
	}

	printf("%d", cnt);
	return 0;
}