#include <iostream>

using namespace std;

int a, b, c, d, res_idx, res;

int main(void) {
	for (int i = 0; i < 5; i++) {
		cin >> a >> b >> c >> d;
		if (res < a + b + c + d) res = a + b + c + d, res_idx = i + 1;
	}
	printf("%d %d\n", res_idx, res);
	return 0;
}