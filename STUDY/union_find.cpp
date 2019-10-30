#include <iostream>

// 부모 노드를 찾는 함수
int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a); b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

// 같은 부모를 가지는지 확인 
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a); b = getParent(parent, b);
	if (a == b) return 1;
	return 0;
}

int main(void) {
	int par[11];
	for (int i = 1; i <= 10; i++) {
		par[i] = i;
	}
	unionParent(par, 1, 2);
	unionParent(par, 2, 3);
	unionParent(par, 3, 4);
	unionParent(par, 5, 6);
	unionParent(par, 6, 7);
	unionParent(par, 7, 8);

	printf("1번과 5번이 연결이 되어있나요?? : %d\n", findParent(par, 1, 5));
	printf("1번과 4번이 연결이 되어있나요?? : %d\n", findParent(par, 1, 4));
}