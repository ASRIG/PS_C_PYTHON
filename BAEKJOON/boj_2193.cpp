#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

long ar0[95], ar1[95];
int n, answer = 0;

int main(void) {
	cin >> n;
	ar0[1] = 0; ar1[1] = 1;
	for (int i = 2; i <= n; i++) {
		ar0[i] = ar1[i - 1] + ar0[i - 1];
		ar1[i] = ar0[i - 1];
	}
	printf("%ld\n", ar0[n] + ar1[n]);
	return 0;
}