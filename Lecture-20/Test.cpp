// NodeAtDistanceK.cpp
#include <iostream>
using namespace std;
// 8 10 1 -1 -1 6 7 -1 -1 -1 3 4 -1 -1 14 13 -1 -1 -1
class node {
public:
	int data;
	node* left, *right;
	node(int d): data(d), left(NULL), right(NULL) {}
};

void printAtLevelK(node* root, int k) {
	if (!root) return;

	if (k == 0) {
		cout << root->data << " ";
		return;
	}

	printAtLevelK(root->left, k - 1);
	printAtLevelK(root->right, k - 1);

}

node* makeTree() {
	int data;
	cin >> data;

	if (data == -1) {
		return NULL;
	}
	node* root = new node(data);
	root->left = makeTree();
	root->right = makeTree();

	return root;
}

void morrisInorder(node* root) { // O(1) space and O(n) time
	while (root) {
		if (root->left == NULL) {
			cout << root->data << " ";
			root = root->right;
		}
		else {
			node* pre = root->left;
			while (pre->right and pre->right != root) {
				pre = pre->right;
			}

			if (pre->right == NULL) {
				pre->right = root;
				root = root->left;
			}
			else {
				pre->right = NULL;
				cout << root->data << " ";
				root = root->right;
			}
		}
	}

	cout << endl;
}

void morrisPreOrder(node* root) { // O(1) space and O(n) time
	while (root) {
		if (root->left == NULL) {
			cout << root->data << " ";
			root = root->right;
		}
		else {
			node* pre = root->left;
			while (pre->right and pre->right != root) {
				pre = pre->right;
			}
			if (pre->right == NULL) {
				cout << root->data << " ";
				pre->right = root;
				root = root->left;
			}
			else {
				pre->right = NULL;
				root = root->right;
			}
		}
	}
	cout << endl;
}

void inorder(node * root) {
	if (!root) return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(node* root) {
	if (!root) return;

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

int main() {

	node* root = NULL;

	root = makeTree();

	inorder(root);
	cout << endl;
	morrisInorder(root); // O(N)

	morrisPreOrder(root);
	preorder(root);
	cout << endl;





	return 0;
}
















