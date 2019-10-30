#include <iostream>
#include <algorithm>

using namespace std;

int num, tmp;

int main(void) {
	cin >> num;
	for (int i = 0; i < 9; i++) {
		cin >> tmp;  num -= tmp;
	}
	printf("%d\n", num);
	return 0;
}