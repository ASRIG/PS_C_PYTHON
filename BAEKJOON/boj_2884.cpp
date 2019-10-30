#include <iostream>
#include <algorithm>

using namespace std;

int h, m, rh, rm;

int main(void) {
	cin >> h >> m;
	rm = m - 45;
	if (rm < 0) {
		rm += 60; h--;
	}
	if (h < 0) h += 24;
	printf("%d %d\n", h, rm);
	return 0;
}