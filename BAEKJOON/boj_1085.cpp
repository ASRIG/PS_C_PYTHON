#include <iostream>
#define comp(a, b, result) b - a > result ? result : b - a

using namespace std;

int x, y, w, h, res = 999999;

int main(void) {
	cin >> x >> y >> w >> h;
	res = comp(0, x, res); res = comp(x, w, res);
	res = comp(0, y, res); res = comp(y, h, res);
	printf("%d\n", res);
	return 0;
}