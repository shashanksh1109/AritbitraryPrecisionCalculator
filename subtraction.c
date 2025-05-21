/*******************************************************************************************************************************************************************
 *Title			: Subtraction
 *Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
 *Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
 *Input Parameters	: head1: Pointer to the first node of the first double linked list.
 : tail1: Pointer to the last node of the first double linked list.
 : head2: Pointer to the first node of the second double linked list.
 : tail2: Pointer to the last node of the second double linked list.
 : headR: Pointer to the first node of the resultant double linked list.
 *Output			: Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "apc.h"

int subtraction(Dlist *tail1 ,Dlist *tail2, Dlist **headR, Dlist **tailR)
{
	int n1,n2,res = 0,borrow = 0;
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

		if(borrow == 1)
			n1 = n1-1;

		if(n1 < n2)
		{
			n1 = n1 + 10;
			res = n1 - n2;
			borrow = 1;
		}
		else
		{
			res = n1 - n2;
			borrow = 0;
		}
		if(res != 0 || tail1->prev != NULL)
			insert_at_first(headR ,tailR ,res);

		if(tail1)
			tail1 = tail1->prev;
		if(tail2)
			tail2 = tail2->prev;
	}
	printf("Subtraction :");
		print_list(*headR);
}
