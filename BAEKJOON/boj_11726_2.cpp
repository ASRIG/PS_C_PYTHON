#include <iostream>

using namespace std;

int n;

int main(void) {
	cin >> n;
	int a = 1, b = 1, c = 1;
	// ���簢���� ��� ä����Ŀ� ���� ������ ���
	// ������ ����� ���� ���� �Ǻ���ġ�� ����.
	for (int i = 1; i < n; i++) {
		c = (a + b) % 10007;
		a = b; b = c;
	}
	printf("%d\n", c);
	return 0;
}