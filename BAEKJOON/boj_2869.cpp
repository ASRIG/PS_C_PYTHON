#include <iostream>

using namespace std;

long V, A, B, cur, day_ = 0;

int main(void) {
	cin >> A >> B >> V;
	day_ = (V - B - 1) / (A - B);
	printf("%ld\n", day_ + 1);
	return 0;
}