#define node ListNode
class Solution {
public:
	node* merge(node* a, node* b) {
		// base case
		if (!a) return b;
		if (!b) return a;

		// recursive
		node* nh;
		if (a->val < b->val) {
			nh = a;
			nh->next = merge(a->next, b);
		}
		else {
			nh = b;
			nh->next = merge(a, b->next);
		}
		return nh;
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) {
			return NULL;
		}
		int n = lists.size() - 1;

		while (n != 0) {
			int s = 0, e = n;
			while (s < e) {
				lists[s] = merge(lists[s], lists[e]);
				s++;
				e--;
			}
			n = e;
		}
		return lists[0];
	}
};



















