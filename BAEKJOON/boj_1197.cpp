#include <iostream>
#include <algorithm>

using namespace std;

struct MAP {
	int a, b, c;
};

int V, K, E;
int i, j, t, start, end, cnt;
MAP input[200001]; 
int arr[50001];
long long answer;

bool comp(MAP &aa, MAP &bb) {
	return aa.c < bb.c;
}

int find(int n) {
	if (arr[n] == n) return n;
	arr[n] = find(arr[n]);
	return arr[n];
}

int merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return 0;
	arr[b] = a;
	return 1;
}

int main(void) {
	answer = 0;
	cin >> V >> E;
	int ta, tb, tc;
	for (i = 0; i < E; i++) {
		cin >> ta >> tb >> tc;
		input[i].a = ta; input[i].b = tb; input[i].c = tc;
	}
	for (i = 1; i <= V; i++) arr[i] = i;

	sort(input, input + E, comp);

	for (i = 0; i < E; i++) {
		if (merge(input[i].a, input[i].b) == 1) {
			answer += input[i].c;
		}
	}
	printf("%lld\n", answer);
	return 0;
}