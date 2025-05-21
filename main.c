/**************************************************************************************************************************************************************
 *Title		: main function(Driver function)
 *Description	: This function is used as the driver function for the all the functions
 ***************************************************************************************************************************************************************/
#include "apc.h"

int main(int argc ,char *argv[])
{
	/* Declare the pointers */
	Dlist *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL ,*tailR = NULL;
	char option, operator;
	int choice ,flag = 0;

	if(argc != 4)
	{
		printf("ERROR : please pass 4 arguments\nUSAGE : ./a.out 1234 + 2345\n\n");
		return FAILURE;
	}

	if(argv[2][0] == '+' || argv[2][0] == '-' || argv[2][0] == '*' || argv[2][0] == '/')
		operator = argv[2][0];
	else
	{
		printf("Invalid Input:-( Try again...\n");
		return FAILURE;
	}

	char *s1 = argv[1];
	char *s2 = argv[3];

	if(strlen(s1) > strlen(s2))
		printf("S1 is greater\n");
	else
		printf("S2 is greater\n");

	if(strlen(s1) < strlen(s2))
	{
		a_to_i(s2 ,&head1 ,&tail1);
		a_to_i(s1 ,&head2 ,&tail2);
	}
	else
	{
		a_to_i(s1 ,&head1 ,&tail1);
		a_to_i(s2 ,&head2 ,&tail2);
	}
	print_list(head1);
	print_list(head2);


	switch (operator)
	{
		case '+':
			/* call the function to perform the addition operation */
			printf("addition selected\n");
			addition(tail1 ,tail2 ,&headR ,&tailR);
			break;
		case '-':	
			/* call the function to perform the subtraction operation */
			if(flag == 1)
				printf("-");
			subtraction(tail1 ,tail2 ,&headR ,&tailR);
			break;
		case '*' || 'x':	
			printf("multiplication selected\n");
			/* call the function to perform the multiplication operation */
			multiplication(tail1 ,tail2 ,&headR ,&tailR);
			break;
		case '/':	
			/* call the function to perform the division operation */
			printf("division selected\n");
			if(strlen(s1) < strlen(s2))
				printf("s1 is less than s2\t Result = 0\n");
			else
				division(&head1 ,&tail1 ,&head2 ,&tail2 ,&headR ,&tailR);
			break;
	}
	return 0;
}

int a_to_i(char *s ,Dlist **head ,Dlist **tail)
{
	int i = 0;

	while(s[i] != '\0')
	{
		int data = s[i] - 48;
		insert_at_last(data ,head ,tail);
		i++;
	}
}

int insert_at_last(data_t data ,Dlist **head ,Dlist **tail)
{
	Dlist *new = malloc(sizeof(Dlist));
	if(new == NULL)
		return FAILURE;

	new->data = data;
	new->prev = NULL;
	new->next = NULL;

	if(*head == NULL)
	{
		*head = new;
		*tail = new;
		return SUCCESS;
	}
	(*tail)->next = new;
	new->prev = *tail;
	*tail = new;
	return SUCCESS;
}

