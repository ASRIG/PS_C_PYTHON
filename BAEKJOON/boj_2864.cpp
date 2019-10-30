#include <iostream>
#include <string>

using namespace std;

string a, b;
int aa, bb, answer1, answer2;

int main(void) {
	cin >> a; cin >> b;
	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] == '6') a[i] = '5';
	}
	for (int i = 0; i <(int)b.size(); i++) {
		if (b[i] == '6') b[i] = '5';
	}
	int tmp = 1;
	for (int i = (int)a.size() - 1; i >= 0; i--) {
		aa += (a[i] - '0') * tmp;
		tmp *= 10;
	}

	tmp = 1;
	for (int i = b.size() - 1; i >= 0; i--) {
		bb += (b[i] - '0') * tmp;
		tmp *= 10;
	}

	answer1 = aa + bb;

	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] == '5') a[i] = '6';
	}
	for (int i = 0; i < (int)b.size(); i++) {
		if (b[i] == '5') b[i] = '6';
	}

	tmp = 1; aa = 0; bb = 0;
	for (int i = (int)a.size() - 1; i >= 0; i--) {
		aa += (a[i] - '0') * tmp;
		tmp *= 10;
	}

	tmp = 1;
	for (int i = b.size() - 1; i >= 0; i--) {
		bb += (b[i] - '0') * tmp;
		tmp *= 10;
	}
	answer2 = aa + bb;

	printf("%d %d\n", answer1, answer2);
	return 0;
}