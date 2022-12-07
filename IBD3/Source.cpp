#include<iostream>
using namespace std;
typedef struct node* ptr;
int i = 0;
struct node {
	int Data;
	ptr left;
	ptr right;
};
ptr IBD(int n) {
	if (n > 0) {
		int NLeft = n / 2, NRight = n - NLeft - 1;
		ptr durj = new node;
		durj->Data = ++i;
		durj->left = IBD(NLeft);
		durj->right = IBD(NRight);
		return durj;
	}
	else {
		return NULL;
	}
}
void infix(ptr help) {
	if (help) {
		infix(help->left);
		cout << help->Data << " ";
		infix(help->right);
	}
}
void prefix(ptr help) {
	if (help) {
		cout << help->Data << " ";
		infix(help->left);
		infix(help->right);
	}
}
void postfix(ptr help) {
	if (help) {
		infix(help->left);
		infix(help->right);
		cout << help->Data << " ";
	}
}
int main() {
	int x = 34; ptr root;
	root = IBD(x);
	cout << endl;
	cout << "infix: " << endl;
	infix(root);
	cout << endl;
	cout << "prefix:" << endl;
	prefix(root);
	cout << endl;
	cout << "postfix:" << endl;
	postfix(root);
	return 0;
}