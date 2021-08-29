#define node ListNode
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        node* n = new node(0);
        n->next = head;
        head = n;

        node* t = head;
        node* n9;

        while (t) {
            if (t->val != 9)
                n9 = t;
            t = t -> next;
        }

        n9->val++;
        n9 = n9->next;
        while (n9 != NULL) {
            n9->val = 0;
            n9 = n9->next;
        }

        if (head->val == 0) return head->next;
        return head;
    }
};