#include <iostream>
#include <cstdio>
#include <string>

#define HASHMAX 13
#define a 1
using namespace std;

int hash_table[HASHMAX];

int main()
{
	while (1)
	{
		int key, value;

		cout << "key :: ";
		cin >> key;
		cout << "value ::";
		cin >> value;

		int hashKey = (a * key) % HASHMAX;

		if (!hash_table[hashKey])
		{
			hash_table[hashKey] = value;
			cout << "key :: " << key << " -> " << hashKey << " value :: " << value << " 완료 " << endl;
		}
		else
		{
			cout << "이미 hash_table에 입력한 key가 존재합니다." << endl;
			cout << "이미 존재하는 key :: " << hashKey << " value :: " << value << endl;
			break;
		}
		cout << endl;
	}

	return 0;
}