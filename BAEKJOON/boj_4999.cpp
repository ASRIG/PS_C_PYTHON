#include <iostream>

using namespace std;

int _strlen(char chr[]) {
	int ret = 0;
	while (chr[ret++] != 0);
	return ret;
}

int main(void) {
	char a[1000], b[1000];
	cin >> a; cin >> b;
	int len_a = _strlen(a);
	int len_b = _strlen(b);
	if (len_a >= len_b) printf("go\n");
	else printf("no\n");


	return 0;
}