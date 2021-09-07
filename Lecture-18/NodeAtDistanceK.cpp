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

int printAtDistanceK(node* root, node* target, int k) {
	if (!root) {
		return -1;
	}

	if (root == target) {
		printAtLevelK(root, k);
		return 0;
	}

	int DL = printAtDistanceK(root->left, target, k);
	if (DL != -1) {
		// Left mei target exist karta hai
		if (DL + 1 == k) {
			cout << root->data << " ";
		}
		else {
			printAtLevelK(root->right, k - DL - 2);
		}
		return DL + 1;
	}

	int DR = printAtDistanceK(root->right, target, k);
	if (DR != -1) {
		// Right mei target exist karta hai
		if (DR + 1 == k) {
			cout << root->data << " ";
		}
		else {
			printAtLevelK(root->left, k - DR - 2);
		}
		return DR + 1;
	}

	return -1;
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

int main() {

	node* root = NULL;

	root = makeTree();

	printAtDistanceK(root, root->left, 2);




	return 0;
}
















