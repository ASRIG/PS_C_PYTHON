#include <stdio.h>

const int number = 15;

// �ϳ��� ��� ������ �����Ѵ�.
typedef struct node *treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
}node;

// ������ȸ �����ϱ�
void preorder(treePointer ptr) {
	if (ptr) {
		printf("%d ", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

// ������ȸ �����ϱ�
void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		printf("%d ", ptr->data);
		inorder(ptr->rightChild);
	}
}

// ������ȸ �����ϱ�
void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%d ", ptr->data);
	}
}

int main(void) {
	int i;
	node nodes[number + 1];
	for (i = 1; i <= number; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	for (i = 1; i <= number; i++) {
		if (i % 2 == 0) {
			nodes[i / 2].leftChild = &nodes[i];
		}
		else {
			nodes[i / 2].rightChild = &nodes[i];
		}
	}

	preorder(&nodes[1]); printf("\n");
	inorder(&nodes[1]); printf("\n");
	postorder(&nodes[1]); printf("\n");
}