#include <iostream>
#include <algorithm>
#define MAXN 1000001
using namespace std;

int t, T, i, j, temp;
int l_i, r_i, P[MAXN];

int main(void) {
	cin >> l_i >> r_i;

	// ��ó��
	for (i = 1; i < r_i; i++) {
		P[i] = i;
	}

	for (i = 2; i < r_i; i++) {
		if (P[i] == i) {	// �Ҽ��� �����ڴ�
			for (j = i; j < r_i; j += i) {
				P[j] = P[j] - (P[j] / i);	
				// �Ҽ��� ������ �������� �ֵ��� ����.
			}
		}
	}
	
	for (i = l_i; i <= r_i; i++) {
		if (P[i] == i - 1) printf("%d\n", P[i] + 1);
	}
}