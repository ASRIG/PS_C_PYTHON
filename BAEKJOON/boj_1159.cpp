#include <iostream>

using namespace std;

int cnt[30], N;
char name_[40];

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name_;
		cnt[name_[0] - 'a']++;
	}

	int cntt = 0;
	for (int i = 0; i < 28; i++) {
		if (cnt[i] >= 5) printf("%c", (char)i + 'a'), cntt++;
	}
	if (cntt == 0) {
		printf("PREDAJA");
	}
	printf("\n");
	return 0;
}