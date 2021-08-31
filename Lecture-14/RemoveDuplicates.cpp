// RemoveDuplicates.cpp
#define node ListNode
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		node* c, *nh = NULL, *nt = NULL;
		c = head;
		while (c) {
			node* t = c;
			int cnt = 0;
			while (t and c->val == t->val) {
				t = t->next;
				cnt++;
			}

			if (cnt == 1) {
				if (nh == NULL) {
					nh = nt = c;
					nt->next = NULL;
					c = t;
				}
				else {
					nt->next = c;
					nt = c;
					nt->next = NULL;
					c = t;
				}
			}
			else {
				c = t;
			}
		}
		return nh;
	}
};