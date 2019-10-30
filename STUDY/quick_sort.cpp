#include <iostream>
#include <algorithm>

using namespace std;

int number = 10;
int data_[] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

void show() {
	int i;
	for (i = 0; i < number; i++) {
		printf("%d ", data_[i]);
	}
	printf("\n");
}

void quickSort(int *data, int start, int end) {
	if (start >= end) {
		// ���Ұ� 1���� ��� �״�� �α�
		return;
	}

	int key = start; // Ű�� ù ��° ����
	int i = start + 1, j = end, temp;

	while (i <= j) {
		// ������ ������ �ݺ�
		while (i <= end && data[i] <= data[key]) i++;
		// ���ʺ��� Ű������ ū ��ã��
		while (j > start && data[j] >= data[key]) j--;
		// �����ʺ��� Ű������ ���� ��ã��

		if (i > j) {	//���� ������ ���¸� Ű ��ü
			temp = data[j]; data[j] = data[key];
			data[key] = temp;
		}
		else {			// �������� �ʾҴٸ� i�� j�� ��ü
			temp = data[i]; data[i] = data[j];
			data[j] = temp;
		}
	}
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main(void) {
	quickSort(data_, 0, number - 1);
	show();
	return 0;
}