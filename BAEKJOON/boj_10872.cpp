#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long answer = 1;
long long a[13];

long long fact(int i) {
	if (a[i] == 0) {
		if (i == 0) return 1;
		if (i == 1) return 1;
		return a[i] = fact(i - 1) * i;
	}
	else {
		return a[i];
	}
}

int main(void) {
	cin >> n;
	answer = fact(n);
	printf("%lld\n", answer);
	return 0;
}