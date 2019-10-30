#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int a, b, c, ret;
	cin >> a >> b >> c;
	if (a == b && b == c && c == a) {
		ret = 10000 + (a * 1000);
	}
	else if (a != b && b != c && c != a) {
		ret = max({ a, b, c }) * 100;
	}
	else {
		if (a == b || a == c) ret = 1000 + (a * 100);
		else if (b == c) ret = 1000 + (b * 100);
	}

	printf("%d\n", ret);
	return 0;
}