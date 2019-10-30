#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

#define HASHMAX 13
#define a 1
using namespace std;

typedef pair<int, int> pii;
vector<pii> hash_table[HASHMAX];

int main() {
	cout << "�ؽ� ���̺� ����\n" << endl;
	for (int i = 0; i < 6; i++)
	{
		int key, value;

		cout << "key :: ";
		cin >> key;
		cout << "value ::";
		cin >> value;

		int hashKey = (a * key) % HASHMAX;

		// �ؽ� ���̺��� �ش��ϴ� key�� ���� ���� ���
		if (hash_table[hashKey].size() == 0) {
			hash_table[hashKey].push_back({ key, value });
			cout << "key :: " << key << " -> " << hashKey << " value :: " << value << " �Ϸ� " << endl;
		}
		// ��� ���� ���� ��� ���Ḯ��Ʈ�� �̾��ش�.
		else {
			hash_table[hashKey].push_back({ key, value });
			cout << "key :: " << key << " -> " << hashKey << " value :: " << value << " �Ϸ�(�浹�� ��� �Ͼ���ϴ�.) " << endl;
		}
		cout << endl;
	}
	cout << "�ؽ� ���̺��� Ž��\n" << endl;
	for (int i = 0; i < 6; i++)
	{
		int key;
		cout << "key :: ";
		cin >> key;

		int hashKey = key % HASHMAX;
		for (int j = 0; j < hash_table[hashKey].size(); j++)
			if (hash_table[hashKey][j].first == key)
			{
				cout << "value :: " << hash_table[hashKey][j].second << endl;
				break;
			}
	}
	return 0;
}