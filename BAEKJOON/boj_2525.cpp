#include <iostream>

using namespace std;

int A, B, C;

int main(void) {
	cin >> A >> B; cin >> C;

	int hour_plus = C / (60);
	C %= (60);
	
	B += C;
	if (B >= 60) {
		B -= 60; A += 1;
	}
	A += hour_plus;
	while (A >= 24) {
		A -= 24;
		if (A >= 0 && A <= 23) break;
	}

	printf("%d %d\n", A, B);
	return 0;
}