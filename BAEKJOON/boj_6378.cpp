#include <iostream>
#include <string>

using namespace std;
char str[1005];

int ans(char test[]) {
	int sum = 0, cnt = 0;
	while (test[cnt] != '\0') {
		sum += test[cnt++] - '0';
	}
	if (sum >= 10) {
		sprintf(test, "%d", sum);
		sum = ans(test);
	}
	return sum;
}

int main(void) {
	cin >> str;
	while (str[0] != '0') {
		printf("%d\n", ans(str));
		cin >> str;
	}
	

	return 0;
}