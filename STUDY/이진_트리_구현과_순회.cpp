#include <iostream>

using namespace std;

const int number = 15;

typedef struct node *treePointer;

struct node {
	int data;
	node *leftChild, *rightChild;
};

// 전위 순회
void preorder(node* ptr) {
	if (ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

// 중위 순회
void inorder(node *ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

// 후위 순회
void postorder(node *ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main(void) {
	node nodes[number + 1];
	for (int i = 1; i <= number; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL; nodes[i].rightChild = NULL;
	}

	for (int i = 1; i <= number; i++) {
		if (i % 2 == 0)
			nodes[i / 2].leftChild = &nodes[i];
		else
			nodes[i / 2].rightChild = &nodes[i];
	}
	printf("\n\n");
	preorder(&nodes[1]);
	printf("\n\n");
	inorder(&nodes[1]);
	printf("\n\n");
	postorder(&nodes[1]);
	printf("\n\n");
	return 0;
}