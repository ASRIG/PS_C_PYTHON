#include <iostream>

using namespace std;

int l, a, b, c, d;

int main(void) {
	cin >> l >> a >> b >> c >> d;
	int tmp1 = a / c, tmp2 = b / d;
	if (a % c != 0) tmp1++; if (b %d != 0) tmp2++;
	if (tmp1 > tmp2) l -= tmp1;
	else l -= tmp2;
	printf("%d\n", l);
	return 0;
}