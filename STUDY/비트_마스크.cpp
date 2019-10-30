#include <iostream>

using namespace std;

// 2���� ���·� ����ϱ�
void show(int *a) {
	for (int i = 32; i > 0; i--) {
		cout << ((*a & (1 << i - 1)) ? 1 : 0);
	}
}

// ��� ���� �����ϱ�
void init(int *a) {
	*a = 0;
}

// ��� ���Ҹ� �����ϱ�
void full(int *a) {
	*a = -1;
}

// Ư�� ���Ҹ� �����ϱ�
void drop(int *a, int i) {
	*a &= ~(1 << i);
}

// Ư�������� ���Կ��� Ȯ���ϱ�
bool isSet(int *a, int i) {
	return *a & (1 << i);
}

// Ư�� ���Ҹ� ���Խ�Ű��
void set(int *a, int i) {
	*a |= (1 << i);
}

// Ư�� ���Ҹ� ����ϱ�
void toggle(int *a, int i) {
	*a ^= (1 << i);
}

// ������ ���� ���ϱ�
int getLast(int *a) {
	return (*a & -*a);
}

// ������ ���� �����ϱ�
void dropLast(int *a) {
	*a &= (*a - 1);
}

int main(void) {
	int a;

	init(&a);
	cout << "��� ���� ����: "; show(&a);
	cout << endl;

	full(&a);
	cout << "��� ���� ���� : "; show(&a);
	cout << endl;

	drop(&a, 5);
	cout << "5��° �ε��� ���� : "; show(&a);
	cout << '\n';

	set(&a, 5);
	cout << "5��° �ε��� ���� : "; show(&a);
	cout << endl;

	cout << "5��° �ε��� ���� ���� : " << isSet(&a, 5);
	cout << endl;

	toggle(&a, 5);
	cout << "5���� �ε��� ��� : "; show(&a);
	cout << endl;
	cout << "5��° �ε��� ���� ���� : " << isSet(&a, 5);
	cout << endl;

	dropLast(&a);
	dropLast(&a);
	dropLast(&a);
	cout << "������ ���� 3�� ���� : "; show(&a);
	cout << endl;
	cout << "������ ���� ���ϱ� : " << getLast(&a);
	cout << endl;

}