#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;
int arr[26];

int main(void) {
	cin >> s;
	for (int i = 0; i < 26; i++) arr[i] = -1;
	for (int i = 0; i < s.size(); i++) {
		int tmp = s[i] - 'a';
		if (arr[tmp] == -1)arr[tmp] = i;
	}
	for (int i = 0; i < 26; i++) printf("%d ", arr[i]);
	printf("\n");
	return 0;
}