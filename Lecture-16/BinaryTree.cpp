#include <iostream>
#include <map>
#include <vector>
using namespace std;
// 8 10 1 -1 -1 6 7 -1 -1 -1 3 4 -1 -1 14 13 -1 -1 -1

class node {
public:
	int data;
	node* left;
	node* right;
	node(int d): data(d), left(NULL), right(NULL) {}
};

node* createBT() {
	node* root = NULL;
	int data;
	cin >> data;

	if (data == -1) {
		return NULL;
	}
	root = new node(data);
	root->left = createBT();
	root->right = createBT();
	return root;
}

void rightView(node* root, int level, int &mx_level) {
	// base case
	if (!root) return;

	// recursive case
	if (level > mx_level) {
		cout << root->data << " ";
		mx_level = level;
	}

	rightView(root->right, level + 1, mx_level);
	rightView(root->left, level + 1, mx_level);

}

void leftView(node* root, int level, int &mx_level) {
	// base case
	if (!root) return;

	// recursive case
	if (level > mx_level) {
		cout << root->data << " ";
		mx_level = level;
	}

	leftView(root->left, level + 1, mx_level);
	leftView(root->right, level + 1, mx_level);
}

void topViewHelper(node* root, int level, int d, map<int, pair<int, int> > &h) {
	// base case
	if (!root) return;

	// recursive case
	// h.count(d) == 0, agar d distance map mei nhi hai toh store krna padega
	// level < h[d].second, agar jo current level hai that is smaller than map mei jo d distance par node hai uske
	// level se
	if (h.count(d) == 0 || level < h[d].second) {
		h[d] = {root->data, level};
	}
	topViewHelper(root->left, level + 1, d - 1, h);
	topViewHelper(root->right, level + 1, d + 1, h);
}

void topView(node* root) {
	map<int, pair<int, int> > h;
	topViewHelper(root, 0, 0, h);
	for (auto node : h) {
		cout << node.second.first << " ";
	}
	cout << endl;
}

void bottomViewHelper(node* root, int level, int d, map<int, pair<int, int> > &h) {
	// base case
	if (!root) return;

	// recursive case
	// h.count(d) == 0, agar d distance map mei nhi hai toh store krna padega
	// level < h[d].second, agar jo current level hai that is smaller than map mei jo d distance par node hai uske
	// level se
	if (h.count(d) == 0 || level >= h[d].second) {
		h[d] = {root->data, level};
	}
	bottomViewHelper(root->left, level + 1, d - 1, h);
	bottomViewHelper(root->right, level + 1, d + 1, h);
}

void bottomView(node* root) {
	map<int, pair<int, int> > h;
	bottomViewHelper(root, 0, 0, h);
	for (auto node : h) {
		cout << node.second.first << " ";
	}
	cout << endl;
}

void DiagonalPrint(node* root, int d, map<int, vector<int> > &h) {
	// base case
	if (!root) return;

	// recursive case
	h[d].push_back(root->data);
	// cout<<root->data<<" ";
	DiagonalPrint(root->left, d + 1, h);
	DiagonalPrint(root->right, d, h);
}

int main() {

	node* root = createBT();
	int mx_level = -1;
	rightView(root, 0, mx_level);
	cout << endl;
	mx_level = -1;
	leftView(root, 0, mx_level);
	cout << endl;

	topView(root);
	bottomView(root);

	map<int, vector<int> > h;
	DiagonalPrint(root, 0, h);
	for (auto node : h) {
		for (auto data : node.second) {
			cout << data << " ";
		}
		cout << endl;
	}




	return 0;
}
















