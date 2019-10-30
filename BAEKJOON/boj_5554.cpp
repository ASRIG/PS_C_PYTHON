#include <iostream>
#include <algorithm>

using namespace std;

int x, y, tmp;

int main(void) {
	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		y += tmp;
	}
	
	x = y / 60;
	y %= 60;

	printf("%d\n", x);
	printf("%d\n", y);

	return 0;
}