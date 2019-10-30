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
	cout << "해시 테이블에 삽입\n" << endl;
	for (int i = 0; i < 6; i++)
	{
		int key, value;

		cout << "key :: ";
		cin >> key;
		cout << "value ::";
		cin >> value;

		int hashKey = (a * key) % HASHMAX;

		// 해시 테이블의 해당하는 key에 값이 없을 경우
		if (hash_table[hashKey].size() == 0) {
			hash_table[hashKey].push_back({ key, value });
			cout << "key :: " << key << " -> " << hashKey << " value :: " << value << " 완료 " << endl;
		}
		// 어떠한 값이 있을 경우 연결리스트로 이어준다.
		else {
			hash_table[hashKey].push_back({ key, value });
			cout << "key :: " << key << " -> " << hashKey << " value :: " << value << " 완료(충돌이 잠시 일어났습니다.) " << endl;
		}
		cout << endl;
	}
	cout << "해시 테이블에서 탐색\n" << endl;
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