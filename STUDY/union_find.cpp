#include <iostream>

// �θ� ��带 ã�� �Լ�
int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

// �� �θ� ��带 ��ġ�� �Լ�
void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a); b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

// ���� �θ� �������� Ȯ�� 
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

	printf("1���� 5���� ������ �Ǿ��ֳ���?? : %d\n", findParent(par, 1, 5));
	printf("1���� 4���� ������ �Ǿ��ֳ���?? : %d\n", findParent(par, 1, 4));
}