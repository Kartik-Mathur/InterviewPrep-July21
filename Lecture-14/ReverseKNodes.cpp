// ReverseKNodes.cpp
#define node ListNode
class Solution {
public:
	node* reverseLL(node* head, int k) {
		node* c = head;
		node* p = NULL;
		node*n;
		while (k) {
			n = c->next;
			c->next = p;
			p = c;
			c = n;
			k--;
		}
		return p;
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		node* cH = head;
		int cnt = 0;
		while (cnt < k and cH != NULL) {
			cH = cH->next;
			cnt++;
		}
		// Base case, when we don't have K nodes to reverse we will stop, calling recursion
		if (cnt == k) {
			node* nH = reverseLL(head, k);
			head->next = reverseKGroup(cH, k);
			return nH;
		}
		return head;
	}
};