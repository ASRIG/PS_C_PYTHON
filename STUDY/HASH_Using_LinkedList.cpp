#include <iostream>
#include <algorithm>

using namespace std;

typedef struct node {
	int num;
	char str[20];
	node *next, *prev;
	node(char*s, int num) :num(num) {
		next = prev = NULL;
		int i = 0;
		for (i = 0; s[i]; i++)str[i] = s[i];
		s[i] = 0;
	}
};

typedef struct list {
	node *begin, *end;
	list() {
		begin = end = NULL;
	}
};

#define mod 11
typedef struct myhash {
	list A[mod];

	int gethash(int num) {
		int v = 0, k = 1;
		while (num) {
			v = (v + (num % 10) * k) % mod;
			k = (k * 17) % mod; num /= 10;
		}
		return v % mod;
	}

	int mycmp(char *a, char *b) {
		for (int i = 0; a[i] || b[i]; i++) if (a[i] != b[i]) return 0;
		return 1;
	}

	void insert(char *str, int num) {
		node *newnode = new node(str, num);
		int v = gethash(num);
		node *i = A[v].begin;
		if (i == NULL) {
			A[v].begin = A[v].end = newnode;
		}
		else {
			while (i != NULL) {
				if (mycmp(i->str, str)) {
					delete newnode; return;
				}
				i = i->next;
			}
			newnode->prev = A[v].end;
			A[v].end->next = newnode;
			A[v].end = newnode;
		}
	}
	int ret(char *str, int num) {
		int v = gethash(num);
		node *i = A[v].begin;
		while (i != NULL) {
			if (mycmp(i->str, str)) {
				return i->num;
			}
			i = i->next;
		}
		return 0;
	}
	void del(char *str, int num) {
		int v = gethash(num);
		node *i = A[v].begin;
		while (i != NULL) {
			if (mycmp(i->str, str)) {
				if (i == A[v].begin) {
					if (A[v].begin->next == NULL) A[v].begin = A[v].end = NULL;
					else {
						A[v].begin->next->prev = NULL;
						A[v].begin = A[v].begin->next;
					}
				}
				else if (i->next == NULL) {
					A[v].end = i->prev;
					A[v].end->next = NULL;
				}
				else {
					i->prev->next = i->next;
					i->next->prev = i->prev;
				}
				delete i;
				return;
			}
			i = i->next;
		}
		return;
	}
};