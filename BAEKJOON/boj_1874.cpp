#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int n, arr[100005];
char so_[200015];
stack<int> s;

int main(void) {
	cin >> n;
	int chk = 1, temp = 0, ans = 0;
	for (int i = 1; i <= n;i++) {
		cin >> arr[i];
		while (s.empty() || s.top() < arr[i]) {
			s.push(chk++); so_[temp++] = '+';
		}
		if (arr[i] == s.top()) {
			s.pop(); so_[temp++] = '-';
		}
		else {
			ans = 1; break;
		}
	}

	if (ans == 1) printf("NO\n");
	else {
		for (int i = 0; i < temp; i++) {
			printf("%c\n", so_[i]);
		}
	}

	return 0;
}