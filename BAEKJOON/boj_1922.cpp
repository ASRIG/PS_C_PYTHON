#include <iostream>
#include <algorithm>

using namespace std;

struct INPUT {
	int a, b, c;
};

int n, m, k, a, b, c;
int i, j, start_, end_, cnt_;
INPUT input_[100005];
int arr[1005];
long long answer;

bool comp(INPUT &a, INPUT &b) {
	return a.c < b.c;
}

int find(int n) {	// 루트 찾기
	if (arr[n] == n) return n;
	arr[n] = find(arr[n]);
	return arr[n];
}

int merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return 0; // 루트가 같음
	arr[b] = a;
	return 1;
}

int main(void) {
	cin >> n; cin >> m;
	
	for (i = 1; i <= n; i++) arr[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> input_[i].a >> input_[i].b >> input_[i].c;
	}

	sort(input_, input_ + m, comp);

	for (i = 0; i < m; i++) {
		if (merge(input_[i].a, input_[i].b) == 1) {
			answer += input_[i].c;
		}
	}
	printf("%lld\n", answer);
	return 0;
}