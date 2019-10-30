#include <iostream>

using namespace std;

int n;
long s;

int main(void) {
	cin >> s;
	for (long i = 1; i <= s; i++) {
		long tmp = s - i; n++;
		if (tmp <= 0) break;
		s = tmp;
	}
	printf("%d\n", n);
	return 0;
}