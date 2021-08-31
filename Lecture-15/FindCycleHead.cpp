// FindCycleHead.cpp
#define node ListNode
class Solution {
public:
	ListNode* hasCycle(ListNode *head) {
		node* s = head, *f = head;

		while (f and f->next) {
			f = f->next->next;
			s = s->next;

			if (f == s) return f;
		}
		return NULL;
	}
	ListNode *detectCycle(ListNode *head) {
		ListNode* ans = hasCycle(head);
		if (ans == NULL) return NULL;

		ListNode* f = ans;
		ListNode* s = head;

		while (f != s) {
			f = f->next;
			s = s->next;
		}
		return f;

	}
};






