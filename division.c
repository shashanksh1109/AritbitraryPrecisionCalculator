/*******************************************************************************************************************************************************************
 *Title			: Division
 *Description		: This function performs division of two given large numbers and store the result in the resultant list.
 *Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
 *Input Parameters	: head1: Pointer to the first node of the first double linked list.
 : tail1: Pointer to the last node of the first double linked list.
 : head2: Pointer to the first node of the second double linked list.
 : tail2: Pointer to the last node of the second double linked list.
 : headR: Pointer to the first node of the resultant double linked list.
 *Output			: Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "apc.h"

int division(Dlist **head1 ,Dlist **tail1 ,Dlist **head2 ,Dlist **tail2 ,Dlist **headR ,Dlist **tailR)
{
	int count = 1;

	while(*head1 != *tail1)
	{
		 /*call addition fun to add count to the list  add(original_count ,1)*/
         /*copy the count to from resultant list to original count copy(original_count ,res)*/
         /*subtraction function*/
         /*copy result from resultant to head1 list*/

		subtraction(*tail1 ,*tail2 ,headR ,tailR);
		*head1 = *headR;
		*tail1 = *tailR;

		*headR = NULL;
		*tailR = NULL;

		count++;
		if(*head1 == *tail1)
		{
			while((*head1)->data > (*head2)->data)
			{
				printf("head1 ->data = %d\n",(*head1)->data);
				subtraction(*tail1 ,*tail2 ,headR ,tailR);
				*head1 = *headR;
				*tail1 = *tailR;

				*headR = NULL;
				*tailR = NULL;
				count ++;
			}
			if((*head1)->data == (*head2)->data)
				count ++;

			print_list(*head1);
			printf("count = %d\n",count);
		}
	}
}


#if 0
	int division(char *s1 ,char *s2)
	{
		/* Definition goes here */
		int n1 = atoi(s1);
		int n2 = atoi(s2) ,count = 1;

		while(n1 > n2)
		{
			n1 = n1 - n2;
			count++;
			printf("n1 = %d\t n2 = %d\t count = %d\n",n1,n2,count);
		}
		printf("count = %d\n",count);

	}
#endif

