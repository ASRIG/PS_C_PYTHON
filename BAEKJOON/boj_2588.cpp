#include <iostream>

using namespace std;

int a, b;

int main(void) {
	cin >> a; cin >> b;
	int ret6 = a * b;
	while (b != 0) {
		int tmp = b % 10;
		printf("%d\n", a * tmp);
		b /= 10;
	}printf("%d\n", ret6);
	return 0;
}