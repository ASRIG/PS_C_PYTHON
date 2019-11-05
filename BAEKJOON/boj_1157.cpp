#include <iostream>
#include <string>

using namespace std;

string str;
int len[30];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	cin >> str;
	for (int i = 0; i < (int)str.length(); i++) {
		if (str[i] >= 'a') str[i] -= 32;
		len[str[i] - 'A']++;
	}
	
	int max_num = 0, max_idx = 0, cnt = 0;
	for (int i = 0; i < 28; i++) {
		if (max_num < len[i]) max_num = len[i], max_idx = i;
	}

	for (int i = 0; i < 28; i++) {
		if (max_num == len[i]) cnt++;
	}
	if (cnt == 1) printf("%c\n", max_idx + 'A');
	else printf("?\n");
	return 0;
}