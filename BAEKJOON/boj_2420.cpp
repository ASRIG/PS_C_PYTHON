#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long n, m;
long long ans;

long long abs_(long long a) {
	long long ret = a;
	if (ret < 0) ret *= -1;
	return ret;
}

int main(void) {
	cin >> n >> m;
	ans = abs_(n - m);
	printf("%lld\n", ans);
	return 0;
}