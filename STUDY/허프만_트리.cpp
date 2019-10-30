#include <iostream>
using namespace std;

typedef struct HuffmanTree {
public:
	HuffmanTree * left, *right;
	char ch;

	HuffmanTree() {
		left = right = NULL;
		ch = '\0';
	}
};

int _strlen(char *str) {
	int len = 0;
	while (str[++len]);
	return len;
}

int main(void) {
	char str[52]; cin >> str;
	int n; cin >> n;

	HuffmanTree *root = new HuffmanTree();
	
	for (int i = 0; i < n; i++) {
		char tmp[52]; cin >> tmp;
		int len = _strlen(tmp);
		HuffmanTree *cur = root;
		for (int j = 0; j < len; j++) {
			if (tmp[j] == '0') {
				if (cur->left == nullptr)
					cur->left = new HuffmanTree();
				
				cur = cur->left;
			}
			else if (tmp[j] == '1') {
				printf("i : %d , j : %d\n", i, j);
				if (cur->right == nullptr) cur->right = new HuffmanTree();

				cur = cur->right;
			}
		}
		cur->ch = 'A' + i;
	}

	int len = _strlen(str);
	HuffmanTree *cur = root;
	for (int i = 0; i < len; i++) {
		if (str[i] == '0') {
			cur = cur->left;
			if (cur->left == nullptr) {
				printf("%c", cur->ch);
				cur = root;
			}
		}
		else if (str[i] == '1') {
			cur = cur->right;
			if (cur->right == nullptr) {
				printf("%c", cur->ch);
				cur = root;
			}
		}
	}
	return 0;
}