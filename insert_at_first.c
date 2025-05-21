#include "apc.h"

int insert_at_first(Dlist **head ,Dlist **tail ,data_t data)
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
	new->next = *head;
	(*head)->prev = new;
	*head = new;
	return SUCCESS;
}

