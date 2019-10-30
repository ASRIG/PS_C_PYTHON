#include <iostream>

using namespace std;

char boj[105];
int cnt[28];

int main(void) {
	cin >> boj;
	for (int i = 0; i < (int)sizeof(boj); i++) {
		cnt[boj[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", cnt[i]);
	}printf("\n");
	return 0;
}