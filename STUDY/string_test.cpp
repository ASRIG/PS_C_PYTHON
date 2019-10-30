#include<iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main(void) {
	// 동시에 선언과 초기화
	string str1 = "str1";
	string str2("str2");
	// 멤버함수 사용
	string str4;
	str4.assign("str4");
	// 동적 할당
	string *pstr5 = new string("str5");
	delete pstr5;

	// 크기 관련
	string sentence("Hello this is a sentence");
	int sen_size = sentence.size(), sen_size2 = sentence.length();
	
	// 특정 위치에 있는 글자
	char zero_sen = sentence[0], zero_sen2 = sentence.at(0);
	sentence[1] = 'a'; sentence.at(2) = 'b';
	char start_sen = sentence.front(), end_sen = sentence.back();

	// 문자열 비교
	str1 = "Hello"; str2 = "Hello";
	cout << (str1 == str2) << endl;	// 1
	cout << (str1 != str2) << endl;	// 0
	
	string str3("apple"); str4 = "banana";
	if (str3 < str4) {
		cout << "apple은 a로 시작하니 b인 바나나보다 사전적으로 먼저 위치" << endl;
		cout << "<는 사전적으로 앞에있다를 의미" << endl;
	}

	cout << str1.compare(str2) << endl;
	cout << str3.compare(str4) << endl;
	cout << str4.compare(str3) << endl;
	cout << "-1은 사전적 앞, 0은 사전적 동일, 1은 사전적 뒤" << endl;

	// 글자 추가
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

	// 특정 문자 탐색
	str1 = "find a word 'computer' in this sentence!";
	str2 = "computer";
	cout << str1.find(str2) << endl;
	cout << str1.at(str1.find(str2)) << endl;

	size_t pos;
	str3 = "I love my friends, my friends are sooo nice";
	pos = str3.find("friend");
	// 첫번째 friend
	pos = str3.find("friend", pos + 1);
	// 두번째 friend 찾기


	// 문자열 초기화
	if (!str1.empty()) {
		str1.clear();
	}
	if (str1.empty()) str1 = "new!";
	cout << str1 << endl;


	// 문자열 추출하기
	printf("문자열 추출하기\n");
	str1 = "good morning Mr Brown";
	str2.clear();
	str2 = str1.substr(5, 7);	// morning
	cout << str2 << endl;
	str2 = str1.substr(5);	// morning Mr Brown
	cout << str2 << endl;	
	str2 = str1.substr(str1.find("Mr"));	// Mr Brown
	cout << str2 << endl;

	// 반복자
	string::iterator it;
	for (it = str1.begin(); it < str1.end(); it++)
		cout << *it;
	cout << endl;

	// 특정 문자열 제거하기
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

	
	// 특정 문자열 변경하기
	string str = "hello my name is Ella!";
	str2 = str;
	cout << str << endl;
	str.replace(str.find("my"), 2, "your");
	cout << str << endl;

	str2.replace(str2.begin() + 6, str2.begin() + 8, "her");
	cout << str2 << endl;


	return 0;
}