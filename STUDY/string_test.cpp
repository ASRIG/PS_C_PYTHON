#include<iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main(void) {
	// ���ÿ� ����� �ʱ�ȭ
	string str1 = "str1";
	string str2("str2");
	// ����Լ� ���
	string str4;
	str4.assign("str4");
	// ���� �Ҵ�
	string *pstr5 = new string("str5");
	delete pstr5;

	// ũ�� ����
	string sentence("Hello this is a sentence");
	int sen_size = sentence.size(), sen_size2 = sentence.length();
	
	// Ư�� ��ġ�� �ִ� ����
	char zero_sen = sentence[0], zero_sen2 = sentence.at(0);
	sentence[1] = 'a'; sentence.at(2) = 'b';
	char start_sen = sentence.front(), end_sen = sentence.back();

	// ���ڿ� ��
	str1 = "Hello"; str2 = "Hello";
	cout << (str1 == str2) << endl;	// 1
	cout << (str1 != str2) << endl;	// 0
	
	string str3("apple"); str4 = "banana";
	if (str3 < str4) {
		cout << "apple�� a�� �����ϴ� b�� �ٳ������� ���������� ���� ��ġ" << endl;
		cout << "<�� ���������� �տ��ִٸ� �ǹ�" << endl;
	}

	cout << str1.compare(str2) << endl;
	cout << str3.compare(str4) << endl;
	cout << str4.compare(str3) << endl;
	cout << "-1�� ������ ��, 0�� ������ ����, 1�� ������ ��" << endl;

	// ���� �߰�
	str1 = "Hello"; str2 = "friend"; str3 = str1 + " " + str2;
	str3 += "! ";
	str4 = "nice to meet you";
	cout << str3 << endl;
	str3.append(str4, 0, 4);
	cout << str3 << endl;
	str3.append(" to meet you");
	cout << str3 << endl;
	str3.append(5, '!');
	cout << str3 << endl;

	// Ư�� ���� Ž��
	str1 = "find a word 'computer' in this sentence!";
	str2 = "computer";
	cout << str1.find(str2) << endl;
	cout << str1.at(str1.find(str2)) << endl;

	size_t pos;
	str3 = "I love my friends, my friends are sooo nice";
	pos = str3.find("friend");
	// ù��° friend
	pos = str3.find("friend", pos + 1);
	// �ι�° friend ã��


	// ���ڿ� �ʱ�ȭ
	if (!str1.empty()) {
		str1.clear();
	}
	if (str1.empty()) str1 = "new!";
	cout << str1 << endl;


	// ���ڿ� �����ϱ�
	printf("���ڿ� �����ϱ�\n");
	str1 = "good morning Mr Brown";
	str2.clear();
	str2 = str1.substr(5, 7);	// morning
	cout << str2 << endl;
	str2 = str1.substr(5);	// morning Mr Brown
	cout << str2 << endl;	
	str2 = str1.substr(str1.find("Mr"));	// Mr Brown
	cout << str2 << endl;

	// �ݺ���
	string::iterator it;
	for (it = str1.begin(); it < str1.end(); it++)
		cout << *it;
	cout << endl;

	// Ư�� ���ڿ� �����ϱ�
	str1.erase(); str2.erase(); str3.erase();
	str1.assign("12345678");
	str1.erase(0, 4); // 5678
	str1.erase();

	str2.assign("abcdefgh"); str2.erase(4, 3); // abcde
	string sub_str2 = "abcde";
	str2.erase(2); // ab
	cout << str2 << endl;
	sub_str2.erase(sub_str2.begin()); // bcde
	cout << sub_str2 << endl;
	sub_str2 = "abcde";
	sub_str2.erase(sub_str2.begin() + 2); // abde
	cout << sub_str2 << endl;
	sub_str2 = "abcde";
	sub_str2.erase(sub_str2.begin(), sub_str2.begin() + 3); // abde
	cout << sub_str2 << endl;

	str3.assign("1a2b3c4d5e");
	str3.erase(str3.begin() + 1); // 12bb3c4d5e

	
	// Ư�� ���ڿ� �����ϱ�
	string str = "hello my name is Ella!";
	str2 = str;
	cout << str << endl;
	str.replace(str.find("my"), 2, "your");
	cout << str << endl;

	str2.replace(str2.begin() + 6, str2.begin() + 8, "her");
	cout << str2 << endl;


	return 0;
}