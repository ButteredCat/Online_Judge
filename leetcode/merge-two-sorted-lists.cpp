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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *l3, *newList;

        // find head of the new list
        if(l1==NULL || l2==NULL) {
            return l1==NULL? l2:l1;
        } else {
            if (l1->val < l2->val) {
                l3=l1;
                l1=l1->next;
            } else {
                l3=l2;
                l2=l2->next;
            }
        }
        newList=l3;
        // merge
        while(l1!=NULL && l2!=NULL) {
            if(l1->val < l2->val) {
                l3->next = l1;
                l1=l1->next;
            } else {
                l3->next = l2;
                l2=l2->next;
            }
            l3=l3->next;
        }
        if(l1==NULL) {
            l3->next=l2;
        }
        if(l2==NULL) {
            l3->next=l1;
        }

        return newList;
    }
};