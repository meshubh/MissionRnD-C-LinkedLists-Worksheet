/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K)
{
	struct node * current = head;
	struct node * temp = head;
	struct node * prev = NULL;
	int count = 0, len = 0,i;
	if (head == NULL)
		return NULL;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	if (K <= 1 )
		return NULL;
	for (i = 1; i < len; i++)
	{
		if (i % K == 0)
		{
			prev->next = current->next;
			current = current->next;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
	if (len%K == 0)
		prev->next = NULL;
	prev = head;
	return prev;
}