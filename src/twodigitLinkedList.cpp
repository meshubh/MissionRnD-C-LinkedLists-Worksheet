/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>
int pow_10(int n);
struct node {
	int digit1;
	int digit2;
	struct node *next;
};

int convert_sll_2digit_to_int(struct node *head)
{
	int num = 0,count=0;
	struct node* temp;
	temp = head;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	count = count * 2 - 1;
	while (head)
	{
		num = num + ((head->digit1) * pow_10(count));
		count--;
		num = num + ((head->digit2) * pow_10(count));
		count--;
		head = head->next;
	}
	return num;
}
int pow_10(int n)
{
	int iterator, power = 1;
	for (iterator = 0; iterator<n; iterator++)
	{
		power = power * 10;
	}
	return power;
}