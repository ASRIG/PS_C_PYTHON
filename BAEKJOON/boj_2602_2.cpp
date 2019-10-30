#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int i, j, l, t, N;
char input[25];
char bridge[2][105];
int angel[25][105], devil[25][105];
int answer, cnt, cnt_input;

int main() {
	cin >> input;
	cnt_input = strlen(input);
	cin >> bridge[0]; cin >> bridge[1];
	cnt = strlen(bridge[0]);

	for (i = 1; i <= cnt_input; i++) {
		for (j = i; j <= cnt; j++) {
			// 악마의 다리부터 시작

		}
	}

}