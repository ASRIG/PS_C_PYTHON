#include <iostream>
#include <algorithm>
#define max(x,y) ((x) > (y) ? (x) : (y))

using namespace std;

int n, answer = 0;
int a, dp;

int main(void) {
	cin >> n;
	cin >> a;
	dp = a; answer = a;
	for (int i = 2; i <= n;i++) {
		cin >> a;
		dp = max(dp + a, a);
		answer = max(answer, dp);
	}

	printf("%d\n", answer);
	return 0;
}