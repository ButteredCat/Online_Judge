/**
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 *   After removing the second node from the end, the linked list becomes 1->2->3->5.
 *   Note:
 *
 * Given n will always be valid.
 * Try to do this in one pass.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *node = findNthFromEnd(head, n+1);
        if(node == nullptr) {
            if(findNthFromEnd(head,n) != nullptr)
                return head->next;
            else
                return head;
        } else {
            removeNextNode(node);
            return head;
        }
    }

private:
    inline ListNode *findNthFromEnd(ListNode *head, int n) {
        ListNode *a = head;
        ListNode *b = head;
        do {
            if(a != nullptr)
                a = a->next;
            else
                b = nullptr;
        } while(--n);
        while(a != nullptr) {
            a = a->next;
            b = b->next;
        }
        return b;
    }
    inline void removeNextNode(ListNode *node) {
        if(node != nullptr && node->next != nullptr)
            node->next = node->next->next;
    }
};
