#include<iostream>

using namespace std;

int a[31], tmp;

int main(void) {
	for (int i = 0; i < 28; i++) cin >> tmp, a[tmp]++;
	for (int i = 1; i <= 30; i++) {
		if (a[i] == 0) printf("%d\n", i);
	}
	return 0;
}