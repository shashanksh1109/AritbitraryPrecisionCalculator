/*******************************************************************************************************************************************************************
 *Title			: Multiplication
 *Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
 *Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
 *Input Parameters	: head1: Pointer to the first node of the first double linked list.
 : tail1: Pointer to the last node of the first double linked list.
 : head2: Pointer to the first node of the second double linked list.
 : tail2: Pointer to the last node of the second double linked list.
 : headR: Pointer to the first node of the resultant double linked list.
 *Output			: Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "apc.h"

int multiplication(Dlist *tail1 ,Dlist *tail2 ,Dlist **headR, Dlist **tailR)
{
	Dlist *res_head1 = NULL, *res_tail1 = NULL, *res_head2 = NULL, *res_tail2 = NULL;
	int mul = 1,carry ,n1,n2,count = 0;

	while(tail1 != NULL)
	{
		/* adding zeros to res1 */
		for(int i = 0; i < count; i++)
		{
			printf("count = %d\n",count);
			insert_at_last(0 ,&res_head1 ,&res_tail1);
		}
		count++; 

		puts("Inside res_head1 before while ");
		print_list(res_head1);

		if(tail1)
			n1 = tail1->data;
		else
			n1 = 1;

		Dlist *temp = tail2; carry = 0;
		while(temp != NULL)
		{

			if(temp)
				n2 = temp->data;
			else
				n2 = 1;

			mul = (n1 * n2) + carry;
			carry = mul / 10;

			if(mul >= 10)
				mul = mul % 10;

			printf("mul = %d\tcarry = %d\n",mul,carry);
			insert_at_first(&res_head1 ,&res_tail1 ,mul);


				temp = temp->prev;
			if(temp == NULL && carry > 0)
				insert_at_first(&res_head1 ,&res_tail1 ,carry);
			
			print_list(res_head1);
		}
		puts("Inside res_head1 1 :");
		print_list(res_head1);

		if(res_head2 == NULL)
			insert_at_last(0 ,&res_head2 ,&res_tail2);

		printf("before adding res_head2 :");
		print_list(res_head2);

		/*call addition fun to add res1 & res2 */
		addition(res_tail1 ,res_tail2 ,headR ,tailR);

		//delete res_head1
		delete_list(&res_head1 ,&res_tail1);

		//delete res_head2
		delete_list(&res_head2 ,&res_tail2);

		/* copying result to res2 */
		res_tail2 = *tailR;
		res_head2 = *headR;

		*headR = NULL;
		*tailR = NULL;
		
		tail1 = tail1->prev;
	}
	printf("multiplication :");
	print_list(res_head2);
}

int delete_list(Dlist **head,Dlist **tail)
{
	if(*head == NULL)
		return FAILURE;

	*head = (*head)->next;
	while(*head)
	{
		free((*head)->prev);
		*head = (*head)->next;
	}
	*tail = NULL;
		return SUCCESS;
}

