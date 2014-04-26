#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
	if(head!=NULL)
	{
		//find head of the new list
		while(head->next!=NULL)
		{
			if(head->val != head->next->val)
			{
				if(head->next->next == NULL)
				{
					break;
				}
				else if(head->next->val != head->next->next->val)
				{
					break;
				}
			}
			else if(head->next->next != NULL)
			{
				head=head->next->next
			}
		}
	}
	return head;
}
