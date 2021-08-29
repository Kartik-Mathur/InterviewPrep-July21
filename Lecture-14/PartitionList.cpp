// PartitionList.cpp
#define node ListNode
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		node* h = head, *n;
		node* ah, *at, *bh, *bt;
		ah = at = bt = bh = NULL;

		while (h) {
			n = h->next;
			if (h->val < x) {
				// h wali node ko a mei add krna
				if (ah == NULL) {
					ah = at = h;
					h->next = NULL;
				}
				else {
					at->next = h;
					at = at->next;
					h->next = NULL;
				}
			}
			else {
				// h wali node ko b mei add krna
				if (bh == NULL) {
					bh = bt = h;
					h->next = NULL;
				}
				else {
					bt->next = h;
					bt = bt->next;
					h->next = NULL;
				}
			}

			h = n;
		}

		if (ah) {
			at->next = bh;
			return ah;
		}
		return bh; // If bh == NULL, or bh is some valid node

	}
};