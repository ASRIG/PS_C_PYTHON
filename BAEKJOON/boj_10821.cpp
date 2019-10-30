#include <iostream>
#include <string>

using namespace std;

string sen;

int main(void) {
	cin >> sen;
	int answer = 1;
	for (int i = 0; i < (int)sen.size(); i++) {
		if (sen[i] == ',') answer++;
	}

	printf("%d\n", answer);

	return 0;
}