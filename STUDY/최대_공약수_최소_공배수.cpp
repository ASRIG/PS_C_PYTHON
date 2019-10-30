#include <iostream>

using namespace std;

int gcd1(int a, int b) {
	while (1) {
		int r = a % b;	// 나머지가 0이라면 종료
		if (r == 0) return b;
		/*gcd(a, b) = gcd(b, r)*/
		a = b; b = r;
	}
}

int gcd2(int a, int b) {
	if (b == 0) return a;
	else return gcd2(b, a % b);
}

int gcd3(int a, int b) {
	return !b ? a : gcd3(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd3(a, b);
}

int main(void) {
	int a, b;
	cin >> a >> b;
	cout << gcd1(a, b) << "  " << lcm(a, b) << "\n";
	cout << gcd2(a, b) << "  " << lcm(a, b) << "\n";
	cout << gcd3(a, b) << "  " << lcm(a, b) << "\n";


	return 0;
}