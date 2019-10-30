#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int t;

int main(void) {
	scanf("%d", &t);
	while (getchar() != '\n');
	//getchar();
	for (int tes = 1; tes <= t; tes++) {
		string str;
		int answer_cnt = 0;
		char answer_tmp[25];
	
		getline(cin, str);

		if (str.size() != 0) answer_tmp[answer_cnt++] = str[0] - 32;
		for (int i = 0; i < (int)str.size(); i++) {
			if (str[i] == ' ') {
				answer_tmp[answer_cnt++] = str[i + 1] - 32;
			}
		}
		answer_tmp[answer_cnt] = 0;
		string answer = answer_tmp;
		cout << "#" << tes << " " << answer << "\n";
	}
	return 0;
}