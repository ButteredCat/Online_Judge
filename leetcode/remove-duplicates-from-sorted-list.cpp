/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL) {
            return NULL;
        }

        ListNode *node=head->next;
        ListNode *prior=head;
        while(node != NULL) {
            if(node->val != prior->val) {
                prior->next = node;
                prior = node;
            } else if (node->next == NULL) {
                prior->next=NULL;
            }
            node=node->next;
        }
        return head;
    }
};
