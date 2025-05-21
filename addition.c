/*******************************************************************************************************************************************************************
 *Title			: Addition
 *Description		: This function performs addition of two given large numbers and store the result in the resultant list.
 *Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
 *Input Parameters	: head1: Pointer to the first node of the first double linked list.
 : tail1: Pointer to the last node of the first double linked list.
 : head2: Pointer to the first node of the second double linked list.
 : tail2: Pointer to the last node of the second double linked list.
 : headR: Pointer to the first node of the resultant double linked list.
 *Output			: Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "apc.h"
int addition(Dlist *tail1, Dlist *tail2, Dlist **headR ,Dlist **tailR)
{
	int sum = 0,carry = 0,n1,n2;
	/* Definition goes here */
	while(tail1 != NULL || tail2 != NULL)
	{
		if(tail1)
			n1 = tail1->data;
		else
			n1 = 0;

		if(tail2)
			n2 = tail2->data;
		else
			n2 = 0;

		sum = n1 + n2 + carry;
		carry= sum/10;

		if(sum >= 10)
		{
			sum = sum % 10;
		}
		insert_at_first(headR ,tailR ,sum);

		if(tail1 != NULL)
			tail1 = tail1->prev;
		if(tail2 != NULL)
			tail2 = tail2->prev;
	}
	printf("Addition :");
		print_list(*headR);
}
