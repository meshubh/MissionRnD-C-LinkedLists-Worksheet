/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N)
{

	struct node *link = (struct node *) malloc(sizeof(struct node));
	struct node *head = NULL;
	if (N<0)
		N = N*-1;
	else if (N == 0)
	{
		link->num = 0;
		link->next = NULL;
		return link;
	}
	while (N>0)
	{
		struct node *link = (struct node *) malloc(sizeof(struct node));
		link->num = N % 10;
		N = N / 10;
		link->next = head;
		head = link;
	}
	link = head;
	return link;
}