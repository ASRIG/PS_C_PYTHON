#include <iostream>

using namespace std;

int A, B, C, D;

int main(void) {
	cin >> A >> B >> C; cin >> D;
	int hour_plus = D / (60 * 60);
	D %= (60 * 60);
	int min_plus = D / (60);
	D %= (60);
	int sec_plus = D;

	C += D; 
	if (C >= 60) {
		B += 1; C -= 60;
	}
	B += min_plus;
	if (B >= 60) {
		A += 1; B -= 60;
	}

	A += hour_plus;
	while (A >= 24) {
		A -= 24;
		if (A >= 0 && A <= 23) break;
	}

	printf("%d %d %d\n", A, B, C);


	return 0;
}