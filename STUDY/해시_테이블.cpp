#include <iostream>
#include <cstdio>
#include <string>

#define HASHMAX 10000
using namespace std;

int hash_table[HASHMAX];

int _strlen(char *input) {
	int i = 0;
	while (input[i] != 0) i++;
	return i;
}

int split(char *str) {
	int ret = 0;
	int len = _strlen(str);
	for (int i = 0; i < len; i++) {
		ret += str[i] - '0';
	}
	return ret;
}

int main() {
	while (1) {
		char key[10];
		int value;

		cout << "key :: ";
		cin >> key;
		cout << "value ::";
		cin >> value;

		int hashKey = split(key);
		if (!hash_table[hashKey]) {
			hash_table[hashKey] = value;
			cout << "key :: " << key << " -> " << hashKey << " value :: " << value << " 완료 " << endl;
		}
		else {
			cout << "이미 hash_table에 입력한 key가 존재합니다." << endl;
			cout << "이미 존재하는 key :: " << hashKey << " value :: " << value << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}