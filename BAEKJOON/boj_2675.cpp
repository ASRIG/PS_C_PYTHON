#include <iostream>
#include <string>

using namespace std;

string s;
int t, num;

int main(void) {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> num >> s;
		for (int j = 0; j < (int)s.size(); j++) {
			for (int k = 0; k < num; k++) {
				printf("%c", s[j]);
			}
		}
		printf("\n");
	}
	return 0;
}