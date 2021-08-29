// NextGreaterNode.cpp
#define node ListNode
class Solution {
public:
	void solve(node* head, stack<int> &s, vector<int> &ans) {
		if (head == NULL) return;

		// First we need to go till the last node
		solve(head->next, s, ans);
		int curr_val = head->val;
		while (!s.empty() and s.top() <= curr_val) {
			s.pop();
		}

		if (s.empty()) {
			ans.push_back(0);
		}
		else {
			ans.push_back(s.top());
		}
		s.push(curr_val);
	}

	vector<int> nextLargerNodes(ListNode* head) {
		vector<int> ans;
		stack<int> s;
		solve(head, s, ans);
		reverse(ans.begin(), ans.end());
		return ans;
	}
};