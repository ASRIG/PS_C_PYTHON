#include <iostream>
#include <algorithm>

using namespace std;

int a, b, cnt = 0;

int main(void) {
	cin >> a;
	for (int i = 0; i < 5; i++) {
		cin >> b;
		if (a == b) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}