 /*
NO.203
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
 */
//Tue Apr 28 01:15:42 CST 2015	DEUS
#include <stdlib.h>
#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* Ret = head;
	struct ListNode* pre = head;
	struct ListNode* cur = head;
	if(NULL == head) return head;
	do
	{
		if (cur == Ret && cur->val == val)
		{
			Ret = cur->next;
			free(cur);
			pre = Ret;
			cur = Ret;
		}
		else if (cur->val == val)
		{
			struct ListNode* tmp = cur;
			pre->next = cur->next;
			cur = cur->next;
			free(tmp);
			
		}
		else if (cur == Ret)
		{
			cur = cur->next;
		}
		else
		{
			cur = cur->next;
			pre = pre->next;
		}
	}
	while (NULL != cur);
	return Ret;
}
int main()
{
	struct ListNode* f1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* f2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* f3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	f1->val = 1;
	f2->val = 2;
	f3->val = 1;
	f1->next = f2;
	f2->next = f3;
	f3->next = NULL;

	struct ListNode* p = removeElements(f1, 1);
	
	while(NULL != p){
		printf("%d\n", p->val);
		p = p->next;
	}

}

