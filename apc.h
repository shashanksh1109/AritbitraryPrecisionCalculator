#ifndef APC_H
#define APC_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

int a_to_i(char *s ,Dlist **head ,Dlist **tail);
int insert_at_last(int data ,Dlist **head ,Dlist **tail);
int insert_at_first(Dlist **head ,Dlist **tail,int data);
int delete_list(Dlist **head ,Dlist **tail);

int addition(Dlist *tail1 ,Dlist *tail2 ,Dlist **headR ,Dlist **tailR);
int subtraction(Dlist *tail1 ,Dlist *tail2 ,Dlist **headR ,Dlist **tailR);
int multiplication(Dlist *tail1 ,Dlist *tail2 ,Dlist **headR ,Dlist **tailR);
int division(Dlist **head1 ,Dlist **tail1 ,Dlist **head2 ,Dlist **tail2 ,Dlist **headR ,Dlist **tailR);
void print_list(Dlist *head);
#endif
