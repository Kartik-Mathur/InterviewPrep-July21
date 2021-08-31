// FlattenMultiLevelList.cpp
class Solution {
public:
	Node* solve(Node* head) {
		Node* c = head;
		Node* BadiKaTail = head;
		while (c) {
			Node* n = c->next;
			Node* child = c->child;
			if (c->child) {
				Node* ChotiKaTail = solve(c->child);
				child->prev = c;
				c->next = child;
				ChotiKaTail->next = n;
				if (n) n->prev = ChotiKaTail;
				c->child = NULL;
				c = ChotiKaTail;
			}
			else {
				c = c->next;
			}
			if (c)
				BadiKaTail = c;
		}
		return BadiKaTail;
	}
	Node* flatten(Node* head) {
		if (head)
			solve(head);
		return head;
	}
};