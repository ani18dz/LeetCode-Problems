/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* r = l1;
        bool carry = false;

        while (p != nullptr || q != nullptr || carry) {
            if (carry && p == nullptr && q == nullptr) {
                r->next = new ListNode(1);
                carry = false;
                return l1;
            }

            if (p == nullptr) {
                p = q;
                while (carry) {
                    if (++q->val == 10) {
                        q->val = 0;
                        q = q->next;
                        if (q == nullptr) {
                            p->next = new ListNode(1);
                            carry = false;
                        } else
                            p = p->next;
                    } else {
                        carry = false;
                        return l2;
                    }
                }
                return l2;
            }

            else if (q == nullptr) {
                q = p;
                while (carry) {
                    if (++p->val == 10) {
                        p->val = 0;
                        p = p->next;
                        if (p == nullptr) {
                            q->next = new ListNode(1);
                            carry = false;
                        } else
                            q = q->next;
                    } else {
                        carry = false;
                        return l1;
                    }
                }
                return l1;
            }

            else {
            }

            p->val += q->val;

            carry ? p->val++ : (int)0;

            if (p->val > 9) {
                carry = true;
                p->val %= 10;
            } else {
                carry = false;
            }
            q->val = p->val;

            p = p->next;
            q = q->next;
            if (r->next != nullptr)
                r = r->next;
        }

        return l1;
    }
};